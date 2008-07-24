// mycontextbase.h
// ������������ ���� ��� �������� ������, ������������ ���������������� CBLContext'�
// ��������������:
// - ��������������� ��������� ������ � CBLContext::RegisterContextClass
// - ��������� ���������������� ������� ��� ������ ����������� ������
// - ������ � ������ �������, ������� ����� ������ ������, ���������������
//		������ ������ � ����������, �������� � �����
// - ������ � ������ ���������� �������, ������� ����� ������ ��������,
//		���������/������ �������� ����� �����������, �������� � �����.
// - ��������� ������� � �������������� ������ ����������
// �����������:
// - ������ ���� ������ � ������ ������������ ������ ������.

#ifndef MYCONTEXTBASE_H
#define MYCONTEXTBASE_H
#include "blmap.h"
#include "blptr.h"

typedef int (CBLContext::*PF_GET_PROP)(CValue&)const;
typedef int (CBLContext::*PF_SET_PROP)(CValue const&);
typedef int (CBLContext::*PF_CALL_AS_PROC)(CValue**);
typedef int (CBLContext::*PF_CALL_AS_FUNC)(CValue&,CValue**);
typedef int (CBLContext::*PF_GET_PARAM_DEF)(int,CValue*)const;
//typedef int (PF_CTOR_PARAM_DEF)(int,CValue*);

typedef int (CBLContext::*PF_CALL_AS_PROC_WITH_UN_LIM_PARAMS)(int nParamsCount, CValue**);
typedef int (CBLContext::*PF_CALL_AS_FUNC_WITH_UN_LIM_PARAMS)(int nParamsCount, CValue&, CValue**);

// ����������, ��� ������� �����
class CMyContextBase : public CBLContext  
{
public:
	CMyContextBase();
	virtual ~CMyContextBase();  
	virtual int  CallAsFunc(int,CValue&,CValue**);
	virtual int  CallAsProc(int,CValue**);
	virtual int  FindMethod(char const *)const;
	virtual int  FindProp(char const *)const;
    //virtual char const*  GetCode(void)const;
	virtual int  GetDestroyUnRefd(void)const;
	//virtual CObjID GetID(void)const;
	virtual char const*  GetMethodName(int,int)const;
	virtual int  GetNMethods(void)const;
	virtual int  GetNParams(int)const;
	virtual int  GetNProps(void)const;
	virtual int  GetParamDefValue(int,int,CValue*)const;
	virtual char const* GetPropName(int,int)const;
	virtual int  GetPropVal(int,CValue&)const;
	//virtual long  GetTypeID(void)const;
	virtual char const* GetTypeString(void)const;
	//virtual CType GetValueType(void)const;
	virtual int  HasRetVal(int)const;
	virtual int  IsExactValue(void)const;
	virtual int  IsOleContext(void)const;
	virtual int  IsPropReadable(int)const;
	virtual int  IsPropWritable(int)const;
	virtual int  IsSerializable(void);
	virtual int  SaveToString(CString &);
	virtual int  SetPropVal(int,CValue const&);

	virtual struct _S_MyContextBaseInfo* GetBaseInfo()const=0;
	static void InitContextClass(_S_MyContextBaseInfo* pInfo);
	static void DoneContextClass(_S_MyContextBaseInfo* pInfo);

    virtual BOOL _Create(CValue** ppValue) {return TRUE;};
};

// ������ ���������������

// �������� ����� ������ � ����� �������
struct _S_MethDef
{
	const char *Names[2];	// ����� ������
	DWORD NumberOfParam;
	PF_CALL_AS_PROC pDoProc;
	PF_CALL_AS_FUNC pDoFunc;
	PF_GET_PARAM_DEF pDefValProc;

	bool bIsUnLimParMethod; // ������� � �������������� ����������� ����������
	PF_CALL_AS_PROC_WITH_UN_LIM_PARAMS pDoProcWithUnLimParams;
	PF_CALL_AS_FUNC_WITH_UN_LIM_PARAMS pDoFuncWithUnLimParams;
};

// ��������� ����� ������ � ����� �������
struct _S_PropDef
{
	const char *Names[2];
	PF_GET_PROP pGetProp;
	PF_SET_PROP pSetProp;
};

// ��������� ���������� � ������-���������
typedef void (*PVVF)();

struct _S_MyContextBaseInfo
{
	// ���������, ������ ���������� ��� ����������
	const _S_MethDef* pMethodDef;	// ����� �������
	const _S_PropDef* pPropDef;		// ����� �������
	const char* EngTypeString;		// ��� ���� ����������
	const char* RusTypeString;		// ��� ���� �������
	BOOL RegToCreate;				// �������������� ����� ��� �������� ��������
	const CRuntimeClass* pRTC;		// ��� ����������� ��� ������������
	int methCount;					// ���������� �������
	int propCount;					// ���������� �������
	PVVF pInitFunc;					// ��������� �� �������-�������������
	PVVF pDoneFunc;					// ��������� �� �������-�������������
    int nFactoryCtorParamCount;     // ���������� ���������� ������������ �������
    //PF_CTOR_PARAM_DEF pCtorParamDef;// ��������� �� ������� ��������� �������� ��������� ��-��������� ��� ������������ �������

	// artbear
	int m_CountParametersInCallMethod; // ���������� ���������� � ������, ������� ��������

	// ���������, ����������� � ����������� ��� �������������
	CBLMap* pMethMap;	// ������� ����� ������ ������
	CBLMap* pPropMap;	// ������� ����� ������ ��������
};

// ������ ��� ������������ ���������� ������-���������
#define DECLARE_MY_CONTEXT() \
public:\
	static _S_MyContextBaseInfo		m_myCtxBaseInfo[]; \
	static const _S_MethDef			m_MethDef[]; \
	static const _S_PropDef			m_PropDef[]; \
	virtual _S_MyContextBaseInfo* GetBaseInfo()const{return m_myCtxBaseInfo;}

// ������ ��� ����������� ������ ������������ ������-���������
#define IMPLEMENT_MY_CONTEXT(parClassName, parEngTypeString, parRusTypeString, parRegToCreate, parInitFunc, parDoneFunc, parFactoryCtorParamCount) \
	_S_MyContextBaseInfo parClassName::m_myCtxBaseInfo[]= \
	{\
		parClassName::m_MethDef, \
		parClassName::m_PropDef, \
		parEngTypeString, \
		parRusTypeString, \
		parRegToCreate, \
		RUNTIME_CLASS(parClassName), \
		sizeof(parClassName::m_MethDef)/sizeof(_S_MethDef) - 1, \
		sizeof(parClassName::m_PropDef)/sizeof(_S_PropDef) - 1, \
		parInitFunc, \
		parDoneFunc, \
        parFactoryCtorParamCount,\
		-1,\
		NULL, NULL \
	};\
	IMPLEMENT_DYNCREATE(parClassName, CBLContext)

// 2 ������� ��� ����������� ����������� ��� ������ ���������� �� ���������
#define IMPLEMENT_MY_CREATE_CONTEXT(parClassName, parEngTypeString, parRusTypeString) \
	IMPLEMENT_MY_CONTEXT(parClassName, parEngTypeString, parRusTypeString, 1, NULL, NULL, -1)

#define IMPLEMENT_MY_NONCREATE_CONTEXT(parClassName, parEngTypeString, parRusTypeString) \
	IMPLEMENT_MY_CONTEXT(parClassName, parEngTypeString, parRusTypeString, 0, NULL, NULL, -1)

#define BEGIN_BL_METH_MAP(parClassName) \
	const _S_MethDef parClassName::m_MethDef[]={

// ������� ��� ����������� �������
#define BL_METH(parNameEng,parNameRus,parNumberOfParam,parDoProc,parDoFunc,parDefValProc) \
	{{parNameEng,parNameRus},parNumberOfParam,static_cast<PF_CALL_AS_PROC>(parDoProc),static_cast<PF_CALL_AS_FUNC>(parDoFunc),static_cast<PF_GET_PARAM_DEF>(parDefValProc), false, NULL, NULL},

// 4 ������� ��� ����������� ����������� ��� ������ ���������� �� ���������
#define BL_METH_PROC(parNameEng,parNameRus,parNumberOfParam,parDoProc) \
	{{parNameEng,parNameRus},parNumberOfParam,static_cast<PF_CALL_AS_PROC>(parDoProc), NULL, NULL, false, NULL, NULL},

#define BL_METH_FUNC(parNameEng,parNameRus,parNumberOfParam,parDoFunc) \
	{{parNameEng,parNameRus},parNumberOfParam, NULL, static_cast<PF_CALL_AS_FUNC>(parDoFunc), NULL, false, NULL, NULL},

#define BL_METH_PROC_DEF_PARAM(parNameEng,parNameRus,parNumberOfParam,parDoProc,parDefValProc) \
	{{parNameEng,parNameRus},parNumberOfParam,static_cast<PF_CALL_AS_PROC>(parDoProc), NULL, static_cast<PF_GET_PARAM_DEF>(parDefValProc), false, NULL, NULL},

#define BL_METH_FUNC_DEF_PARAM(parNameEng,parNameRus,parNumberOfParam,parDoFunc,parDefValProc) \
	{{parNameEng,parNameRus},parNumberOfParam, NULL, static_cast<PF_CALL_AS_FUNC>(parDoFunc), static_cast<PF_GET_PARAM_DEF>(parDefValProc), false, NULL, NULL},

// artbear
// 2 ������� ��� ����������� ������� � �������������� ������ ����������
// parNumberOfParam - ����� ������������ ����������
// ���� 0, ������, ���������� ���������� ���, � ������� ��� ����������
//
#define BL_METH_PROC_WITH_UN_LIM_PARAMS(parNameEng,parNameRus,parNumberOfParam,parDoProc) \
	{{parNameEng,parNameRus},parNumberOfParam,NULL, NULL, NULL, true, static_cast<PF_CALL_AS_PROC_WITH_UN_LIM_PARAMS>(parDoProc), NULL},

#define BL_METH_FUNC_WITH_UN_LIM_PARAMS(parNameEng,parNameRus,parNumberOfParam,parDoFunc) \
	{{parNameEng,parNameRus},parNumberOfParam, NULL, NULL, NULL, true, NULL, static_cast<PF_CALL_AS_FUNC_WITH_UN_LIM_PARAMS>(parDoFunc)},

#define END_BL_METH_MAP() {{NULL,NULL},0,0,NULL,NULL}};

// ������� ��� ����������� �������
#define BEGIN_BL_PROP_MAP(parClassName) \
	const _S_PropDef parClassName::m_PropDef[]={

#define BL_PROP(parNameEng,parNameRus,parGet,parSet) \
	{{parNameEng,parNameRus},static_cast<PF_GET_PROP>(parGet),static_cast<PF_SET_PROP>(parSet)},

#define END_BL_PROP_MAP() {{NULL,NULL},NULL,NULL}};

// artbear ������ ��� ������ ��� �������
#define BEGIN_EMPTY_BL_PROP_MAP(parClassName) \
	BEGIN_BL_PROP_MAP(parClassName) \
	END_BL_PROP_MAP()

#define IS_BLTYPE(Value, class_name) (Value.GetTypeCode() == AGREGATE_TYPE_1C && Value.GetContext()->GetRuntimeClass() == RUNTIME_CLASS(##class_name))

#define CHECK_BLTYPE(Value, class_name)\
    if (!IS_BLTYPE(Value, class_name))\
    {\
        CBLModule::RaiseExtRuntimeError("������������ �������� ��������.", 0);\
        return FALSE;\
    }

#define GET_ENUM_PROP(type, first, last)\
    type _enum = (type)Value.GetNumeric().operator long();\
    if (_enum < first || _enum > last)\
    {\
        CBLModule::RaiseExtRuntimeError("������������ �������� ��������.", 0);\
        return FALSE;\
    }

// ���������� ��������-������ ��� ������
#define DECLARE_PROPERTY_ARRAY(PropertyName, PropertyType, PropertyKeyType) \
	__declspec(property(get=get_##PropertyName, put=put_##PropertyName)) PropertyType PropertyName []; \
	BOOL get_##PropertyName(PropertyKeyType key);  \
	void put_##PropertyName(PropertyKeyType key, PropertyType newValue);

// ���������� ������� �������� ��� ������
#define DECLARE_ONE_PROPERTY(Property, PropertyType) \
	__declspec(property(get=get_##Property, put=put_##Property)) PropertyType Property; \
	BOOL get_##Property();  \
	void put_##Property(PropertyType newValue);

// ������� ������� ��� ��������, ����� �������� __declspec allocate
#pragma data_seg(".blc$b")
#pragma data_seg()

// ������ ������� � �������� ����� ����� �������� .blc � .data
#pragma comment(linker, "/MERGE:.blc=.data")
#endif