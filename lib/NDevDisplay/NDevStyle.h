#pragma once

#include "NDevTypes.h"
#include "NDevSequence.h"
#include "NDevShader.h"

namespace NDev
{
	namespace Display
	{
		using namespace Types;

		struct FStyle
		{
			TSequence<FShader> Pipeline;
		};

	}



}