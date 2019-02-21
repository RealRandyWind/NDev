#pragma once

#include "NDevTypes.h"
#include "NDevSequence.h"

namespace NDev
{
	namespace Display
	{
		using namespace Types;

		struct FShader
		{
			enum class EType
			{
				_Unknown = Unknown,
				Vertex,
				TessellationControl,
				TessellationEvaluation,
				Geometry,
				Fragment,
				Compute,
				_Size
			};

			struct FArgument
			{
				FSize Id;
				FBoolean bConstant, bInput, bOutput;
				FString Name;
				FDescriptor Descriptor;
			};

			EType Type;
			FSize Id, Priority, Layer;
			FBoolean bBinary;
			FString Name;
			TSequence<FArgument> Arguments;


		};




	}



}