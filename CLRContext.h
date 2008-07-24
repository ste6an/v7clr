#pragma once
#include "StdAfx.h"
#include "CLRWrapper.h"

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
