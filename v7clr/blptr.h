//______________________________________________________________________________
//
// ������� � ������� �����-��������� �� CBLContext
//
// �����: ����� �������� ���������� ���������
//		������� ��� ��������� ������� ������ ��� ��������� ����������� �������� DecrRef
//
// ������� ����� ������ ������������ ��� ����������, ����������� ��������������� � ���� ��
//
//	�����: ����� ������ ������������ ��� �������� ��������� ����������, 
//		�.�. �� ������������� �������� ����� ������������� � �������� ��������������� ����������
//
//	���������� �������� ������ ���������� ����� - ����� ��������� �� �������� CSafeContextPtr (SafeContext.h)
//		��� ����� ���������� �����, ������������� ����������� ����� ����������, 
//			� �.�. � ��������� ����������
//		����������� ����������� ������ � �������������� ������������� 
// 
//	����� DmitrO 
// ����� ��������� � ������� artbear, 2006

// kms:
// ��� ��������� ���������� ������ IncrRef /DecrRef �� ���������� - ��� �����������
//______________________________________________________________________________
//

//#pragma once
#ifndef __BLPTR__INCLUDED
#define __BLPTR__INCLUDED

template <class T>
class CBLPtr
{
public:
	typedef T _PtrClass;
	CBLPtr() : p(NULL), m_bIsGroupContext(FALSE)
	{	}

	CBLPtr(T* lp) : p(NULL), m_bIsGroupContext(FALSE)
	{
		_Assign(lp);
	}

	template<class U>
	CBLPtr(const CBLPtr<U>& lp) : p(NULL), m_bIsGroupContext(FALSE)
	{
		_Assign((U*)lp); // ����� ����� ���� ��������� ���������� �� CBLPtr<CBLContext> � CBLPtr<CComponentClass>
	}

	// ������� ����� �RuntimeClass::CreateObject
	CBLPtr(CRuntimeClass& RuntimeClassRef) : p(NULL), m_bIsGroupContext(FALSE)
	{
		T* newptr = static_cast<T*>(RuntimeClassRef.CreateObject());
		_Assign(newptr);
		newptr->DecrRef();
	}

	// ���� �������� ������ ������, ����� ������ �������� ���� ����, ��� �������� � �������
	//	����� �� ������ ��� ������ ����
	//		CBLPtr<CExecuteModule> pContExecModule();
	//		pContExecModule.Create();
	//	� ������
	//		CBLPtr<CExecuteModule> pContExecModule("");
	//
    CBLPtr(const CString& szTypeName) : p(NULL), m_bIsGroupContext(FALSE)
    {
		if (szTypeName.IsEmpty())
			Create();
		else
			Create(szTypeName);
    };
	~CBLPtr()
	{
		Release();
	}
	operator T*() const
	{
		return (T*)p;
	}

	// TODO ������-�� ��� ������������� CBLPTr<CBLFont> � ������������� ����� ���������
	// ���� ���� �������� �� ���������� � h-�����, � � cpp-�����, ����� ������ ��������
	// ���� �� ������ ����� CBLContext& CSafeContextPtr<CBLFont>::operator*() const
	// � ������, ����������� ��� � �� ������� :(
	T& operator*() const
	{
		ATLASSERT(p!=NULL);
		if (p)
			return *p;

		// TODO � h-����� �� ������� ��������������� ����. �������
		// ���� ���������� ������������ �����, �������� ������ ����������
		//
		//::RuntimeError("CSafeContextPtr:: ������� ��������� � ��������������� ���������");
		_ErrorNULLObject(); // ������������� ����������

		return *p; // ��� ���������� �������������� �����������

	}

/* artbear ������� ������� �������� - ����� ������ ������ ����� �������� �������� ����������� ���������
	//The assert on operator& usually indicates a bug.  If this is really
	//what is needed, however, take the address of the p member explicitly.
	T** operator&()
	{
		ATLASSERT(p==NULL);
		return &p;
	}
*/    
	T* operator->() const
	{
		ATLASSERT(p!=NULL);
		if (p)
			return p;

		_ErrorNULLObject(); // ������������� ����������

		return p; // ��� ���������� �������������� �����������
	}
    
	CBLPtr& operator=(T* lp)
	{
		if (p != lp)
			Assign(lp);

	    return *this;
	}

	template<class U>
	CBLPtr& operator=(const CBLPtr<U>& lp)
	{
		if (&lp == this)
			return *this;

		return operator=(lp.p);
	}

	bool operator!() const
	{
		return !operator bool();
	}

	operator bool() const
	{
		return (p != NULL);
	}

	bool operator==(T* pT) const
	{
		return p == pT;
	}

	bool operator!=(T* pT) const
	{
		return !operator ==(pT);
	}

    void Create()
    {
		Release();

		// �� ��������� ������� ������ �� ����� Assign
        p = new T();
		_CheckContext();
    };

    void Create(const CString& szTypeName)
    { // TODO ��� �������� ������������ ����������� ����� � ����� ������-�������

		Release();

		// ���� try �� ����� artbear - � ���� ��� ������������ ������� ����� :)
		// �� ��������� ������� ������ �� ����� Assign
		p = (T*)CBLContext::CreateInstance(szTypeName); //no cast is special: this only for CBLContext instance
		_CheckContext();
    };

	// �������� ��������� ����������
	inline BOOL IsGroupContext() const
	{
		return m_bIsGroupContext;
	};

	void Empty(void) { Release(); p = 0; }

protected: // artbear
	//T* ptr;
	T* p;
	BOOL m_bIsGroupContext;

	void _CheckContext()
	{
		if (p)
			m_bIsGroupContext = p->IsKindOf( RUNTIME_CLASS( CGroupContext ));

		else
			m_bIsGroupContext = FALSE;
	};

	void _IncrRef()
	{
		if (p && !IsGroupContext())
			p->IncrRef();
	}

	void _DecrRef()
	{
		if (p && !IsGroupContext())
			p->DecrRef();
	}

	// ���������� ������
	void _Assign(T * pCont)
	{
		p = pCont;

		_CheckContext();
		_IncrRef();
	};

	void Assign(T * pCont)
	{
		Release();
		_Assign(pCont);
	};

	// ������������ ������
	void Release()
	{
		_DecrRef();
		//p = 0;
	};

	void _ErrorNULLObject(LPCSTR szErrorString = NULL) const; // ������������� ���������� � ��������� ����������

};

// ��������� ���������� � ��������� ����������
template <class T>
void CBLPtr<T>::_ErrorNULLObject(LPCSTR szErrorString) const
{
	if (!szErrorString)
		szErrorString = "CBLPtr<T> : ������� ��������� � ��������� NULL"; // TODO ���������� ��� ��������� ������ ��� �������� ��������

	::RuntimeError("%s", szErrorString); // TODO � ���������� ����� ������� ������ ��� ����������

};

#endif