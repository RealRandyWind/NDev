#pragma once

#include "NDevTypes.h"

namespace NDev
{
	using namespace Types;

    template<typename TypeData>
    struct TIterator
    {
        TypeData & operator[](FSize Index)
		{
			return _Data[Index];
		}

		const TypeData & operator[](FSize Index) const
		{
			return _Data[Index];
		}

		TIterator<TypeData> & begin()
		{
			return &_Data[0];
		}

		const TIterator<TypeData> & begin() const
		{
			return &_Data[0];
		}

		TIterator<TypeData> & end()
		{
			return &_Data[SizeData];
		}

		const TIterator<TypeData> & end() const
		{
			return &_Data[SizeData];
		}

        
    };



}