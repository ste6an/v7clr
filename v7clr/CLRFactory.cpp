#include "StdAfx.h"
#include "CLRFactory.h"
#include "CLRContext.h"

BEGIN_BL_METH_MAP(CCLRFactory) 
	BL_METH_FUNC_WITH_UN_LIM_PARAMS("CreateInstance", "—оздать", 1, &CCLRFactory::fNewObject)
	BL_METH_FUNC("CreateControl","—оздатьЌа‘орме",2,&CCLRFactory::pCreateControl)
END_BL_METH_MAP()

BEGIN_EMPTY_BL_PROP_MAP(CCLRFactory)

IMPLEMENT_MY_CREATE_CONTEXT(CCLRFactory, "CLRFactory", "CLR‘абрика")

CCLRFactory::CCLRFactory(void)
{
}

CCLRFactory::~CCLRFactory(void)
{
}

int CCLRFactory::fNewObject(int nParamsCount, CValue &RetVal, CValue **ppValue)
{
	RetVal.AssignContext(new CCLRContext(nParamsCount,ppValue));
	RetVal.m_Context->DecrRef();
	return TRUE;
}
int CCLRFactory::pCreateControl(CValue &RetVal,CValue **ppValue)
{
	CValue* val = ppValue[0];
	if(val->type=100)
	{
		if(!strcmp(val->m_Context->GetRuntimeClass()->m_lpszClassName,"CFormCtrlContext"))
		{
			CGetField* gf = ((CFormCtrlContext*)val->m_Context)->m_pGetField;
			RetVal.AssignContext(new CCLRContext(gf,ppValue[1]->m_String));
			RetVal.m_Context->DecrRef();
		}
	}
	return TRUE;
}