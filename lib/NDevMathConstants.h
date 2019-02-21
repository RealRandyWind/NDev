#pragma once

#include "NDevTypes.h"

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

	template<typename Type>
	struct TConstant
	{
		static Type Pi() { return Constants::Pi; }

		static Type Pi2() { return Constants::Pi2; }

		static Type Pi3() { return Constants::Pi3; }

		static Type ByPi() { return Constants::ByPi; }

		static Type PiBy2() { return Constants::PiBy2; }

		static Type PiBy3() { return Constants::PiBy3; }

		static Type Phi() { return Constants::PhiBy2; }

		static Type ByPhi() { return Constants::ByPhi; }

		static Type E() { return Constants::E; }

		static Type ByE() { return Constants::ByE; }

		static Type Sqrt2() { return Constants::Sqrt2; }

		static Type BySqrt2() { return Constants::BySqrt2; }

		static Type Sqrt3() { return Constants::Sqrt3; }

		static Type BySqrt3() { return Constants::BySqrt3; }


	};



}