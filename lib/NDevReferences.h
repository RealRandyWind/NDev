#pragma once

#include "NDevTypes.h"
#include "NDevDefinitions.h"

namespace NDev
{
	using namespace Types;
	
	template<FSize SizeData, typename TypeData>
	struct TReferences
	{
		using FData = typename TypeData;
	
		FPointer _Data[SizeData];

		FSize Size()
		{
			return SizeData;
		}

		const FSize Size() const
		{
			return SizeData;
		}

		FBoolean Assert()
		{
			FSize Index, End;

			End = SizeData;
			for (Index = 0; Index < End; ++Index)
			{
				if (!_Data[Index]) { return False; }
			}
			return True;
		}

		FBoolean Assert(FSize Index)
		{
			return _Data[Index] != NullPtr;
		}

		FBoolean Assert() const
		{
			FSize Index, End;

			End = SizeData;
			for (Index = 0; Index < End; ++Index)
			{
				if (!_Data[Index]) { return False; }
			}
			return True;
		}

		FBoolean Assert(FSize Index) const
		{
			return _Data[Index] != NullPtr;
		}

		TypeData & operator[](FSize Index)
		{
			if (!_Data[Index]) { exit(Failure); }
			return *(TypeData *)_Data[Index];
		}

		const TypeData & operator[](FSize Index) const
		{
			if (!_Data[Index]) { exit(Failure); }
			return *(TypeData *)_Data[Index];
		}

		TypeData ** begin()
		{
			return (TypeData **)&_Data[0];
		}

		const TypeData ** begin() const
		{
			return (TypeData **)&_Data[0];
		}

		TypeData ** end()
		{
			return (TypeData **)&_Data[SizeData];
		}

		const TypeData ** end() const
		{
			return (TypeData **)&_Data[SizeData];
		}

		template<FSize SizeLhs, typename TypeLhs>
		operator TReferences<SizeLhs, TypeLhs>()
		{
			TReferences<SizeLhs, TypeLhs> Lhs;
			FSize Index, End;

			End = Min(SizeData, SizeLhs);
			for (Index = 0; Index < End; ++Index)
			{
				Lhs._Data[Index] = _Data[Index];
			}
			End = SizeLhs;
			for (; Index < End; ++Index)
			{
				Lhs._Data[Index] = NullPtr;
			}
			return Lhs;
		}
		
		TReferences<SizeData, typename TypeData> & operator=(const decltype(NullPtr) Rhs)
		{
			FSize Index, End;
			End = SizeData;
			for (Index = 0; Index < End; ++Index)
			{
				_Data[Index] = Rhs;
			}
			return *this;
		}


		template<typename TypeRhs>
		TReferences<SizeData, TypeData> & operator=(const TypeRhs &Rhs)
		{
			FSize Index, End;
			TypeData **Pointers;
			
			Pointers = (TypeData **)_Data;
			End = SizeData;
			for (Index = 0; Index < End; ++Index)
			{
				if (Pointers[Index])
				{
					*Pointers[Index] = static_cast<TypeData>(Rhs);
				}
			}
			return *this;
		}

		template<typename TypeRhs>
		TReferences<SizeData, TypeData> & operator=(TypeRhs *Rhs)
		{
			FSize Index, End;
			TypeData **Pointers;

			Pointers = (TypeData **)this->_Data;
			End = SizeData;
			for (Index = 0; Index < End; ++Index)
			{
				Pointers[Index] = Rhs;
			}
			return *this;
		}

		template<FSize SizeRhs, typename TypRhs>
		TReferences<SizeData, TypeData> & operator=(const TReferences<SizeRhs, TypRhs> &Rhs)
		{
			FSize Index, End;

			End = Min(SizeData, SizeRhs);
			for (Index = 0; Index < End; ++Index)
			{
				_Data[Index] = Rhs._Data[Index];
			}
			return *this;
		}

		template<FSize SizeRhs>
		static TReferences<SizeRhs, TypeData> Like()
		{
			TReferences<SizeRhs, TypeData> Result;
			return Result;
		}

		template<typename TypeRhs>
		static TReferences<SizeData, TypeRhs> Like()
		{
			TReferences<SizeData, TypeRhs> Result;
			return Result;
		}


	};



}