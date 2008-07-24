#pragma once
#include "MethodsWrapper.h"


typedef CBLContext* (*PF_CreateInstance)(char const *);

class CCLRActivator
{
private:
	CDllMethodWrapper<PF_CreateInstance> m_wrapperCreateInstance;
	static CBLContext* CreateInstance(char const * szClassName);
public:
	static CCLRActivator& TheObject(void);
	CCLRActivator(){};
	CCLRActivator(CCLRActivator&){};
	~CCLRActivator();
public:
	void Init(void);
	void Destroy(void);
};
