#include "StdAfx.h"
#include "CLRContext.h"

IMPLEMENT_DYNCREATE(CCLRContext, CBLContext)

CCLRContext::CCLRContext() : CBLContext(1){}

CCLRContext::CCLRContext(int nParamsCount,	CValue** ppValue)
: CBLContext(1)
{
	clrwrapper = new CCLRWrapper(nParamsCount,ppValue);
}

CCLRContext::CCLRContext(CCLRWrapper* wrapper)
: CBLContext(1)
{
	clrwrapper = wrapper;
}

CCLRContext::CCLRContext(char const * szClassName)
: CBLContext(1)
{
	clrwrapper = new CCLRWrapper(szClassName);
}

CCLRContext::CCLRContext(CGetField* getField, const char* className)
: CBLContext(1)
{
	clrwrapper = new CCLRWrapper(getField,className);
}

CCLRContext::~CCLRContext(void)
{
	delete clrwrapper;
}

int  CCLRContext::CallAsFunc(int iMethNum,CValue& rValue,CValue **ppValue)
{
	return clrwrapper->CallAsFunc(iMethNum,rValue,ppValue);
}
int  CCLRContext::CallAsProc(int iMethNum,CValue **ppValue)
{
	return clrwrapper->CallAsProc(iMethNum,ppValue);
}

int  CCLRContext::FindMethod(char const * lpMethodName)const
{
	return clrwrapper->FindMethod(lpMethodName);
}

char const*  CCLRContext::GetMethodName(int iMethNum,int iMethodAlias)const
{
	return clrwrapper->GetMethodName(iMethNum);
}

int  CCLRContext::GetNMethods(void)const
{
	return clrwrapper->GetNMethods();
}

int  CCLRContext::GetNParams(int iMethodNum)const
{
	return clrwrapper->GetNParams(iMethodNum);
}

int  CCLRContext::GetParamDefValue(int iMethodNum,int iParamNum,CValue *pDefValue)const
{
	return clrwrapper->GetParamDefValue(iMethodNum,iParamNum,pDefValue);
}

int  CCLRContext::HasRetVal(int iMethodNum)const
{
	return clrwrapper->HasRetVal(iMethodNum);
}

int  CCLRContext::GetNProps(void)const
{
	return clrwrapper->GetNProps();
}

int  CCLRContext::FindProp(char const * propName)const
{
	return clrwrapper->FindProp(propName);
}

char const* CCLRContext::GetPropName(int propNum, int propAlias)const
{
	return clrwrapper->GetPropName(propNum);
}

int  CCLRContext::GetPropVal(int propNum,CValue& retVal)const
{
	return clrwrapper->GetPropVal(propNum,retVal);
}

int  CCLRContext::SetPropVal(int iPropNum,CValue const &vValue)
{
	return clrwrapper->SetPropVal(iPropNum,vValue);
}

char const* CCLRContext::GetTypeString(void)const
{
	return clrwrapper->GetTypeString();
}

int  CCLRContext::IsExactValue(void)const
{
	return clrwrapper->IsExactValue();
}

int  CCLRContext::IsOleContext(void)const
{
	return clrwrapper->IsOleContext();
}

int  CCLRContext::IsPropReadable(int iPropNum)const
{
	return clrwrapper->IsPropReadable(iPropNum);
}

int  CCLRContext::IsPropWritable(int iPropNum)const
{
	return clrwrapper->IsPropWritable(iPropNum);
}

int  CCLRContext::IsSerializable(void)
{
	return clrwrapper->IsSerializable();
}

int  CCLRContext::SaveToString(CString &str)
{
	return clrwrapper->SaveToString(str);
}

