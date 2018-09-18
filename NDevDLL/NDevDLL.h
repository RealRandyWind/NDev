#pragma once

#ifdef NDEVDLL_EXPORTS
#define NDEVDLL_EXPORTS __declspec(dllexport)
#else
#define NDEVDLL_EXPORTS __declspec(dllimport)
#endif

#include "NDev.h"

namespace NDev
{
		class NDEVDLL_EXPORTS CResource;

		template struct NDEVDLL_EXPORTS TSequence<_FResource>;
}
