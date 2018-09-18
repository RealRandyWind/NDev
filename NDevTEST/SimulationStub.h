#pragma once;

#include "NDev.h"

namespace NDevTest
{
	using namespace NDev;
	using namespace NDev::Types;

	template<FSize SizePoint>
	struct TSimulationStub : TSimulation<SizePoint>
	{
		using FSimulation = TSimulation<SizePoint>;

		struct FParameters
		{
			FReal Alpha, Weight;
			FSize Size;
		};

		struct FState
		{
			TSequence<typename FSimulation::FPoint> Space;
		};

		FParameters Parameters;
		FState State;


	protected:
		virtual FVoid _Initialize() override
		{
			State.Space.Reserve(Parameters.Size, True);
			for (auto &Point : State.Space)
			{
				Point = Parameters.Alpha;
			}
		}

		virtual FVoid _Step(TData<typename FSimulation::FPoint> &Result) override
		{
			for (auto &Point : State.Space)
			{
				Point += Parameters.Weight;
			}
			if (this->NSteps() >= Parameters.Size) { this->Stop(); }
		}

		virtual FVoid _Result(TData<typename FSimulation::FPoint> &Result) override
		{
			Result.Data(State.Space.Descriptor());
		}


	};



}