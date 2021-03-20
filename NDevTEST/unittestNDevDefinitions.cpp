#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "NDev.h"

namespace NDev::Test
{

	using namespace NDev;
	using namespace NDev::Types;

	TEST_CLASS(UnitTestNDevDefinitions)
	{
	public:
		
		TEST_METHOD(TestMinMaxSwap)
		{
			const FReal One = - 1, Two = 2;
			Assert::AreEqual(One, Min(One, Two), NullPtr, LINE_INFO());
			Assert::AreEqual(Two, Max(One, Two), NullPtr, LINE_INFO());

			FReal A = Two, B = One;
			Swap(A, B);
			Assert::AreEqual(One, A, NullPtr, LINE_INFO());
			Assert::AreEqual(Two, B, NullPtr, LINE_INFO());
		}

		TEST_METHOD(TestSwap2)
		{
			
		}

		TEST_METHOD(TestShift)
		{
			const FSize NL1 = 1, NL10=10, NLN = 2048, K=7, R=511;
			FSize Index, End;
			FReal *L;
			FReal Number;

			End = NL1;
			L = (FReal *) malloc(End * sizeof(FReal));
			for (Index = 0; Index < End; ++Index) { L[Index] = Index; }
			L = Shift(L, K, End);
			for (Index = K; Index < End; ++Index)
			{
				Number = Index - K;
				Assert::AreEqual(Number, L[Index], NullPtr, LINE_INFO());
			}
			free(L);
			End = NL10;
			L = (FReal *)malloc(End * sizeof(FReal));
			for (Index = 0; Index < End; ++Index) { L[Index] = Index; }
			L = Shift(L, K, End);
			for (Index = K; Index < End; ++Index)
			{
				Number = Index - K;
				Assert::AreEqual(Number, L[Index], NullPtr, LINE_INFO());
			}
			free(L);
			End = NLN;
			L = (FReal *)malloc(End * sizeof(FReal));
			for (Index = 0; Index < End; ++Index) { L[Index] = Index; }
			L = Shift(L, K, End);
			for (Index = K; Index < End; ++Index)
			{
				Number = Index - K;
				Assert::AreEqual(Number, L[Index], NullPtr, LINE_INFO());
			}
			free(L);
			End = NLN;
			L = (FReal *)malloc(End * sizeof(FReal));
			for (Index = 0; Index < End; ++Index) { L[Index] = Index; }
			L = Shift(L, R, End);
			for (Index = R; Index < End; ++Index)
			{
				Number = Index - R;
				Assert::AreEqual(Number, L[Index], NullPtr, LINE_INFO());
			}
			End = NL1;
			L = (FReal *) malloc(End * sizeof(FReal));
			for (Index = 0; Index < End; ++Index) { L[Index] = Index; }
			L = Shift(L, K, End);
			for (Index = K; Index < End; ++Index)
			{
				Number = Index - K;
				Assert::AreEqual(Number, L[Index], NullPtr, LINE_INFO());
			}
			free(L);
			End = NL10;
			L = (FReal *)malloc(End * sizeof(FReal));
			for (Index = 0; Index < End; ++Index) { L[Index] = Index; }
			L = Shift(L, K, End);
			for (Index = K; Index < End; ++Index)
			{
				Number = Index - K;
				Assert::AreEqual(Number, L[Index], NullPtr, LINE_INFO());
			}
			free(L);
			End = NLN;
			L = (FReal *)malloc(End * sizeof(FReal));
			for (Index = 0; Index < End; ++Index) { L[Index] = Index; }
			L = Shift(L, K, End);
			for (Index = K; Index < End; ++Index)
			{
				Number = Index - K;
				Assert::AreEqual(Number, L[Index], NullPtr, LINE_INFO());
			}
			free(L);
			End = NLN;
			L = (FReal *)malloc(End * sizeof(FReal));
			for (Index = 0; Index < End; ++Index) { L[Index] = Index; }
			L = Shift(L, R, End);
			for (Index = R; Index < End; ++Index)
			{
				Number = Index - R;
				Assert::AreEqual(Number, L[Index], NullPtr, LINE_INFO());
			}
			End = NL1;
			L = (FReal *)malloc(End * sizeof(FReal));
			for (Index = 0; Index < End; ++Index) { L[Index] = Index; }
			L = Shift(L, K, End, False);
			for (Index = 0; Index + K < End; ++Index)
			{
				Number = Index + K;
				Assert::AreEqual(Number, L[Index], NullPtr, LINE_INFO());
			}
			free(L);
			End = NL10;
			L = (FReal *)malloc(End * sizeof(FReal));
			for (Index = 0; Index < End; ++Index) { L[Index] = Index; }
			L = Shift(L, K, End, False);
			for (Index = 0; Index + K < End; ++Index)
			{
				Number = Index + K;
				Assert::AreEqual(Number, L[Index], NullPtr, LINE_INFO());
			}
			free(L);
			End = NLN;
			L = (FReal *)malloc(End * sizeof(FReal));
			for (Index = 0; Index < End; ++Index) { L[Index] = Index; }
			L = Shift(L, K, End, False);
			for (Index = 0; Index + K < End; ++Index)
			{
				Number = Index + K;
				Assert::AreEqual(Number, L[Index], NullPtr, LINE_INFO());
			}
			free(L);
			End = NLN;
			L = (FReal *)malloc(End * sizeof(FReal));
			for (Index = 0; Index < End; ++Index) { L[Index] = Index; }
			L = Shift(L, R, End, False);
			for (Index = 0; Index + R < End; ++Index)
			{
				Number = Index + R;
				Assert::AreEqual(Number, L[Index], NullPtr, LINE_INFO());
			}
		}

		TEST_METHOD(TestRotate)
		{
			/*
			const FSize NL1 = 1, NL2 = 2, NL3 = 3, NLN = 2048, K = 7;
			FSize Index, End;
			FReal *L;
			FReal Number;

			End = NL1;
			L = (FReal *)malloc(End * sizeof(FReal));
			for (Index = 0; Index < End; ++Index) { L[Index] = Index; }
			L = Shift(L, K, End);
			for (Index = 0; Index < End; ++Index)
			{
				Number = (Index + K) % End;
				Assert::AreEqual(Number, L[Index], NullPtr, LINE_INFO());
			}
			L = Shift(L, K, End, False);
			for (Index = 0; Index < End; ++Index)
			{
				Number = Index;
				Assert::AreEqual(Number, L[Index], NullPtr, LINE_INFO());
			}

			End = NL2;
			L = (FReal *)malloc(End * sizeof(FReal));
			for (Index = 0; Index < End; ++Index) { L[Index] = Index; }
			L = Shift(L, K, End);
			for (Index = 0; Index < End; ++Index)
			{
				Number = (Index + K) % End;
				Assert::AreEqual(Number, L[Index], NullPtr, LINE_INFO());
			}
			L = Shift(L, K, End, False);
			for (Index = 0; Index < End; ++Index)
			{
				Number = Index;
				Assert::AreEqual(Number, L[Index], NullPtr, LINE_INFO());
			}
			*/
		}

		TEST_METHOD(TestMake)
		{
			
		}

		TEST_METHOD(TestResize)
		{

		}

		TEST_METHOD(TestMove)
		{

		}

		TEST_METHOD(TestCopy)
		{
			const FSize NL1 = 1, NL2 = 2, NL3 = 3, NLN = 2048, K = 7;
			FSize Index, End;
			FReal *L, *Q, *NullL = NullPtr;

			End = NL1;
			L = (FReal *)malloc(End * sizeof(FReal));
			for (Index = 0; Index < End; ++Index) { L[Index] = Index; }
			Q = Copy(L, NullL, End);
			for (Index = 0; Index < End; ++Index)
			{
				Assert::AreEqual(L[Index], Q[Index], NullPtr, LINE_INFO());
			}
			free(L);
			free(Q);

			End = NL2;
			L = (FReal *)malloc(End * sizeof(FReal));
			for (Index = 0; Index < End; ++Index) { L[Index] = Index; }
			Q = Copy(L, NullL, End);
			for (Index = 0; Index < End; ++Index)
			{
				Assert::AreEqual(L[Index], Q[Index], NullPtr, LINE_INFO());
			}
			free(L);
			free(Q);

			End = NL3;
			L = (FReal *)malloc(End * sizeof(FReal));
			for (Index = 0; Index < End; ++Index) { L[Index] = Index; }
			Q = Copy(L, NullL, End);
			for (Index = 0; Index < End; ++Index)
			{
				Assert::AreEqual(L[Index], Q[Index], NullPtr, LINE_INFO());
			}
			free(L);
			free(Q);

			End = NLN;
			L = (FReal *)malloc(End * sizeof(FReal));
			for (Index = 0; Index < End; ++Index) { L[Index] = Index; }
			Q = Copy(L, NullL, End);
			for (Index = 0; Index < End; ++Index)
			{
				Assert::AreEqual(L[Index], Q[Index], NullPtr, LINE_INFO());
			}
			Q = Copy(L, Q, End);
			for (Index = 0; Index < End; ++Index)
			{
				Assert::AreEqual(L[Index], Q[Index], NullPtr, LINE_INFO());
			}
			Copy(L, &Q[End/2], End/2);
			for (Index = 0; Index < End/2; ++Index)
			{
				Assert::AreEqual(L[Index], Q[Index], NullPtr, LINE_INFO());
				Assert::AreEqual(L[Index], Q[End/2 + Index], NullPtr, LINE_INFO());
			}
			free(L);
			free(Q);
		}

		TEST_METHOD(TestRemove)
		{

		}

		TEST_METHOD(TestSet)
		{

		}

		TEST_METHOD(TestEqual)
		{
			struct FStruct
			{
				FReal A, B, C;
			};

			FStruct Lhs, Rhs, Same;
			Same = Lhs = { 1.0, 2.0, 3.0 };
			Rhs = { 3.0, 2.0, 1.0 };

			Assert::IsTrue(Equal(Lhs, Lhs));
			Assert::IsTrue(Equal(Lhs, Same));
			Assert::IsFalse(Equal(Lhs, Rhs));
		}

		TEST_METHOD(TestText)
		{
			const char *CString = "C String";
			const FString NDevString = "NDev String";

			FString String;
			String = Text(CString);
			
			Remove(String);
		}


	};



}