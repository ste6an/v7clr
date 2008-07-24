//#include <vcclr.h>
#pragma unmanaged
#include "StdAfx.h"
#include "CLRActivator.h"
#include "CLRContext.h"

HANDLE hProcess;

CCLRActivator& CCLRActivator::TheObject(void)
{
	static CCLRActivator* object;
	if(!object)
		object = new CCLRActivator();
	return *object;
}

void CCLRActivator::Init(void)
{
	hProcess=GetCurrentProcess();
	m_wrapperCreateInstance.DoWrap(::GetModuleHandle((LPCTSTR)"bkend.dll"), "?CreateInstance@CBLContext@@SAPAV1@PBD@Z", 
		(PF_CreateInstance)CCLRActivator::CreateInstance);
}

void CCLRActivator::Destroy()
{
	//m_wrapperCreateInstance.RestoreOrigAddress();
}
CCLRActivator::~CCLRActivator()
{
	m_wrapperCreateInstance.RestoreOrigAddress();
}

//#pragma managed
CBLContext* CCLRActivator::CreateInstance(char const * szClassName)
{
		CDllMethodWrapperGuard<PF_CreateInstance> wrapper(TheObject().m_wrapperCreateInstance);
		CBLContext* ret;
		if(szClassName[0]=='!')
			ret = new CCLRContext(szClassName+1);
		else
			ret = wrapper.GetOrigMethod()(szClassName);
		//Wrapper().RestoreWrapAddress();
		return ret; // восстановление адреса перехватчика произойдет автоматически !!
}
