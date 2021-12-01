#pragma once

#include "NDevTypes.h"
#include "NDevReferences.h"
#include "NDevDefinitions.h"
#include "NDevSequence.h"
#include "NDevPoint.h"

namespace NDev
{
	using namespace Types;

	template<FSize SizePoint, typename TypeValue>
	struct TKDTree
	{
		using FPoint = typename TPoint<SizePoint, TypeValue>;

		struct _FNode
		{
			FPoint Position;
			_FNode *Parent;
			TReferences<SizePoint, _FNode> Children;
		};

		TSequence<_FNode> _Nodes;
		TSequence<FPoint> _Points;

	};



}
