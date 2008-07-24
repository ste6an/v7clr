// v7CLR.cpp : Defines the initialization routines for the DLL.
//
#include "stdafx.h"
#include <afxdllx.h>
#include "CLRActivator.h"
#include "CLRFactory.h"

#ifdef _MANAGED
//#error Please read instructions in v7CLR.cpp to compile with /clr
// If you want to add /clr to your project you must do the following:
//	1. Remove the above include for afxdllx.h
//	2. Add a .cpp file to your project that does not have /clr thrown and has
//	   Precompiled headers disabled, with the following text:
//			#include <afxwin.h>
//			#include <afxdllx.h>
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static AFX_EXTENSION_MODULE v7CLRDLL = { NULL, NULL };

//extern "C" int APIENTRY
int DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	// Remove this if you use lpReserved
	UNREFERENCED_PARAMETER(lpReserved);

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		TRACE0("v7CLR.DLL Initializing!\n");
		
		// Extension DLL one-time initialization
		//if (!AfxInitExtensionModule(v7CLRDLL, hInstance))
			//return 0;

		// Insert this DLL into the resource chain
		// NOTE: If this Extension DLL is being implicitly linked to by
		//  an MFC Regular DLL (such as an ActiveX Control)
		//  instead of an MFC application, then you will want to
		//  remove this line from DllMain and put it in a separate
		//  function exported from this Extension DLL.  The Regular DLL
		//  that uses this Extension DLL should then explicitly call that
		//  function to initialize this Extension DLL.  Otherwise,
		//  the CDynLinkLibrary object will not be attached to the
		//  Regular DLL's resource chain, and serious problems will
		//  result.

		//new CDynLinkLibrary(v7CLRDLL);
		
		CCLRActivator::TheObject().Init();
		pBkEndUI=GetBkEndUI();
		CMyContextBase::InitContextClass(CCLRFactory::m_myCtxBaseInfo);
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		TRACE0("v7CLR.DLL Terminating!\n");

		// Terminate the library before destructors are called
		CCLRActivator::TheObject().Destroy();
		CMyContextBase::DoneContextClass(CCLRFactory::m_myCtxBaseInfo);
		//AfxTermExtensionModule(v7CLRDLL);
	}
	return 1;   // ok
}

//#pragma managed

