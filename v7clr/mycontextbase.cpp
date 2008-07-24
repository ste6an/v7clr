// mycontextbase.cpp
#include "stdafx.h"
#include "mycontextbase.h"

void CMyContextBase::InitContextClass(_S_MyContextBaseInfo* pInfo)
{
	if(pInfo)
	{
		if(pInfo->methCount)
		{
			pInfo->pMethMap=new CBLMap;
			const _S_MethDef* pDef=pInfo->pMethodDef;
			for(int i=0;i<pInfo->methCount;)
			{
				pInfo->pMethMap->InsertKey(pDef->Names[0],i);
				pInfo->pMethMap->InsertKey(pDef->Names[1],i++);
				pDef++;
			}
			pInfo->pMethMap->Optimize();
		}

		if(pInfo->propCount)
		{
			pInfo->pPropMap=new CBLMap;
			const _S_PropDef* pProp=pInfo->pPropDef;
			for(int i=0;i<pInfo->propCount;)
			{
				pInfo->pPropMap->InsertKey(pProp->Names[0],i);
				pInfo->pPropMap->InsertKey(pProp->Names[1],i++);
				pProp++;
			}
			pInfo->pPropMap->Optimize();
		}

		if (pInfo->RegToCreate)
		{
			CBLContext::RegisterContextClass((CRuntimeClass*)pInfo->pRTC,pInfo->EngTypeString,CType(100));
			CBLContext::RegisterContextClass((CRuntimeClass*)pInfo->pRTC,pInfo->RusTypeString,CType(100));
		}

		if(pInfo->pInitFunc)
			pInfo->pInitFunc();
	}
}

void CMyContextBase::DoneContextClass(_S_MyContextBaseInfo* pInfo)
{
	if(pInfo)
	{
		if(pInfo->pDoneFunc)
			pInfo->pDoneFunc();
		if(pInfo->RegToCreate)
			CBLContext::UnRegisterContextClass((CRuntimeClass*)pInfo->pRTC);
		delete pInfo->pMethMap;
		delete pInfo->pPropMap;
	}
}

CMyContextBase::CMyContextBase()
{
}

CMyContextBase::~CMyContextBase()
{
}

int CMyContextBase::CallAsFunc(int iMethNum,CValue& rValue,CValue **ppValue)
{
	_S_MyContextBaseInfo* pInfo=GetBaseInfo();
	if(((DWORD)iMethNum)>=pInfo->methCount)
		return FALSE;
	
	const _S_MethDef& MethDef = pInfo->pMethodDef[iMethNum];
	if (MethDef.bIsUnLimParMethod)
	{
		return (this->*pInfo->pMethodDef[iMethNum].pDoFuncWithUnLimParams)(pInfo->m_CountParametersInCallMethod, rValue, ppValue);
	}

	return (this->*pInfo->pMethodDef[iMethNum].pDoFunc)(rValue,ppValue);
}

int CMyContextBase::CallAsProc(int iMethNum,CValue **ppValue)
{
	_S_MyContextBaseInfo* pInfo=GetBaseInfo();
	if(((DWORD)iMethNum)>=pInfo->methCount)
		return FALSE;
	
	const _S_MethDef& MethDef = pInfo->pMethodDef[iMethNum];
	if (MethDef.bIsUnLimParMethod)
	{
		return (this->*pInfo->pMethodDef[iMethNum].pDoProcWithUnLimParams)(pInfo->m_CountParametersInCallMethod, ppValue);
	}

	return (this->*pInfo->pMethodDef[iMethNum].pDoProc)(ppValue);
}


int CMyContextBase::FindMethod(char const * lpMethodName)const
{
    _S_MyContextBaseInfo* pInfo = GetBaseInfo();
    if (pInfo->methCount)
	    return (int)pInfo->pMethMap->GetKey(lpMethodName);
    else
        return -1;
}

char const* CMyContextBase::GetMethodName(int iMethNum,int iMethodAlias)const
{
	_S_MyContextBaseInfo* pInfo=GetBaseInfo();
	if(((DWORD)iMethNum)>=pInfo->methCount || ((DWORD)iMethodAlias)>1)
		return NULL;
	return GetBaseInfo()->pMethodDef[iMethNum].Names[iMethodAlias];
}

int CMyContextBase::GetNMethods(void)const
{
	return GetBaseInfo()->methCount;
}

int CMyContextBase::HasRetVal(int iMethodNum)const
{
	_S_MyContextBaseInfo* pInfo=GetBaseInfo();
	if(((DWORD)iMethodNum)>=pInfo->methCount)
		return 0;
	
	const _S_MethDef& MethDef = pInfo->pMethodDef[iMethodNum];
	if (MethDef.bIsUnLimParMethod)
	{
		return MethDef.pDoFuncWithUnLimParams != NULL;;
	}

	//return pInfo->pMethodDef[iMethodNum].pDoFunc != NULL;
	return MethDef.pDoFunc != NULL;
}

int CMyContextBase::GetNParams(int iMethodNum)const
{
	_S_MyContextBaseInfo* pInfo=GetBaseInfo();
	if(((DWORD)iMethodNum)>=pInfo->methCount)
		return 0;
	
	const _S_MethDef& MethDef = pInfo->pMethodDef[iMethodNum];
	if (MethDef.bIsUnLimParMethod)
	{
		// ���� �������� ������ ����������, ��� ������ ���� �� ���������,
		// 1� ������ ������ ����������� ������ � ���������� ����������
 		return pInfo->m_CountParametersInCallMethod <= MethDef.NumberOfParam ? 
 			MethDef.NumberOfParam : pInfo->m_CountParametersInCallMethod;
		//return min(pInfo->m_CountParametersInCallMethod, MethDef.NumberOfParam);
	}

	//return pInfo->pMethodDef[iMethodNum].NumberOfParam;
	return MethDef.NumberOfParam;
}

int CMyContextBase::GetParamDefValue(int iMethodNum,int iParamNum,CValue *pDefValue)const
{
	_S_MyContextBaseInfo* pInfo=GetBaseInfo();
	if(((DWORD)iMethodNum)>=pInfo->methCount || ((DWORD)iParamNum)>=pInfo->pMethodDef[iMethodNum].NumberOfParam)
		return FALSE;
	PF_GET_PARAM_DEF pFunc=pInfo->pMethodDef[iMethodNum].pDefValProc;
	if(pFunc)
		return (this->*pFunc)(iParamNum,pDefValue);
	return FALSE;
}

int CMyContextBase::GetDestroyUnRefd(void)const
{
	return TRUE;
}

char const*  CMyContextBase::GetTypeString(void)const
{
	if (GetMetaData()->GetTaskDef()->GetDefaultLanguage() == 0)
		return GetBaseInfo()->EngTypeString;
	else
		return GetBaseInfo()->RusTypeString;
}

int CMyContextBase::IsExactValue(void)const
{
	return TRUE;
}

int CMyContextBase::IsOleContext(void)const
{
// artbear
  int regEBX = 0;
  __asm {
    mov regEBX, ebx // � ���� �������� 1� ������ ���������� ���������� ��� ������ ������
  }
  GetBaseInfo()->m_CountParametersInCallMethod = regEBX; // �������� ��� ��������
// end

	return FALSE;
}

int CMyContextBase::IsPropReadable(int iPropNum)const
{
	return TRUE;
}

int CMyContextBase::IsPropWritable(int iPropNum)const
{
	_S_MyContextBaseInfo* pInfo=GetBaseInfo();
	if(((DWORD)iPropNum)>=pInfo->propCount)
		return 0;
	return pInfo->pPropDef[iPropNum].pSetProp!=NULL;
}

int CMyContextBase::IsSerializable(void)
{
	return FALSE;
}

int CMyContextBase::SaveToString(CString &csStr)
{	
	return FALSE;
}

int CMyContextBase::GetNProps(void)const
{
	return GetBaseInfo()->propCount;
}

char const* CMyContextBase::GetPropName(int iPropNum, int iAlias)const
{	
	_S_MyContextBaseInfo* pInfo=GetBaseInfo();
	if(((DWORD)iPropNum)>=pInfo->propCount || ((DWORD)iAlias)>1)
		return 0;
	return pInfo->pPropDef[iPropNum].Names[iAlias];
}

int CMyContextBase::GetPropVal(int iPropNum,CValue &rValue)const
{
	_S_MyContextBaseInfo* pInfo=GetBaseInfo();
	if(((DWORD)iPropNum)>=pInfo->propCount)
		return 0;
	return (this->*pInfo->pPropDef[iPropNum].pGetProp)(rValue);
}

int CMyContextBase::SetPropVal(int iPropNum,CValue const &vValue)
{
	_S_MyContextBaseInfo* pInfo=GetBaseInfo();
	if(((DWORD)iPropNum)>=pInfo->propCount)
		return 0;
	return (this->*pInfo->pPropDef[iPropNum].pSetProp)(vValue);
}

int  CMyContextBase::FindProp(char const * Name)const
{
    _S_MyContextBaseInfo* pInfo = GetBaseInfo();
    if (pInfo->propCount)
	    return (int)pInfo->pPropMap->GetKey(Name);
    else
        return -1;
}