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