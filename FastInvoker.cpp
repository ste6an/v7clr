#include "FastInvoker.h"

void CFastInvoker::EmitCastToReference(ILGenerator^ il, Type^ type)
{
	if (type->IsValueType)
	{
		il->Emit(OpCodes::Unbox_Any, type);
	}
	else
	{
		il->Emit(OpCodes::Castclass, type);
	}
}

void CFastInvoker::EmitBoxIfNeeded(ILGenerator^ il, Type^ type)
{
	if (type->IsValueType)
	{
		il->Emit(OpCodes::Box, type);
	}
}

void CFastInvoker::EmitUnboxIfNeeded(ILGenerator^ il, Type^ type)
{
	if (type->IsValueType)
	{
		il->Emit(OpCodes::Unbox_Any, type);
	}
}

void CFastInvoker::EmitFastInt(ILGenerator^ il, int value)
{
	switch (value)
	{
	case -1:
		il->Emit(OpCodes::Ldc_I4_M1);
		return;
	case 0:
		il->Emit(OpCodes::Ldc_I4_0);
		return;
	case 1:
		il->Emit(OpCodes::Ldc_I4_1);
		return;
	case 2:
		il->Emit(OpCodes::Ldc_I4_2);
		return;
	case 3:
		il->Emit(OpCodes::Ldc_I4_3);
		return;
	case 4:
		il->Emit(OpCodes::Ldc_I4_4);
		return;
	case 5:
		il->Emit(OpCodes::Ldc_I4_5);
		return;
	case 6:
		il->Emit(OpCodes::Ldc_I4_6);
		return;
	case 7:
		il->Emit(OpCodes::Ldc_I4_7);
		return;
	case 8:
		il->Emit(OpCodes::Ldc_I4_8);
		return;
	}

	if (value > -129 && value < 128)
	{
		il->Emit(OpCodes::Ldc_I4_S, (SByte)value);
	}
	else
	{
		il->Emit(OpCodes::Ldc_I4, value);
	}
}

FastInvokeHandler^ CFastInvoker::GetMethodInvoker(MethodInfo^ methodInfo)
{
	array<Type^>^ tmpArr = { Object::typeid->MakeByRefType(), Object::typeid };
	DynamicMethod^ dynamicMethod = gcnew DynamicMethod(String::Empty, Object::typeid, tmpArr, methodInfo->DeclaringType->Module);
	ILGenerator^ il = dynamicMethod->GetILGenerator();
	array<ParameterInfo^>^ ps = methodInfo->GetParameters();
	array<Type^>^ paramTypes = gcnew array<Type^>(ps->Length);
	for (int i = 0; i < paramTypes->Length; i++)
	{
		if (ps[i]->ParameterType->IsByRef)
			paramTypes[i] = ps[i]->ParameterType->GetElementType();
		else
			paramTypes[i] = ps[i]->ParameterType;
	}
	array<LocalBuilder^>^ locals = gcnew array<LocalBuilder^>(paramTypes.Length+1);
	//array<LocalBuilder^>^ locals = gcnew array<LocalBuilder^>(paramTypes.Length);

	for (int i = 0; i < paramTypes->Length; i++)
	{
		locals[i] = il->DeclareLocal(paramTypes[i], true);
	}
	for (int i = 0; i < paramTypes->Length; i++)
	{
		il->Emit(OpCodes::Ldarg_1);
		EmitFastInt(il, i);
		il->Emit(OpCodes::Ldelem_Ref);
		EmitCastToReference(il, paramTypes[i]);
		il->Emit(OpCodes::Stloc, locals[i]);
	}
	locals[paramTypes->Length]=il->DeclareLocal(methodInfo->DeclaringType);
	if (!methodInfo->IsStatic)
	{
		il->Emit(OpCodes::Ldarg_0);
		il->Emit(OpCodes::Ldind_Ref);
		EmitUnboxIfNeeded(il,methodInfo->DeclaringType);
		il->Emit(OpCodes::Stloc,locals[paramTypes->Length]);
		if(methodInfo->DeclaringType->IsValueType)
			il->Emit(OpCodes::Ldloca,locals[paramTypes->Length]);
		else
			il->Emit(OpCodes::Ldloc,locals[paramTypes->Length]);
	}
	for (int i = 0; i < paramTypes->Length; i++)
	{
		if (ps[i]->ParameterType->IsByRef)
			il->Emit(OpCodes::Ldloca_S, locals[i]);
		else
			il->Emit(OpCodes::Ldloc, locals[i]);
	}
	
	if (methodInfo->IsStatic || methodInfo->IsFinal)
		il->EmitCall(OpCodes::Call, methodInfo, nullptr);
	else
		il->EmitCall(OpCodes::Callvirt, methodInfo, nullptr);
	if (methodInfo->ReturnType == void::typeid)
		il->Emit(OpCodes::Ldnull);
	else
		EmitBoxIfNeeded(il, methodInfo->ReturnType);

	for (int i = 0; i < paramTypes->Length; i++)
	{
		if (ps[i]->ParameterType->IsByRef)
		{
			il->Emit(OpCodes::Ldarg_1);
			EmitFastInt(il, i);
			il->Emit(OpCodes::Ldloc, locals[i]);
			if (locals[i]->LocalType->IsValueType)
				il->Emit(OpCodes::Box, locals[i]->LocalType);
			il->Emit(OpCodes::Stelem_Ref);
		}
	}

	il->Emit(OpCodes::Ret);
	return (FastInvokeHandler^)dynamicMethod->CreateDelegate(FastInvokeHandler::typeid);
}

FastGetAccessorHandler^ CFastInvoker::GetGetAccessorInvoker(PropertyInfo^ propertyInfo)
{
	MethodInfo^ mi=propertyInfo->GetGetMethod();
	if(mi==nullptr)
		return nullptr;
	array<Type^>^ tmpArr = { Object::typeid->MakeByRefType()};
	DynamicMethod^ dynamicMethod = gcnew DynamicMethod(String::Empty, Object::typeid, tmpArr, propertyInfo->DeclaringType->Module);
	ILGenerator^ il = dynamicMethod->GetILGenerator();

	//LocalBuilder^ localTarget = 
	il->DeclareLocal(propertyInfo->DeclaringType, true);
	il->Emit(OpCodes::Ldarg_0);
	il->Emit(OpCodes::Ldind_Ref);
	EmitUnboxIfNeeded(il,propertyInfo->DeclaringType);
	il->Emit(OpCodes::Stloc,0);
	if(propertyInfo->DeclaringType->IsValueType)
		il->Emit(OpCodes::Ldloca_S,0);
	else
		il->Emit(OpCodes::Ldloc_S,0);
	//il->Emit(OpCodes::Constrained,propertyInfo->DeclaringType);

	if (mi->IsFinal)
		il->EmitCall(OpCodes::Call, mi, nullptr);
	else
		il->EmitCall(OpCodes::Callvirt, mi, nullptr);
	EmitBoxIfNeeded(il, mi->ReturnType);
	il->Emit(OpCodes::Ret);
	return (FastGetAccessorHandler^)dynamicMethod->CreateDelegate(FastGetAccessorHandler::typeid);
}

FastSetAccessorHandler^ CFastInvoker::GetSetAccessorInvoker(PropertyInfo^ propertyInfo)
{
	MethodInfo^ mi=propertyInfo->GetSetMethod();
	if(mi==nullptr)
		return nullptr;
	array<Type^>^ tmpArr = { Object::typeid->MakeByRefType(), Object::typeid};
	DynamicMethod^ dynamicMethod = gcnew DynamicMethod(String::Empty, void::typeid, tmpArr, propertyInfo->DeclaringType->Module);
	ILGenerator^ il = dynamicMethod->GetILGenerator();

	il->DeclareLocal(propertyInfo->DeclaringType, true);
	il->Emit(OpCodes::Ldarg_0);
	il->Emit(OpCodes::Ldind_Ref);
	EmitUnboxIfNeeded(il,propertyInfo->DeclaringType);
	il->Emit(OpCodes::Stloc,0);
	if(propertyInfo->DeclaringType->IsValueType)
		il->Emit(OpCodes::Ldloca_S,0);
	else
		il->Emit(OpCodes::Ldloc_S,0);

	il->Emit(OpCodes::Ldarg_1);
	EmitUnboxIfNeeded(il, propertyInfo->PropertyType);
	//il->Emit(OpCodes::Constrained,propertyInfo->DeclaringType);
	if (mi->IsFinal)
		il->EmitCall(OpCodes::Call, mi, nullptr);
	else
		il->EmitCall(OpCodes::Callvirt, mi, nullptr);
	il->Emit(OpCodes::Ret);
	return (FastSetAccessorHandler^)dynamicMethod->CreateDelegate(FastSetAccessorHandler::typeid);
}
