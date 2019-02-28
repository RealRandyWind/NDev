#pragma once

#include "NDevTypes.h"
#include "NDevSequence.h"
#include "NDevIterator.h"
#include "NDevShader.h"

namespace NDev
{
	namespace Display
	{
		using namespace Types;

		struct FPipeline
		{
			FBoolean _bInitialized;
			TSequence<FShader> Shaders;

			FPipeline()
			{
				_bInitialized = False;
				UseDefaultParameters();
			}

			~FPipeline() { }

			FBoolean Initialized()
			{
				return _bInitialized;
			}

			const FBoolean Initialized() const
			{
				return _bInitialized;
			}

			FVoid Initialize()
			{
				_bInitialized = False;
				_Initialize();
				_bInitialized = True;
			}

			virtual FVoid UseDefaultParameters() { };

		protected:
			virtual FVoid _Initialize() { };


		};

		struct _FContext
		{
			FVoid Render(const FPipeline &Pipeline, FBoolean bClear = True)
			{
				_Render(Pipeline, bClear);
			}

		protected:
			virtual FVoid _Render(const FPipeline &, FBoolean) = 0;


		};

	}



}