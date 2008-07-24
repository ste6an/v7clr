#pragma once
#pragma managed
using namespace System;
using namespace System::Reflection;
using namespace System::Reflection::Emit;

typedef array<Object^>^ objArray_t;
public delegate Object^ FastInvokeHandler(Object^% target, objArray_t paramters);
public delegate Object^ FastGetAccessorHandler(Object^% target);
public delegate void FastSetAccessorHandler(Object^% target, Object^ value);

ref class Globals abstract sealed
{
public:
	static initonly array<Type^>^ numTypes =
		{Int16::typeid, Int32::typeid, Int64::typeid,
		Double::typeid, SByte::typeid, Single::typeid,
		UInt16::typeid, UInt32::typeid, UInt64::typeid};
	static StringComparer^ sc=StringComparer::Create(System::Globalization::CultureInfo::InvariantCulture,false);
	static Type^ objectType = Object::typeid;
};

class CFastInvoker
{
public:
	static FastInvokeHandler^ GetMethodInvoker(MethodInfo^ methodInfo);
	static FastGetAccessorHandler^ GetGetAccessorInvoker(PropertyInfo^ propertyInfo);
	static FastSetAccessorHandler^ GetSetAccessorInvoker(PropertyInfo^ propertyInfo);
	static void EmitCastToReference(ILGenerator^ il, Type^ type);
	static void EmitBoxIfNeeded(ILGenerator^ il, Type^ type);
	static void EmitUnboxIfNeeded(ILGenerator^ il, Type^ type);
	static void EmitFastInt(ILGenerator^ il, int value);
};
