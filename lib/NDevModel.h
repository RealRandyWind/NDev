#pragma once

#include "NDevTypes.h"
#include "NDevResource.h"
#include "NDevPoint.h"
#include "NDevData.h"
#include "NDevMathExtend.h"
#include "NDevMathPoint.h"

namespace NDev
{
	using namespace Types;

	template<FSize SizeFeature, FSize SizeLabel>
	struct TModel : public FResource
	{
		using FFeature = TPoint<SizeFeature, FReal>;

		using FLabel = TPoint<SizeLabel, FReal>;

		struct FSample
		{
			FFeature Feature;
			FLabel Label;
		};

		struct FError
		{
			FLabel Value, Label;
			FReal Weight, Epsilon;
			FSize WorkerID, Significance;
			FDuration Time;
		};

		using FOnUse = TFunction<FVoid(const FFeature &, const FLabel &)>;

		using FOnTrain = TFunction<FVoid(const FLabel &, const FSample &)>;

		using FOnOptimize = TFunction<FVoid(const FSample &)>;

		using FOnValidate = TFunction<FVoid(const FSample &, const FError &)>;

		FOnUse OnUse;
		FOnTrain OnTrain;
		FOnOptimize OnOptimize;
		FOnValidate OnValidate;
		FBoolean _bInitialized;

		TModel()
		{
			_bInitialized = False;
			OnUse = NullPtr;
			OnTrain = NullPtr;
			OnOptimize = NullPtr;
			OnValidate = NullPtr;
			UseDefaultParameters();
		}

		~TModel() { }

		FBoolean Initialized()
		{
			return _bInitialized;
		}

		const FBoolean Initialized() const
		{
			return _bInitialized;
		}

		FSize FeatureSize()
		{
			return SizeFeature;
		}

		const FSize FeatureSize() const
		{
			return SizeFeature;
		}

		FSize LabelSize()
		{
			return SizeLabel;
		}

		const FSize LabelSize() const
		{
			return SizeLabel;
		}

		FVoid Initialize()
		{
			_bInitialized = False;
			_Initialize();
			_bInitialized = True;
		}

		FVoid Train(const TData<FSample> &Samples)
		{
			FLabel Label;

			if (!_bInitialized) { return; }

			for (const auto &Sample : Samples)
			{
				_Use(Sample.Feature, Label, True);
				_Train(Label, Sample);
			}
		}

		FVoid Train(const TIterator<FSample> &Samples)
		{
			FLabel Label;

			if (!_bInitialized) { return; }

			for (const auto &Sample : Samples)
			{
				_Use(Sample.Feature, Label, True);
				_Train(Label, Sample);
			}
		}

		FVoid Use(const TData<FFeature> &Features, TData<FLabel> &Labels)
		{
			FSize Index, End;

			if (!_bInitialized) { return; }

			End = Features.Size();
			Labels.Reserve(End, True);
			for (Index = 0; Index < End; ++Index)
			{
				_Use(Features[Index], Labels[Index]);
			}
		}

		FVoid Validate(const TData<FSample> &Samples, TData<FError> &Errors)
		{
			FTime Start;
			FSize Index, End;

			if (!_bInitialized) { return; }

			End = Samples.Size();
			Errors.Reserve(End, True);
			for (Index = 0; Index < End; ++Index)
			{
				const auto &Sample = Samples[Index];
				auto &Error = Errors[Index];
				Start = FClock::now();
				_Use(Sample.Feature, Error.Label);
				Error.Time = (FClock::now() - Start);
				_Validate(Sample, Error);
			}
		}

		FVoid Optimize(const TData<FSample> &Samples)
		{
			if (!_bInitialized) { return; }

			for (const auto &Sample : Samples)
			{
				_Optimize(Sample);
			}
		}

		FVoid Optimize()
		{
			if (!_bInitialized) { return; }

			_Optimize();
		}

		virtual FVoid UseDefaultParameters() { }

	protected:
		virtual FVoid _Initialize() = 0;

		virtual FVoid _Use(const FFeature &, FLabel &, FBoolean = False) = 0;

		virtual FVoid _Train(const FLabel &, const FSample &) = 0;

		virtual FVoid _Optimize(const FSample &) { }

		virtual FVoid _Optimize() { }

		virtual FVoid _Validate(const FSample &Sample, FError &Error)
		{
			Error.Value = Sample.Label - Error.Label;
			Error.Weight = 1;
			Error.WorkerID = 0; 
			Error.Epsilon = TLimit<FReal>::Epsilon();
			Error.Significance = TLimit<FSize>::Infinity();
			if (OnValidate) { OnValidate(Sample, Error); }
		}


	};



}