#pragma once
#include <hash_map>
#include "CLRContext.h"

#ifdef _MANAGED
//#error "oops"
#include <vcclr.h>
#include "FastInvoker.h"

// #define IMPORT_1C __declspec(dllimport)
// #include <afx.h>
// #include <afxext.h>
// #include <afxtempl.h>
// #include <set>
// #include <map>
// #include <WTypes.h>
// class IDispatch;
// #include "../../_1Common.2005/1cheaders/type32.h"
// #include "../../_1Common.2005/1cheaders/types.h"
// #include "../../_1Common.2005/1cheaders/br32.h"
// #include "../../_1Common.2005/1cheaders/bkend.h"
// #include "../../_1Common.2005/1cheaders/basic.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Security::Permissions;

typedef array<System::Reflection::MethodInfo^> methodsArray;
typedef array<System::Reflection::PropertyInfo^> propertiesArray;
typedef array<Type^> paramTypesArray;

private class PropInfo
{
protected:
	friend class CCLRWrapper;
	gcroot<FastGetAccessorHandler^> clrGetAccessor;
	gcroot<FastSetAccessorHandler^> clrSetAccessor;
	gcroot<Type^> propType;
public:
	~PropInfo();
};
typedef PropInfo* propInfoPtr;

private class MethInfo
{
protected:
	friend class CCLRWrapper;
	int numParams;
	gcroot<FastInvokeHandler^> clrInvokeHandler;
	gcroot<MethodInfo^> reflectionMethodInfo;
	gcroot<paramTypesArray^> paramTypes;
	gcroot<Type^> retType;
public:
	~MethInfo();
};

typedef MethInfo* methInfoPtr;

typedef array<Object^> ObjectArray;
ref class EventManager;
public delegate void CallAsProcDelegate(ObjectArray^ args, Int32 v7ProcNum);

class CCLRWrapper;

//[System::Security::Permissions::SecurityPermissionAttribute(SecurityAction::Assert,UnmanagedCode=true)]
 ref class EventManager: public System::Windows::Forms::Control
 {
 public:
 	EventManager(CCLRWrapper* wrapper,Object ^ sender, CBLContext* context, String^ prefix);
 	void HandleEvent(ObjectArray^ args, Int32 v7ProcNum);
 	void InvokeBLProc(ObjectArray^ args, Int32 v7ProcNum);
 	CBLContext* context;
 private:
 	CallAsProcDelegate^ callProcDelegate;
 	Object^ source;
 	CCLRWrapper* wrapper;
 };

#endif

class CCLRWrapper
{
private:
#ifdef _MANAGED
public:
	static void ObjectToValue(Object^,Type^,CValue&);
	static void ValueToObject(const CValue &, Object^%, Type^);
private:
	gcroot<System::Object^> pClrObj;
	gcroot<EventManager^> eventManager;
	typedef stdext::hash_map<int,propInfoPtr> propInfoMap_t;
	typedef stdext::hash_map<int,methInfoPtr> methInfoMap_t;
	propInfoMap_t propInfoMap;
	methInfoMap_t methInfoMap;
	propInfoPtr GetPropInfo(int);
	void Init(Type^);
	CCLRWrapper(Object^);
	static int MethodComparer(MethodInfo^ meth1,MethodInfo^ meth2);
#else
	char fill[4];//pClrObj
	char fill2[60];//propInfoMap
	char fill3[60];//methInfoMap
	char fill4[4];//eventManager
#endif
	typedef stdext::hash_map<std::string, int> propNamesMap_t;
	typedef stdext::hash_map<std::string, int> methNamesMap_t;
	propNamesMap_t propNamesMap;
	methNamesMap_t methNamesMap;
public:
	CCLRWrapper(int nParamsCount,	CValue** ppValue);
	CCLRWrapper(char const * szClassName);
	CCLRWrapper(CGetField* getField, const char* className);
	~CCLRWrapper(void);
	int  CallAsFunc(int,CValue&,CValue**);
	int  CallAsProc(int,CValue**);
	int  FindMethod(char const *)const;
	int  FindProp(char const *)const;
	char const*  GetMethodName(int)const;
	int  GetNMethods(void)const;
	int  GetNParams(int);
	int  GetNProps(void)const;
	int  GetParamDefValue(int,int,CValue*)const;
	char const* GetPropName(int)const;
	int  GetPropVal(int,CValue&);
	//long  GetTypeID(void)const;
	char const* GetTypeString(void)const;
	//CType GetValueType(void)const;
	int  HasRetVal(int);
	int  IsExactValue(void)const;
	int  IsOleContext(void)const;
	int  IsPropReadable(int);
	int  IsPropWritable(int);
	int  IsSerializable(void);
	int  SaveToString(CString &);
	int  SetPropVal(int,CValue const&);
};

class CCLRContext :	public CBLContext
{
	friend class CCLRWrapper;
	DECLARE_DYNCREATE(CCLRContext);
protected:
	CCLRWrapper* clrwrapper;
public:
	CCLRContext();
	CCLRContext(int nParamsCount,	CValue** ppValue);
	CCLRContext(char const * szClassName);
	CCLRContext(CCLRWrapper* wrapper);
	CCLRContext(CGetField* getField, const char* className);
	~CCLRContext(void);
	virtual int  CallAsFunc(int,CValue&,CValue**);
	virtual int  CallAsProc(int,CValue**);
	virtual int  FindMethod(char const *)const;
	virtual int  FindProp(char const *)const;
	//virtual int  GetDestroyUnRefd(void)const {return TRUE;};
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
};
