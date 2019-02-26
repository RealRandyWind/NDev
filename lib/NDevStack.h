#pragma once

#include "NDevTypes.h"
#include "NDevDefinitions.h"
#include "NDevSequence.h"

namespace NDev
{
	using namespace Types;
	
	template<typename TypeValue>
	struct TStack : public TSequence<TypeValue>
	{

		TStack() : TSequence<TypeValue>()
		{

		}

		TStack(FSize ReserveSize, FBoolean bSetSizeToReserveSize = False, FBoolean bFill = False) : TStack()
		{
			this->Reserve(ReserveSize, bSetSizeToReserveSize, bFill);
		}

		~TStack()
		{

		}

		FVoid Push(TypeValue Rhs)
		{
			FBoolean bResize = !this->_bFixedSize && this->_Size >= this->_BufferSize;

			if (bResize) { this->Reserve(this->_Size + this->_IncrementSize); }
			this->_Data[this->_Size] = Rhs;
			++this->_Size;
		}

		TypeValue Pop()
		{
			--this->_Size;
			return this->_Data[this->_Size];
		}

		TypeValue &Peek()
		{
			return this->_Data[this->_Size - 1];
		}

		const TypeValue &Peek() const
		{
			return this->_Data[this->_Size - 1];
		}


	};



}