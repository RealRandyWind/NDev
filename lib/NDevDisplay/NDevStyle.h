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
			FBoolean _bInitialized;
			TSequence<FShader> Shaders;

			FStyle()
			{
				UseDefaultParameters();
			}

			~FStyle() { }

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



	}



}