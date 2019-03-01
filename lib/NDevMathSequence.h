#include "NDevTypes.h"
#include "NDevMathConstants.h"
#include "NDevDefinitions.h"
#include "NDevSequence.h"

namespace NDev
{
	using namespace Types;

	template<typename Type>
	TSequence<Type> Conv(const TSequence<Type> &Lhs, const TSequence<Type> &Rhs, FBoolean bCircular = False, FBoolean bPadding = False)
	{
		TSequence<Type> Result;

		return Result;
	}

	template<typename Type>
	FVoid ConvInto(TSequence<Type> &Into, const TSequence<Type> &Rhs, FBoolean bCircular = False, FBoolean bPadding = False)
	{

	}

	template<typename Type>
	FVoid ConvInto(TSequence<Type> &Into, const TSequence<Type> &Lhs, const TSequence<Type> &Rhs, FBoolean bCircular = False, FBoolean bPadding = False)
	{

	}

	template<typename Type>
	TSequence<Type> Corr(const TSequence<Type> &Lhs, const TSequence<Type> &Rhs, FBoolean bCircular = False, FBoolean bPadding = False)
	{
		TSequence<Type> Result;

		return Result;
	}

	template<typename Type>
	FVoid CorrInto(TSequence<Type> &Into, const TSequence<Type> &Rhs, FBoolean bCircular = False, FBoolean bPadding = False)
	{

	}

	template<typename Type>
	FVoid CorrInto(TSequence<Type> &Into, const TSequence<Type> &Lhs, const TSequence<Type> &Rhs, FBoolean bCircular = False, FBoolean bPadding = False)
	{

	}

	template<typename Type>
	TSequence<Type> Union(const TSequence<Type> &Lhs, const TSequence<Type> &Rhs)
	{
		TSequence<Type> Result;

		return Result;
	}

	template<typename Type>
	FVoid UnionInto(TSequence<Type> &Into, const TSequence<Type> &Rhs)
	{

	}

	template<typename Type>
	FVoid UnionInto(TSequence<Type> &Into, const TSequence<Type> &Lhs, const TSequence<Type> &Rhs)
	{

	}

	template<typename Type>
	TSequence<Type> Intersection(const TSequence<Type> &Lhs, const TSequence<Type> &Rhs)
	{
		TSequence<Type> Result;

		return Result;
	}

	template<typename Type>
	FVoid IntersectionInto(TSequence<Type> &Into, const TSequence<Type> &Rhs)
	{

	}

	template<typename Type>
	FVoid IntersectionInto(TSequence<Type> &Into, const TSequence<Type> &Lhs, const TSequence<Type> &Rhs)
	{

	}

	template<typename Type>
	TSequence<Type> Complement(const TSequence<Type> &Lhs, const TSequence<Type> &Rhs)
	{
		TSequence<Type> Result;

		return Result;
	}

	template<typename Type>
	FVoid ComplementInto(TSequence<Type> &Into, const TSequence<Type> &Rhs)
	{
		
	}

	template<typename Type>
	FVoid ComplementInto(TSequence<Type> &Into, const TSequence<Type> &Lhs, const TSequence<Type> &Rhs)
	{

	}

	template<typename Type>
	TSequence<Type> & Difference(const TSequence<Type> &Lhs, const TSequence<Type> &Rhs)
	{
		TSequence<Type> Result;

		return Result;
	}

	template<typename Type>
	TSequence<Type> DifferenceInto(TSequence<Type> &Into, const TSequence<Type> &Rhs)
	{

	}

	template<typename Type>
	TSequence<Type> DifferenceInto(TSequence<Type> &Into, const TSequence<Type> &Lhs, const TSequence<Type> &Rhs)
	{

	}

	

}