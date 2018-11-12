#pragma once

#include <limits.h>
#include <chrono>

#include "NDevTypes.h"

namespace NDev
{
    using namespace Types;

    template<typename Type>
	struct TLimit
	{
		static Type Upper()
		{
			return std::numeric_limits<Type>::max();
		}

		static Type Lower()
		{
			if (std::numeric_limits<Type>::is_bounded)
			{
				return std::numeric_limits<Type>::lowest();
			}
			return std::numeric_limits<Type>::min();
		}

		static Type Epsilon()
		{
			return std::numeric_limits<Type>::epsilon();
		}

		static Type Infinity()
		{
			if (!std::numeric_limits<Type>::has_infinity) { return Type(); }
			return std::numeric_limits<Type>::infinity();
		}

		static Type NaN()
		{
			if (!std::numeric_limits<Type>::has_quiet_NaN) { return Type(); }
			return std::numeric_limits<Type>::quiet_NaN();
		}
	};

	template<typename Type>
	struct TUnit
	{
		static Type Seconds(FTime Time)
		{
			return std::chrono::duration_cast<std::chrono::duration<Type>>(std::chrono::time_point_cast<std::chrono::seconds>(Time).time_since_epoch()).count();
		}

		static Type Seconds(FDuration Time)
		{
			return std::chrono::duration_cast<std::chrono::duration<Type>>(Time).count();;
		}
	};
}
