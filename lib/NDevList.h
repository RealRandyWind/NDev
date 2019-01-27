#pragma once

#include "NDevTypes.h"
#include "NDevDefinitions.h"
#include "NDevSequence.h"

namespace NDev
{
	using namespace Types;
	
	template<typename TypeData>
	struct TList : public TSequence<TypeData>
	{
		using FOnPriority = TFunction<FBoolean(const TypeData&, const TypeData&)>;

		FOnPriority OnPriority;

		TList() : TSequence<TypeData>()
		{
			OnPriority = NullPtr;
		}

		TList(FSize ReserveSize, FBoolean bSetSizeToReserveSize = False) : TList()
		{
			this->Reserve(ReserveSize, bSetSizeToReserveSize);
		}

		~TList()
		{

		}

		FVoid Add(TypeData Rhs)
		{
			FBoolean bResize = !this->_bFixedSize && this->_Size >= this->_BufferSize;

			if (bResize) { this->Reserve(this->_Size + this->_IncrementSize); }
			this->_Data[this->_Size] = Rhs;
			++this->_Size;
		}

		FVoid Remove(TypeData &Rhs)
		{

		}

		FVoid Sort()
		{
			FSize End, Cursor, Pivot;

			if (!OnPriority) { return; }

			End = this->_Size;
			for (Pivot = 0; Pivot < End; ++Pivot)
			{
				auto &Value = this->_Data[Pivot];
				_FindPosition(Value, Cursor, Pivot);
				_InsertPosition(Value, Cursor, Pivot);
			}
		}

		FVoid Sort(TSequence<FSize> &Indices)
		{
			FSize End, Cursor, Pivot;
			Indices.Reserve(this->_Size, True);

			if (!OnPriority) { return; }

			End = this->_Size;
			for (Pivot = 0; Pivot < End; ++Pivot)
			{
				auto &Value = this->_Data[Pivot];
				_FindPosition(Value, Cursor, Pivot, Indices);
				_InsertPosition(Pivot, Cursor, Pivot, Indices);
			}
		}

		FVoid Sort(TSequence<FSize> &Indices) const
		{
			FSize Index, End;

			if (!OnPriority) { return; }

			End = this->_Size;
		}

		FVoid Sort(TSequence<FSize> &Indices, const TSequence<FSize> &Targets)
		{
			FSize Index, End;

			if (!OnPriority) { return; }

			End = this->_Size;
		}

		FVoid Sort(TSequence<FSize> &Indices, const TSequence<FSize> &Targets) const
		{
			FSize Index, End;

			if (!OnPriority) { return; }

			End = this->_Size;
		}

		FVoid _FindPosition(TypeData &Value, FSize &Cursor, FSize Pivot)
		{
			FBoolean bPriority;

			for (Cursor = 0; Cursor < Pivot && bPriority; ++Cursor)
			{
				bPriority = OnPriority(Value, this->_Data[Cursor]);
			}
		}

		FVoid _FindPosition(TypeData &Value, FSize &Cursor, FSize Pivot, const TSequence<FSize> &Indices)
		{
			FBoolean bPriority;

			for (Cursor = 0; Cursor < Pivot && bPriority; ++Cursor)
			{
				bPriority = OnPriority(Value, this->_Data[Indices[Cursor]]);
			}
		}
		
		FVoid _InsertPosition(TypeData &Value, FSize Cursor, FSize Pivot)
		{
			for (; Cursor < Pivot; ++Cursor)
			{
				Swap(Value, this->_Data[Cursor]);
			}
		}

		FVoid _InsertPosition(TypeData &Value, FSize Cursor, FSize Pivot, const TSequence<FSize> &Indices)
		{
			for (; Cursor < Pivot; ++Cursor)
			{
				Swap(Value, this->_Data[Cursor]);
			}
		}

	};



}