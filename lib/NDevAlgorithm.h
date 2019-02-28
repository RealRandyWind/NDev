#pragma once

#include "NDevTypes.h"
#include "NDevData.h"
#include "NDevResource.h"

namespace NDev
{
	using namespace Types;

	template<typename TypeInput, typename TypeOutput>
	struct TAlgorithm : public FResource
	{
		using FInput = TypeInput;
		
		using FOutput = TypeOutput;

		using FOnUse = TFunction<FVoid(const FInput &, const FOutput &)>;

		FOnUse OnUse;
		FBoolean _bInitialized;

		TAlgorithm()
		{
			_bInitialized = False;
			OnUse = NullPtr;
			UseDefaultParameters();
		}

		~TAlgorithm() { }

		FBoolean Initialized()
		{
			return _bInitialized;
		}

		const FBoolean Initialized() const
		{
			return _bInitialized;
		}

		FSize InputSize()
		{
			return sizeof(FInput);
		}

		const FSize InputSize() const
		{
			return sizeof(FInput);
		}

		FSize OutputSize()
		{
			return sizeof(FOutput);
		}

		const FSize OutputSize() const
		{
			return sizeof(FOutput);
		}

		FVoid Initialize()
		{
			_bInitialized = False;
			_Initialize();
			_bInitialized = True;
		}

		FVoid Use(const TData<FInput> &Inputs, TData<FOutput> &Outputs)
		{
			FSize Index, End;

			if (!_bInitialized) { return; }

			End = Inputs.Size();
			Outputs.Reserve(End, True);
			for (Index = 0; Index < End; ++Index)
			{
				_Use(Inputs[Index], Outputs[Index]);
			}
		}

		FVoid Use(const FInput &Input, FOutput &Output)
		{
			if (!_bInitialized) { return; }

			_Use(Input, Output);
		}

		virtual FVoid UseDefaultParameters() { };

	protected:
		virtual FVoid _Initialize() { };

		virtual FVoid _Use(const FInput &, FOutput &) = 0;


	};



}