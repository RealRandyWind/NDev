#pragma once

#include "NDevTypes.h"
#include "NDevDefinitions.h"
#include <NDevList.h>

namespace NDev
{
	using namespace Types;

	enum class EPointer : FEnum
	{
		_Unknown = Unknown,
		Weak,
		Shared,
		Unique,
		_Size
	};

	struct _FPointer
	{
		struct FEntry
		{
			union
			{
				_FPointer *Pointer;
				FEntry *_Next;
			};
			FSize _Count, Count;

			FEntry()
			{
				_Next = NullPtr;
				_Count = Count = 0;
			}
			
			~FEntry() { }
		};

		FEntry *_Entry;

		static TList<FEntry> _List;
		static FEntry *_Next;

		_FPointer();

		~_FPointer();


	};

	template<typename TypeValue, EPointer EnumType = EPointer::Shared>
	struct TPointer;

	template<typename TypeValue>
	struct TPointer<TypeValue, EPointer::Weak> : public _FPointer, public TypeValue
	{
		using FValue = TypeValue;

		/* TODO */

		/*
		~TPointer() { };

		TPointer<TypeValue, EPointer::Shared> & operator=(const TypeValue &Rhs);

		operator TypeValue();

		FVoid operator delete(FPointer Rhs);

		FVoid operator delete[](FPointer Rhs);
		*/
	};

	template<typename TypeValue>
	struct TPointer<TypeValue, EPointer::Shared> : public _FPointer, public TypeValue
	{
		using FValue = TypeValue;

		/* TODO */

	};

	template<typename TypeValue>
	struct TPointer<TypeValue, EPointer::Unique> : public _FPointer, public TypeValue
	{
		using FValue = TypeValue;

		/* TODO */

	};


}