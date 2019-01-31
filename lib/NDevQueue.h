#pragma once

#include "NDevTypes.h"
#include "NDevDefinitions.h"
#include "NDevSequence.h"

namespace NDev
{
	using namespace Types;

	template<typename TypeValue>
	struct TQueue : public TSequence<TypeValue>
	{
		using FOnPriority = TFunction<FBoolean(const TypeValue&, const TypeValue&)>;

		FOnPriority OnPriority;

		FSize _LastIndex, _FirstIndex;

		TQueue() : TSequence<TypeValue>()
		{
			OnPriority = NullPtr;
			_LastIndex = _FirstIndex = 0;
		}

		TQueue(FSize ReserveSize, FBoolean bSetSizeToReserveSize = False) : TQueue()
		{
			this->Reserve(ReserveSize, bSetSizeToReserveSize);
		}

		~TQueue()
		{

		}

		virtual FVoid Reset() override
		{
			this->_Size = this->_RecentIndex = _LastIndex = _FirstIndex = 0;
		}

		FBoolean _Queue(TypeValue Rhs)
		{
			if (this->_Size >= this->_BufferSize) { return False; }
			_LastIndex = (_LastIndex == 0 ? this->_BufferSize : _LastIndex) - 1;
			if (!this->_Size) { _FirstIndex = _LastIndex; }
			this->_Data[_LastIndex] = Rhs;
			++this->_Size;
			return True;
		}

		FBoolean Queue(TypeValue Rhs)
		{
			FSize Index, Cursor;
			FBoolean bQueued;

			_FindPosition(Rhs, Cursor, bQueued);
			_InsertPosition(Rhs, Cursor, bQueued);

			return bQueued;
		}

		TypeValue Dequeue()
		{
			FSize Index;

			if (!this->_Size) { exit(Failure); }
			--this->_Size;
			if (_FirstIndex == _LastIndex) { return this->_Data[_FirstIndex]; }
			Index = _FirstIndex;
			_FirstIndex = (_FirstIndex == 0 ? this->_BufferSize : _FirstIndex) - 1;
			return this->_Data[Index];
		}

		TypeValue & Last()
		{
			return this->_Data[_LastIndex];
		}

		const TypeValue & Last() const
		{
			return this->_Data[_LastIndex];
		}

		TypeValue & First()
		{
			return this->_Data[_FirstIndex];
		}

		const TypeValue & First() const
		{
			return this->_Data[_FirstIndex];
		}

		FVoid _FindPosition(const TypeValue &Rhs, FSize &Cursor, FBoolean &bQueue)
		{
			bQueue = False;

			if (!OnPriority)
			{
				bQueue = True;
				Cursor = (_LastIndex == 0 ? this->_Size : this->_LastIndex) - 1 ;
				return;
			}
		}

		FVoid _InsertPosition(TypeValue &Rhs, FSize Cursor, FBoolean bQueue)
		{
			FBoolean bResize = !this->_bFixedSize && bQueue && this->_FirstIndex == this->_LastIndex;
			
			if (bResize)
			{
				
			}
		}

	};



}