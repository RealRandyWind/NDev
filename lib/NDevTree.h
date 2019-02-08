#pragma once

#include "NDevTypes.h"
#include "NDevDefinitions.h"
#include "NDevSequence.h"
#include "NDevPoint.h"

namespace NDev
{
	using namespace Types;

	template<FSize SizeData, typename TypeValue>
	struct TTree
	{
		TSequence<TPoint<SizeData, TypeValue>> _Points, _Data;
		TSequence<FSize> _Nodes

		TTree()
		{
			
		}


		~TTree()
		{

		}

	};



}