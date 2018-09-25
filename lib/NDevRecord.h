#pragma once

#include "NDevTypes.h"

namespace NDev
{
	using namespace Types;

    template<typename ... TypeAttributes>
    struct TRecord
    {
		FByte[sizeof(TypeAttributes)]

		FSize Size()
		{
			return sizeof(TypeAttributes);
		}

		const FSize Size() const
		{
			return sizeof(TypeAttributes);
		}
        

    };
}