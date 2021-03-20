#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "NDev.h"
#include "NDevDisplay/NDevDisplay.h"

namespace NDev::Test
{

	using namespace NDev;
	using namespace NDev::Types;
	using namespace NDev::Display;

	TEST_CLASS(UnitTestNDevDisplay)
	{
	public:

		TEST_METHOD(TestDisplay)
		{
			
		}

		TEST_METHOD(TestShader)
		{

		}

		TEST_METHOD(TestStyle)
		{

		}

		TEST_METHOD(TestWindow)
		{
			FWindow Window;
			Window.UseDefault();
			auto Other = FWindow();
			Assert::IsTrue(Equal(Window, Other), NullPtr, LINE_INFO());
			Window.Title = Text("Nameless");
			Assert::IsFalse(Equal(Window, Other), NullPtr, LINE_INFO());
		}

		TEST_METHOD(TestContext)
		{

		}

		TEST_METHOD(TestController)
		{

		}

		TEST_METHOD(TestOpenGL)
		{

		}

	};
}