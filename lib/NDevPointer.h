#pragma once

#include "NDevTypes.h"
#include "NDevDefinitions.h"

namespace NDev
{
	using namespace Types;

	template<typename TypeValue>
	struct TPointer
	{
		enum class EPointer
		{
			_Unknown = Unknown,
			Weak,
			Strong,
			Unique,
			_Size
		};
	};

}