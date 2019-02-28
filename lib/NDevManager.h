#pragma once

#include "NDevTypes.h"
#include "NDevDefinitions.h"
#include "NDevList.h"

namespace NDev
{
	using namespace Types;

	template<typename Type>
	struct TManager
	{
		struct FInitializer
		{
			using FOnTerminate = TFunction<FBoolean()>;
			using FOnInitialize = TFunction<FBoolean()>;

			FBoolean _bTerminating, _bInitializing, _bInitialized;
			FOnTerminate _OnTerminate;

			FInitializer(FOnInitialize OnInitialize, FOnTerminate OnTerminate)
			{
				_bTerminating = _bInitializing = _bInitialized = False;
				_OnTerminate = OnTerminate;
				if (OnInitialize)
				{
					_bInitializing = True;
					_bInitialized = OnInitialize();
					_bInitializing = False;
				}
			}

			~FInitializer()
			{
				const FBoolean bTerminate = _bInitialized && _OnTerminate && !_bTerminating && !_bInitializing;

				if (bTerminate)
				{
					_bTerminating = True;
					_bInitialized = !_OnTerminate();
					_bTerminating = False;
				}
			}
		};

		static FInitializer _Initializer;
		static TList<Type> _Instances;


	};



}

