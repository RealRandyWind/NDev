#pragma once

#include "NDevTypes.h"
#include "NDevDefinitions.h"
#include "NDevSequence.h"

namespace NDev
{
	using namespace Types;
	
	template<typename TypeData>
	struct TStack : public TSequence<TypeData>
	{

		TStack() : TSequence<TypeData>()
		{

		}

		TStack(FSize ReserveSize, FBoolean bSetSizeToReserveSize = False) : TStack()
		{
			this->Reserve(ReserveSize, bSetSizeToReserveSize);
		}

		~TStack()
		{

		}

		FVoid Push(TypeData Rhs)
		{
			FBoolean bResize = !this->_bFixedSize && this->_Size >= this->_BufferSize;

			if (bResize) { this->Reserve(this->_Size + this->_IncrementSize); }
			this->_Data[this->_Size] = Rhs;
			++this->_Size;
		}

		TypeData &Pop()
		{
			--this->Size;
			return this->_Data[this->_Size];
		}

		TypeData &Peek()
		{
			return this->_Data[this->_Size - 1];
		}

		const TypeData &Peek() const
		{
			return this->_Data[this->_Size - 1];
		}


	};



}