#include "StdAfx.h"
#pragma managed
#include "CLRWrapper.h"
#include "StringConvertor.h"
using namespace System;
using namespace System::Threading;
using namespace System::Reflection;
using namespace System::Reflection::Emit;
using namespace System::Windows::Forms;

CBkEndUI*		pBkEndUI;

int CCLRWrapper::MethodComparer(MethodInfo^ meth1,MethodInfo^ meth2)
{
	int result=Globals::sc->Compare(meth1->Name,meth2->Name);
	if(result!=0) return result;
	result = meth1->GetParameters()->Length - meth2->GetParameters()->Length;
	if(result!=0) return result;
	return meth1->GetHashCode()-meth2->GetHashCode();
}

void CCLRWrapper::Init(Type^ t)
{
	propertiesArray^ properties = t->GetProperties();
	methodsArray^ methods = t->GetMethods();
	Array::Sort(methods,gcnew Comparison<MethodInfo^>(MethodComparer));
	std::string propName;
	for(int i=0;i<properties->Length;i++)
	{
		propName = (char*)(Marshal::StringToHGlobalAnsi(properties[i]->Name)).ToPointer();
		propNamesMap.insert(std::make_pair(propName,i));
	}
	std::string methName;
	methNamesMap_t::const_iterator p;
	int methNum=0;
	for(int i=0;i<methods->Length;i++)
	{
		MethodInfo^ mi=methods[i];
		if((mi->Attributes & MethodAttributes::SpecialName)!=MethodAttributes()) continue;
		methName = (char*)(Marshal::StringToHGlobalAnsi(mi->Name)).ToPointer();
		p=methNamesMap.find(methName);
		if(p!=methNamesMap.end())
		{
			char num=2;
			methName+='2';
			while(p!=methNamesMap.end()){
				methName[methName.length()-1]='0'+num;
				num++;
				p=methNamesMap.find(methName);
			}
		}
		methNamesMap.insert(std::make_pair(methName,methNum));

		methInfoPtr methodInfo=new MethInfo();
		methodInfo->retType=mi->ReturnType;
		array<ParameterInfo^>^ paramInfoArray = mi->GetParameters();
		methodInfo->paramTypes = gcnew paramTypesArray(paramInfoArray->Length);
		for(int i=0;i<paramInfoArray->Length;i++)
			methodInfo->paramTypes[i]=paramInfoArray[i]->ParameterType;
		methodInfo->numParams=paramInfoArray->Length;
		methodInfo->reflectionMethodInfo=mi;
		methInfoMap.insert(std::make_pair(methNum,methodInfo));
		methNum++;
	}
}

PropInfo::~PropInfo()
{
	if(static_cast<FastGetAccessorHandler^>(clrGetAccessor)!=nullptr) delete clrGetAccessor;
	if(static_cast<FastSetAccessorHandler^>(clrSetAccessor)!=nullptr) delete clrSetAccessor;
	if(static_cast<Type^>(propType)!=nullptr) delete propType;
}

MethInfo::~MethInfo()
{
	if(static_cast<FastInvokeHandler^>(clrInvokeHandler)!=nullptr) delete clrInvokeHandler;
	if(static_cast<MethodInfo^>(reflectionMethodInfo)!=nullptr) delete reflectionMethodInfo;
	if(static_cast<paramTypesArray^>(paramTypes)!=nullptr)
		for(int i=0;i<paramTypes->Length;i++)
			delete paramTypes[i];
	if(static_cast<Type^>(retType)!=nullptr) delete retType;
}

CCLRWrapper::CCLRWrapper(Object^ pObj)
{
	pClrObj=pObj;
	Init(pClrObj->GetType());
}

CCLRWrapper::CCLRWrapper(char const * szClassName)
{
	try
	{
		String^ s = gcnew String(szClassName,0,strlen(szClassName),System::Text::Encoding::ASCII);
		Type^ t = Type::GetType(s);
		if(t==nullptr)
			CBLModule::RaiseExtRuntimeError ("Класс не найден", mmRedErr);
		if(!t->IsAbstract)
			try
			{
				pClrObj = Activator::CreateInstance(t);
			}
			catch (System::MissingMethodException^ e){
				pClrObj=nullptr;
			}
		else
			pClrObj = nullptr;
		Init(t);
	}
	catch (System::Exception^ e){
		StringUtilities::StringConvertor sc(e->ToString());
		CBLModule::RaiseExtRuntimeError (sc.NativeCharPtr, mmRedErr);
	}
}

CCLRWrapper::CCLRWrapper(int nParamsCount,	CValue** ppValue)
{
	try
	{
		CString s=ppValue[0]->m_String;
		String^ className=gcnew String(s,0,s.GetLength(),System::Text::Encoding::ASCII);
		Type^ t = Type::GetType(className);
		if(t==nullptr)
			CBLModule::RaiseExtRuntimeError ("Класс не найден", mmRedErr);
		/*if((nParamsCount==2) && (ppValue[1]->type=100))
		{
			CValue* val=ppValue[1];
			if(val->m_Context->GetRuntimeClass() == RUNTIME_CLASS(CCLRContext))
			{
				Object^ param=((CCLRContext*)val->m_Context)->clrwrapper->pClrObj;
				Type^ paramType=param->GetType();
				if((paramType->Equals(Object::typeid->MakeArrayType())))
				{
					pClrObj=Activator::CreateInstance(t,param);
					Init(pClrObj->GetType());
					return;
				}
			}
		}/**/
		array<Object^>^ paramValues = gcnew array<Object^>(nParamsCount-1);
		for(int i=0;i<nParamsCount-1;i++){
			CValue* val=ppValue[i+1];
			switch(val->type)
			{
			case 1: paramValues[i]=(Int32)val->m_Number; break;
			case 2: paramValues[i]=gcnew String(val->m_String); break;
			case 100:
				if(val->m_Context->GetRuntimeClass() == RUNTIME_CLASS(CCLRContext))
				{
					paramValues[i]=((CCLRContext*)val->m_Context)->clrwrapper->pClrObj;
				}
			}
		}
		if(!t->IsAbstract)
		{
			try
			{
				pClrObj=Activator::CreateInstance(t,paramValues);
			}
			catch (System::MissingMethodException^ e){
				pClrObj=nullptr;
			}
		}else
			pClrObj = nullptr;
		Init(t);
	}
	catch (System::Exception^ e){
		StringUtilities::StringConvertor sc(e->ToString());
		CBLModule::RaiseExtRuntimeError (sc.NativeCharPtr, mmRedErr);
	}
}

CCLRWrapper::CCLRWrapper(CGetField* getField, const char* className)
{
	String^ s = gcnew String(className);
	Type^ t = Type::GetType(s);
	if(t==nullptr)
		CBLModule::RaiseExtRuntimeError ("Класс не найден", mmRedErr);
 	if(!t->IsSubclassOf(Control::typeid))
 		CBLModule::RaiseExtRuntimeError ("Класс не является наследником Windows.Forms.Control", mmRedErr);
	Control^ c = static_cast<Control^>(Activator::CreateInstance(t));
	CWnd* w= getField->m_GetDoc->GetFieldWnd(getField);
	CWnd* pw = w->GetParent();
	CRect r;
	w->GetWindowRect(r);
	int id=w->GetDlgCtrlID();
	pw->ScreenToClient(r);
	//w->Detach();
	//CWnd* childw = new CWnd();
	DWORD dwStyle = WS_CHILD | (getField->GetCtrlInfo()->m_CtrlType!=1 ? WS_TABSTOP : 0);
	//if (getField->m_Visible)
		dwStyle |= WS_VISIBLE;
	if (getField->GetReadOnly())
		dwStyle |= WS_DISABLED;
	((NativeWindow^)c->WindowTarget)->AssignHandle(IntPtr(w->m_hWnd));
	//w->Attach((HWND)c->Handle.ToPointer());
	c->Top=r.top;
	c->Left=r.left;
	//c->CreateHandle();
	c->Refresh();
	pClrObj = c;
	Init(t); 
}

CCLRWrapper::~CCLRWrapper(void)
{
 	if(static_cast<EventManager^>(eventManager)!=nullptr)
 		delete eventManager;
	if(pClrObj)
	{
		if(pClrObj->GetType()->IsSubclassOf(Control::typeid))
		{
			Control^ c = static_cast<Control^>((Object^)pClrObj);
			((NativeWindow^)c->WindowTarget)->DestroyHandle();
		}
		delete pClrObj;
	}
	for(propInfoMap_t::iterator i=propInfoMap.begin();i!=propInfoMap.end();i++)
	{
		delete i->second;
	}
	for(methInfoMap_t::iterator i=methInfoMap.begin();i!=methInfoMap.end();i++)
	{
		delete i->second;
	}
}

propInfoPtr CCLRWrapper::GetPropInfo(int propNum)
{
	propInfoMap_t::const_iterator piPair=propInfoMap.find(propNum);
	if(piPair==propInfoMap.end())
	{
		propInfoPtr pi=new PropInfo();
		try
		{
			PropertyInfo^ p=pClrObj->GetType()->GetProperties()[propNum];
			pi->clrGetAccessor = CFastInvoker::GetGetAccessorInvoker(p);
			pi->clrSetAccessor = CFastInvoker::GetSetAccessorInvoker(p);
			pi->propType=p->PropertyType;
			propInfoMap.insert(std::pair<int,propInfoPtr>(propNum,pi));
		}
		catch (System::Exception^ e){
			delete pi;
			StringUtilities::StringConvertor sc(e->ToString());
			CBLModule::RaiseExtRuntimeError (sc.NativeCharPtr, mmRedErr);
		}
		return pi;
	}else{
		return piPair->second;
	}
}

void CCLRWrapper::ObjectToValue(Object^ obj, Type^ t,CValue& retVal)
{
	if(t==Int32::typeid) retVal=CNumeric((int)static_cast<Int32>(obj));
	else if(t==Int16::typeid) retVal=CNumeric((int)static_cast<Int16>(obj));
	else if(t==Int64::typeid) retVal=CNumeric((double)static_cast<Int64>(obj));
	else if(t==UInt16::typeid) retVal=CNumeric((int)static_cast<UInt16>(obj));
	else if(t==UInt32::typeid) retVal=CNumeric((int)static_cast<UInt32>(obj));
	else if(t==UInt64::typeid) retVal=CNumeric((double)static_cast<UInt64>(obj));
	else if((t==Double::typeid) || (t==Single::typeid))
	{
		retVal.type=1;
		retVal.m_Number=(double)obj;
	}else if(t==String::typeid)
	{
		retVal = CValue((char*)(Marshal::StringToHGlobalAnsi(static_cast<String^>(obj))).ToPointer());
	}else if(t==Boolean::typeid)
	{
		retVal.type=1;
		retVal.m_Number=static_cast<Boolean>(obj) ? 1 : 0;
	}else if(t==void::typeid)
	{
	}else if(t==DateTime::typeid)
	{
		retVal.type=3;
		retVal.m_Date=CDate(static_cast<DateTime>(obj).Year,static_cast<DateTime>(obj).Month,static_cast<DateTime>(obj).Day);
	}else if(!t->IsValueType)
	{
		CCLRWrapper* w=new CCLRWrapper(obj);
		retVal.AssignContext(new CCLRContext(w));
		retVal.m_Context->DecrRef();
	}else{
		retVal = CValue((char*)(Marshal::StringToHGlobalAnsi(obj->ToString())).ToPointer());
	}
}

void CCLRWrapper::ValueToObject(const CValue &val, Object^% obj, Type^ t)
{
	
	if(t==Int32::typeid) obj=(Int32)(int)val.m_Number;
	else if(t==Boolean::typeid)	obj= val.m_Number!=0 ? true : false;
	else if(t==String::typeid) obj=gcnew String(val.m_String);
	else if(val.type==100)
	{
		if(val.m_Context->GetRuntimeClass() == RUNTIME_CLASS(CCLRContext))
		{
			obj=((CCLRContext*)val.m_Context)->clrwrapper->pClrObj;
		}
	}
	else if(t==DateTime::typeid) obj=gcnew DateTime(val.m_Date.GetYear(),val.m_Date.GetMonth(),val.m_Date.GetMonthDay());
	else if(t==Int16::typeid) obj=(Int16)(int)val.m_Number;
	else if(t==Int64::typeid) obj=(Int64)(double)val.m_Number;
	else if(t==Double::typeid) obj=(Double)(double)val.m_Number;
	else if(t==SByte::typeid) obj=(SByte)(int)val.m_Number;
	else if(t==Single::typeid) obj=(Single)(double)val.m_Number;
	else if(t==UInt16::typeid) obj=(UInt16)(int)val.m_Number;
	else if(t==UInt32::typeid) obj=(UInt32)(int)val.m_Number;
	else if(t==UInt64::typeid) obj=(UInt64)(double)val.m_Number;
	else if(t->IsEnum)
		if(val.type==2)
		{
			obj=Enum::Parse(t,gcnew String(val.m_String));
		}
}

EventManager::EventManager(CCLRWrapper* w, Object^ sender, CBLContext* cont, String^ prefix)
{
	source=sender;
	context = cont;
	wrapper = w;
	//System::Threading::Thread::CurrentThread->Name="Main thread";
	//callProcDelegate = Marshal::GetDelegateForFunctionPointer((IntPtr)&CBLContext::CallAsProc,CallAsProcDelegate::typeid);
	array<EventInfo^>^ events=source->GetType()->GetEvents();
	int eventNum=0;
	callProcDelegate = (CallAsProcDelegate^)Delegate::CreateDelegate(CallAsProcDelegate::typeid,this,GetType()->GetMethod("InvokeBLProc"));
	CreateHandle();
	for each(EventInfo^ ei in events)
	{
		char* eventName = (char*)Marshal::StringToHGlobalAnsi(static_cast<String^>(prefix+ei->Name)).ToPointer();
		int r=context->FindMethod(eventName);
		if(r>=0)
		{
			MethodInfo^ invokeMethodInfo=ei->EventHandlerType->GetMethod("Invoke");
			Type^ delegateReturnType = invokeMethodInfo->ReturnParameter->ParameterType;
			array<ParameterInfo^>^ ps = invokeMethodInfo->GetParameters();
			array<Type^>^ paramTypes = gcnew array<Type^>(ps->Length+1);
			paramTypes[0]=EventManager::typeid;
			for (int i = 0; i < ps->Length; i++)
				paramTypes[i+1]=ps[i]->ParameterType;
			DynamicMethod^ dm = gcnew DynamicMethod(String::Empty,delegateReturnType,paramTypes,EventManager::typeid->Module);
			dm->InitLocals=false;
			ILGenerator^ il = dm->GetILGenerator();
			LocalBuilder^ lb= il->DeclareLocal(ObjectArray::typeid);
			CFastInvoker::EmitFastInt(il,ps->Length);
			il->Emit(OpCodes::Newarr,Object::typeid);
			il->Emit(OpCodes::Stloc,lb);
			for (int i = 0; i < ps->Length; i++)
			{
				il->Emit(OpCodes::Ldloc, lb);
				CFastInvoker::EmitFastInt(il,i);
				il->Emit(OpCodes::Ldarg, i+1);
				il->Emit(OpCodes::Stelem_Ref);
			}
			il->Emit(OpCodes::Ldarg_0);
			il->Emit(OpCodes::Ldloc,lb);
			CFastInvoker::EmitFastInt(il,r);
			il->EmitCall(OpCodes::Call,EventManager::typeid->GetMethod("HandleEvent"),nullptr);
			il->Emit(OpCodes::Ret);
			Delegate^ d = dm->CreateDelegate(ei->EventHandlerType,this);
			ei->AddEventHandler(source,d);
		}
	}
}

void EventManager::HandleEvent(ObjectArray^ args, Int32 v7ProcNum)
{
	try
	{
		this->Invoke(callProcDelegate, gcnew ObjectArray(2){args,v7ProcNum});
	}
	catch(Exception^ e)
	{
		//CBLModule::RaiseExtRuntimeError ((char*)Marshal::StringToHGlobalAnsi(static_cast<String^>(e->ToString())).ToPointer(), mmRedErr);
	}
}

void EventManager::InvokeBLProc(ObjectArray^ args, Int32 v7ProcNum)
{
	//CValue p1, p2, p3, p4, p5, p6, p7, p8, p9, p10;
	//CValue *pArray[10]={&p1, &p2, &p3, &p4, &p5, &p6, &p7, &p8, &p9, &p10};
	CValue **paramArr = (CValue**)calloc(args->Length,sizeof(CValue*));
	for(int i=0; i<args->Length ; i++)
	{
		paramArr[i]=new CValue();
		CCLRWrapper::ObjectToValue(args[i],args[i]->GetType(),*paramArr[i]);
	}
	context->CallAsProc(v7ProcNum,paramArr);
	//System::Windows::Forms::MessageBox::Show(System::Threading::Thread::CurrentThread->ThreadState.ToString());
	//CWinApp* maint = AfxGetApp();
	//if(maint->)
	free(paramArr);
}

int  CCLRWrapper::CallAsFunc(int iMethNum,CValue& rValue,CValue **ppValue)
{
	try
	{
		if(iMethNum==methInfoMap.size())
		{
			CValue* val = ppValue[0];
			String^ prefix = gcnew String(ppValue[1]->m_String);
			if(val->type==100)
			{
 				eventManager = gcnew EventManager(this,pClrObj,val->m_Context,prefix);
			}
			return TRUE;
		}
		methInfoPtr mi=methInfoMap[iMethNum];
		if(static_cast<FastInvokeHandler^>(mi->clrInvokeHandler)==nullptr)
			mi->clrInvokeHandler=CFastInvoker::GetMethodInvoker(mi->reflectionMethodInfo);
		array<Object^>^ paramValues = gcnew array<Object^>(mi->numParams);
		array<ParameterInfo^>^ paramInfoArray = mi->reflectionMethodInfo->GetParameters();
		for(int i=0;i<mi->numParams;i++){
			ValueToObject(*ppValue[i],paramValues[i],mi->paramTypes[i]);
		}
		Object^% ref = (Object^)pClrObj;//boxing?
		Object^ rv = mi->clrInvokeHandler->Invoke(ref,paramValues);
		//ref = (Object^)pClrObj;
		ObjectToValue(rv,mi->retType,rValue);
	}
	catch (System::Exception^ e){
		StringUtilities::StringConvertor sc(e->ToString());
		CBLModule::RaiseExtRuntimeError (sc.NativeCharPtr, mmRedErr);
	}
	return TRUE;
}
int  CCLRWrapper::CallAsProc(int iMethNum,CValue **ppValue)
{
	CValue v;
	return CallAsFunc(iMethNum,v,ppValue);
}

int  CCLRWrapper::FindMethod(char const * lpMethodName)const
{
	if(!strcmp(lpMethodName,"ПривязатьСобытияККонтексту"))
		return methNamesMap.size();
	methNamesMap_t::const_iterator p=methNamesMap.find(lpMethodName);
	if(p==methNamesMap.end())
		return -1;
	return p->second;
}

char const*  CCLRWrapper::GetMethodName(int methNum)const
{
	methNamesMap_t::const_iterator p;
	for(p=methNamesMap.begin(); p!=methNamesMap.end(); p++)
		if(p->second==methNum)
			return p->first.c_str();
}

int  CCLRWrapper::GetNMethods(void)const
{
	return methInfoMap.size()+1;
}

int  CCLRWrapper::GetNParams(int methNum)
{
	if(methNum==methInfoMap.size())
		return 2;
	return methInfoMap[methNum]->numParams;
}

int  CCLRWrapper::GetParamDefValue(int iMethodNum,int iParamNum,CValue *pDefValue)const
{
	return TRUE;
}

int  CCLRWrapper::HasRetVal(int methNum)
{
	if(methNum==methInfoMap.size())
		return FALSE;
	return static_cast<Type^>(methInfoMap[methNum]->retType)!=void::typeid;
}

int  CCLRWrapper::FindProp(char const * propName)const
{
	propNamesMap_t::const_iterator p=propNamesMap.find(propName);
	if(p==propNamesMap.end())
		return -1;
	return p->second;
}

int  CCLRWrapper::GetNProps(void)const
{
	return propNamesMap.size();
}

char const* CCLRWrapper::GetPropName(int propNum)const
{
	propNamesMap_t::const_iterator p;
	for(p=propNamesMap.begin(); p!=propNamesMap.end(); p++)
		if(p->second==propNum)
			return p->first.c_str();
}

int  CCLRWrapper::GetPropVal(int propNum,CValue& retVal)
{
	try
	{
		PropInfo* pi=GetPropInfo(propNum);
		Object^% ref = (Object^)pClrObj;
		Object^ val = pi->clrGetAccessor->Invoke(ref);
		ObjectToValue(val,pi->propType,retVal);
	}
	catch (System::Exception^ e){
		StringUtilities::StringConvertor sc(e->ToString());
		CBLModule::RaiseExtRuntimeError (sc.NativeCharPtr, mmRedErr);
	}
	return TRUE;
}

int  CCLRWrapper::SetPropVal(int iPropNum,CValue const &vValue)
{
	PropInfo* pi=GetPropInfo(iPropNum);
	try
	{
		Object^ val;
		ValueToObject(vValue,val,pi->propType);
		Object^% ref = (Object^)pClrObj;
		pi->clrSetAccessor->Invoke(ref,val);
		//pClrObj=ref;
	}
	catch (System::Exception^ e){
		StringUtilities::StringConvertor sc(e->ToString());
		CBLModule::RaiseExtRuntimeError (sc.NativeCharPtr, mmRedErr);
	}
	return TRUE;
}

char const* CCLRWrapper::GetTypeString(void)const
{
	return (char*)(Marshal::StringToHGlobalAnsi(pClrObj->GetType()->FullName)).ToPointer();;
}

int  CCLRWrapper::IsExactValue(void)const
{
	return TRUE;
}

int  CCLRWrapper::IsOleContext(void)const
{
	return FALSE;
}

int  CCLRWrapper::IsPropReadable(int iPropNum)
{
	return static_cast<FastGetAccessorHandler^>(GetPropInfo(iPropNum)->clrGetAccessor)==nullptr ? FALSE : TRUE ;
}

int  CCLRWrapper::IsPropWritable(int iPropNum)
{
	return static_cast<FastSetAccessorHandler^>(GetPropInfo(iPropNum)->clrSetAccessor)==nullptr ? FALSE : TRUE ;
}

int  CCLRWrapper::IsSerializable(void)
{
	return TRUE;
}

int  CCLRWrapper::SaveToString(CString &str)
{
	std::string s = (char*)(Marshal::StringToHGlobalAnsi(pClrObj->ToString())).ToPointer();
	str = s.c_str();
	return TRUE;
}

/*CCLRContext* CCLRWrapper::SpawnInstance(int nParamsCount, CValue **ppValue)
{
	return nullptr;
}/**/

