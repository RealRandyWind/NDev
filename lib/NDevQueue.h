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
			FBoolean bQueued, bPriority;

			_FindPosition(Rhs, Cursor, bPriority);
			_InsertPosition(Rhs, Cursor, bPriority, bQueued);

			return bQueued;
		}

		TypeValue Dequeue()
		{
			FSize Index = _FirstIndex;

			if (!this->_Size) { exit(Failure); }
			--this->_Size;
			if (_FirstIndex != _LastIndex)
			{
				_FirstIndex = (_FirstIndex == this->_BufferSize ? 0 : _FirstIndex) + 1;
			}
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

		FVoid _ResizeQueue(FSize &Cursor)
		{
			this->Reserve(this->_BufferSize + this->_IncrementSize);
			
			if (_LastIndex < _FirstIndex)
			{
				Copy(&this->_Data[_FirstIndex], &this->_Data[_FirstIndex + _IncrementSize], _IncrementSize);
				_FirstIndex += _IncrementSize;
				if (Cursor >= _FirstIndex) { Cursor += _IncrementSize; }
			}
			else
			{
				Copy(&this->_Data[_LastIndex], &this->_Data[_LastIndex + _IncrementSize], _IncrementSize);
				_LastIndex += _IncrementSize;
				if (Cursor >= _LastIndex) { Cursor += _IncrementSize; }
				if (_LastIndex == _FirstIndex) { _FirstIndex = _LastIndex; }
			}
		}

		FVoid _FindPosition(const TypeValue &Value, FSize &Cursor, FBoolean &bPriority)
		{
			if (!this->_Size)
			{
				bPriority = False;
				Cursor = 0;
				return;
			}

			if (!OnPriority)
			{
				bPriority = False;
				Cursor = _LastIndex + 1;
				return;
			}

			Cursor = _FirstIndex;
			while (Cursor != _LastIndex)
			{
				if (OnPriority(Value, this->_Data[Cursor]))
				{
					bPriority = True;
					return;
				}
				Cursor = (Cursor + 1) % this->_BufferSize;
			}
			bPriority = OnPriority(Value, this->_Data[Cursor]);
			if (!bPriority) { ++Cursor; }
		}

		FVoid _InsertPosition(TypeValue &Value, FSize Cursor, FBoolean bPriority, FBoolean &bQueued)
		{
			FBoolean bFull = this->_Size + 1 >= this->_BufferSize;
			FBoolean bResize = !this->_bFixedSize && bFull;
			
			bQueued = False;
			//Q =(a0 A aN ...)|(... a0 A aN ...)|(AN aN ... a0 A0) |(...), a0 > ai > aN, j = ?
			if (bPriority)
			{
				while (Cursor != _LastIndex)
				{
					Swap(Value, this->_Data[Cursor]);
					Cursor = (Cursor + 1) % this->_BufferSize;
				}
				Swap(Value, this->_Data[Cursor]);
				bQueued = True;
			}

			if (bResize)
			{
				_ResizeQueue(Cursor);
				this->_Data[Cursor] = Value;
				bQueued = True;
			}

			if (!bFull || bResize) { ++this->_Size; }
		}


	};



}