#pragma once

#include "NDevTypes.h"
#include "NDevMathConstants.h"
#include "NDevAssume.h"
#include "NDevDefinitions.h"
#include "NDevPoint.h"
#include "NDevBases.h"

namespace NDev
{
	using namespace Types;

	/* Bases @ Bases */

	/* Bases @= Bases */

	/* Bases @ Vector */

	/* Bases @= Vector */

	/* Vector @ Bases */

	/* Bases @ Alpha */

	/* Bases @= Alpha */

	/* Alpha @ Bases */

	/* Function(Bases...) */

	template<FSize SizePoint, FSize SizeBases, typename Type>
	FReal Det(const TBases<SizePoint, SizeBases, Type> &Rhs)
	{

	}

	template<FSize SizePoint, FSize SizeBases, typename Type>
	TPoint<SizePoint, Type> Transform(const TPoint<SizePoint, Type> &Lhs, const TBases<SizePoint, SizeBases, Type> &Rhs, const FSize Offset = 0)
	{
		FSize Index, End;
		TPoint<SizePoint, Type> Result;

		Result = TAssume<Type>::Zero();
		End = Min(SizePoint, SizeBases);
		for (Index = 0; Index + Offset < End; ++Index)
		{
			Result += Lhs[Index] * Rhs[Index + Offset];
		}

		return Result;
	}

	template<FSize SizePoint, FSize SizeBases, typename Type>
	FVoid TransformInto(TPoint<SizePoint, Type> &Into, const TBases<SizePoint, SizeBases, Type> &Rhs, const FSize Offset = 0)
	{
		FSize Index, End;
		TPoint<SizePoint, Type> Temp;

		Temp = Into;
		Into = TAssume<Type>::Zero();
		End = Min(SizePoint, SizeBases);
		for (Index = 0; Index + Offset < End; ++Index)
		{
			Into += Temp[Index] * Rhs[Index + Offset];
		}
	}

	template<FSize SizePoint, FSize SizeBases, typename Type>
	FVoid TransformInto(TPoint<SizePoint, Type> &Into, const TPoint<SizePoint, Type> &Lhs, const TBases<SizePoint, SizeBases, Type> &Rhs, const FSize Offset = 0)
	{
		FSize Index, End;

		Into = TAssume<Type>::Zero();
		End = Min(SizePoint, SizeBases);
		for (Index = 0; Index + Offset < End; ++Index)
		{
			Into += Lhs[Index] * Rhs[Index + Offset];
		}
	}
}