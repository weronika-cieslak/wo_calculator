#include "pch.h"
#include "CppUnitTest.h"
#include "../Calculator/Calc.h"
#include "../Calculator/Calc.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
std::wstring ToString(Calc_System value)
{
	switch (value) {
	case Calc_System::System_Bin: return L"BIN"; 
	case Calc_System::System_Dec: return L"DEC";
	case Calc_System::System_Hex: return L"HEX";
	case Calc_System::System_Oct: return L"OCT";
	}

	return std::to_wstring(static_cast<int>(value));
}
std::wstring ToString(Calc_Typ value)
{
	switch (value) {
	case Calc_Typ::BYTE: return L"BYTE";
	case Calc_Typ::QWORD: return L"QWORD";
	case Calc_Typ::DWORD: return L"DWORD";
	case Calc_Typ::WORD: return L"WORD";
	}

	return std::to_wstring(static_cast<int>(value));
}
namespace UnitTestInit
{
	TEST_CLASS(UnitTestInit)
	{
	public:
		
		TEST_METHOD(Init)
		{
			Calc test = Calc();
			Assert::IsNotNull(&test);
		}
		TEST_METHOD(DefaultValue)
		{
			Calc test = Calc();
			Assert::IsTrue(test.get_result() == 0);
		}
		TEST_METHOD(Default_System) {
			Calc test = Calc();
			Assert::AreEqual(System_Dec, test.get_system());
		}
		TEST_METHOD(Default_Typ) {
			Calc test = Calc();
			Assert::AreEqual(test.get_typ(), QWORD);
		}
		TEST_METHOD(Default_BinArray) {
			Calc test = Calc();
			Assert::IsTrue(test.get_unset_bits() == 64);
		}
	};
}
namespace UnitTestInput {
	TEST_CLASS(UnitTestInput)
	{
	public:
		TEST_METHOD(InputBin) {
			Calc test = Calc();
			test.set_system(System_Bin);
			test.set_values("q1");
			Assert::IsTrue(test.values.back() == "1");
		}
		TEST_METHOD(InputBin1) {
			Calc test = Calc();
			test.set_system(System_Bin);
			test.set_values("1ww");
			Assert::IsTrue(test.values.back() == "1");
		}
		TEST_METHOD(InputBin2) {
			Calc test = Calc();
			test.set_system(System_Bin);
			test.set_values("11 w1e1");
			Assert::IsTrue(test.values.back() == "1111");
		}
		TEST_METHOD(InputBinChar) {
			Calc test = Calc();
			test.set_system(System_Bin);
			test.set_values("11 +1e1");
			Assert::IsTrue(test.values.back() == "11+11");
		}
		TEST_METHOD(InputBinChar1) {
			Calc test = Calc();
			test.set_system(System_Bin);
			test.set_values("11 +1*e1");
			Assert::IsTrue(test.values.back() == "11+1*1");
		}
	};
}
