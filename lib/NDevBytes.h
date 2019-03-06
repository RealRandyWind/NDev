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

	template<FSize SizeBytes, EBytes EnumFrom = EBytes::LittleEndian, EBytes EnumTo = EBytes::LittleEndian, FSize SizeBlockFrom = BlockSize, FSize SizeBlockTo = BlockSize>
    struct TBytes
	{
		using FType = TBytes<SizeBytes, EnumFrom, EnumTo, SizeBlockFrom, SizeBlockTo>;

		FByte _Data[SizeBytes];

		template<typename TypeLhs>
		operator TypeLhs()
		{
			TypeLhs Lhs;

			return Lhs;
		}

		static FType Like()
		{
			return FType();
		}
    };
	
}