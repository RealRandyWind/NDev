#pragma once

#include "NDevTypes.h"
#include "NDevDefinitions.h"
#include "NDevSequence.h"

namespace NDev
{
	using namespace Types;
	
	template<typename TypeValue>
	struct TList : public TSequence<TypeValue>
	{
		using FOnPriority = TFunction<FBoolean(const TypeValue&, const TypeValue&)>;

		FOnPriority OnPriority;

		TList() : TSequence<TypeValue>()
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

		FSize Make()
		{
			FSize Index;
			_New(Index);
			return Index;
		}

		FSize Make(TypeValue Rhs)
		{
			FSize Index;

			_New(Index) = Rhs;
			return Index;
		}

		TypeValue &New()
		{
			return _New();
		}

		TypeValue &New(TypeValue Rhs)
		{
			return (_New() = Rhs);
		}

		FVoid Add(TypeValue Rhs)
		{
			FBoolean bResize = !this->_bFixedSize && this->_Size >= this->_BufferSize;

			if (bResize) { this->Reserve(this->_Size + this->_IncrementSize); }
			this->_Data[this->_Size] = Rhs;
			++this->_Size;
		}

		FVoid Sort()
		{
			FSize End, Cursor, Pivot;

			if (!OnPriority || this->_Size < 2) { return; }

			End = this->_Size;
			for (Pivot = 0; Pivot < End; ++Pivot)
			{
				auto &Value = this->_Data[Pivot];
				_FindPosition(Value, Cursor, Pivot);
				_InsertPosition(Value, Cursor, Pivot);
			}
		}

		FVoid Sort(TSequence<FSize> &Indices) const
		{
			FSize End, Cursor, Pivot;
			Indices.Reserve(this->_Size, True);

			if (!OnPriority) { return; }

			End = this->_Size;
			for (Pivot = 0; Pivot < End; ++Pivot)
			{
				Indices[Pivot] = Pivot;
				_FindPosition(this->_Data[Pivot], Cursor, Pivot, Indices);
				_InsertPosition(Indices[Pivot], Cursor, Pivot, Indices);
			}
		}

		FVoid TargetSort(TSequence<FSize> &Indices, const TSequence<FSize> &Targets) const
		{
			FSize End, Cursor, Pivot;
			Indices.Reserve(Targets.Size(), True);

			if (!OnPriority) { return; }

			End = Targets.Size();
			for (Pivot = 0; Pivot < End; ++Pivot)
			{
				Indices[Pivot] = Targets[Pivot];
				_FindPosition(this->_Data[Targets[Pivot]], Cursor, Pivot, Indices);
				_InsertPosition(Indices[Pivot], Cursor, Pivot, Indices);
			}
		}

		FVoid TargetSort(const TSequence<FSize> &Targets)
		{
			FSize End, Cursor, Pivot;

			if (!OnPriority || this->_Size < 2) { return; }

			End = Targets.Size();
			for (Pivot = 0; Pivot < End; ++Pivot)
			{
				auto &Value = this->_Data[Targets[Pivot]];
				_TargetFindPosition(Value, Cursor, Pivot, Targets);
				_TargetInsertPosition(Value, Cursor, Pivot, Targets);
			}
		}

		TypeValue &_New()
		{
			FSize Index;
			
			return _New(Index);
		}

		TypeValue &_New(FSize &Index)
		{
			FBoolean bResize = !this->_bFixedSize && this->_Size >= this->_BufferSize;

			if (bResize) { this->Reserve(this->_Size + this->_IncrementSize); }
			Index = this->_Size;
			auto &Result = this->_Data[Index];
			++this->_Size;
			return Result;
		}

		FVoid _FindPosition(const TypeValue &Value, FSize &Cursor, FSize Pivot) const
		{
			for (Cursor = 0; Cursor < Pivot; ++Cursor)
			{
				if (!OnPriority(Value, this->_Data[Cursor])) { return; }
			}
		}

		FVoid _FindPosition(const TypeValue &Value, FSize &Cursor, FSize Pivot, const TSequence<FSize> &Indices) const
		{
			for (Cursor = 0; Cursor < Pivot; ++Cursor)
			{
				if (!OnPriority(Value, this->_Data[Indices[Cursor]])) { return; }
			}
		}

		FVoid _InsertPosition(TypeValue &Value, FSize Cursor, FSize Pivot)
		{
			for (; Cursor < Pivot; ++Cursor)
			{
				Swap(Value, this->_Data[Cursor]);
			}
		}

		FVoid _InsertPosition(FSize &Index, FSize Cursor, FSize Pivot, TSequence<FSize> &Indices) const
		{
			for (; Cursor < Pivot; ++Cursor)
			{
				Swap(Index, Indices[Cursor]);
			}
		}

		FVoid _TargetFindPosition(const TypeValue &Value, FSize &Cursor, FSize Pivot, const TSequence<FSize> &Targets) const
		{
			for (Cursor = 0; Cursor < Pivot; ++Cursor)
			{
				if (!OnPriority(Value, this->_Data[Targets[Cursor]])) { return; }
			}
		}

		FVoid _TargetInsertPosition(TypeValue &Value, FSize Cursor, FSize Pivot, const TSequence<FSize> &Targets)
		{
			for (; Cursor < Pivot; ++Cursor)
			{
				Swap(Value, this->_Data[Targets[Cursor]]);
			}
		}


	};



}