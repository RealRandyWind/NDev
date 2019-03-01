#pragma once

#ifdef NDEVDLL_EXPORTS
#define NDEVDLL_EXPORTS __declspec(dllexport)
#else
#define NDEVDLL_EXPORTS __declspec(dllimport)
#endif

#include "NDev.h"

namespace NDev
{
		struct NDEVDLL_EXPORTS FResource;

		struct NDEVDLL_EXPORTS _FPointer;

		template struct NDEVDLL_EXPORTS TSequence<_FResource>;

		template struct NDEVDLL_EXPORTS TList<_FPointer::FEntry>;


}
