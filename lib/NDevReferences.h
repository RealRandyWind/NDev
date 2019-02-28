#pragma once

#include "NDevTypes.h"
#include "NDevDefinitions.h"

namespace NDev
{
	using namespace Types;
	
	template<FSize SizeData, typename TypeValue>
	struct TReferences
	{
		using FValue = typename TypeValue;

		struct FSame
		{
			template<typename _TypeValue>
			using Size = TReferences<SizeData, _TypeValue>;

			template<FSize _SizeData>
			using Type = TReferences<_SizeData, TypeValue>;
		};
	
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

		TypeValue & operator[](FSize Index)
		{
			if (!_Data[Index]) { exit(Failure); }
			return *(TypeValue *)_Data[Index];
		}

		const TypeValue & operator[](FSize Index) const
		{
			if (!_Data[Index]) { exit(Failure); }
			return *(TypeValue *)_Data[Index];
		}

		TypeValue ** begin()
		{
			return (TypeValue **)&_Data[0];
		}

		const TypeValue ** begin() const
		{
			return (TypeValue **)&_Data[0];
		}

		TypeValue ** end()
		{
			return (TypeValue **)&_Data[SizeData];
		}

		const TypeValue ** end() const
		{
			return (TypeValue **)&_Data[SizeData];
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
		
		TReferences<SizeData, typename TypeValue> & operator=(const decltype(NullPtr) Rhs)
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
		TReferences<SizeData, TypeValue> & operator=(const TypeRhs &Rhs)
		{
			FSize Index, End;
			TypeValue **Pointers;
			
			Pointers = (TypeValue **)_Data;
			End = SizeData;
			for (Index = 0; Index < End; ++Index)
			{
				if (Pointers[Index])
				{
					*Pointers[Index] = static_cast<TypeValue>(Rhs);
				}
			}
			return *this;
		}

		template<typename TypeRhs>
		TReferences<SizeData, TypeValue> & operator=(TypeRhs *Rhs)
		{
			FSize Index, End;
			TypeValue **Pointers;

			Pointers = (TypeValue **)this->_Data;
			End = SizeData;
			for (Index = 0; Index < End; ++Index)
			{
				Pointers[Index] = Rhs;
			}
			return *this;
		}

		template<FSize SizeRhs, typename TypRhs>
		TReferences<SizeData, TypeValue> & operator=(const TReferences<SizeRhs, TypRhs> &Rhs)
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
		static TReferences<SizeRhs, TypeValue> Like()
		{
			TReferences<SizeRhs, TypeValue> Result;
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