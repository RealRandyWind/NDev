#pragma once

#include <math.h>

#include "NDevTypes.h"
#include "NDevMathConstants.h"
#include "NDevDefinitions.h"
#include "NDevPoint.h"

namespace NDev
{
	using namespace Types;

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
	Type Sum(const TPoint<Size, Type> &Rhs, const Type Zero = 0)
	{
		FSize Index, End;
		Type Result = Zero;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result += Rhs[Index];
		}
		return Result;
	}

	template<FSize Size, typename Type>
	Type Prod(const TPoint<Size, Type> &Rhs, const Type One = 1)
	{
		FSize Index, End;
		Type Result = One;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result *= Rhs[Index];
		}
		return Result;
	}

	template<FSize Size, typename Type>
	Type Prod(const TPoint<Size, Type> &Rhs, const Type &Alpha, const Type One = 1)
	{
		FSize Index, End;
		Type Result = One;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result *= Rhs[Index] * (One / Alpha) ;
		}
		return Result;
	}

	template<FSize Size, typename Type>
	Type Dot(const TPoint<Size, Type> &Lhs, const TPoint<Size, Type> &Rhs, const Type Zero = 0)
	{
		FSize Index, End;
		Type Result = Zero; // TAssume<Type>::Zero();

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result += Lhs[Index] * Rhs[Index];
		}
		return Result;
	}

	template<FSize Size, typename Type>
	Type Norm2(const TPoint<Size, Type> &Rhs, const Type &N, const Type Zero = 0)
	{
		FSize Index, End;
		Type Result = Zero; // TAssume<Type>::Zero();

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result += pow(Rhs[Index], N);
		}
		return Result;
	}

	template<FSize Size, typename Type>
	Type Norm2(const TPoint<Size, Type> &Rhs, const Type Zero = 0)
	{
		FSize Index, End;
		Type Result = Zero; // TAssume<Type>::Zero();

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result += Rhs[Index] * Rhs[Index];
		}
		return Result;
	}

	template<FSize Size, typename Type>
	Type Norm(const TPoint<Size, Type> &Rhs, const Type &N, const Type One = 1)
	{
		// const auto ByN = TAssume<Type>::One() / N
		const Type ByN = One / N; 

		return pow(Norm2(Rhs, N), ByN);
	}

	template<FSize Size, typename Type>
	Type Norm(const TPoint<Size, Type> &Rhs)
	{
		return sqrt(Norm2(Rhs));
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> &Normalize2(const TPoint<Size, Type> &Rhs, const Type &N, const Type One = 1)
	{
		// Type Alpha = TAssume<Type>::One() / Norm2(Rhs, N);
		Type Alpha = One / Norm2(Rhs, N);
		return Rhs * Alpha;
	}

	template<FSize Size, typename Type>
	FVoid Normalize2Into(TPoint<Size, Type> &Into, const Type &N, const Type One = 1)
	{
		// Type Alpha = TAssume<Type>::One() / Norm2(Into, N);
		Type Alpha = One / Norm2(Into, N);
		Into *= Alpha;
	}

	template<FSize Size, typename Type>
	FVoid Normalize2Into(TPoint<Size, Type> &Into, const TPoint<Size, Type> &Rhs, const Type &N, const Type One = 1)
	{
		// Type Alpha = TAssume<Type>::One() / Norm2(Rhs, N);
		Type Alpha = One / Norm2(Rhs, N);
		Into = Rhs * Alpha;
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> &Normalize2(const TPoint<Size, Type> &Rhs, const Type One = 1)
	{
		// Type Alpha = TAssume<Type>::One() / Norm2(Rhs);
		Type Alpha = One / Norm2(Rhs);
		return Rhs * Alpha;
	}

	template<FSize Size, typename Type>
	FVoid Normalize2Into(TPoint<Size, Type> &Into, const Type One = 1)
	{
		// Type Alpha = TAssume<Type>::One() / Norm2(Into);
		Type Alpha = One / Norm2(Into);
		Into *= Alpha;
	}

	template<FSize Size, typename Type>
	FVoid Normalize2Into(TPoint<Size, Type> &Into, const TPoint<Size, Type> &Rhs, const Type One = 1)
	{
		// Type Alpha = TAssume<Type>::One() / Norm2(Rhs);
		Type Alpha = One / Norm2(Rhs);
		Into = Rhs * Alpha;
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> &Normalize(const TPoint<Size, Type> &Rhs, const Type &N, const Type One = 1)
	{
		// Type Alpha = TAssume<Type>::One() / Norm(Rhs, N);
		Type Alpha = One / Norm(Rhs, N);
		return  Rhs * Alpha;
	}

	template<FSize Size, typename Type>
	FVoid NormalizeInto(TPoint<Size, Type> &Into, const Type &N, const Type One = 1)
	{
		// Type Alpha = TAssume<Type>::One() / Norm(Into, N);
		Type Alpha = One / Norm(Into, N);
		Into *= Alpha;
	}

	template<FSize Size, typename Type>
	FVoid NormalizeInto(TPoint<Size, Type> &Into, const TPoint<Size, Type> &Rhs, const Type &N, const Type One = 1)
	{
		// Type Alpha = TAssume<Type>::One() / Norm(Rhs, N);
		Type Alpha = One / Norm(Rhs, N);
		Into = Rhs * Alpha;
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> &Normalize(const TPoint<Size, Type> &Rhs, const Type One = 1)
	{
		// Type Alpha = TAssume<Type>::One() / Norm(Rhs);
		Type Alpha = One / Norm(Rhs);
		return  Rhs * Alpha;
	}

	template<FSize Size, typename Type>
	FVoid NormalizeInto(TPoint<Size, Type> &Into, const Type One = 1)
	{
		// Type Alpha = TAssume<Type>::One() / Norm(Into);
		Type Alpha = One / Norm(Into);
		Into *= Alpha;
	}

	template<FSize Size, typename Type>
	FVoid NormalizeInto(TPoint<Size, Type> &Into, const TPoint<Size, Type> &Rhs, const Type One = 1)
	{
		// Type Alpha = TAssume<Type>::One() / Norm(Rhs);
		Type Alpha = One / Norm(Rhs);
		Into = Rhs * Alpha;
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
	FVoid MinInto(TPoint<Size, Type> &Into, const TPoint<Size, Type> &Rhs)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] = Min(Into[Index], Rhs[Index]);
		}
	}

	template<FSize Size, typename Type>
	FVoid MinInto(TPoint<Size, Type> &Into, const TPoint<Size, Type> &Lhs, const TPoint<Size, Type> &Rhs)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] = Min(Lhs[Index], Rhs[Index]);
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
	FVoid MaxInto(TPoint<Size, Type> &Into, const TPoint<Size, Type> &Rhs)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] = Max(Into[Index], Rhs[Index]);
		}
	}

	template<FSize Size, typename Type>
	FVoid MaxInto(TPoint<Size, Type> &Into, const TPoint<Size, Type> &Lhs, const TPoint<Size, Type> &Rhs)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] = Max(Lhs[Index], Rhs[Index]);
		}
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> Sign(const TPoint<Size, Type> &Lhs, const Type Zero = 0, const Type One = 1)
	{
		FSize Index, End;
		TPoint<Size, Type> Result;
		/*
		const auto Zero = TAssume<Type>::Zero();
		const auto One = TAssume<Type>::One();
		*/

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = Sign(Lhs[Index], Zero, One);
		}
		return Result;
	}

	template<FSize Size, typename Type>
	FVoid SignInto(TPoint<Size, Type> &Into, const Type Zero = 0, const Type One = 1)
	{
		FSize Index, End;
		/*
		const auto Zero = TAssume<Type>::Zero();
		const auto One = TAssume<Type>::One();
		*/

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] = Sign(Into[Index], Zero, One);
		}
	}

	template<FSize Size, typename Type>
	FVoid SignInto(TPoint<Size, Type> &Into, const TPoint<Size, Type> &Rhs, const Type Zero = 0, const Type One = 1)
	{
		FSize Index, End;
		/*
		const auto Zero = TAssume<Type>::Zero();
		const auto One = TAssume<Type>::One();
		*/

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] = Sign(Rhs[Index], Zero, One);
		}
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> Abs(const TPoint<Size, Type> &Lhs, const Type Zero = 0)
	{
		FSize Index, End;
		TPoint<Size, Type> Result;
		/*
		const auto Zero = TAssume<Type>::Zero();
		*/

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = Abs(Lhs[Index], Zero);
		}
		return Result;
	}

	template<FSize Size, typename Type>
	FVoid AbsInto(TPoint<Size, Type> &Into, const Type Zero = 0)
	{
		FSize Index, End;
		/*
		const auto Zero = TAssume<Type>::Zero();
		*/

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] = Abs(Into[Index], Zero);
		}
	}

	template<FSize Size, typename Type>
	FVoid AbsInto(TPoint<Size, Type> &Into, const TPoint<Size, Type> &Rhs, const Type Zero = 0)
	{
		FSize Index, End;
		/*
		const auto Zero = TAssume<Type>::Zero();
		*/

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] = Abs(Rhs[Index], Zero);
		}
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> ZeroEps(const TPoint<Size, Type> &Lhs, const Type &Eps, const Type Zero = 0)
	{
		FSize Index, End;
		TPoint<Size, Type> Result;
		/*
		const auto Zero = TAssume<Type>::Zero();
		*/

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = ZeroEps(Lhs[Index], Eps, Zero);
		}
		return Result;
	}

	template<FSize Size, typename Type>
	FVoid ZeroEpsInto(TPoint<Size, Type> &Into, const Type &Eps, const Type Zero = 0)
	{
		FSize Index, End;
		/*
		const auto Zero = TAssume<Type>::Zero();
		*/

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] = ZeroEps(Into[Index], Eps, Zero);
		}
	}

	template<FSize Size, typename Type>
	FVoid ZeroEpsInto(TPoint<Size, Type> &Into, const TPoint<Size, Type> &Rhs, const Type &Eps, const Type Zero = 0)
	{
		FSize Index, End;
		/*
		const auto Zero = TAssume<Type>::Zero();
		*/

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] = ZeroEps(Rhs[Index], Eps, Zero);;
		}
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> ZeroEps(const TPoint<Size, Type> &Lhs, const TPoint<Size, Type> &Eps, const Type Zero = 0)
	{
		FSize Index, End;
		TPoint<Size, Type> Result;
		/*
		const auto Zero = TAssume<Type>::Zero();
		*/

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = ZeroEps(Lhs[Index], Eps[Index], Zero);
		}
		return Result;
	}

	template<FSize Size, typename Type>
	FVoid ZeroEpsInto(TPoint<Size, Type> &Into, const TPoint<Size, Type> &Eps, const Type Zero = 0)
	{
		FSize Index, End;
		/*
		const auto Zero = TAssume<Type>::Zero();
		*/

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] = ZeroEps(Into[Index], Eps[Index], Zero);
		}
	}

	template<FSize Size, typename Type>
	FVoid ZeroEpsInto(TPoint<Size, Type> &Into, const TPoint<Size, Type> &Rhs, const TPoint<Size, Type> &Eps, const Type Zero = 0)
	{
		FSize Index, End;
		/*
		const auto Zero = TAssume<Type>::Zero();
		*/

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] = ZeroEps(Rhs[Index], Eps[Index], Zero);;
		}
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> EqualEps(const TPoint<Size, Type> &Lhs, const TPoint<Size, Type> &Rhs, const Type &Eps)
	{
		FSize Index, End;
		TPoint<Size, Type> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = EqualEps(Lhs[Index], Rhs[Index], Eps);
		}
		return Result;
	}

	template<FSize Size, typename Type>
	FVoid EqualEpsInto(TPoint<Size, Type> &Into, const TPoint<Size, Type> &Rhs, const Type &Eps)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] = EqualEps(Into[Index], Rhs[Index], Eps);
		}
	}

	template<FSize Size, typename Type>
	FVoid EqualEpsInto(TPoint<Size, Type> &Into, const TPoint<Size, Type> &Lhs, const TPoint<Size, Type> &Rhs, const Type &Eps)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] = EqualEps(Lhs[Index], Rhs[Index], Eps);
		}
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> EqualEps(const TPoint<Size, Type> &Lhs, const TPoint<Size, Type> &Rhs, const TPoint<Size, Type> &Eps)
	{
		FSize Index, End;
		TPoint<Size, Type> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = EqualEps(Lhs[Index], Rhs[Index], Eps[Index]);
		}
		return Result;
	}

	template<FSize Size, typename Type>
	FVoid EqualEpsInto(TPoint<Size, Type> &Into, const TPoint<Size, Type> &Rhs, const TPoint<Size, Type> &Eps)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] = EqualEps(Into[Index], Rhs[Index], Eps[Index]);
		}
	}

	template<FSize Size, typename Type>
	FVoid EqualEpsInto(TPoint<Size, Type> &Into, const TPoint<Size, Type> &Lhs, const TPoint<Size, Type> &Rhs, const TPoint<Size, Type> &Eps)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] = EqualEps(Lhs[Index], Rhs[Index], Eps[Index]);
		}
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> EqualEps(const TPoint<Size, Type> &Lhs, const Type &Rhs, const Type &Eps)
	{
		FSize Index, End;
		TPoint<Size, Type> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = EqualEps(Lhs[Index], Rhs, Eps);
		}
		return Result;
	}

	template<FSize Size, typename Type>
	FVoid EqualEpsInto(TPoint<Size, Type> &Into, const Type &Rhs, const Type &Eps)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] = EqualEps(Into[Index], Rhs, Eps);
		}
	}

	template<FSize Size, typename Type>
	FVoid EqualEpsInto(TPoint<Size, Type> &Into, const TPoint<Size, Type> &Lhs, const Type &Rhs, const Type &Eps)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] = EqualEps(Lhs[Index], Rhs, Eps);
		}
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> EqualEps(const TPoint<Size, Type> &Lhs, const Type &Rhs, const TPoint<Size, Type> &Eps)
	{
		FSize Index, End;
		TPoint<Size, Type> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = EqualEps(Lhs[Index], Rhs, Eps[Index]);
		}
		return Result;
	}

	template<FSize Size, typename Type>
	FVoid EqualEpsInto(TPoint<Size, Type> &Into, const Type &Rhs, const TPoint<Size, Type> &Eps)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] = EqualEps(Into[Index], Rhs, Eps[Index]);
		}
	}

	template<FSize Size, typename Type>
	FVoid EqualEpsInto(TPoint<Size, Type> &Into, const TPoint<Size, Type> &Lhs, const Type &Rhs, const TPoint<Size, Type> &Eps)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] = EqualEps(Lhs[Index], Rhs, Eps[Index]);
		}
	}

	template<FSize Size, typename Type>
	Type Angle(const TPoint<Size, Type> &Lhs, const TPoint<Size, Type> &Rhs)
	{
		const Type One = 1;
		Type Alpha = One / (Norm(Lhs) * Norm(Rhs));
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
	FVoid MaskInto(TPoint<Size, Type> &Into, const TPoint<Size, FBoolean> &Rhs)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] *= Rhs[Index];
		}
	}

	template<FSize Size, typename Type>
	FVoid MaskInto(TPoint<Size, Type> &Into, const TPoint<Size, Type> &Lhs, const TPoint<Size, FBoolean> &Rhs)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] = Lhs[Index] * Rhs[Index];
		}
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> Clamp(const TPoint<Size, Type> &Lhs, const TPoint<Size, Type> &Lower, const TPoint<Size, Type> &Upper)
	{
		FSize Index, End;
		TPoint<Size, Type> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = Clamp(Lhs[Index], Lower[Index], Upper[Index]);
		}
		return Result;
	}

	template<FSize Size, typename Type>
	FVoid ClampInto(TPoint<Size, Type> &Into, const TPoint<Size, Type> &Lower, const TPoint<Size, Type> &Upper)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] = Clamp(Into[Index], Lower[Index], Upper[Index]);
		}
	}

	template<FSize Size, typename Type>
	FVoid ClampInto(TPoint<Size, Type> &Into, const TPoint<Size, Type> &Lhs, const TPoint<Size, Type> &Lower, const TPoint<Size, Type> &Upper)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] = Clamp(Lhs[Index], Lower[Index], Upper[Index]);
		}
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> Clamp(const TPoint<Size, Type> &Lhs, const TPoint<Size, Type> (&Range)[2])
	{
		FSize Index, End;
		TPoint<Size, Type> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = Clamp(Lhs[Index], Range[0][Index], Range[1][Index]);
		}
		return Result;
	}

	template<FSize Size, typename Type>
	FVoid ClampInto(TPoint<Size, Type> &Into, const TPoint<Size, Type> (&Range)[2])
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] = Clamp(Into[Index], Range[0][Index], Range[1][Index]);
		}
	}

	template<FSize Size, typename Type>
	FVoid ClampInto(TPoint<Size, Type> &Into, const TPoint<Size, Type> &Lhs, const TPoint<Size, Type> (&Range)[2])
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] = Clamp(Lhs[Index], Range[0][Index], Range[1][Index]);
		}
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> Clamp(const TPoint<Size, Type> &Lhs, const Type &Lower, const Type &Upper)
	{
		FSize Index, End;
		TPoint<Size, Type> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = Clamp(Lhs[Index], Lower, Upper);
		}
		return Result;
	}

	template<FSize Size, typename Type>
	FVoid ClampInto(TPoint<Size, Type> &Into, const Type &Lower, const Type &Upper)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] = Clamp(Into[Index], Lower, Upper);
		}
	}

	template<FSize Size, typename Type>
	FVoid ClampInto(TPoint<Size, Type> &Into, const TPoint<Size, Type> &Lhs, const Type &Lower, const Type &Upper)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] = Clamp(Lhs[Index], Lower, Upper);
		}
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> Clamp(const TPoint<Size, Type> &Lhs, const Type (&Range)[2])
	{
		FSize Index, End;
		TPoint<Size, Type> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = Clamp(Lhs[Index], Range[0], Range[1]);
		}
		return Result;
	}

	template<FSize Size, typename Type>
	FVoid ClampInto(TPoint<Size, Type> &Into, const Type (&Range)[2])
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] = Clamp(Into[Index], Range[0], Range[1]);
		}
	}

	template<FSize Size, typename Type>
	FVoid ClampInto(TPoint<Size, Type> &Into, const TPoint<Size, Type> &Lhs, const Type (&Range)[2])
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] = Clamp(Lhs[Index], Range[0], Range[1]);
		}
	}

	template<FSize Size, typename Type>
	TPoint<Size, FBoolean> Between(const TPoint<Size, Type> &Lhs, const TPoint<Size, Type> &Lower, const TPoint<Size, Type> &Upper, FBoolean bStrict = True)
	{
		FSize Index, End;
		TPoint<Size, FBoolean> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = Between(Lhs[Index], Lower[Index], Upper[Index], bStrict);
		}
		return Result;
	}

	template<FSize Size, typename Type>
	FVoid BetweenInto(TPoint<Size, FBoolean> &Into, const TPoint<Size, Type> &Lower, const TPoint<Size, Type> &Upper, FBoolean bStrict = True)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] = Between(Into[Index], Lower[Index], Upper[Index], bStrict);
		}
	}

	template<FSize Size, typename Type>
	FVoid BetweenInto(TPoint<Size, FBoolean> &Into, const TPoint<Size, Type> &Lhs, const TPoint<Size, Type> &Lower, const TPoint<Size, Type> &Upper, FBoolean bStrict = True)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] = Between(Lhs[Index], Lower[Index], Upper[Index], bStrict);
		}
	}

	template<FSize Size, typename Type>
	TPoint<Size, FBoolean> Between(const TPoint<Size, Type> &Lhs, const TPoint<Size, Type> (&Range)[2], FBoolean bStrict = True)
	{
		FSize Index, End;
		TPoint<Size, FBoolean> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = Between(Lhs[Index], Range[0][Index], Range[1][Index], bStrict);
		}
		return Result;
	}

	template<FSize Size, typename Type>
	FVoid BetweenInto(TPoint<Size, FBoolean> &Into, const TPoint<Size, Type> (&Range)[2], FBoolean bStrict = True)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] = Between(Into[Index], Range[0][Index], Range[1][Index], bStrict);
		}
	}

	template<FSize Size, typename Type>
	FVoid BetweenInto(TPoint<Size, FBoolean> &Into, const TPoint<Size, Type> &Lhs, const TPoint<Size, Type> (&Range)[2], FBoolean bStrict = True)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] = Between(Lhs[Index], Range[0][Index], Range[1][Index], bStrict);
		}
	}

	template<FSize Size, typename Type>
	TPoint<Size, FBoolean> Between(const TPoint<Size, Type> &Lhs, const Type &Lower, const Type &Upper, FBoolean bStrict = True)
	{
		FSize Index, End;
		TPoint<Size, FBoolean> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = Between(Lhs[Index], Lower, Upper, bStrict);
		}
		return Result;
	}

	template<FSize Size, typename Type>
	FVoid BetweenInto(TPoint<Size, FBoolean> &Into, const Type &Lower, const Type &Upper, FBoolean bStrict = True)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] = Between(Into[Index], Lower, Upper, bStrict);
		}
	}

	template<FSize Size, typename Type>
	FVoid BetweenInto(TPoint<Size, FBoolean> &Into, const TPoint<Size, Type> &Lhs, const Type &Lower, const Type &Upper, FBoolean bStrict = True)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] = Between(Lhs[Index], Lower, Upper, bStrict);
		}
	}

	template<FSize Size, typename Type>
	TPoint<Size, FBoolean> Between(const TPoint<Size, Type> &Lhs, const Type (&Range)[2], FBoolean bStrict = True)
	{
		FSize Index, End;
		TPoint<Size, FBoolean> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = Between(Lhs[Index], Range[0], Range[1], bStrict);
		}
		return Result;
	}

	template<FSize Size, typename Type>
	FVoid BetweenInto(TPoint<Size, FBoolean> &Into, const Type (&Range)[2], FBoolean bStrict = True)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] = Between(Into[Index], Range[0], Range[1], bStrict);
		}
	}

	template<FSize Size, typename Type>
	FVoid BetweenInto(TPoint<Size, FBoolean> &Into, const TPoint<Size, Type> &Lhs, const Type (&Range)[2], FBoolean bStrict = True)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] = Between(Lhs[Index], Range[0], Range[1], bStrict);
		}
	}

	template<FSize Size, typename Type>
	TPoint<Size, FBoolean> IsZeroEps(const TPoint<Size, Type> &Lhs, const Type &Eps, const Type Zero = 0)
	{
		FSize Index, End;
		TPoint<Size, FBoolean> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = IsZeroEps(Lhs[Index], Eps, Zero);
		}
		return Result;
	}

	template<FSize Size, typename Type>
	FVoid IsZeroEpsInto(TPoint<Size, FBoolean> &Into, const TPoint<Size, Type> &Lhs, const Type &Eps, const Type Zero = 0)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] = IsZeroEps(Lhs[Index], Eps, Zero);
		}
	}

	template<FSize Size, typename Type>
	TPoint<Size, FBoolean> IsZeroEps(const TPoint<Size, Type> &Lhs, const TPoint<Size, Type> &Eps, const Type Zero = 0)
	{
		FSize Index, End;
		TPoint<Size, FBoolean> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = IsZeroEps(Lhs[Index], Eps[Index], Zero);
		}
		return Result;
	}

	template<FSize Size, typename Type>
	FVoid IsZeroEpsInto(TPoint<Size, Type> &Into, const TPoint<Size, Type> &Lhs, const TPoint<Size, Type> &Eps, const Type Zero = 0)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] = IsZeroEps(Lhs[Index], Eps[Index], Zero);
		}
	}

	template<FSize Size, typename Type>
	TPoint<Size, FBoolean> IsEqualEps(const TPoint<Size, Type> &Lhs, const TPoint<Size, Type> &Rhs, const Type &Eps)
	{
		FSize Index, End;
		TPoint<Size, FBoolean> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = IsEqualEps(Lhs[Index], Rhs[Index], Eps);
		}
		return Result;
	}

	template<FSize Size, typename Type>
	FVoid IsEqualEpsInto(TPoint<Size, Type> &Into, const TPoint<Size, Type> &Lhs, const TPoint<Size, Type> &Rhs, const Type &Eps)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] = IsEqualEps(Lhs[Index], Rhs[Index], Eps);
		}
	}

	template<FSize Size, typename Type>
	TPoint<Size, FBoolean> IsEqualEpsInto(const TPoint<Size, Type> &Lhs, const TPoint<Size, Type> &Rhs, const TPoint<Size, Type> &Eps)
	{
		FSize Index, End;
		TPoint<Size, FBoolean> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = IsEqualEps(Lhs[Index], Rhs[Index], Eps[Index]);
		}
		return Result;
	}

	template<FSize Size, typename Type>
	FVoid IsEqualEpsInto(TPoint<Size, Type> &Into, const TPoint<Size, Type> &Lhs, const TPoint<Size, Type> &Rhs, const TPoint<Size, Type> &Eps)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] = IsEqualEps(Lhs[Index], Rhs[Index], Eps[Index]);
		}
	}

	template<FSize Size, typename Type>
	TPoint<Size, FBoolean> IsEqualEps(const TPoint<Size, Type> &Lhs, const Type &Rhs, const Type &Eps)
	{
		FSize Index, End;
		TPoint<Size, FBoolean> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = IsEqualEps(Lhs[Index], Rhs, Eps);
		}
		return Result;
	}

	template<FSize Size, typename Type>
	FVoid IsEqualEpsInto(TPoint<Size, FBoolean> &Into, const TPoint<Size, Type> &Lhs, const Type &Rhs, const Type &Eps)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] = IsEqualEps(Lhs[Index], Rhs, Eps);
		}
	}

	template<FSize Size, typename Type>
	TPoint<Size, FBoolean> IsEqualEps(const TPoint<Size, Type> &Lhs, const Type &Rhs, const TPoint<Size, Type> &Eps)
	{
		FSize Index, End;
		TPoint<Size, FBoolean> Result;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Result[Index] = IsEqualEps(Lhs[Index], Rhs, Eps[Index]);
		}
		return Result;
	}

	template<FSize Size, typename Type>
	FVoid IsEqualEpsInto(TPoint<Size, Type> &Into, const TPoint<Size, Type> &Lhs, const Type &Rhs, const TPoint<Size, Type> &Eps)
	{
		FSize Index, End;

		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			Into[Index] = IsEqualEps(Lhs[Index], Rhs, Eps[Index]);
		}
	}

	template<FSize Size, typename Type>
	FBoolean InBound(const TPoint<Size, Type> &Lhs, const TPoint<Size, Type> &Lower, const TPoint<Size, Type> &Upper, FBoolean bStrict = True)
	{
		FSize Index, End;
		FBoolean bInBound;

		bInBound = (Size != 0);
		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			bInBound &= Between(Lhs[Index], Lower[Index], Upper[Index], bStrict);
			if (!bInBound) { return False; }
		}
		return bInBound;
	}

	template<FSize Size, typename Type>
	FBoolean InBound(const TPoint<Size, Type> &Lhs, const TPoint<Size, Type> (&Range)[2], FBoolean bStrict = True)
	{
		FSize Index, End;
		FBoolean bInBound;

		bInBound = (Size != 0);
		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			bInBound &= Between(Lhs[Index], Range[0][Index], Range[1][Index], bStrict);
			if (!bInBound) { return False; }
		}
		return bInBound;
	}

	template<FSize Size, typename Type>
	FBoolean InBound(const TPoint<Size, Type> &Lhs, const Type &Lower, const Type &Upper, FBoolean bStrict = True)
	{
		FSize Index, End;
		FBoolean bInBound;

		bInBound = (Size != 0);
		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			bInBound &= Between(Lhs[Index], Lower, Upper, bStrict);
			if (!bInBound) { return False; }
		}
		return bInBound;
	}

	template<FSize Size, typename Type>
	FBoolean InBound(const TPoint<Size, Type> &Lhs, const Type (&Range)[2], FBoolean bStrict = True)
	{
		FSize Index, End;
		FBoolean bInBound;

		bInBound = (Size != 0);
		End = Size;
		for (Index = 0; Index < End; ++Index)
		{
			bInBound &= Between(Lhs[Index], Range[0], Range[1], bStrict);
			if (!bInBound) { return False; }
		}
		return bInBound;
	}

	template<FSize Size, typename Type>
	TPoint<Size, Type> Spike(Type Value, FSize Index = 0, const Type Zero = 0)
	{
		TPoint<Size, Type> Result;
		/*
		const auto Zero = TAssume<Type>::Zero();
		*/

		if (Index >= Size) { exit(Failure); }
		Result = Zero;
		Result[Index] = Value;
		return Result;
	}

	template<FSize Size, typename Type>
	FVoid SpikeInto(TPoint<Size, Type> &Into, Type Value, FSize Index = 0, const Type Zero = 0)
	{
		/*
		const auto Zero = TAssume<Type>::Zero();
		*/
		if (Index >= Size) { exit(Failure); }
		Into = Zero;
		Into[Index] = Value;
	}



}