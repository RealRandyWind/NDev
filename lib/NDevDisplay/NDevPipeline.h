#pragma once

#include "NDevTypes.h"
#include "NDevSequence.h"
#include "NDevIterator.h"
#include "NDevAlgorithm.h"
#include "NDevShader.h"

namespace NDev
{
	namespace Display
	{
		using namespace Types;

		struct _FPipeline
		{
			TSequence<FShader> _Shaders;

		};

		template<typename TypeInput, typename TypeOutput>
		struct TPipeline : public TAlgorithm<TypeInput, TypeOutput>, public _FPipeline
		{

		};

		struct _FContext
		{
			FVoid Render(const _FPipeline &Pipeline, FBoolean bClear = True, FBoolean bQueue = False)
			{
				_Render(Pipeline, bClear, bQueue);
			}

		protected:
			virtual FVoid _Render(const _FPipeline &, FBoolean, FBoolean) = 0;


		};

	}



}