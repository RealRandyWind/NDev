/*
#include "NDevCppUnitTest.h"
using namespace NDev::StandAlone::CppUnitTestFramework;
*/

#define LINE_INFO() &NDev::StandAlone::CppUnitTestFramework::__LineInfo(__FILE__, __FUNCTION__, __LINE__)

#define TEST_CLASS(className) class className /* TODO Wrap */

#define TEST_METHOD(methodName) static const methodName /* TODO Wrap */

namespace NDev
{
	namespace StandAlone
	{
		namespace CppUnitTestFramework
		{
			struct __LineInfo
			{
				__LineInfo(const char* PtrFileName, const unsigned char* PtrFuncName, int LineNo) :
					_PtrFileName(PtrFileName), _PtrFuncName(PtrFuncName), _LineNo(LineNo) {}

				const char* _PtrFileName;
				const unsigned char* _PtrFuncName;
				int _LineNo;
			};

			template<typename T>
			class Assert
			{
				static void Fail(const char* Message = nullptr, const __LineInfo* PtrLineInfo = nullptr)
				{
					/* TODO */
				}

				static void AreEqual(const T& Expected, const T& Actual, const char* Message = nullptr, const __LineInfo* PtrLineInfo = nullptr)
				{
					/* TODO */
				}

				static void AreNotEqual(const T& Expected, const T& Actual, const char* Message = nullptr, const __LineInfo* PtrLineInfo = nullptr)
				{
					/* TODO */
				}

				static void IsTrue(bool Condition, const char* Message = nullptr, const __LineInfo* PtrLineInfo = nullptr)
				{
					/* TODO */
				}

				static void IsFalse(bool Condition, const char* Message = nullptr, const __LineInfo* PtrLineInfo = nullptr)
				{
					/* TODO */
				}

				static void IsNull(const T* Actual, const char* Message = nullptr, const __LineInfo* PtrLineInfo = nullptr)
				{
					/* TODO */
				}

				static void IsNotNull(const T* Actual, const char* Message = nullptr, const __LineInfo* PtrLineInfo = nullptr)
				{
					/* TODO */
				}

				static void AreSame(const T& Expected, const T* Actual, const char* Message = nullptr, const __LineInfo* PtrLineInfo = nullptr)
				{
					/* TODO */
				}

				template<typename _EXC, typename _FUN>
				static void ExpectException(_FUN Function, const char* Message = nullptr, const __LineInfo* PtrLineInfo = nullptr)
				{
					try { Function(); }
					catch (_EXC) { return; }
					catch (...)
					{
						/* TODO */
						throw;
					}
					Fail(message, pLineInfo);
				}
			};
		} 
	}
	
}
