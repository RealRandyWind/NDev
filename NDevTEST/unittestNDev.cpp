#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include <random>
#include "NDev.h"
#include "ModelStub.h"
#include "SimulationStub.h"

namespace NDevTest
{

	using namespace NDev;
	using namespace NDev::Types;

	TEST_CLASS(UnitTestNDev)
	{
	public:
		
		TEST_METHOD(TestResource)
		{
			const FSize N0 = 0, N1 = 1, N2 = 2, N3 = 3, N4 = 4, N5 = 5;

			Assert::AreEqual(N0, FResource::ResourceCount(), NullPtr, LINE_INFO());
			FResource R1, R2, *R3, *R4, *R5, *R7;
			Assert::AreEqual(N2, FResource::ResourceCount(), NullPtr, LINE_INFO());
			Assert::IsTrue(&R1 == &FResource::Reference(N1 - 1), NullPtr, LINE_INFO());
			Assert::IsTrue(&R2 == &FResource::Reference(N2 - 1), NullPtr, LINE_INFO());
			R3 = new FResource();
			R4 = new FResource();
			Assert::AreEqual(N4, FResource::ResourceCount(), NullPtr, LINE_INFO());
			Assert::AreEqual(N4 - 1, R4->Id(), NullPtr, LINE_INFO());
			Assert::IsTrue(R4 == FResource::Pointer(N4 - 1), NullPtr, LINE_INFO());
			delete R4;
			Assert::IsNull(FResource::Pointer(N4), NullPtr, LINE_INFO());
			Assert::AreEqual(N3, FResource::ResourceCount(), NullPtr, LINE_INFO());
			R5 = new FResource();
			Assert::AreEqual(N4, FResource::ResourceCount(), NullPtr, LINE_INFO());
			Assert::AreEqual(N4 - 1, R5->Id(), NullPtr, LINE_INFO());
			Assert::IsTrue(R5 == FResource::Pointer(N4 - 1), NullPtr, LINE_INFO());
			if (True)
			{
				FResource R6;
				Assert::AreEqual(N5, FResource::ResourceCount(), NullPtr, LINE_INFO());
				Assert::IsTrue(&R6 == FResource::Pointer(N5 - 1), NullPtr, LINE_INFO());
			}
			Assert::AreEqual(N4, FResource::ResourceCount(), NullPtr, LINE_INFO());
			Assert::IsNull(FResource::Pointer(N5 - 1), NullPtr, LINE_INFO());
			delete R5;
			delete R3;
			Assert::AreEqual(N2, FResource::ResourceCount(), NullPtr, LINE_INFO());
			R3 = new FResource();
			R5 = new FResource();
			R7 = new FResource();
			Assert::IsTrue(R3 == FResource::Pointer(N3 - 1), NullPtr, LINE_INFO());
			Assert::IsTrue(R5 == FResource::Pointer(N4 - 1), NullPtr, LINE_INFO());
			Assert::IsTrue(R7 == FResource::Pointer(N5 - 1), NullPtr, LINE_INFO());
			Assert::AreEqual(N5 - 1, R7->Id(), NullPtr, LINE_INFO());
		}

		TEST_METHOD(TestPoint)
		{
			const FReal Zero = 0, One = 1, Two = 2, Three = 3, Four = 4;
			const FSize H1D = 1, H2D = 2, H3D = 3, HND = 2048;
			FSize Index, Center, End;

			/* 1D Point test */
			TPoint<H1D, FReal> P1D;
			End = H1D;
			Assert::AreEqual(P1D.Size(), End, NullPtr, LINE_INFO());
			P1D = Zero;
			for (auto Value : P1D) { Assert::AreEqual(Value, Zero, NullPtr, LINE_INFO()); }
			P1D = One;
			for (auto Value : P1D) { Assert::AreEqual(Value, One, NullPtr, LINE_INFO()); }
			Center = End / 2;
			P1D[Center] = Two;
			for (Index = 0; Index < End; ++Index)
			{
				auto &Value = P1D._Data[Index];
				if (Index == Center) { Assert::AreEqual(Value, Two, NullPtr, LINE_INFO()); }
				else { Assert::AreEqual(Value, One, NullPtr, LINE_INFO()); }
			}
			const auto ConstValue1 = P1D[Center];
			Assert::AreEqual(ConstValue1, Two, NullPtr, LINE_INFO());

			/* 2D Point test */
			TPoint<H2D, FReal> P2D;
			End = H2D;
			Assert::AreEqual(P2D.Size(), End);
			P2D = Zero;
			for (auto Value : P2D) { Assert::AreEqual(Value, Zero, NullPtr, LINE_INFO()); }
			P2D = One;
			for (auto Value : P2D) { Assert::AreEqual(Value, One, NullPtr, LINE_INFO()); }
			Center = End / 2;
			P2D[Center] = Two;
			for (Index = 0; Index < End; ++Index)
			{
				auto &Value = P2D._Data[Index];
				if (Index == Center) { Assert::AreEqual(Value, Two, NullPtr, LINE_INFO()); }
				else { Assert::AreEqual(Value, One, NullPtr, LINE_INFO()); }
			}
			const auto ConstValue2 = P2D[Center];
			Assert::AreEqual(ConstValue2, Two, NullPtr, LINE_INFO());

			/* 3D Point test */
			TPoint<H3D, FReal> P3D;
			End = H3D;
			Assert::AreEqual(P3D.Size(), End, NullPtr, LINE_INFO());
			P3D = Zero;
			for (auto Value : P3D) { Assert::AreEqual(Value, Zero, NullPtr, LINE_INFO()); }
			P3D = One;
			for (auto Value : P3D) { Assert::AreEqual(Value, One, NullPtr, LINE_INFO()); }
			Center = End / 2;
			P3D[Center] = Two;
			for (Index = 0; Index < End; ++Index)
			{
				auto &Value = P3D._Data[Index];
				if (Index == Center) { Assert::AreEqual(Value, Two, NullPtr, LINE_INFO()); }
				else { Assert::AreEqual(Value, One, NullPtr, LINE_INFO()); }
			}
			const auto ConstValue3 = P3D[Center];
			Assert::AreEqual(ConstValue3, Two, NullPtr, LINE_INFO());

			/* ND Point test */
			TPoint<HND, FReal> PND;
			End = HND;
			Assert::AreEqual(PND.Size(), End, NullPtr, LINE_INFO());
			PND = Zero;
			for (auto Value : PND) { Assert::AreEqual(Value, Zero, NullPtr, LINE_INFO()); }
			PND = One;
			for (auto Value : PND) { Assert::AreEqual(Value, One, NullPtr, LINE_INFO()); }
			Center = End / 2;
			PND[Center] = Two;
			for (Index = 0; Index < End; ++Index)
			{
				auto &Value = PND._Data[Index];
				if (Index == Center) { Assert::AreEqual(Value, Two, NullPtr, LINE_INFO()); }
				else { Assert::AreEqual(Value, One, NullPtr, LINE_INFO()); }
			}
			const auto ConstValueN = PND[Center];
			Assert::AreEqual(ConstValueN, Two, NullPtr, LINE_INFO());

			/* casting and assignmnet tests */
			TPoint<HND, FSize> PNDT;
			TPoint<HND, FReal> PNDA, PNDB, PNDC;
			PNDT = Three;
			PND = PNDT;
			for (auto Value : PND) { Assert::AreEqual(Value, Three, NullPtr, LINE_INFO()); }
			PNDT = Four;
			PND = static_cast<TPoint<HND, FReal>>(PNDT);
			for (auto Value : PND) { Assert::AreEqual(Value, Four, NullPtr, LINE_INFO()); }
			P3D = Zero;
			P3D = PND;
			for (auto Value : P3D) { Assert::AreEqual(Value, Four, NullPtr, LINE_INFO()); }
			P3D = Four;
			PND = One;
			PND = P3D;
			End = HND;
			for (Index = 0; Index < End; ++Index)
			{
				auto &Value = PND._Data[Index];
				if (Index < H3D) { Assert::AreEqual(Value, Four, NullPtr, LINE_INFO()); }
				else { Assert::AreEqual(Value, One, NullPtr, LINE_INFO()); }
			}
			
			PNDA = PNDB = Three;
			End = HND;
			for (Index = 0; Index < End; ++Index)
			{
				Assert::AreEqual(PNDA._Data[Index], Three, NullPtr, LINE_INFO());
				Assert::AreEqual(PNDB._Data[Index], Three, NullPtr, LINE_INFO());
			}
			PNDA = Four;
			End = HND;
			for (Index = 0; Index < End; ++Index)
			{
				Assert::AreEqual(PNDA._Data[Index], Four, NullPtr, LINE_INFO());
				Assert::AreEqual(PNDB._Data[Index], Three, NullPtr, LINE_INFO());
			}
			PNDC = One;
			PNDA = PNDB = PNDC;
			End = HND;
			for (Index = 0; Index < End; ++Index)
			{
				Assert::AreEqual(PNDA._Data[Index], One, NullPtr, LINE_INFO());
				Assert::AreEqual(PNDB._Data[Index], One, NullPtr, LINE_INFO());
				Assert::AreEqual(PNDC._Data[Index], One, NullPtr, LINE_INFO());
			}
			PNDA = Four;
			End = HND;
			for (Index = 0; Index < End; ++Index)
			{
				Assert::AreEqual(PNDA._Data[Index], Four, NullPtr, LINE_INFO());
				Assert::AreEqual(PNDB._Data[Index], One, NullPtr, LINE_INFO());
				Assert::AreEqual(PNDC._Data[Index], One, NullPtr, LINE_INFO());
			}
			PNDB = Four;
			End = HND;
			for (Index = 0; Index < End; ++Index)
			{
				Assert::AreEqual(PNDA._Data[Index], Four, NullPtr, LINE_INFO());
				Assert::AreEqual(PNDB._Data[Index], Four, NullPtr, LINE_INFO());
				Assert::AreEqual(PNDC._Data[Index], One, NullPtr, LINE_INFO());
			}

			/* like tests */
			auto SameSize = PNDT.Like<FReal>();
			Assert::AreEqual(PNDT.Size(), SameSize.Size());
			auto SameType = PNDT.Like<HND / 2>();

		}

		TEST_METHOD(TestSequence)
		{
			const FReal Zero = 0, One = 1, Two = 2, Three = 3, Four = 4;
			const FSize HS0 = 0, HS1 = 1, HS2 = 2, HS3 = 3, HSN = 4096, HSK = 8192, HSM = 128;
			TSequence<FReal> S0, S1, S2, S3, SN, SM;
			TSequence<FSize> SIM;
			FSize Size = 0, Pivot = 0, Select = 0, Temp = 0;

			/* reserve buffer tests */
			S1.Reserve(HS1);
			Assert::AreEqual(S1.BufferSize(), HS1, NullPtr, LINE_INFO());
			Assert::AreEqual(S1.Size(), HS0, NullPtr, LINE_INFO());
			S2.Reserve(HS2);
			Assert::AreEqual(S2.BufferSize(), HS2, NullPtr, LINE_INFO());
			Assert::AreEqual(S2.Size(), HS0, NullPtr, LINE_INFO());
			S3.Reserve(HS3);
			Assert::AreEqual(S3.BufferSize(), HS3, NullPtr, LINE_INFO());
			Assert::AreEqual(S3.Size(), HS0, NullPtr, LINE_INFO());
			SN.Reserve(HSN);
			Assert::AreEqual(SN.BufferSize(), HSN, NullPtr, LINE_INFO());
			Assert::AreEqual(SN.Size(), HS0, NullPtr, LINE_INFO());

			/* index access tests */
			S1[HS1 - 1] = One;
			S1[HS1 - 1] = Two;
			Assert::AreEqual(S1._Data[HS1 - 1], Two, NullPtr, LINE_INFO());
			S2[HS2 - 1] = One;
			S2[HS2 - 1] = Two;
			Assert::AreEqual(S2._Data[HS2 - 1], Two, NullPtr, LINE_INFO());
			S3[HS3 - 1] = One;
			S3[HS3 - 1] = Two;
			Assert::AreEqual(S3._Data[HS3 - 1], Two, NullPtr, LINE_INFO());
			SN[HSN - 1] = One;
			SN[HSN - 1] = Two;
			Assert::AreEqual(SN._Data[HSN - 1], Two, NullPtr, LINE_INFO());
			const auto ConstValue = SN[HSN - 1];
			Assert::AreEqual(ConstValue, Two, NullPtr, LINE_INFO());

			/* size/resize on access tests */
			SN.SizeOnAccess();
			SN.ResizeOnAccess();
			Assert::AreEqual(SN.Size(), HS0, NullPtr, LINE_INFO());
			SN[HSN - 1] = Three;
			Assert::AreEqual(SN.BufferSize(), HSN, NullPtr, LINE_INFO());
			Assert::AreEqual(SN.Size(), HSN, NullPtr, LINE_INFO());
			SN[HSN] = Four;
			Assert::AreEqual(SN.BufferSize(), HSN + SN._IncrementSize, NullPtr, LINE_INFO());
			Assert::AreEqual(SN.Size(), HSN + 1, NullPtr, LINE_INFO());
			Assert::AreEqual(SN._Data[HSN], Four, NullPtr, LINE_INFO());


			/* constructor tests */
			Assert::AreEqual(S0.BufferSize(), HS0, NullPtr, LINE_INFO());
			Assert::IsTrue(S0.Empty(), NullPtr, LINE_INFO());
			TSequence<FReal> SK(HSK);
			Assert::AreEqual(SK.BufferSize(), HSK, NullPtr, LINE_INFO());

			/* iterator tests */
			for (auto &Value : SK) { Assert::Fail(NullPtr, LINE_INFO()); }
			SK.IterateAll();
			Size = 0;
			for (auto &Value : SK) { Value = Zero; ++Size; }
			Assert::AreEqual(Size, HSK, NullPtr, LINE_INFO());
			SK.IterateAll(False);
			for (auto &Value : SK) { Assert::Fail(NullPtr, LINE_INFO()); }

			/* recursive collection test */
			TSequence<TSequence<TSequence<FReal>>> Rec3;
			Rec3.Reserve(HSM, True, True);
			for (auto &Rec2 : Rec3)
			{
				Rec2.Reserve(HSM, True, True);
				for (auto &Rec1 : Rec2)
				{
					Rec1.Reserve(HSM, True);
					for (auto &Index : Rec1) { Rec1 = Two; }
				}
			}
		}

		TEST_METHOD(TestList)
		{
			const FReal Three = 3;
			const FSize HSK = 8192, HSN = 2048, HSM = 2;
			TSequence<FSize> SIN, STN, STIN;
			TList<FReal> SK, SN, SON;
			FSize Index, End, Center, Size = 0, Select, Pivot, Temp;
			FReal Number;

			/* add element tests */
			Center = HSK / 2;
			End = Center;
			for (Index = 0; Index < End; ++Index)
			{
				SK.Add(Three);
				Assert::AreEqual(SK.Size(), Index + 1, NullPtr, LINE_INFO());
				Assert::AreEqual(SK[Index], Three, NullPtr, LINE_INFO());
			}
			Size = 0;
			for (auto &Value : SK) { Assert::AreEqual(Value, Three, NullPtr, LINE_INFO()); ++Size; }
			Assert::AreEqual(Size, Center, NullPtr, LINE_INFO());

			/* sort test */
			STN.Reserve(HSN / HSM, True);
			SON.Reserve(HSN, True);
			SN.Reserve(HSN, True);
			SN.OnPriority = [](const auto &Lhs, const auto &Rhs) { return Lhs > Rhs; };
			End = HSN;
			for (Index = 0; Index < End; ++Index)
			{
				SON[Index] = Index;
			}
			End = HSN / HSM;
			for (Index = 0; Index < End; ++Index)
			{
				STN[Index] = Index * HSM;
			}
			srand(HSN);
			End = HSN;
			for (Index = 0; Index < End; ++Index)
			{
				Pivot = End - 1 - Index;
				Select = rand() % (Pivot + 1);
				SN[Index] = SON[Select];

				Temp = SON[Pivot];
				SON[Pivot] = SON[Select];
				SON[Select] = Temp;
			}
			SN.Sort(SIN);
			End = HSN;
			for (Index = 0; Index < End; ++Index)
			{
				Number = Index;
				Assert::AreEqual(Number, SN[SIN[Index]], NullPtr, LINE_INFO());
			}
			for (Index = 1; Index < End; ++Index)
			{
				Assert::IsTrue(SN.OnPriority(SN[SIN[Index]], SN[SIN[Index - 1]]), NullPtr, LINE_INFO());
			}
			SN.TargetSort(STIN, STN);
			End = STN.Size();
			for (Index = 1; Index < End; ++Index)
			{
				Assert::IsTrue(SN.OnPriority(SN[STIN[Index]], SN[STIN[Index - 1]]), NullPtr, LINE_INFO());
			}
			SN.TargetSort(STN);
			End = STN.Size();
			for (Index = 1; Index < End; ++Index)
			{
				Assert::IsTrue(SN.OnPriority(SN[STN[Index]], SN[STN[Index - 1]]), NullPtr, LINE_INFO());
			}
			SN.Sort();
			End = HSN;
			for (Index = 0; Index < End; ++Index)
			{
				Number = Index;
				Assert::AreEqual(Number, SN[Index], NullPtr, LINE_INFO());
			}


		}

		TEST_METHOD(TestBuffer)
		{
			const FSize HS3 = 3, HSN = 4096;
			TBuffer<FReal> SN;
			FSize Index, End, Size = 0;
			FReal Number;

			/* swap buffer tests */
			SN.Reserve(HSN);
			End = HSN * HS3;
			for (Index = 0; Index < End; ++Index)
			{
				Number = (FReal)Index;
				SN.Swap(Number);
				Assert::AreEqual(Number, SN.Active(), NullPtr, LINE_INFO());
			}
		}

		TEST_METHOD(TestStack)
		{
			const FSize HS3 = 3, HSN = 4096;
			TStack<FReal> SN;
			FSize Index, End, Size = 0;
			FReal Number;

			/* stack tests */
			SN.Reserve(HSN);
			End = HSN * HS3;
			for (Index = 0; Index < End; ++Index)
			{
				Number = (FReal)Index;
				SN.Push(Number);
				Assert::AreEqual(Number, SN.Peek(), NullPtr, LINE_INFO());
			}

			for (; End; --End)
			{
				Number = (FReal)End;
				SN.Push(Number);
				Assert::AreEqual(Number, SN.Pop(), NullPtr, LINE_INFO());
			}
		}

		TEST_METHOD(TestQueue)
		{
			const FReal Zero = 0, One = 1, Two = 2, Three = 3, Four = 4;
			const FSize HS0 = 0, HS1 = 1, HS2 = 2, HS3 = 3, HSN = 4096, HSK = 8192, HSM = 128;
			TQueue<FReal> SM;
			TSequence<FReal> SOM;
			FSize Index, End, Next, Size = 0, Pivot = 0, Select = 0, Temp = 0;
			FReal Number, OtherNumber;

			/* queue/dequeue tests */
			SM.FixedSize();
			SM.Reserve(HSM);
			End = HSM;
			for (Index = 0; Index < End; ++Index)
			{
				Number = (FReal)(Index);
				SM.Queue(Number);
				Assert::AreEqual(Number, SM.Last(), NullPtr, LINE_INFO());
				Assert::AreEqual(Zero, SM.First(), NullPtr, LINE_INFO());
			}
			SM.Queue(HSK);
			Assert::AreEqual(Number, SM.Last(), NullPtr, LINE_INFO());
			Assert::AreEqual(Zero, SM.First(), NullPtr, LINE_INFO());
			OtherNumber = SM.Dequeue();
			Assert::AreEqual(Zero, OtherNumber, NullPtr, LINE_INFO());
			Assert::AreEqual(Number, SM.Last(), NullPtr, LINE_INFO());
			Assert::AreEqual(One, SM.First(), NullPtr, LINE_INFO());
			OtherNumber = (FReal)End;
			SM.Queue(OtherNumber);
			Assert::AreEqual(OtherNumber, SM.Last(), NullPtr, LINE_INFO());
			Assert::AreEqual(One, SM.First(), NullPtr, LINE_INFO());
			SM.Reset();
			SM.OnPriority = [](const auto &Lhs, const auto &Rhs) { return Lhs > Rhs; };
			Size = End = HSM * HS3;
			for (Index = 0; Index < End; ++Index)
			{
				SM.Queue(Index);
			}
			OtherNumber = (FReal)HSM;
			SM.Queue(OtherNumber);
			Assert::AreNotEqual(OtherNumber, SM.Last(), NullPtr, LINE_INFO());
			End = HSM;
			for (Index = 0; Index < End; ++Index)
			{
				Number = Size - Index - 1;
				Assert::AreEqual(Number, SM.Dequeue(), NullPtr, LINE_INFO());
			}
			Assert::IsTrue(SM.Empty(), NullPtr, LINE_INFO());
			SM.Reset();
			SM.OnPriority = [](const auto &Lhs, const auto &Rhs) { return Lhs > Rhs; };
			Size = End = HSM * HS3;
			for (Index = 0; Index < End; ++Index)
			{
				SM.Queue(End - Index - 1);
			}
			OtherNumber = (FReal)HSM;
			SM.Queue(OtherNumber);
			Assert::AreNotEqual(OtherNumber, SM.Last(), NullPtr, LINE_INFO());
			End = HSM;
			for (Index = 0; Index < End; ++Index)
			{
				Number = Size - Index - 1;
				Assert::AreEqual(Number, SM.Dequeue(), NullPtr, LINE_INFO());
			}
			Assert::IsTrue(SM.Empty(), NullPtr, LINE_INFO());
			SOM.Reserve(HSM);
			SM.OnPriority = [](const auto &Lhs, const auto &Rhs) { return Lhs > Rhs; };
			End = HSM;
			for (Index = 0; Index < End; ++Index)
			{
				SOM[Index] = Index;
			}
			SM.Reset();
			SM.OnPriority = [](const auto &Lhs, const auto &Rhs) { return Lhs > Rhs; };
			srand(HSM);
			End = HSM;
			for (Index = 0; Index < End; ++Index)
			{
				Pivot = End - Index - 1;
				Select = rand() % (Pivot + 1);
				SM.Queue(SOM[Select]);

				Temp = SOM[Pivot];
				SOM[Pivot] = SOM[Select];
				SOM[Select] = Temp;
			}
			Index = SM._FirstIndex;
			while (Index != SM._LastIndex)
			{
				Next = (Index + 1) % SM._BufferSize;
				Assert::IsTrue(SM.OnPriority(SM._Data[Index],SM._Data[Next]), NullPtr, LINE_INFO());
				Index = Next;
			}
			End = HSM;
			for (Index = 0; Index < End; ++Index)
			{
				Number = End - Index - 1;
				Assert::AreEqual(Number, SM.Dequeue(), NullPtr, LINE_INFO());
			}
			Assert::IsTrue(SM.Empty(), NullPtr, LINE_INFO());

			/* repeate no fixed size */
			SM.Reset();
			SM.FixedSize(False);
			SM.Reserve(HSM);
			SM.OnPriority = NullPtr;
			End = HSM;
			for (Index = 0; Index < End; ++Index)
			{
				Number = (FReal)(Index);
				SM.Queue(Number);
				Assert::AreEqual(HSM, SM.BufferSize(), NullPtr, LINE_INFO());
				Assert::AreEqual(Number, SM.Last(), NullPtr, LINE_INFO());
				Assert::AreEqual(Zero, SM.First(), NullPtr, LINE_INFO());
			}
			SM.OnPriority = [](const auto &Lhs, const auto &Rhs) { return Lhs > Rhs; };
			srand(HSM);
			End = HSM;
			for (Index = 0; Index < End; ++Index)
			{
				Pivot = End - Index - 1;
				Select = rand() % (Pivot + 1);
				SM.Queue(SOM[Select] + HSM);

				Temp = SOM[Pivot];
				SOM[Pivot] = SOM[Select];
				SOM[Select] = Temp;
			}
			End = 2 * HSM;
			Assert::AreEqual(End, SM.Size(), NullPtr, LINE_INFO());
			Index = SM._FirstIndex;
			while (Index != SM._LastIndex)
			{
				Next = (Index + 1) % SM._BufferSize;
				Assert::IsTrue(SM.OnPriority(SM._Data[Index], SM._Data[Next]), NullPtr, LINE_INFO());
				Index = Next;
			}
			for (Index = 0; Index < End; ++Index)
			{
				Number = End - Index - 1;
				Assert::AreEqual(Number, SM.Dequeue(), NullPtr, LINE_INFO());
			}
			Assert::IsTrue(SM.Empty(), NullPtr, LINE_INFO());
		}

		TEST_METHOD(TestData)
		{
			const FReal Zero = 0, One = 1, Two = 2, Three = 3, Four = 4;
			const FSize HD0 = 0, HD1 = 1, HD2 = 2, HD3 = 3, HDN = 4096, HSK = 8192;
			TData<FReal> D0, D1, D2, D3, DN;
			FSize Size = 0;

			/* reserve buffer tests */
			D1.Reserve(HD1);
			Assert::AreEqual(D1.BufferSize(), HD1, NullPtr, LINE_INFO());
			Assert::AreEqual(D1.Size(), HD0, NullPtr, LINE_INFO());
			D2.Reserve(HD2);
			Assert::AreEqual(D2.BufferSize(), HD2, NullPtr, LINE_INFO());
			Assert::AreEqual(D2.Size(), HD0, NullPtr, LINE_INFO());
			D3.Reserve(HD3);
			Assert::AreEqual(D3.BufferSize(), HD3, NullPtr, LINE_INFO());
			Assert::AreEqual(D3.Size(), HD0, NullPtr, LINE_INFO());
			DN.Reserve(HDN);
			Assert::AreEqual(DN.BufferSize(), HDN, NullPtr, LINE_INFO());
			Assert::AreEqual(DN.Size(), HD0, NullPtr, LINE_INFO());

			/* index access tests */
			D1[HD1 - 1] = One;
			D1[HD1 - 1] = Two;
			Assert::AreEqual(D1._Data[HD1 - 1], Two, NullPtr, LINE_INFO());
			D2[HD2 - 1] = One;
			D2[HD2 - 1] = Two;
			Assert::AreEqual(D2._Data[HD2 - 1], Two, NullPtr, LINE_INFO());
			D3[HD3 - 1] = One;
			D3[HD3 - 1] = Two;
			Assert::AreEqual(D3._Data[HD3 - 1], Two, NullPtr, LINE_INFO());
			DN[HDN - 1] = One;
			DN[HDN - 1] = Two;
			Assert::AreEqual(DN._Data[HDN - 1], Two, NullPtr, LINE_INFO());
			const auto ConstValue = DN[HDN - 1];
			Assert::AreEqual(ConstValue, Two, NullPtr, LINE_INFO());


			/* constructor tests */
			Assert::AreEqual(D0.BufferSize(), HD0, NullPtr, LINE_INFO());
			Assert::IsTrue(D0.Empty(), NullPtr, LINE_INFO());
			TData<FReal> SK(HSK);
			Assert::AreEqual(SK.BufferSize(), HSK, NullPtr, LINE_INFO());

			/* iterator tests */
			for (auto &Value : SK) { Assert::Fail(NullPtr, LINE_INFO()); }
			SK.IterateAll();
			Size = 0;
			for (auto &Value : SK) { Value = Zero; ++Size; }
			Assert::AreEqual(Size, HSK, NullPtr, LINE_INFO());
			SK.IterateAll(False);
			for (auto &Value : SK) { Assert::Fail(NullPtr, LINE_INFO()); }
		}

		TEST_METHOD(TestModel)
		{
			/*(F|L|M)\d   ${1}2*/
			const FReal Zero = 0, Half = .5, One = 1, Two = 2, Three = 3;
			const FSize N0 = 0, L1 = 1, F1 = 2, L2 = 2, F2 = 4, L3 = 3, F3 = 6, LN = 256, FN = 512;
			FSize Index, End;
			FReal RU, RT, RO, RO1;;

			/* 2D Feature 1D Label, 2 Data tests */
			RU = F1 * One; RT = Half - RU; RO = RT + F1 * Half * (F1 * One + L1 * Half), RO1 = Half * RO;
			auto M1 = TModelStub<F1, L1>();
			Assert::AreEqual(Zero, M1.Parameters.Alpha, NullPtr, LINE_INFO());
			Assert::AreEqual(Zero, M1.Parameters.Weight, NullPtr, LINE_INFO());
			Assert::AreEqual(Zero, M1.Parameters.Difference, NullPtr, LINE_INFO());
			Assert::AreEqual(N0, M1.Parameters.Size, NullPtr, LINE_INFO());
			TData<TModelStub<F1, L1>::FError> Errors1;
			TData<TModelStub<F1, L1>::FFeature> Features1(F1, True);
			TData<TModelStub<F1, L1>::FLabel> Labels1;
			TData<TModelStub<F1, L1>::FSample> Samples1(F1, True);
			End = F1;
			for (Index = 0; Index < End; ++Index)
			{
				Features1[Index] = One;
				Samples1[Index].Feature = One;
				Samples1[Index].Label = Half;
			}
			Assert::AreEqual(M1.FeatureSize(), F1, NullPtr, LINE_INFO());
			Assert::AreEqual(M1.LabelSize(), L1, NullPtr, LINE_INFO());
			M1.Parameters = { One, Half, Zero, F1 };
			M1.Parameters.Alpha = One;
			M1.Parameters.Weight = Half;
			M1.Parameters.Difference = Zero;
			M1.Parameters.Size = F1;
			Assert::IsFalse(M1.Initialized(), NullPtr, LINE_INFO());
			M1.Initialize();
			Assert::IsTrue(M1.Initialized(), NullPtr, LINE_INFO());
			Assert::AreEqual(F1, M1.State.Weights.Size(), NullPtr, LINE_INFO());
			for (const auto &Weight : M1.State.Weights)
			{
				Assert::AreEqual(One, Weight, NullPtr, LINE_INFO());
			}
			for (const auto &Value : M1.State.Difference)
			{
				Assert::AreEqual(Zero, Value, NullPtr, LINE_INFO());
			}
			Assert::AreEqual(N0, Labels1.Size(), NullPtr, LINE_INFO());
			M1.Use(Features1, Labels1);
			Assert::AreEqual(F1, Labels1.Size(), NullPtr, LINE_INFO());
			for (const auto &Label : Labels1)
			{
				for (const auto &Value : Label)
				{
					Assert::AreEqual(RU, Value, NullPtr, LINE_INFO());
				}
			}
			M1.Train(Samples1);
			for (const auto &Value : M1.State.Difference)
			{
				Assert::AreEqual(RT, Value, NullPtr, LINE_INFO());
			}
			M1.Optimize(Samples1);
			for (const auto &Value : M1.State.Difference)
			{
				Assert::AreEqual(RO, Value, NullPtr, LINE_INFO());
			}
			M1.Optimize();
			for (const auto &Value : M1.State.Difference)
			{
				Assert::AreEqual(RO1, Value, NullPtr, LINE_INFO());
			}
			M1.Validate(Samples1, Errors1);
			for (const auto &Error : Errors1)
			{
				for (const auto &Value : Error.Value)
				{
					Assert::AreEqual(Half - RU, Value, NullPtr, LINE_INFO());
				}
			}

			/* 4D Feature 2D Label, 4 Data tests */
			RU = F2 * One; RT = Half - RU; RO = RT + F2 * Half * (F2 * One + L2 * Half), RO1 = Half * RO;
			auto M2 = TModelStub<F2, L2>();
			Assert::AreEqual(Zero, M2.Parameters.Alpha, NullPtr, LINE_INFO());
			Assert::AreEqual(Zero, M2.Parameters.Weight, NullPtr, LINE_INFO());
			Assert::AreEqual(Zero, M2.Parameters.Difference, NullPtr, LINE_INFO());
			Assert::AreEqual(N0, M2.Parameters.Size, NullPtr, LINE_INFO());
			TData<TModelStub<F2, L2>::FError> Errors2;
			TData<TModelStub<F2, L2>::FFeature> Features2(F2, True);
			TData<TModelStub<F2, L2>::FLabel> Labels2;
			TData<TModelStub<F2, L2>::FSample> Samples2(F2, True);
			End = F2;
			for (Index = 0; Index < End; ++Index)
			{
				Features2[Index] = One;
				Samples2[Index].Feature = One;
				Samples2[Index].Label = Half;
			}
			Assert::AreEqual(M2.FeatureSize(), F2, NullPtr, LINE_INFO());
			Assert::AreEqual(M2.LabelSize(), L2, NullPtr, LINE_INFO());
			M2.Parameters = { One, Half, Zero, F2 };
			M2.Parameters.Alpha = One;
			M2.Parameters.Weight = Half;
			M2.Parameters.Difference = Zero;
			M2.Parameters.Size = F2;
			Assert::IsFalse(M2.Initialized(), NullPtr, LINE_INFO());
			M2.Initialize();
			Assert::IsTrue(M2.Initialized(), NullPtr, LINE_INFO());
			Assert::AreEqual(F2, M2.State.Weights.Size(), NullPtr, LINE_INFO());
			for (const auto &Weight : M2.State.Weights)
			{
				Assert::AreEqual(One, Weight, NullPtr, LINE_INFO());
			}
			for (const auto &Value : M2.State.Difference)
			{
				Assert::AreEqual(Zero, Value, NullPtr, LINE_INFO());
			}
			Assert::AreEqual(N0, Labels2.Size(), NullPtr, LINE_INFO());
			M2.Use(Features2, Labels2);
			Assert::AreEqual(F2, Labels2.Size(), NullPtr, LINE_INFO());
			for (const auto &Label : Labels2)
			{
				for (const auto &Value : Label)
				{
					Assert::AreEqual(RU, Value, NullPtr, LINE_INFO());
				}
			}
			M2.Train(Samples2);
			for (const auto &Value : M2.State.Difference)
			{
				Assert::AreEqual(RT, Value, NullPtr, LINE_INFO());
			}
			M2.Optimize(Samples2);
			for (const auto &Value : M2.State.Difference)
			{
				Assert::AreEqual(RO, Value, NullPtr, LINE_INFO());
			}
			M2.Optimize();
			for (const auto &Value : M2.State.Difference)
			{
				Assert::AreEqual(RO1, Value, NullPtr, LINE_INFO());
			}
			M2.Validate(Samples2, Errors2);
			for (const auto &Error : Errors2)
			{
				for (const auto &Value : Error.Value)
				{
					Assert::AreEqual(Half - RU, Value, NullPtr, LINE_INFO());
				}
			}

			/* 6D Feature 3D Label, 6 Data tests */
			RU = F3 * One; RT = Half - RU; RO = RT + F3 * Half * (F3 * One + L3 * Half), RO1 = Half * RO;
			auto M3 = TModelStub<F3, L3>();
			Assert::AreEqual(Zero, M3.Parameters.Alpha, NullPtr, LINE_INFO());
			Assert::AreEqual(Zero, M3.Parameters.Weight, NullPtr, LINE_INFO());
			Assert::AreEqual(Zero, M3.Parameters.Difference, NullPtr, LINE_INFO());
			Assert::AreEqual(N0, M3.Parameters.Size, NullPtr, LINE_INFO());
			TData<TModelStub<F3, L3>::FError> Errors3;
			TData<TModelStub<F3, L3>::FFeature> Features3(F3, True);
			TData<TModelStub<F3, L3>::FLabel> Labels3;
			TData<TModelStub<F3, L3>::FSample> Samples3(F3, True);
			End = F3;
			for (Index = 0; Index < End; ++Index)
			{
				Features3[Index] = One;
				Samples3[Index].Feature = One;
				Samples3[Index].Label = Half;
			}
			Assert::AreEqual(M3.FeatureSize(), F3, NullPtr, LINE_INFO());
			Assert::AreEqual(M3.LabelSize(), L3, NullPtr, LINE_INFO());
			M3.Parameters = { One, Half, Zero, F3 };
			M3.Parameters.Alpha = One;
			M3.Parameters.Weight = Half;
			M3.Parameters.Difference = Zero;
			M3.Parameters.Size = F3;
			Assert::IsFalse(M3.Initialized(), NullPtr, LINE_INFO());
			M3.Initialize();
			Assert::IsTrue(M3.Initialized(), NullPtr, LINE_INFO());
			Assert::AreEqual(F3, M3.State.Weights.Size(), NullPtr, LINE_INFO());
			for (const auto &Weight : M3.State.Weights)
			{
				Assert::AreEqual(One, Weight, NullPtr, LINE_INFO());
			}
			for (const auto &Value : M3.State.Difference)
			{
				Assert::AreEqual(Zero, Value, NullPtr, LINE_INFO());
			}
			Assert::AreEqual(N0, Labels3.Size(), NullPtr, LINE_INFO());
			M3.Use(Features3, Labels3);
			Assert::AreEqual(F3, Labels3.Size(), NullPtr, LINE_INFO());
			for (const auto &Label : Labels3)
			{
				for (const auto &Value : Label)
				{
					Assert::AreEqual(RU, Value, NullPtr, LINE_INFO());
				}
			}
			M3.Train(Samples3);
			for (const auto &Value : M3.State.Difference)
			{
				Assert::AreEqual(RT, Value, NullPtr, LINE_INFO());
			}
			M3.Optimize(Samples3);
			for (const auto &Value : M3.State.Difference)
			{
				Assert::AreEqual(RO, Value, NullPtr, LINE_INFO());
			}
			M3.Optimize();
			for (const auto &Value : M3.State.Difference)
			{
				Assert::AreEqual(RO1, Value, NullPtr, LINE_INFO());
			}
			M3.Validate(Samples3, Errors3);
			for (const auto &Error : Errors3)
			{
				for (const auto &Value : Error.Value)
				{
					Assert::AreEqual(Half - RU, Value, NullPtr, LINE_INFO());
				}
			}

			/* 2ND Feature ND Label, 2N Data tests */
			RU = FN * One; RT = Half - RU; RO = RT + FN * Half * (FN * One + LN * Half), RO1 = Half * RO;
			auto MN = TModelStub<FN, LN>();
			Assert::AreEqual(Zero, MN.Parameters.Alpha, NullPtr, LINE_INFO());
			Assert::AreEqual(Zero, MN.Parameters.Weight, NullPtr, LINE_INFO());
			Assert::AreEqual(Zero, MN.Parameters.Difference, NullPtr, LINE_INFO());
			Assert::AreEqual(N0, MN.Parameters.Size, NullPtr, LINE_INFO());
			TData<TModelStub<FN, LN>::FError> ErrorsN;
			TData<TModelStub<FN, LN>::FFeature> FeaturesN(FN, True);
			TData<TModelStub<FN, LN>::FLabel> LabelsN;
			TData<TModelStub<FN, LN>::FSample> SamplesN(FN, True);
			End = FN;
			for (Index = 0; Index < End; ++Index)
			{
				FeaturesN[Index] = One;
				SamplesN[Index].Feature = One;
				SamplesN[Index].Label = Half;
			}
			Assert::AreEqual(MN.FeatureSize(), FN, NullPtr, LINE_INFO());
			Assert::AreEqual(MN.LabelSize(), LN, NullPtr, LINE_INFO());
			MN.Parameters = { One, Half, Zero, FN };
			MN.Parameters.Alpha = One;
			MN.Parameters.Weight = Half;
			MN.Parameters.Difference = Zero;
			MN.Parameters.Size = FN;
			Assert::IsFalse(MN.Initialized(), NullPtr, LINE_INFO());
			MN.Initialize();
			Assert::IsTrue(MN.Initialized(), NullPtr, LINE_INFO());
			Assert::AreEqual(FN, MN.State.Weights.Size(), NullPtr, LINE_INFO());
			for (const auto &Weight : MN.State.Weights)
			{
				Assert::AreEqual(One, Weight, NullPtr, LINE_INFO());
			}
			for (const auto &Value : MN.State.Difference)
			{
				Assert::AreEqual(Zero, Value, NullPtr, LINE_INFO());
			}
			Assert::AreEqual(N0, LabelsN.Size(), NullPtr, LINE_INFO());
			MN.Use(FeaturesN, LabelsN);
			Assert::AreEqual(FN, LabelsN.Size(), NullPtr, LINE_INFO());
			for (const auto &Label : LabelsN)
			{
				for (const auto &Value : Label)
				{
					Assert::AreEqual(RU, Value, NullPtr, LINE_INFO());
				}
			}
			MN.Train(SamplesN);
			for (const auto &Value : MN.State.Difference)
			{
				Assert::AreEqual(RT, Value, NullPtr, LINE_INFO());
			}
			MN.Optimize(SamplesN);
			for (const auto &Value : MN.State.Difference)
			{
				Assert::AreEqual(RO, Value, NullPtr, LINE_INFO());
			}
			MN.Optimize();
			for (const auto &Value : MN.State.Difference)
			{
				Assert::AreEqual(RO1, Value, NullPtr, LINE_INFO());
			}
			MN.Validate(SamplesN, ErrorsN);
			for (const auto &Error : ErrorsN)
			{
				for (const auto &Value : Error.Value)
				{
					Assert::AreEqual(Half - RU, Value, NullPtr, LINE_INFO());
				}
			}
		}

		TEST_METHOD(TestSimulation)
		{
			/*(P|N|S)\d   ${1}2*/
			const FReal Zero = 0, Half = .5, One = 1, Two = 2, Three = 3;
			const FSize N0 = 0, P1 = 1, P2 = 2, P3 = 3, PN = 256;
			FReal RS;

			/* N1D Point N1 data tests*/
			RS = Half + (Two * P1);
			auto S1 = TSimulationStub<P1>();
			Assert::AreEqual(Zero, S1.Parameters.Alpha, NullPtr, LINE_INFO());
			Assert::AreEqual(Zero, S1.Parameters.Weight, NullPtr, LINE_INFO());
			Assert::AreEqual(N0, S1.Parameters.Size, NullPtr, LINE_INFO());
			TData<TSimulationStub<P1>::FPoint> R1;
			S1.Parameters.Alpha = Half;
			S1.Parameters.Size = P1;
			S1.Parameters.Weight = Two;
			S1.Initialize();
			Assert::AreEqual(P1, S1.State.Space.Size(), NullPtr, LINE_INFO());
			for (const auto &Point : S1.State.Space)
			{
				for (const auto &Value : Point)
				{
					Assert::AreEqual(Half, Value, NullPtr, LINE_INFO());
				}
			}
			S1.Start(R1);
			Assert::AreEqual(P1, S1.NSteps(), NullPtr, LINE_INFO());
			Assert::AreEqual(P1, R1.Size(), NullPtr, LINE_INFO());
			for (const auto &Point : R1)
			{
				for (const auto &Value : Point)
				{
					Assert::AreEqual(RS, Value, NullPtr, LINE_INFO());
				}
			}


			/* N2D Point 1 data tests*/
			RS = Half + (Two * P2);
			auto S2 = TSimulationStub<P2>();
			Assert::AreEqual(Zero, S2.Parameters.Alpha, NullPtr, LINE_INFO());
			Assert::AreEqual(Zero, S2.Parameters.Weight, NullPtr, LINE_INFO());
			Assert::AreEqual(N0, S2.Parameters.Size, NullPtr, LINE_INFO());
			TData<TSimulationStub<P2>::FPoint> R2;
			S2.Parameters.Alpha = Half;
			S2.Parameters.Size = P2;
			S2.Parameters.Weight = Two;
			S2.Initialize();
			Assert::AreEqual(P2, S2.State.Space.Size(), NullPtr, LINE_INFO());
			for (const auto &Point : S2.State.Space)
			{
				for (const auto &Value : Point)
				{
					Assert::AreEqual(Half, Value, NullPtr, LINE_INFO());
				}
			}
			S2.Start(R2);
			Assert::AreEqual(P2, S2.NSteps(), NullPtr, LINE_INFO());
			Assert::AreEqual(P2, R2.Size(), NullPtr, LINE_INFO());
			for (const auto &Point : R2)
			{
				for (const auto &Value : Point)
				{
					Assert::AreEqual(RS, Value, NullPtr, LINE_INFO());
				}
			}

			/* N3D Point 1 data tests*/
			RS = Half + (Two * P3);
			auto S3 = TSimulationStub<P3>();
			Assert::AreEqual(Zero, S3.Parameters.Alpha, NullPtr, LINE_INFO());
			Assert::AreEqual(Zero, S3.Parameters.Weight, NullPtr, LINE_INFO());
			Assert::AreEqual(N0, S3.Parameters.Size, NullPtr, LINE_INFO());
			TData<TSimulationStub<P3>::FPoint> R3;
			S3.Parameters.Alpha = Half;
			S3.Parameters.Size = P3;
			S3.Parameters.Weight = Two;
			S3.Initialize();
			Assert::AreEqual(P3, S3.State.Space.Size(), NullPtr, LINE_INFO());
			for (const auto &Point : S3.State.Space)
			{
				for (const auto &Value : Point)
				{
					Assert::AreEqual(Half, Value, NullPtr, LINE_INFO());
				}
			}
			S3.Start(R3);
			Assert::AreEqual(P3, S3.NSteps(), NullPtr, LINE_INFO());
			Assert::AreEqual(P3, R3.Size(), NullPtr, LINE_INFO());
			for (const auto &Point : R3)
			{
				for (const auto &Value : Point)
				{
					Assert::AreEqual(RS, Value, NullPtr, LINE_INFO());
				}
			}

			/* NND Point 1 data tests*/
			RS = Half + (Two * PN);
			auto SN = TSimulationStub<PN>();
			Assert::AreEqual(Zero, SN.Parameters.Alpha, NullPtr, LINE_INFO());
			Assert::AreEqual(Zero, SN.Parameters.Weight, NullPtr, LINE_INFO());
			Assert::AreEqual(N0, SN.Parameters.Size, NullPtr, LINE_INFO());
			TData<TSimulationStub<PN>::FPoint> RN;
			SN.Parameters.Alpha = Half;
			SN.Parameters.Size = PN;
			SN.Parameters.Weight = Two;
			SN.Initialize();
			Assert::AreEqual(PN, SN.State.Space.Size(), NullPtr, LINE_INFO());
			for (const auto &Point : SN.State.Space)
			{
				for (const auto &Value : Point)
				{
					Assert::AreEqual(Half, Value, NullPtr, LINE_INFO());
				}
			}
			SN.Start(RN);
			Assert::AreEqual(PN, SN.NSteps(), NullPtr, LINE_INFO());
			Assert::AreEqual(PN, RN.Size(), NullPtr, LINE_INFO());
			for (const auto &Point : RN)
			{
				for (const auto &Value : Point)
				{
					Assert::AreEqual(RS, Value, NullPtr, LINE_INFO());
				}
			}


		}

		TEST_METHOD(TestIterator)
		{
			const FReal Zero = 0, One = 1, Two = 2, Three = 3, Four = 4, Five = 5;
			const FSize HI0 = 0, HI1 = 1, HI2 = 2, HI3 = 3, HIN = 4096, HIK = 8192, HINBy2 = HIN / 2;
			const FSize Offset = 8, Stride = 16, StopAt = HIN + HINBy2;

			FSize Size = 0;
			FDescriptor Select;

			Select.bHeap = False;
			Select.N = 0;
			Select.Offset = Offset;
			Select.Pointer = _Make((sizeof(FReal) + Stride) * HIK + Offset);
			Select.Size = Select._Size = HIK;
			Select.Type = None;
			Select.Stride = Stride;
			Select.SizeOf = sizeof(FReal);
			_Set(Select.Pointer, &NullPtr, (sizeof(FReal) + Stride) * HIK + Offset);

			/* N0 Ierator tests */
			Select.Size = HI0;
			TIterator<FReal> I0(Select);
			for (auto &Value : I0)
			{
				Assert::Fail(NullPtr, LINE_INFO());
			}
			Assert::AreEqual(HI0, Size, NullPtr, LINE_INFO());
			for (const auto &Value : I0)
			{
				Assert::Fail(NullPtr, LINE_INFO());
			}

			/* N1 Ierator tests */
			Select.Size = HI1;
			TIterator<FReal> I1(Select);
			Size = 0;
			for (auto &Value : I1)
			{
				Value = One;
				++Size;
			}
			Assert::AreEqual(HI1, Size, NullPtr, LINE_INFO());
			for (const auto &Value : I1)
			{
				Assert::AreEqual(One, Value, NullPtr, LINE_INFO());
			}

			/* N2 Ierator tests */
			Select.Size = HI2;
			TIterator<FReal> I2(Select);
			Size = 0;
			for (auto &Value : I2)
			{
				Value = Two;
				++Size;
			}
			Assert::AreEqual(HI2, Size, NullPtr, LINE_INFO());
			for (const auto &Value : I2)
			{
				Assert::AreEqual(Two, Value, NullPtr, LINE_INFO());
			}

			/* N3 Ierator tests */
			Select.Size = HI3;
			TIterator<FReal> I3(Select);
			Size = 0;
			for (auto &Value : I3)
			{
				Value = Three;
				++Size;
			}
			Assert::AreEqual(HI3, Size, NullPtr, LINE_INFO());
			for (const auto &Value : I3)
			{
				Assert::AreEqual(Three, Value, NullPtr, LINE_INFO());
			}

			/* NN Ierator tests */
			Select.Size = HIN;
			TIterator<FReal> IN(Select);
			Size = 0;
			for (auto &Value : IN)
			{
				Value = Four;
				++Size;
			}
			Assert::AreEqual(HIN, Size, NullPtr, LINE_INFO());
			for (const auto &Value : IN)
			{
				Assert::AreEqual(Four, Value, NullPtr, LINE_INFO());
			}

			/* Reset test */
			Select.Size = HIK;
			TIterator<FReal> IK(Select);
			IK.Reset(HIN);
			Size = 0;
			for (auto &Value : IK)
			{
				Value = Five;
				++Size;
			}
			Assert::AreEqual(HIK - HIN, Size, NullPtr, LINE_INFO());

			/* OnStop and OnGet test */
			FReal Six = 6; FReal Zeven = 7;
			TIterator<FReal> IS;
			IS.OnStop = [&StopAt](auto Index) -> auto { return Index > StopAt; };
			IS.OnGet = [&Six, &Zeven, &HIN](auto Index, auto Offset, auto Stride) -> FReal& { return Index == HIN ? Six : Zeven; };
			Size = 0;
			for (auto &Value : IS)
			{
				if(Size == HIN)
				{
					Assert::AreEqual(Six, Value, NullPtr, LINE_INFO());
				}
				else
				{
					Assert::AreEqual(Zeven, Value, NullPtr, LINE_INFO());
				}
				++Size;
			}
			Assert::AreEqual(StopAt + 1, Size, NullPtr, LINE_INFO());
		}

		TEST_METHOD(TestRecord)
		{
			

		}

		TEST_METHOD(TestPointer)
		{


		}

		TEST_METHOD(TestKDTree)
		{


		}

		TEST_METHOD(TestKTree)
		{

		}

		TEST_METHOD(TestReference)
		{
			const FReal Zero = 0, One = 1, Two = 2, Three = 3, Four = 4, Five = 5;
			const FSize HI0 = 0, HI1 = 1, HI2 = 2, HI3 = 3, HIN = 4096, HIK = 8192;
			FReal Number = Four, OtherNumber = Three;
			FSize Select = HIN/2;

			TReferences<HIN, FReal> RFN;
			
			/* HI1 iterator, assign and index test */
			for (const auto Pointer : RFN)
			{
				Assert::IsNotNull(Pointer, NullPtr, LINE_INFO());
			}
			RFN = NullPtr;
			for (const auto Pointer : RFN)
			{
				Assert::IsNull(Pointer, NullPtr, LINE_INFO());
			}
			RFN = &Number;
			for (const auto Pointer : RFN)
			{
				Assert::AreSame(Number, *Pointer, NullPtr, LINE_INFO());
			}
			for (auto &Pointer : RFN)
			{
				Pointer = &OtherNumber;
			}
			for (const auto Pointer : RFN)
			{
				Assert::AreSame(OtherNumber, *Pointer, NullPtr, LINE_INFO());
			}
			OtherNumber = Five;
			for (const auto Pointer : RFN)
			{
				Assert::AreSame(OtherNumber, *Pointer, NullPtr, LINE_INFO());
			}

			/* HI1 index access test */
			RFN[Select] = One;
			Assert::AreEqual(One, OtherNumber, NullPtr, LINE_INFO());
			for (const auto Pointer : RFN)
			{
				Assert::AreSame(OtherNumber, *Pointer, NullPtr, LINE_INFO());
			}
		}

	};



}