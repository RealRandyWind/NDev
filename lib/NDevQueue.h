#pragma once

#include "NDevTypes.h"
#include "NDevDefinitions.h"
#include "NDevSequence.h"

namespace NDev
{
	using namespace Types;

	template<typename TypeData>
	struct TQueue : public TSequence<TypeData>
	{
		using FOnPriority = TFunction<FBoolean(const TypeData&, const TypeData&)>;

		FOnPriority OnPriority;

		FSize _LastIndex, _FirstIndex;

		TQueue() : TSequence<TypeData>()
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

		FBoolean _Queue(TypeData Rhs)
		{
			if (this->_Size >= this->_BufferSize) { return False; }
			_LastIndex = (_LastIndex == 0 ? this->_BufferSize : _LastIndex) - 1;
			if (!this->_Size) { _FirstIndex = _LastIndex; }
			this->_Data[_LastIndex] = Rhs;
			++this->_Size;
			return True;
		}

		FBoolean Queue(TypeData Rhs)
		{
			FSize Index;
			FBoolean bPriority, bQueued;

			if (!OnPriority || !this->_Size) { return _Queue(Rhs); }

			Index = _LastIndex;
			bQueued = False;
			bPriority = OnPriority(Rhs, this->_Data[Index]);
			while (Index != _FirstIndex && bPriority)
			{
				++Index;
				if (Index >= this->_BufferSize) { Index = 0; }
				bPriority = OnPriority(Rhs, this->_Data[Index]);
			}

			if (bPriority)
			{
				++_FirstIndex;
				if (_FirstIndex >= this->_BufferSize) { _FirstIndex = 0; }

				this->_Data[_FirstIndex] = Rhs;

				if (this->_Size >= this->_BufferSize)
				{
					++_LastIndex;
					if (_LastIndex >= this->_BufferSize) { _LastIndex = 0; }
					return True;
				}

				++this->_Size;
				return True;
			}

			while (Index != _LastIndex)
			{
				NDev::Swap(Rhs, this->_Data[Index]);
				Index = (Index == 0 ? this->_BufferSize : Index) - 1;
				bQueued = True;
			}

			return _Queue(Rhs) || bQueued;
		}

		TypeData Dequeue()
		{
			FSize Index;

			if (!this->_Size) { exit(Failure); }
			--this->_Size;
			if (_FirstIndex == _LastIndex) { return this->_Data[_FirstIndex]; }
			Index = _FirstIndex;
			_FirstIndex = (_FirstIndex == 0 ? this->_BufferSize : _FirstIndex) - 1;
			return this->_Data[Index];
		}

		TypeData & Last()
		{
			return this->_Data[_LastIndex];
		}

		const TypeData & Last() const
		{
			return this->_Data[_LastIndex];
		}

		TypeData & First()
		{
			return this->_Data[_FirstIndex];
		}

		const TypeData & First() const
		{
			return this->_Data[_FirstIndex];
		}


	};



}