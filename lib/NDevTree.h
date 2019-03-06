#pragma once

#include "NDevTypes.h"
#include "NDevDefinitions.h"
#include "NDevSequence.h"
#include "NDevReferences.h"

namespace NDev
{
	using namespace Types;

	template<typename TypeValue, FSize SizeNodes = 2>
	struct TTree
	{
		using FValue = TypeValue;

		struct _FNode
		{
			FSize Index;
			_FNode *Parent;
			union
			{
				TReferences<SizeNodes, _FNode> Children;
			};
		};

		TSequence<TypeValue> _Data;
		TSequence<_FNode> _Nodes

		TTree()
		{
			
		}


		~TTree()
		{

		}

	};



}