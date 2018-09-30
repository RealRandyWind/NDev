#pragma once

#include "NDevTypes.h"
#include "NDevDefinitions.h"

namespace NDev
{
	using namespace Types;
	
    template<typename ... TypeAttributes>
    struct TRecord
	{
		template<typename Type>
		struct TExpand;

		template<typename ... Types>
		struct TExpand<Types>
		{
			static const FSize Size = TExpand<Types ...>::Size + sizeof(Types ...);
		};

		using FExpand = TExpand<TypeAttributes ...>;

		FByte *_Data[FExpand::Size];

		FSize Size()
		{
			return sizeof...(TypeAttributes);
		}

		const FSize Size() const
		{
			return sizeof...(TypeAttributes);
		}

    };
	
}