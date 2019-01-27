#pragma once

#include <math.h>

#include "NDevTypes.h"
#include "NDevDefinitions.h"
#include "NDevPoint.h"

namespace NDev
{
	using namespace Types;

	namespace Constants
	{
		const FReal Pi = 3.141592653589793238462643383279502884L;

		const FReal Pi2 = 6.283185307179586476925286766559005768L;

		const FReal Pi3 = 9.42477796076937971538793014983850865L;

		const FReal ByPi = 0.31830988618379067153776752674502872L;

		const FReal PiBy2 = 1.57079632679489661923132169163975144L;

		const FReal PiBy3 = 0.954929658551372014613302580235086172L;

		const FReal Phi = 1.61803398874989484820458683436563811772L;

		const FReal ByPhi = 0.61803398874989484820458683436563811772L;

		const FReal E = 2.718281828459045235360287471352662497757247L;

		const FReal ByE = 0.36787944117144232159552377016146086744581L;

		const FReal Sqrt2 = 1.41421356237309504880168872420969807856967L;

		const FReal BySqrt2 = 0.70710678118654752440084436210484903928L;

		const FReal Sqrt3 = 1.7320508075688772935274463415058723669428L;

		const FReal BySqrt3 = 0.5773502691896257645091487805019574556476L;
	}

	/* Vector @ Vector */

	template<FSize Size, typename Type>
	TPoint<Size, Type> operator-(const TPoint<Size, Type> &Lhs, const TPoint<Size, Type> &Rhs)
	{
		FSize Index, End;
		TPoint<Size, Type> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = Lhs[Index] - Rhs[Index];
		}
		return Result;
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> operator+(const TPoint<Size, Type> &Lhs, const TPoint<Size, Type> &Rhs)
	{
		FSize Index, End;
		TPoint<Size, Type> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = Lhs[Index] + Rhs[Index];
		}
		return Result;
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> operator*(const TPoint<Size, Type> &Lhs, const TPoint<Size, Type> &Rhs)
	{
		FSize Index, End;
		TPoint<Size, Type> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = Lhs[Index] * Rhs[Index];
		}
		return Result;
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> operator/(const TPoint<Size, Type> &Lhs, const TPoint<Size, Type> &Rhs)
	{
		FSize Index, End;
		TPoint<Size, Type> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = Lhs[Index] / Rhs[Index];
		}
		return Result;
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> operator^(const TPoint<Size, Type> &Lhs, const TPoint<Size, Type> &Rhs)
	{
		FSize Index, End;
		TPoint<Size, Type> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = pow(Lhs[Index], Rhs[Index]);
		}
		return Result;
	}

	template<FSize Size, typename Type>
	TPoint<Size, FBoolean> operator>(const TPoint<Size, Type> &Lhs, const TPoint<Size, Type> &Rhs)
	{
		FSize Index, End;
		TPoint<Size, FBoolean> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = Lhs[Index] > Rhs[Index];
		}
		return Result;
	}

	template<FSize Size, typename Type>
	TPoint<Size, FBoolean> operator<(const TPoint<Size, Type> &Lhs, const TPoint<Size, Type> &Rhs)
	{
		FSize Index, End;
		TPoint<Size, FBoolean> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = Lhs[Index] < Rhs[Index];
		}
		return Result;
	}

	template<FSize Size, typename Type>
	TPoint<Size, FBoolean> operator>=(const TPoint<Size, Type> &Lhs, const TPoint<Size, Type> &Rhs)
	{
		FSize Index, End;
		TPoint<Size, FBoolean> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = Lhs[Index] >= Rhs[Index];
		}
		return Result;
	}

	template<FSize Size, typename Type>
	TPoint<Size, FBoolean> operator<=(const TPoint<Size, Type> &Lhs, const TPoint<Size, Type> &Rhs)
	{
		FSize Index, End;
		TPoint<Size, FBoolean> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = Lhs[Index] <= Rhs[Index];
		}
		return Result;
	}

	template<FSize Size, typename Type>
	TPoint<Size, FBoolean> operator==(const TPoint<Size, Type> &Lhs, const TPoint<Size, Type> &Rhs)
	{
		FSize Index, End;
		TPoint<Size, FBoolean> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = Lhs[Index] == Rhs[Index];
		}
		return Result;
	}

	template<FSize Size, typename Type>
	TPoint<Size, FBoolean> operator!=(const TPoint<Size, Type> &Lhs, const TPoint<Size, Type> &Rhs)
	{
		FSize Index, End;
		TPoint<Size, FBoolean> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = Lhs[Index] != Rhs[Index];
		}
		return Result;
	}


	/* Vector @= Vector */

	template<FSize Size, typename Type>
	TPoint<Size, Type> &operator+=(TPoint<Size, Type> &Lhs, const TPoint<Size, Type> &Rhs)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Lhs[Index] += Rhs[Index];
		}
		return Lhs;
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> &operator-=(TPoint<Size, Type> &Lhs, const TPoint<Size, Type> &Rhs)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Lhs[Index] -= Rhs[Index];
		}
		return Lhs;
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> &operator*=(TPoint<Size, Type> &Lhs, const TPoint<Size, Type> &Rhs)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Lhs[Index] *= Rhs[Index];
		}
		return Lhs;
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> &operator/=(TPoint<Size, Type> &Lhs, const TPoint<Size, Type> &Rhs)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Lhs[Index] /= Rhs[Index];
		}
		return Lhs;
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> &operator^=(TPoint<Size, Type> &Lhs, const TPoint<Size, Type> &Rhs)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Lhs[Index] = pow(Lhs[Index], Rhs[Index]);
		}
		return Lhs;
	}


	/* Alpha @ Vector */

	template<FSize Size, typename Type>
	TPoint<Size, Type> operator+(const Type &Lhs, const TPoint<Size, Type> &Rhs)
	{
		FSize Index, End;
		TPoint<Size, Type> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = Lhs + Rhs[Index];
		}
		return Result;
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> operator-(const Type &Lhs, const TPoint<Size, Type> &Rhs)
	{
		FSize Index, End;
		TPoint<Size, Type> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = Lhs - Rhs[Index];
		}
		return Result;
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> operator*(const Type &Lhs, const TPoint<Size, Type> &Rhs)
	{
		FSize Index, End;
		TPoint<Size, Type> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = Lhs * Rhs[Index];
		}
		return Result;
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> operator/(const Type &Lhs, const TPoint<Size, Type> &Rhs)
	{
		FSize Index, End;
		TPoint<Size, Type> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = Lhs / Rhs[Index];
		}
		return Result;
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> operator^(const Type &Lhs, const TPoint<Size, Type> &Rhs)
	{
		FSize Index, End;
		TPoint<Size, Type> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = pow(Lhs, Rhs[Index]);
		}
		return Result;
	}

	template<FSize Size, typename Type>
	TPoint<Size, FBoolean> operator>(const Type &Lhs, const TPoint<Size, Type> &Rhs)
	{
		FSize Index, End;
		TPoint<Size, FBoolean> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = Lhs > Rhs[Index];
		}
		return Result;
	}

	template<FSize Size, typename Type>
	TPoint<Size, FBoolean> operator<(const Type &Lhs, const TPoint<Size, Type> &Rhs)
	{
		FSize Index, End;
		TPoint<Size, FBoolean> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = Lhs < Rhs[Index];
		}
		return Result;
	}

	template<FSize Size, typename Type>
	TPoint<Size, FBoolean> operator>=(const Type &Lhs, const TPoint<Size, Type> &Rhs)
	{
		FSize Index, End;
		TPoint<Size, FBoolean> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = Lhs >= Rhs[Index];
		}
		return Result;
	}

	template<FSize Size, typename Type>
	TPoint<Size, FBoolean> operator<=(const Type &Lhs, const TPoint<Size, Type> &Rhs)
	{
		FSize Index, End;
		TPoint<Size, FBoolean> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = Lhs <= Rhs[Index];
		}
		return Result;
	}

	template<FSize Size, typename Type>
	TPoint<Size, FBoolean> operator==(const Type &Lhs, const TPoint<Size, Type> &Rhs)
	{
		FSize Index, End;
		TPoint<Size, FBoolean> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = Lhs == Rhs[Index];
		}
		return Result;
	}

	template<FSize Size, typename Type>
	TPoint<Size, FBoolean> operator!=(const Type &Lhs, const TPoint<Size, Type> &Rhs)
	{
		FSize Index, End;
		TPoint<Size, FBoolean> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = Lhs != Rhs[Index];
		}
		return Result;
	}

	/* Vector @ Alpha */

	template<FSize Size, typename Type>
	TPoint<Size, Type> operator+(const TPoint<Size, Type> &Lhs, const Type &Rhs)
	{
		FSize Index, End;
		TPoint<Size, Type> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = Lhs[Index] + Rhs;
		}
		return Result;
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> operator-(const TPoint<Size, Type> &Lhs, const Type &Rhs)
	{
		FSize Index, End;
		TPoint<Size, Type> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = Lhs[Index] - Rhs;
		}
		return Result;
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> operator*(const TPoint<Size, Type> &Lhs, const Type &Rhs)
	{
		FSize Index, End;
		TPoint<Size, Type> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = Lhs[Index] * Rhs;
		}
		return Result;
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> operator/(const TPoint<Size, Type> &Lhs, const Type &Rhs)
	{
		FSize Index, End;
		TPoint<Size, Type> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = Lhs[Index] / Rhs;
		}
		return Result;
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> operator^(const TPoint<Size, Type> &Lhs, const Type &Rhs)
	{
		FSize Index, End;
		TPoint<Size, Type> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = pow(Lhs[Index], Rhs);
		}
		return Result;
	}

	template<FSize Size, typename Type>
	TPoint<Size, FBoolean> operator>(const TPoint<Size, Type> &Lhs, const Type &Rhs)
	{
		FSize Index, End;
		TPoint<Size, FBoolean> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = Lhs[Index] > Rhs;
		}
		return Result;
	}

	template<FSize Size, typename Type>
	TPoint<Size, FBoolean> operator<(const TPoint<Size, Type> &Lhs, const Type &Rhs)
	{
		FSize Index, End;
		TPoint<Size, FBoolean> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = Lhs[Index] < Rhs;
		}
		return Result;
	}

	template<FSize Size, typename Type>
	TPoint<Size, FBoolean> operator>=(const TPoint<Size, Type> &Lhs, const Type &Rhs)
	{
		FSize Index, End;
		TPoint<Size, FBoolean> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = Lhs[Index] >= Rhs;
		}
		return Result;
	}

	template<FSize Size, typename Type>
	TPoint<Size, FBoolean> operator<=(const TPoint<Size, Type> &Lhs, const Type &Rhs)
	{
		FSize Index, End;
		TPoint<Size, FBoolean> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = Lhs[Index] <= Rhs;
		}
		return Result;
	}

	template<FSize Size, typename Type>
	TPoint<Size, FBoolean> operator==(const TPoint<Size, Type> &Lhs, const Type &Rhs)
	{
		FSize Index, End;
		TPoint<Size, FBoolean> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = Lhs[Index] == Rhs;
		}
		return Result;
	}

	template<FSize Size, typename Type>
	TPoint<Size, FBoolean> operator!=(const TPoint<Size, Type> &Lhs, const Type &Rhs)
	{
		FSize Index, End;
		TPoint<Size, FBoolean> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = Lhs[Index] != Rhs;
		}
		return Result;
	}

	/* Vector @= Alpha */

	template<FSize Size, typename Type>
	TPoint<Size, Type> &operator+=(TPoint<Size, Type> &Lhs, const Type &Rhs)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Lhs[Index] += Rhs;
		}
		return Lhs;
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> &operator-=(TPoint<Size, Type> &Lhs, const Type &Rhs)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Lhs[Index] -= Rhs;
		}
		return Lhs;
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> &operator*=(TPoint<Size, Type> &Lhs, const Type &Rhs)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Lhs[Index] *= Rhs;
		}
		return Lhs;
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> &operator/=(TPoint<Size, Type> &Lhs, const Type &Rhs)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Lhs[Index] /= Rhs;
		}
		return Lhs;
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> &operator^=(TPoint<Size, Type> &Lhs, const Type &Rhs)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Lhs[Index] = pow(Lhs[Index], Rhs);
		}
		return Lhs;
	}

	/* Function(Vector...) */

	template<FSize Size, typename Type>
	Type Sum(const TPoint<Size, Type> &Rhs)
	{
		FSize Index, End;
		Type Result = Type();

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result += Rhs[Index];
		}
		return Result;
	}

	template<FSize Size, typename Type>
	Type Dot(const TPoint<Size, Type> &Lhs, const TPoint<Size, Type> &Rhs)
	{
		FSize Index, End;
		Type Result = Type();

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result += Lhs[Index] * Rhs[Index];
		}
		return Result;
	}

	template<FSize Size, typename Type>
	Type Norm2(const TPoint<Size, Type> &Rhs, const Type &N)
	{
		FSize Index, End;
		Type Result = Type();

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result += pow(Rhs[Index], N);
		}
		return Result;
	}

	template<FSize Size, typename Type>
	Type Norm2(const TPoint<Size, Type> &Rhs)
	{
		FSize Index, End;
		Type Result = Type();

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result += Rhs[Index] * Rhs[Index];
		}
		return Result;
	}

	template<FSize Size, typename Type>
	Type Norm(const TPoint<Size, Type> &Rhs, const Type &N)
	{
		const Type ByN = 1 / N;

		return pow(Norm2(Rhs, N), ByN);
	}

	template<FSize Size, typename Type>
	Type Norm(const TPoint<Size, Type> &Rhs)
	{
		return sqrt(Norm2(Rhs));
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> &Normalize2(const TPoint<Size, Type> &Rhs, const Type &N)
	{
		const FReal One = 1;
		FReal Alpha = One / Norm2(Rhs, N);
		return Rhs * Alpha;
	}

	template<FSize Size, typename Type>
	FVoid Normalize2Into(TPoint<Size, Type> &Rhs, const Type &N)
	{
		const FReal One = 1;
		FReal Alpha = One / Norm2(Rhs, N);
		Rhs *= Alpha;
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> &Normalize2(const TPoint<Size, Type> &Rhs)
	{
		const FReal One = 1;
		FReal Alpha = One / Norm2(Rhs);
		return Rhs * Alpha;
	}

	template<FSize Size, typename Type>
	FVoid Normalize2Into(TPoint<Size, Type> &Rhs)
	{
		const FReal One = 1;
		FReal Alpha = One / Norm2(Rhs);
		Rhs *= Alpha;
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> &Normalize(const TPoint<Size, Type> &Rhs, const Type &N)
	{
		const FReal One = 1;
		FReal Alpha = One / Norm(Rhs, N);
		return  Rhs * Alpha;
	}

	template<FSize Size, typename Type>
	FVoid NormalizeInto(TPoint<Size, Type> &Rhs, const Type &N)
	{
		const FReal One = 1;
		FReal Alpha = One / Norm(Rhs, N);
		Rhs *= Alpha;
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> &Normalize(const TPoint<Size, Type> &Rhs)
	{
		const FReal One = 1;
		FReal Alpha = One / Norm(Rhs);
		return  Rhs * Alpha;
	}

	template<FSize Size, typename Type>
	FVoid NormalizeInto(TPoint<Size, Type> &Rhs)
	{
		const FReal One = 1;
		FReal Alpha = One / Norm(Rhs);
		Rhs *= Alpha;
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> Min(const TPoint<Size, Type> &Lhs, const TPoint<Size, Type> &Rhs)
	{
		FSize Index, End;
		TPoint<Size, Type> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = Min(Lhs[Index], Rhs[Index]);
		}
		return Result;
	}

	template<FSize Size, typename Type>
	FVoid MinInto(TPoint<Size, Type> &Lhs, const TPoint<Size, Type> &Rhs)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Lhs[Index] = Min(Lhs[Index], Rhs[Index]);
		}
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> Max(const TPoint<Size, Type> &Lhs, const TPoint<Size, Type> &Rhs)
	{
		FSize Index, End;
		TPoint<Size, Type> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = Max(Lhs[Index], Rhs[Index]);
		}
		return Result;
	}

	template<FSize Size, typename Type>
	FVoid MaxInto(TPoint<Size, Type> &Lhs, const TPoint<Size, Type> &Rhs)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Lhs[Index] = Max(Lhs[Index], Rhs[Index]);
		}
	}

	template<FSize Size, typename Type>
	Type Angle(const TPoint<Size, Type> &Lhs, const TPoint<Size, Type> &Rhs)
	{
		const FReal One = 1;
		FReal Alpha = One / (Norm(Lhs) * Norm(Rhs));
		return acos(Dot(Lhs, Rhs) * Alpha);
	}

	template<FSize Size, typename Type>
	FBoolean All(const TPoint<Size, Type> &Rhs)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			if (!Rhs[Index]) { return False; };
		}
		return True;
	}

	template<FSize Size, typename Type>
	FBoolean Any(const TPoint<Size, Type> &Rhs)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			if (Rhs[Index]) { return True;  }
		}
		return False;
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> Mask(const TPoint<Size, Type> &Lhs, const TPoint<Size, FBoolean> &Rhs)
	{
		FSize Index, End;
		TPoint<Size, Type> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = Lhs[Index] * Rhs[Index];
		}
		return Result;
	}

	template<FSize Size, typename Type>
	FVoid MaskInto(TPoint<Size, Type> &Lhs, const TPoint<Size, FBoolean> &Rhs)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Lhs[Index] *= Rhs[Index];
		}
	}
	
	/*
	template<FSize Size, typename Type>
	TPoint<Size, Type> &IntoPoint(TPoint<Size, Type> &Lhs, const TQuinsor<Size, Type> &Rhs)
	{
		FSize Index, End;
		Type Scale, Theta;

	}

	template<FSize Size, typename Type>
	TQuinsor<Size, Type> &IntoQuinsor(TQuinsor<Size, Type> &Lhs, const TPoint<Size, Type> &Rhs)
	{
		FSize Index, End;
		Type Scale, Theta;
	}
	*/

}