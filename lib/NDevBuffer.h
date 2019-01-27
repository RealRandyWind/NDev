#pragma once

#include "NDevTypes.h"
#include "NDevDefinitions.h"
#include "NDevSequence.h"

namespace NDev
{
	using namespace Types;

	template<typename TypeData>
	struct TBuffer : public TSequence<TypeData>
	{
		FSize _ActiveIndex;

		TBuffer() : TSequence<TypeData>()
		{
			_ActiveIndex = 0;
		}

		TBuffer(FSize ReserveSize, FBoolean bSetSizeToReserveSize = False) : TBuffer()
		{
			this->Reserve(ReserveSize, bSetSizeToReserveSize);
		}

		~TBuffer()
		{

		}

		virtual FVoid Reset() override
		{
			this->_Size = _ActiveIndex = this->_RecentIndex = 0;
		}

		FVoid Swap(TypeData Rhs)
		{
			if (this->_Size < this->_BufferSize) { ++this->_Size; }

			++_ActiveIndex;
			if (_ActiveIndex >= this->_BufferSize) { _ActiveIndex = 0; }

			this->_Data[_ActiveIndex] = Rhs;
		}

		TypeData & Active()
		{
			return this->_Data[_ActiveIndex];
		}

		const TypeData & Active() const
		{
			return this->_Data[_ActiveIndex];
		}


	};



}