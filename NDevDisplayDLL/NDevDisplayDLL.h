#pragma once

#ifdef NDEVDISPLAYDLL_EXPORTS
#define NDEVDISPLAYDLL_EXPORTS __declspec(dllexport)
#else
#define NDEVDISPLAYDLL_EXPORTS __declspec(dllimport)
#endif

#include "NDevDisplay/NDevDisplay.h"

namespace NDev
{
	namespace Display
	{
		struct NDEVDISPLAYDLL_EXPORTS FWindow;

		struct NDEVDISPLAYDLL_EXPORTS FShader;

		struct NDEVDISPLAYDLL_EXPORTS FContext;

		struct NDEVDISPLAYDLL_EXPORTS FControler;



	}



}
