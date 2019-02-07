#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "NDev.h"

namespace NDevTest
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

		TEST_METHOD(TestRotate)
		{
			const FSize NL1 = 1, NL2 = 2, NL3 = 3, NLN = 2048, K=7;
			FSize Index, End;
			FReal *L;
			FReal Number;

			End = NL1;
			L = (FReal *) malloc(End * sizeof(FReal));
			for (Index = 0; Index < End; ++Index) { L[Index] = Index; }
			L = Rotate(L, K, End);
			for (Index = 0; Index < End; ++Index)
			{
				Number = (Index + K) % End;
				Assert::AreEqual(Number, L[Index], NullPtr, LINE_INFO());
			}
			L = Rotate(L, K, End, False);
			for (Index = 0; Index < End; ++Index)
			{
				Number = Index;
				Assert::AreEqual(Number, L[Index], NullPtr, LINE_INFO());
			}

			End = NL2;
			L = (FReal *)malloc(End * sizeof(FReal));
			for (Index = 0; Index < End; ++Index) { L[Index] = Index; }
			L = Rotate(L, K, End);
			for (Index = 0; Index < End; ++Index)
			{
				Number = (Index + K) % End;
				Assert::AreEqual(Number, L[Index], NullPtr, LINE_INFO());
			}
			L = Rotate(L, K, End, False);
			for (Index = 0; Index < End; ++Index)
			{
				Number = Index;
				Assert::AreEqual(Number, L[Index], NullPtr, LINE_INFO());
			}
			
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

		}

		TEST_METHOD(TestRemove)
		{

		}

		TEST_METHOD(TestSet)
		{

		}

		TEST_METHOD(TestText)
		{
			const char *CString = "C String";
			const FString NDevString = "NDev String";
			
			FSize Index;

			FString String;
			String = Text(CString);
			
			Remove(String);
		}


	};



}