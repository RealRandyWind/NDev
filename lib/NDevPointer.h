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
		};

		FEntry *_Entry;

		static TList<FEntry> _List;
		static FEntry *_Next;

		_FPointer();

		~_FPointer();


	};

	template<typename TypeValue, EPointer EnumType = EPointer::Shared>
	struct TPointer : public _FPointer, public TypeValue
	{
		using FValue = TypeValue;


	};


}