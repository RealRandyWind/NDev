#pragma once

#include "NDevTypes.h"
#include "NDevDefinitions.h"
#include <NDevList.h>

namespace NDev
{
	using namespace Types;

	struct _FPointer
	{
		FSize Id;
		FPointer *Value;
	};

	template<typename TypeValue>
	struct TPointer
	{
		using FValue = TypeValue;

		enum class EType : FEnum
		{
			_Unknown = Unknown,
			Weak,
			Strong,
			Unique,
			_Size
		};

		EType _Type;
		FSize _Id;

		TPointer()
		{

		}

		TPointer(TypeValue &Value)
		{
			
		}

		~TPointer()
		{

		}

		FSize Id() const
		{
			return _Id;
		}

		EType Type() const
		{
			return _Type;
		}

		EType Type(EType NewType)
		{
			return (_Type = NewType);
		}

	};

}