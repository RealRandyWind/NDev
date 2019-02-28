#pragma once

#include "NDevTypes.h"
#include "NDevDefinitions.h"
#include "NDevPoint.h"

namespace NDev
{
	using namespace Types;
	
	template<FSize SizePoint, FSize SizeBases, typename TypeValue>
	struct TBases
	{
		using FValue = TypeValue;

		using FPoint = TPoint<SizePoint, TypeValue>;

		struct FSame
		{
			template<FSize _SizeBases>
			using Point = TBases<SizePoint, _SizeBases, TypeValue>;

			template<FSize _SizePoint>
			using Bases = TBases<_SizePoint, SizeBases, TypeValue>;

			template<typename _TypeValue>
			using Shape = TBases<SizePoint, SizeBases, _TypeValue>;

			template<FSize _SizePoint, typename _TypeValue>
			using Size = TBases<_SizePoint, SizeBases, _TypeValue>;

			template<FSize _SizePoint, FSize _SizeBases>
			using Type = TBases<_SizePoint, _SizeBases, TypeValue>;
		};

		union
		{
			FPoint _Bases[SizeBases];
			TypeValue _Data[SizePoint * SizeBases];
		};
		
		FSize Size()
		{
			return SizeBases;
		}

		const FSize Size() const
		{
			return SizeBases;
		}

		FSize PointSize()
		{
			return SizePoint;
		}

		const FSize PointSize() const
		{
			return SizePoint;
		}

		FSize DataSize()
		{
			return SizePoint * SizeBases;
		}

		const FSize DataSize() const
		{
			return SizePoint * SizeBases;
		}

		FSize SizeOf()
		{
			return sizeof(TypeValue) * SizePoint * SizeBases;
		}

		const FSize SizeOf() const
		{
			return sizeof(TypeValue) * SizePoint * SizeBases;
		}

		FByte * Bytes()
		{
			return (FByte *) &_Data[0];
		}

		const FByte * Bytes() const
		{
			return (FByte *) &_Data[0];
		}

		FPoint * Data()
		{
			return &_Bases[0];
		}

		const FPoint * Data() const
		{
			return &_Bases[0];
		}

		TypeValue * Values()
		{
			return &_Data[0];
		}

		const TypeValue * Values() const
		{
			return &_Data[0];
		}

		const FDescriptor Descriptor() const
		{
			FDescriptor _Descriptor;

			_Descriptor.Type = None;
			_Descriptor.SizeOf = sizeof(FPoint);
			_Descriptor.Size = SizeBases;
			_Descriptor._Size = SizeBases;
			_Descriptor.N = 0;
			_Descriptor.bHeap = False;
			_Descriptor.Bytes = (FByte *) &_Data[0];
			_Descriptor.Offset = 0;
			_Descriptor.Stride = 0;
			return _Descriptor;
		}

		FPoint & operator[](FSize Index)
		{
			return _Bases[Index];
		}

		const FPoint & operator[](FSize Index) const
		{
			return _Bases[Index];
		}

		FPoint * begin()
		{
			return &_Bases[0];
		}

		const FPoint * begin() const
		{
			return &_Bases[0];
		}

		FPoint * end()
		{
			return &_Bases[SizeBases];
		}

		const FPoint * end() const
		{
			return &_Bases[SizeBases];
		}

		template<FSize SizePointLhs, FSize SizeBasesLhs, typename TypeLhs>
		operator TBases<SizePointLhs, SizeBasesLhs, TypeLhs>()
		{
			TBases<SizeLhs, TypeLhs> Lhs;
			FSize Index, End;

			End = Min(SizePoint * SizeBases, SizeLhs);
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
		TBases<SizePoint, SizeBases, TypeValue> & operator=(const TypeRhs &Rhs)
		{
			FSize Index, End;

			End = SizePoint * SizeBases;
			for (Index = 0; Index < End; ++Index)
			{
				_Data[Index] = static_cast<TypeValue>(Rhs);
			}
			return *this;
		}

		template<FSize SizeRhs, typename TypeRhs>
		TBases<SizePoint, SizeBases, TypeValue> & operator=(const TPoint<SizeRhs, TypeRhs> &Rhs)
		{
			FSize Index, End;

			End = SizeBases;
			for (Index = 0; Index < End; ++Index)
			{
				_Bases[Index] = static_cast<FPoint>(Rhs);
			}
			return *this;
		}

		template<FSize SizePointRhs, FSize SizeBasesRhs, typename TypRhs>
		TBases<SizePoint, SizeBases, TypeValue> & operator=(const TBases<SizePointRhs, SizeBasesRhs, TypRhs> &Rhs)
		{
			FSize Index, End;

			End = Min(SizePoint * SizeBases, SizePointRhs * SizeBasesRhs);
			for (Index = 0; Index < End; ++Index)
			{
				_Data[Index] = static_cast<TypeValue>(Rhs._Data[Index]);
			}
			return *this;
		}

		static TBases<SizePoint, SizeBases, TypeValue> Like()
		{
			TBases<SizePoint, SizeBases, TypeValue> Result;
			return Result;
		}

	};



}