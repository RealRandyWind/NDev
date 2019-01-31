#pragma once

#include "NDevTypes.h"
#include "NDevDefinitions.h"
#include "NDevSequence.h"
#include "NDevPoint.h"

namespace NDev
{
	using namespace Types;

	template<FSize SizeData, typename TypeValue>
	struct TKDTree
	{
		using FPoint = typename TPoint<SizeData, TypeValue>;
		
		struct FNode
		{
			FPoint Value;
			FNode * Left, * Right;
		};

		TKDTree()
		{
			
		}


		~TKDTree()
		{

		}

	};



}