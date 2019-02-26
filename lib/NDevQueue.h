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
		FBoolean _bNoEqualPriority;

		TQueue() : TSequence<TypeValue>()
		{
			OnPriority = NullPtr;
			_LastIndex = _FirstIndex = 0;
			_bNoEqualPriority = False;
		}

		TQueue(FSize ReserveSize, FBoolean bSetSizeToReserveSize = False, FBoolean bFill = False) : TQueue()
		{
			this->Reserve(ReserveSize, bSetSizeToReserveSize, bFill);
		}

		~TQueue()
		{

		}

		virtual FVoid Reset() override
		{
			this->_Size = this->_RecentIndex = _LastIndex = _FirstIndex = 0;
		}

		FBoolean Queue(TypeValue Rhs)
		{
			FSize Cursor;
			FBoolean bQueued, bPriority, bRejected;

			_FindPosition(Rhs, Cursor, bPriority, bRejected);
			if (bRejected) { return False; }
			_InsertPosition(Rhs, Cursor, bPriority, bQueued);

			return bQueued;
		}

		TypeValue Dequeue()
		{
			FSize Index = _FirstIndex;

			if (!this->_Size) { exit(Failure); }
			--this->_Size;
			if (_FirstIndex != _LastIndex) { _FirstIndex = (_FirstIndex + 1) % this->_BufferSize; }
			return this->_Data[Index];
		}

		FVoid NoEqualPriority(FBoolean bTrue = True)
		{
			_bNoEqualPriority = bTrue;
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

		FVoid _ResizeQueue(FSize &Cursor, FBoolean &bFull)
		{
			this->Reserve(this->_BufferSize + this->_IncrementSize);
			if (_LastIndex < _FirstIndex)
			{
				Shift(&this->_Data[_FirstIndex], this->_IncrementSize, this->_BufferSize - _FirstIndex);
				if (Cursor >= _FirstIndex) { Cursor += this->_IncrementSize; }
				_FirstIndex += this->_IncrementSize;
			}
			bFull = False;
		}

		FVoid _FindPosition(const TypeValue &Value, FSize &Cursor, FBoolean &bPriority, FBoolean &bRejected) const
		{
			bRejected = False;

			if (!this->_Size)
			{
				bPriority = False;
				Cursor = 0;
				return;
			}

			if (!OnPriority)
			{
				bPriority = False;
				Cursor = _LastIndex;
				return;
			}

			Cursor = _FirstIndex;
			while (Cursor != _LastIndex)
			{
				if (OnPriority(Value, this->_Data[Cursor]))
				{
					if (_bNoEqualPriority) { bRejected = OnPriority(this->_Data[Cursor], Value); }
					bPriority = True;
					return;
				}
				Cursor = (Cursor + 1) % this->_BufferSize;
			}
			bPriority = OnPriority(Value, this->_Data[Cursor]);
			if (_bNoEqualPriority && bPriority) { bRejected = OnPriority(this->_Data[Cursor], Value); }
		}

		FVoid _InsertPosition(TypeValue &Value, FSize Cursor, FBoolean bPriority, FBoolean &bQueued)
		{
			FBoolean bFull = this->_Size >= this->_BufferSize;
			FBoolean bResize = bFull && !this->_bFixedSize;
		
			bQueued = False;

			if (!this->_Size) { _FirstIndex = _LastIndex = 0; }

			if (bResize) { _ResizeQueue(Cursor, bFull); }

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

			if (!bFull)
			{
				if (this->_Size) { _LastIndex = (_LastIndex + 1) % this->_BufferSize; }
				this->_Data[_LastIndex] = Value;
				++this->_Size;
				bQueued = True;
			}
		}


	};



}