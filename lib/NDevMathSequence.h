#include "NDevTypes.h"
#include "NDevMathConstants.h"
#include "NDevDefinitions.h"
#include "NDevSequence.h"

namespace NDev
{
	using namespace Types;


	template<typename Type>
	TSequence<Type> Conv(const TSequence<Type> &Lhs, const TSequence<Type> &Rhs, FBoolean bCircular = False)
	{
		TSequence<Type> Result;

		return Result;
	}

	template<typename Type>
	FVoid ConvInto(TSequence<Type> &Lhs, const TSequence<Type> &Rhs, FBoolean bCircular = False)
	{

	}

	template<typename Type>
	TSequence<Type> Corr(const TSequence<Type> &Lhs, const TSequence<Type> &Rhs, FBoolean bCircular = False)
	{
		TSequence<Type> Result;

		return Result;
	}

	template<typename Type>
	FVoid CorrInto(TSequence<Type> &Lhs, const TSequence<Type> &Rhs, FBoolean bCircular = False)
	{

	}



}