#pragma once

#include "NDevTypes.h"
#include "NDevWindow.h"
#include "NDevPipeline.h"

namespace NDev
{
	namespace Display
	{
		using namespace Types;

		struct _FVulkan : _FContext
		{
			virtual FVoid _Render(const _FPipeline&, FBoolean, FBoolean) override
			{

			}

			virtual FBoolean _Initialize() override
			{

			}

			virtual FBoolean _Deinitialize() override
			{

			}
		};
	}
}