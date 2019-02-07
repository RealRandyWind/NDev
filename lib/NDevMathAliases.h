#pragma once

#include "NDevTypes.h"
#include "NDevPoint.h"
#include <random>

namespace NDev
{
    using namespace Types;

    template<typename Type>
	union TPoint1D
	{
		TPoint<1, Type> Point;
		struct { Type X; };
	};

	template<typename Type>
	union TPoint2D
	{
		TPoint<2, Type> Point;
		struct { Type X, Y; };
	};

	template<typename Type>
	union TPoint3D
	{
		TPoint<3, Type> Point;
		struct { Type X, Y, Z; };
	};

	template<typename Type>
	union TPoint4D
	{
		TPoint<4, Type> Point;
		struct { Type X, Y, Z, W; };
	};

	template<typename Type>
	union TPoint5D
	{
		TPoint<5, Type> Point;
		struct { Type X, Y, Z, W, T; };
	};

	template<typename Type>
	union TPoint6D
	{
		TPoint<6, Type> Point;
		struct { Type X, Y, Z, W, T, E; };
	};

	template<typename Type>
	union TPoint7D
	{
		TPoint<7, Type> Point;
		struct { Type X, Y, Z, W, T, E, R; };
	};

	template<typename Type>
	union TPoint8D
	{
		TPoint<8, Type> Point;
		struct { Type X, Y, Z, W, T, E, R, M; };
	};

	template<typename Type>
	union TPoint9D
	{
		TPoint<9, Type> Point;
		struct { Type X, Y, Z, W, T, E, R, M, Q; };
	};

	template<typename Type>
	union TPoint10D
	{
		TPoint<10, Type> Point;
		struct { Type X, Y, Z, W, T, E, R, M, Q, I; };
	};

	template<typename Type>
	union TPoint11D
	{
		TPoint<11, Type> Point;
		struct { Type X, Y, Z, W, T, E, R, M, Q, I, J; };
	};

	template<typename Type>
	union TColor
	{
		TPoint<4, Type> Point;
		struct { Type R, G, B, A; };
		struct { Type C, M, Y, K; };
		struct { Type H, S; };
		struct { Type V, U; };
	};

	template<typename Type>
	union TComplex
	{
		TPoint<2, Type> Point;
		struct { Type Re, Im; };
	};

	template<typename Type>
	union TSinusoid
	{
		TPoint<3, Type> Point;
		struct { Type A, F, Phi; };
	};

	template<typename Type>
	union TPulse
	{
		TPoint<3, Type> Point;
		struct { Type I, Mu, Sigma; };
	};

	template<typename Type>
	union TQuaternion
	{
		TPoint<4, Type> Point;
		struct { Type One, I, J, K; };
		struct { Type A, B, C, D; };
	};



}
