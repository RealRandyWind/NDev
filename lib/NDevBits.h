#pragma once

#include "NDevTypes.h"
#include "NDevDefinitions.h"

namespace NDev
{
	using namespace Types;

    template<FSize SizeBits>
    struct TBits
	{
		FByte _Data[SizeBits];

		static TBits<SizeBits> Like()
		{
			TBits<SizeBits> Result;
			return Result;
		}
    };
	
}