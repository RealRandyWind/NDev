#pragma once

#include "NDevTypes.h"
#include "NDevMathAliases.h"
#include "NDevList.h"

namespace NDev
{
	namespace Display
	{
		using namespace Types;
		using namespace Aliases;
	
		struct FWindow
		{
			FReal FieldOfView, AspectRatio, Near, Far;
			FSize _Id, _UpdateCount;
			TSize2D<FSize> Size;
			TPoint2D<FSize> Position;
			FBoolean bFullScreen, bBorderless, bWait, bPerspective, bHold, bUpdate;
			FString Title, Style, Simulation;
			TColor<FReal> Color;
			TTransform3D<FReal> Transform;
			FPointer _State;

			FWindow()
			{
				UseDefault();
			}

			~FWindow()
			{
				if (Style) { Remove(Style); }
				if (Title) { Remove(Title); }
				if (Simulation) { Remove(Simulation); }
			}

			virtual FVoid UseDefault()
			{
				Size.W = 1280;
				Size.H = 720;
				Position.X = Position.Y = 32;
				AspectRatio = static_cast<FReal>(Size.W) * (1.0 / static_cast<FReal>(Size.H));
				bFullScreen = false;
				bBorderless = false;
				bWait = false;
				bPerspective = true;
				bHold = false;
				bUpdate = false;
				Far = 0.1;
				Near = 1000;
				FieldOfView = 35;
				Color.R = Color.G = Color.B = 0.0;
				Color.A = 1.0;
				Transform.Bases = 0.0;
				Transform.Left.X = Transform.Up.Y = Transform.Front.Z = Transform.Origin.W = 1.0;
				Style = NullPtr;
				Title = NullPtr;
				Simulation = NullPtr;
				_Id = 0;
			}

		};

		struct _FWindow
		{
			FVoid Display(const FDescriptor &Buffer, FWindow &Window)
			{
				if (Window._State) { _Update(Window); }
				else { _Make(Buffer, Window); }
			}

			FVoid Update(FWindow &Window)
			{
				if (Window._State) { _Update(Window); }
			}

			FVoid Wait()
			{
				_Wait();
			}

		protected:
			virtual FVoid _Update(FWindow &) = 0;

			virtual FVoid _Make(const FDescriptor &, FWindow &) = 0;

			virtual FVoid _Wait() = 0;

		};


	}


}