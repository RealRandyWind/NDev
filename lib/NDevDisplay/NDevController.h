#pragma once

#include "NDevTypes.h"

namespace NDev
{
	namespace Display
	{
		using namespace Types;

		struct FControler
		{
			FBoolean _bInitialized;

			FControler()
			{
				UseDefaultParameters();
			}

			~FControler() { }

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