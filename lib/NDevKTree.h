#pragma once

#include "NDevTypes.h"
#include "NDevDefinitions.h"
#include "NDevSequence.h"
#include "NDevPoint.h"

namespace NDev
{
	using namespace Types;

	template<FSize SizeData, typename TypeData>
	struct TKTree
	{
		TSequence<TPoint<SizeData, TypeData>> _Points, _Data;
		TSequence<FSize> _Nodes

		TKTree()
		{
			
		}


		~TKTree()
		{

		}

	};



}