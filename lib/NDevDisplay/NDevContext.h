#pragma once

#include "NDevTypes.h"
#include "NDevStyle.h"
#include "NDevWindow.h"

namespace NDev
{
	namespace Display
	{
		struct FContext
		{
			FBoolean _bInitialized;
			FReturn _ErrorNo;

			FContext()
			{
				_bInitialized = False;
				_ErrorNo = Success;
			}

			~FContext() { }

			FBoolean Initialized() const
			{
				return _bInitialized;
			}
			
			FVoid Initialize()
			{
				if (_bInitialized) { return; }
				_Initialize();
				_bInitialized = True;
			}

			FVoid Terminate()
			{
				if (!_bInitialized) { return; }
				_Terminate();
				_bInitialized = False;
			}

			FVoid Render(const FWindow &Window, const FStyle &Style)
			{
				_Render(Window, Style);
			}

		protected:
			virtual FVoid _Initialize() = 0;

			virtual FVoid _Terminate() = 0;

			virtual FVoid _Render(const FWindow &, const FStyle &) = 0;


		};



	}



}