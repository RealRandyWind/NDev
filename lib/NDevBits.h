#pragma once

#include "NDevTypes.h"
#include "NDevDefinitions.h"

namespace NDev
{
	using namespace Types;
	
    template<FSize SizeBytes>
    struct TBytes
	{
		FByte _Data[SizeBytes];

		static TBytes<SizeBytes> Like()
		{
			TBytes<SizeBytes> Result;
			return Result;
		}
    };
	
}