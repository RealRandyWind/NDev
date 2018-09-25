#pragma once

#include "NDevTypes.h"

namespace NDev
{
	namespace Templates
	{
		using namespace Types;

		template<FSize Bytes, FSize Index, typename Type, typename ... TypeAttributes>
		struct _TExpand
		{
			using FExpand = _TExpand<Bytes + sizeof(Type), Index + 1, TypeAttributes ...>;
		};

	}



}