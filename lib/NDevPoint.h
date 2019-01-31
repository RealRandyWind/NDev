#pragma once

#include "NDevTypes.h"
#include "NDevDefinitions.h"

namespace NDev
{
	using namespace Types;
	
	template<FSize SizeData, typename TypeValue>
	struct TPoint
	{
		using FValue = typename TypeValue;

		TypeValue _Data[SizeData];

		FSize Size()
		{
			return SizeData;
		}

		const FSize Size() const
		{
			return SizeData;
		}

		FSize SizeOf()
		{
			return sizeof(TypeValue) * SizeData;
		}

		const FSize SizeOf() const
		{
			return sizeof(TypeValue) * SizeData;
		}

		FByte * Bytes()
		{
			return (FByte *) &_Data[0];
		}

		const FByte * Bytes() const
		{
			return (FByte *) &_Data[0];
		}

		TypeValue * Data()
		{
			return &_Data[SizeData];
		}

		const TypeValue * Data() const
		{
			return &_Data[SizeData];
		}

		const FDescriptor Descriptor() const
		{
			FDescriptor _Descriptor;

			_Descriptor.Type = None;
			_Descriptor.SizeOf = sizeof(TypeValue);
			_Descriptor.Size = SizeData;
			_Descriptor._Size = SizeData;
			_Descriptor.N = 0;
			_Descriptor.bHeap = False;
			_Descriptor.Bytes = (FByte *) &_Data[0];
			_Descriptor.Offset = 0;
			_Descriptor.Stride = 0;
			return _Descriptor;
		}

		TypeValue & operator[](FSize Index)
		{
			return _Data[Index];
		}

		const TypeValue & operator[](FSize Index) const
		{
			return _Data[Index];
		}

		TypeValue * begin()
		{
			return &_Data[0];
		}

		const TypeValue * begin() const
		{
			return &_Data[0];
		}

		TypeValue * end()
		{
			return &_Data[SizeData];
		}

		const TypeValue * end() const
		{
			return &_Data[SizeData];
		}

		template<FSize SizeLhs, typename TypeLhs>
		operator TPoint<SizeLhs, TypeLhs>()
		{
			TPoint<SizeLhs, TypeLhs> Lhs;
			FSize Index, End;

			End = Min(SizeData, SizeLhs);
			for (Index = 0; Index < End; ++Index)
			{
				Lhs._Data[Index] = static_cast<TypeLhs>(_Data[Index]);
			}
			End = SizeLhs;
			for (; Index < End; ++Index)
			{
				Lhs._Data[Index] = TypeLhs();
			}
			return Lhs;
		}

		template<typename TypeRhs>
		TPoint<SizeData, TypeValue> & operator=(const TypeRhs &Rhs)
		{
			FSize Index, End;

			End = SizeData;
			for (Index = 0; Index < End; ++Index)
			{
				_Data[Index] = static_cast<TypeValue>(Rhs);
			}
			return *this;
		}

		template<FSize SizeRhs, typename TypRhs>
		TPoint<SizeData, TypeValue> & operator=(const TPoint<SizeRhs, TypRhs> &Rhs)
		{
			FSize Index, End;

			End = Min(SizeData, SizeRhs);
			for (Index = 0; Index < End; ++Index)
			{
				_Data[Index] = static_cast<TypeValue>(Rhs._Data[Index]);
			}
			return *this;
		}

		template<FSize SizeRhs>
		static TPoint<SizeRhs, TypeValue> Like()
		{
			TPoint<SizeRhs, TypeValue> Result;
			return Result;
		}

		template<typename TypeRhs>
		static TPoint<SizeData, TypeRhs> Like()
		{
			TPoint<SizeData, TypeRhs> Result;
			return Result;
		}
	};

}