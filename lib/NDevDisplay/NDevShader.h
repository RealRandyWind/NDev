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
			enum class EType : FEnum
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
				FBoolean bConstant, bInput, bOutput, bStream;
				FString Name;
				FDescriptor Descriptor;
			};

			EType Type;
			FSize Id, Priority, Layer;
			FBoolean bBinary, bPriority;
			FString Name;
			TSequence<FArgument> Arguments;


		};



	}



}