#pragma once

#include "NDevTypes.h"
#include "NDevPoint.h"
#include "NDevBases.h"

namespace NDev
{
    using namespace Types;

	namespace Aliases
	{
		template<typename Type>
		union TPoint1D
		{
			TPoint<1, Type> Point;
			struct { Type X; };
			struct { Type A; };
		};

		template<typename Type>
		union TPoint2D
		{
			TPoint<2, Type> Point;
			struct { Type X, Y; };
			struct { Type A, B; };
		};

		template<typename Type>
		union TPoint3D
		{
			TPoint<3, Type> Point;
			struct { Type X, Y, Z; };
			struct { Type A, B, C; };
		};

		template<typename Type>
		union TPoint4D
		{
			TPoint<4, Type> Point;
			struct { Type X, Y, Z, W; };
			struct { Type A, B, C, D; };
		};

		template<typename Type>
		union TPoint5D
		{
			TPoint<5, Type> Point;
			struct { Type X, Y, Z, W, T; };
			struct { Type A, B, C, D; };
		};

		template<typename Type>
		union TPoint6D
		{
			TPoint<6, Type> Point;
			struct { Type X, Y, Z, W, T, E; };
			struct { Type A, B, C, D; };
		};

		template<typename Type>
		union TPoint7D
		{
			TPoint<7, Type> Point;
			struct { Type X, Y, Z, W, T, E, R; };
			struct { Type A, B, C, D; };
		};

		template<typename Type>
		union TPoint8D
		{
			TPoint<8, Type> Point;
			struct { Type X, Y, Z, W, T, E, R, M; };
			struct { Type A, B, C, D; };
		};

		template<typename Type>
		union TPoint9D
		{
			TPoint<9, Type> Point;
			struct { Type X, Y, Z, W, T, E, R, M, Q; };
			struct { Type A, B, C, D; };
		};

		template<typename Type>
		union TPoint10D
		{
			TPoint<10, Type> Point;
			struct { Type X, Y, Z, W, T, E, R, M, Q, I; };
			struct { Type A, B, C, D; };
		};

		template<typename Type>
		union TPoint11D
		{
			TPoint<11, Type> Point;
			struct { Type X, Y, Z, W, T, E, R, M, Q, I, J; };
			struct { Type A, B, C, D; };
		};

		template<typename Type>
		union TBases1D
		{
			TBases<1, 1, Type> Bases;
			TPoint<1, Type> Points[1];
			struct { TPoint1D<Type> V1; };
			struct { Type A; };
			struct { Type A11; };
		};

		template<typename Type>
		union TBases2D
		{
			TBases<2, 2, Type> Bases;
			TPoint<3, Type> Points[2];
			struct { TPoint1D<Type> V1, V2; };
			struct { Type A, B, C, D; };
			struct { Type A11, A21, A12, A22; };
		};

		template<typename Type>
		union TBases3D
		{
			TBases<3, 3, Type> Bases;
			TPoint<4, Type> Points[3];
			struct { TPoint1D<Type> V1, V2, V3; };
			struct { Type A, B, C, D, E, F, G, H, I; };
			struct { Type A11, A21, A31, A12, A22, A32, A13, A23, A33; };
		};

		template<typename Type>
		union TBases4D
		{
			TBases<4, 4, Type> Bases;
			TPoint<4, Type> Points[4];
			struct { TPoint1D<Type> V1, V2, V3, V4; };
			struct { Type A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P; };
			struct { Type A11, A21, A31, A41, A12, A22, A32, A42, A13, A23, A33, A43, A14, A24, A34, A44; };
		};

		template<typename Type>
		union TBases5D
		{
			TBases<5, 5, Type> Bases;
			TPoint<5, Type> Points[5];
			struct { TPoint1D<Type> V1, V2, V3, V4, V5; };
			struct { Type A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y; };
			struct { Type A11, A21, A31, A41, A51, A12, A22, A32, A42, A52, A13, A23, A33, A43, A53, A14, A24, A34, A44, A54, A15, A25, A35, A45, A55; };
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
		union TPerplex
		{
			TPoint<2, Type> Point;
			struct { Type Re, Hyp; };
		};

		template<typename Type>
		union TDual
		{
			TPoint<2, Type> Point;
			struct { Type Re, Eps; };
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
			struct { Type W, X, Y, Z; };
			struct { Type A, B, C, D; };
		};

		template<typename Type>
		union TSize1D
		{
			TPoint<1, Type> Point;
			struct { Type W; };
			struct { Type Width; };
		};

		template<typename Type>
		union TSize2D
		{
			TPoint<2, Type> Point;
			struct { Type W, H; };
			struct { Type Width, Height; };
		};

		template<typename Type>
		union TSize3D
		{
			TPoint<3, Type> Point;
			struct { Type W, H, D; };
			struct { Type Width, Height, Depth; };
		};

		template<typename Type>
		union TSize4D
		{
			TPoint<4, Type> Point;
			struct { Type W, H, D, L; };
			struct { Type Width, Height, Depth, Duration; };
		};

		template<typename Type>
		union TBin
		{
			TPoint<2, Type> Point;
			struct { Type A, B; };
			struct { Type B, E; };
			struct { Type Begin, End; };
		};

		template<FSize SizePoint, typename Type>
		union TBinND
		{
			TBases<SizePoint, 2, Type> Bases;
			TPoint<SizePoint, Type> Points[2];
			struct { TPoint<SizePoint, Type> A, B; };
			struct { TPoint<SizePoint, Type> B, E; };
			struct { TPoint<SizePoint, Type> Begin, End; };
		};

		template<typename Type>
		union TBin1D
		{
			TBases<1, 2, Type> Bases;
			TPoint<1, Type> Points[2];
			struct { TPoint<1, Type> A, B; };
			struct { TPoint<1, Type> B, E; };
			struct { TPoint<1, Type> Begin, End; };
		};

		template<typename Type>
		union TBin2D
		{
			TBases<2, 2, Type> Bases;
			TPoint<2, Type> Points[2];
			struct { TPoint<2, Type> A, B; };
			struct { TPoint<2, Type> B, E; };
			struct { TPoint<2, Type> Begin, End; };
		};

		template<typename Type>
		union TBin3D
		{
			TBases<3, 2, Type> Bases;
			TPoint<3, Type> Points[2];
			struct { TPoint<3, Type> A, B; };
			struct { TPoint<3, Type> B, E; };
			struct { TPoint<3, Type> Begin, End; };
		};

		template<typename Type>
		union TBin4D
		{
			TBases<4, 2, Type> Bases;
			TPoint<4, Type> Points[2];
			struct { TPoint<4, Type> A, B; };
			struct { TPoint<4, Type> B, E; };
			struct { TPoint<4, Type> Begin, End; };
		};

		template<typename Type>
		union TRange
		{
			TPoint<2, Type> Point;
			struct { Type A, B; };
			struct { Type Min, Max; };
			struct { Type From, To; };
		};

		template<FSize SizePoint, typename Type>
		union TRangeND
		{
			TBases<SizePoint, 2, Type> Bases;
			TPoint<SizePoint, Type> Points[2];
			struct { TPoint<SizePoint, Type> A, B; };
			struct { TPoint<SizePoint, Type> Min, Max; };
			struct { TPoint<SizePoint, Type> From, To; };
		};

		template<typename Type>
		union TRange1D
		{
			TBases<1, 2, Type> Bases;
			TPoint<1, Type> Points[2];
			struct { TPoint<1, Type> A, B; };
			struct { TPoint<1, Type> Min, Max; };
			struct { TPoint<1, Type> From, To; };
		};

		template<typename Type>
		union TRange2D
		{
			TBases<2, 2, Type> Bases;
			TPoint<2, Type> Points[2];
			struct { TPoint<2, Type> A, B; };
			struct { TPoint<2, Type> Min, Max; };
			struct { TPoint<2, Type> From, To; };
		};

		template<typename Type>
		union TRange3D
		{
			TBases<3, 2, Type> Bases;
			TPoint<3, Type> Points[2];
			struct { TPoint<3, Type> A, B; };
			struct { TPoint<3, Type> Min, Max; };
			struct { TPoint<3, Type> From, To; };
		};

		template<typename Type>
		union TRange4D
		{
			TBases<4, 2, Type> Bases;
			TPoint<4, Type> Points[2];
			struct { TPoint<4, Type> A, B; };
			struct { TPoint<4, Type> Min, Max; };
			struct { TPoint<4, Type> From, To; };
		};

		template<FSize SizePoint, typename Type>
		union TTransform
		{
			TBases<SizePoint + 1, SizePoint + 1, Type> Bases;
			TPoint<SizePoint + 1, Type> Points[SizePoint + 1];
			struct { TPoint<SizePoint, Type> _Padding[SizePoint], Origin; };
		};

		template<typename Type>
		union TTransform1D
		{
			TBases<2, 2, Type> Bases;
			TPoint2D<Type> Points[2];
			struct { TPoint2D<Type> _Padding[1], Origin; };
			struct { TPoint2D<Type> Left; };
		};

		template<typename Type>
		union TTransform2D
		{
			TBases<3, 3, Type> Bases;
			TPoint3D<Type> Points[3];
			struct { TPoint3D<Type> _Padding[2], Origin; };
			struct { TPoint3D<Type> Left, Front; };
		};

		template<typename Type>
		union TTransform3D
		{
			TBases<4, 4, Type> Bases;
			TPoint4D<Type> Points[4];
			struct { TPoint4D<Type> _Padding[3], Origin; };
			struct { TPoint4D<Type> Left, Front, Up; };
		};

		template<typename Type>
		union TTransform4D
		{
			TBases<5, 5, Type> Bases;
			TPoint5D<Type> Points[5];
			struct { TPoint5D<Type> _Padding[4], Origin; };
			struct { TPoint5D<Type> Left, Front, Up, Flow; };
		};

	}



}
