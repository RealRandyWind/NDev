#pragma once

#include "NDevTypes.h"
#include "NDevMathAliases.h"
#include "NDevDefinitions.h"

namespace NDev
{
	using namespace Types;
	
    struct FWindow
	{
		FReal LookSpeed, MoveSpeed, FieldOfView, AspectRatio, Near, Far;
		FSize Width, Height, X, Y;
		FBoolean bFullScreen, bBorderless, bWait, bPerspective, bHold, bUpdate;
		FString Title, Style, Simulation;
		NDev::TColor<FReal> Color;
		NDev::TPoint3D<FReal> LookAt, Position, Up;

		virtual FVoid UseDefault()
		{
			Width = 1280;
			Height = 720;
			X = Y = 32;
			AspectRatio = static_cast<FReal>(Width) * (1.0 / static_cast<FReal>(Height));
			bFullScreen = false;
			bBorderless = false;
			bWait = false;
			bPerspective = true;
			bHold = false;
			bUpdate = false;
			Far = 0.1;
			Near = 1000;
			FieldOfView = 35;
			LookSpeed = 180;
			MoveSpeed = 50;
			Color.R = Color.G = Color.B = 0.0;
			Color.A = 1.0;
			LookAt.X = LookAt.Y = LookAt.Z = 0.0;
			Position.X = Position.Y = 0.0;
			Position.Z = 40.0;
			Up.X = Up.Z = 0.0;
			Up.Y = 1.0;
			Style = NullPtr;
			Title = NullPtr;
			Simulation = NullPtr;
		}
    };
	
	

}