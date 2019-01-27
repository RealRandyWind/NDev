#pragma once

#include "NDevTypes.h"
#include "NDevList.h"

namespace NDev
{
	using namespace Types;

	struct FResource;

	struct _FResource
	{
		FSize Id;
		FResource *Pointer;
	};

	struct FResource
	{
		FResource();

		~FResource();

		FSize Id();

		const FSize Id() const;

		static FResource &Reference(FSize);

		static FResource *Pointer(FSize);

		static FSize ResourceCount();

		static FSize ResourceBufferSize();

		static FSize _NextId;
		static FSize _Count;
		static TList<_FResource> _List;

		FSize _Id;


	};

	template<typename Type>
	struct TResource : public FResource
	{
		TResource() : FResource()
		{

		}

		~TResource()
		{

		}


	};

}