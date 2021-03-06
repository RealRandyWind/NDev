#pragma once

#include "NDevTypes.h"
#include "NDevDefinitions.h"
#include "NDevSequence.h"

namespace NDev
{
	using namespace Types;

	template<typename TypeValue>
	struct TSet : public TSequence<TypeValue>
	{
		using FOnEqual = TFunction<FBoolean(const TypeValue&, const TypeValue&)>;
		using FOnMap = TFunction<FSize(const TypeValue&)>;

		FOnEqual OnEqual;
		FOnMap OnMap;

		TSet() : TSequence<TypeValue>()
		{
			OnPriority = NullPtr;
			OnMap = NullPtr;
		}

		TSet(FSize ReserveSize, FBoolean bSetSizeToReserveSize = False, FBoolean bFill = False) : TSet()
		{
			this->Reserve(ReserveSize, bSetSizeToReserveSize, bFill);
		}

		~TSet()
		{

		}

		FBoolean Add(TypeValue Rhs)
		{
			FSize Cursor;
			FBoolean bAdded, bRejected;

			++this->_Size;

			return bAdded;
		}

		FBoolean Remove(TypeValue Rhs)
		{
			FSize Index = _FirstIndex;
			FBoolean bRemoved;

			if (!this->_Size) { exit(Failure); }
			
			--this->_Size;

			return bRemoved;
		}


	};



}