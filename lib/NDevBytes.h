#pragma once

#include "NDevTypes.h"
#include "NDevDefinitions.h"

namespace NDev
{
	using namespace Types;
	
	enum class EBytes : FEnum
	{
		_Unknown = Unknown,
		LittleEndian,
		MiddleEndian,
		BigEndian,
		_Size
	};

	template<FSize SizeBits, EBytes EnumFrom = EBytes::LittleEndian, FSize SizeBlock = BlockSize>
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