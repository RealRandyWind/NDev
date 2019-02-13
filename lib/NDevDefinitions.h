#pragma once

#include "NDevTypes.h"

namespace NDev
{
	using namespace Types;
	
	struct FDescriptor
	{
		FSize Type, SizeOf, Size, _Size, Stride, Offset, N;
		FBoolean bHeap;
		union
		{
			FPointer Pointer;
			FRaw *Raw;
			FByte *Bytes;
		};
	};

	/* Helper Functions */

	template<typename Type>
	Type Min(const Type &Lhs, const Type &Rhs)
	{
		return Lhs < Rhs ? Lhs : Rhs;
	}

	template<typename Type>
	Type Max(const Type &Lhs, const Type &Rhs)
	{
		return Lhs > Rhs ? Lhs : Rhs;
	}

	template<typename Type>
	Type Sign(const Type &Lhs, const Type Zero = 0, const Type One = 1)
	{
		return Lhs < Zero ? -One : One;
	}

	template<typename Type>
	Type Abs(const Type &Lhs, const Type Zero = 0)
	{
		return Lhs < Zero ? -Lhs : Lhs;
	}

	template<typename Type>
	Type ZeroEps(const Type &Lhs, const Type &Eps, const Type Zero = 0)
	{
		return Lhs <= Eps ? Zero : Lhs;
	}

	template<typename Type>
	Type &Swap(Type &Lhs, Type &Rhs)
	{
		Type Temp;

		Temp = Lhs;
		Lhs = Rhs;
		Rhs = Temp;
		return Rhs;
	}

	template<typename Type>
	Type Clamp(const Type &Lhs, const Type &Lower, const Type &Upper)
	{
		return Lhs > Upper ? Upper : (Lhs < Lower ? Lower : Lhs);
	}

	template<typename Type>
	FBoolean Between(const Type &Lhs, const Type &Lower, const Type &Upper, FBoolean bStrict = True)
	{
		return bStrict ? (Lhs < Upper && Lhs > Lower) : (Lhs <= Upper && Lhs >= Lower);
	}

	/* Pure Memory Functions */

	static void * _Make(FSize Bytes)
	{
		FPointer Pointer = malloc(Bytes);
		if (!Pointer) { exit(Failure); }
		return Pointer;
	}

	static void * _Swap2(void *From, void *To, FSize Bytes)
	{
		FSize Index, End;

		if (!From) { exit(Failure); }
		if (!To) { To = _Make(Bytes); }
		auto _From = (FRaw *)From;
		auto _To = (FRaw *)To;
		End = Bytes;
		for (Index = 0; Index < End; ++Index) { Swap(_From[Index], _To[Index]); }
		return _To;
	}

	static void * _Resize(void *Pointer, FSize Bytes)
	{
		FPointer _Pointer = realloc(Pointer, Bytes);
		if (!_Pointer) { exit(Failure); }
		Pointer = _Pointer;
		return Pointer;
	}

	static void * _Move(void *From, void *To, FSize Bytes)
	{
		FSize Index, End;

		if (!From) { exit(Failure); }
		if (!To) { To = _Make(Bytes); }
		auto _From = (FRaw *)From;
		auto _To = (FRaw *)To;
		End = Bytes;
		for (Index = 0; Index < End; ++Index) { _To[Index] = _From[Index]; _From[Index] = 0; }
		return _To;
	}

	static void * _Copy(const void *From, void *To, FSize Bytes)
	{
		FSize Index, End;

		if (!From) { exit(Failure); }
		if (!To) { To = _Make(Bytes); }
		auto _From = (const FRaw *)From;
		auto _To = (FRaw *)To;
		End = Bytes;
		for (Index = 0; Index < End; ++Index) { _To[Index] = _From[Index]; }
		return _To;
	}

	static void * _Remove(void *Pointer)
	{
		if (!Pointer) { return NullPtr; }
		free(Pointer);
		return NullPtr;
	}

	static void * _Set(void *Pointer, const void *Value, FSize Bytes, FSize SizeOf = sizeof(FRaw))
	{
		FSize Index, End, IndexValue, EndValue;

		if (!Pointer || !Value) { exit(Failure); }
		auto _Pointer = (FRaw *) Pointer;
		auto _Value = (const FRaw *) Value;
		if (SizeOf == sizeof(FRaw))
		{
			End = Bytes;
			for (Index = 0; Index < End; ++Index) { _Pointer[Index] = _Value[0]; }
			return _Pointer;
		}
		End = Bytes;
		EndValue = SizeOf;
		for (Index = 0; Index < End; ++Index)
		{
			for (IndexValue = 0; Index < End && IndexValue < EndValue; ++Index, ++IndexValue)
			{
				_Pointer[Index] = _Value[IndexValue];
			}
		}
		return _Pointer;
	}

	static void * _Shift(void *Pointer, FSize Steps, FSize Bytes, FBoolean bRight = True)
	{
		FSize Index, End, Remainder, From, To;

		if (!Pointer) { exit(Failure); }
		auto _Pointer = (FRaw *)Pointer;
		if (Steps >= Bytes) { return _Pointer; }
		Remainder = Bytes % Steps;
		End = Bytes / Steps;
		if (bRight)
		{
			for (Index = 1; Index < End; ++Index)
			{
				From = (End - Index - 1) * Steps + Remainder;
				To = (End - Index) * Steps + Remainder;
				_Copy(&_Pointer[From], &_Pointer[To], Steps);
			}
			if (Remainder) { _Copy(&_Pointer[0], &_Pointer[Steps], Remainder); }
		}
		else
		{
			for (Index = 0; Index + 1 < End; ++Index)
			{
				_Copy(&_Pointer[(Index + 1) * Steps], &_Pointer[Index * Steps], Steps);
			}
			if (Remainder) { _Copy(&_Pointer[End * Steps], &_Pointer[(End - 1) * Steps], Remainder); }
		}
		return _Pointer;
	}

	static void * _Text(const void *String)
	{
		FSize Size;

		if (!String) { exit(Failure); }
		auto _String = (FCharacter *)String;
		for (Size = 0; _String[Size]; ++Size) { }
		return _Copy(_String, NullPtr, Size);
	}

	/* Template Memory Functions */

	template<typename Type, typename TypeFrom>
	Type To(TypeFrom Value)
	{
		return static_cast<Type>(Value);
	}

	template<typename Type>
	Type DefaultValue(Type Value, Type Default)
	{
		return Value ? Type : Default;
	}

	template<typename Type>
	Type * Swap2(Type *From, Type *To, FSize Size = 1)
	{
		return (Type *)_Swap2(From, To, Size * sizeof(Type));
	}

	template<typename Type>
	Type * Make(FSize Size = 1)
	{
		return (Type *) _Make(Size * sizeof(Type));
	}

	template<typename Type>
	Type * Resize(Type *Pointer, FSize Size = 1)
	{
		return (Type *) _Resize(Pointer, Size * sizeof(Type));
	}

	template<typename Type>
	Type * Move(Type *From, Type *To = NullPtr, FSize Size = 1)
	{
		return (Type *) _Move(From, To, Size * sizeof(Type));
	}

	template<typename Type>
	Type * Copy(const Type *From, Type *To = NullPtr, FSize Size = 1)
	{
		return (Type *) _Copy(From, To, Size * sizeof(Type));
	}

	template<typename Type>
	Type * Remove(Type *Pointer)
	{
		return (Type *) _Remove(Pointer);
	}

	template<typename Type>
	Type * Set(Type *Pointer, const Type Value, FSize Size = 1)
	{
		return (Type *) _Set(Pointer, &Value, sizeof(Type) * Size, sizeof(Type));
	}

	template<typename Type>
	Type * Shift(Type *Pointer, FSize Steps, FSize Size = 1, FBoolean bRight = True)
	{
		return (Type *)_Shift(Pointer, Steps * sizeof(Type), Size * sizeof(Type), bRight);
	}

	static FString Text(const char *String, char End = '\0', FSize *PtrSize = NullPtr)
	{
		FSize Size;

		if (!String) { return NullPtr; }
		for (Size = 0; String[Size] != End; ++Size) { };
		if (PtrSize) { *PtrSize = Size; }
		return (FString) _Copy(String, NullPtr, Size + 1);
	}

	static FString Text(const FString String, FCharacter End = NullChr, FSize *PtrSize = NullPtr)
	{
		FSize Size;

		if (!String) { return NullPtr; }
		for (Size = 0; String[Size] != End; ++Size) {};
		if (PtrSize) { *PtrSize = Size; }
		return (FString) _Copy(String, NullPtr, Size + 1);
	}



}