#pragma once
#include "mycontextbase.h"

class CCLRFactory :	public CMyContextBase
{
	DECLARE_DYNCREATE(CCLRFactory);
public:
	CCLRFactory(void);
	~CCLRFactory(void);
	int fNewObject(int nParamsCount, CValue &RetVal, CValue **ppValue);
	int pCreateControl(CValue &RetVal, CValue **ppValue);

	DECLARE_MY_CONTEXT();
};
