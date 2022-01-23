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
namespace UnitTest
{
	TEST_CLASS(Init)
	{
	public:
		
		TEST_METHOD(InitCalc)
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
			Assert::AreEqual(test.get_typ(), WORD);
		}
		TEST_METHOD(Default_BinArray) {
			Calc test = Calc();
			Assert::IsTrue(test.get_unset_bits() == 64);
		}
	};

	TEST_CLASS(Input)
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
			test.set_values("1w2w");
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
		TEST_METHOD(InputHex) {
			Calc test = Calc();
			test.set_system(System_Hex);
			test.set_values(" 3433 A HE3P");
			Assert::IsTrue(test.values.back() == "3433AE3");
		}
		TEST_METHOD(InputHexChar) {
			Calc test = Calc();
			test.set_system(System_Hex);
			test.set_values(" 1A F5 +68E");
			Assert::IsTrue(test.values.back() == "1AF5+68E");
		}
		TEST_METHOD(InputHex3) {
			Calc test = Calc();
			test.set_system(System_Hex);
			test.set_values("1ytu6tA");
			Assert::IsTrue(test.values.back() == "16A");
		}
		TEST_METHOD(InputOct) {
			Calc test = Calc();
			test.set_system(System_Oct);
			test.set_values("1hfy47fgh59");
			Assert::IsTrue(test.values.back() == "1475");
		}
		TEST_METHOD(InputOctChar) {
			Calc test = Calc();
			test.set_system(System_Oct);
			test.set_values("595reg+46-5y");
			Assert::IsTrue(test.values.back() == "55+46-5");
		}
		TEST_METHOD(InputOct2) {
			Calc test = Calc();
			test.set_system(System_Oct);
			test.set_values("4574ryt72352tg");
			Assert::IsTrue(test.values.back() == "457472352");
		}
		TEST_METHOD(inBYTE) {
			Calc test = Calc();
			test.set_typ(BYTE);
			test.set_values("127");
			test.convert_values();
			Assert::IsTrue(test.int_values.back() == 127);
		}
		TEST_METHOD(inBYTE) {
			Calc test = Calc();
			test.set_typ(BYTE);
			test.set_values("128");
			test.convert_values();
			Assert::IsTrue(test.int_values.back() == 12);
		}
		
		/*
		TEST_METHOD(add_decimal) {
			Calc test = Calc();
			Assert::AreEqual(4, calc.Add_decimal(2, 2));
			Assert::AreEqual(-1, calc.Add_decimal(2, -3));
		}
		TEST_METHOD(substract_decimal) {
			Calc test = Calc();
			Assert::AreEqual(10, calc.Substract_decimal(15, 5));
			Assert::AreEqual(20, calc.Substract_decimal(-10, -30));
			Assert::AreEqual(-15, calc.Substract_decimal(-10, 5));
		}
		TEST_METHOD(multiplication_decimal) {

			Calc test = Calc();
			Assert::AreEqual(2, calc.multiplication_decimal(1, 2));
			Assert:AreEqual(0, calc.multiplication_decimal(0, 11));
			Assert::AreEqual(-1, calc.multiplication_decimal(-1, 1));
		}
		TEST_METHOD(divide_decimal) {
			Calc test = calc();
			Assert::AreEqual(2, calc.divide_decimal(12, 6));
			Assert::AreEqual(, calc.dividedecimal(12, 0));
		}
		//dwójkowy
		TEST_METHOD(add_binary) {
			Calc test = Calc();
			Assert::AreEqual(1111, calc.Add_binary(1000,111));
		}
		TEST_METHOD(substract_binary) {
			Calc test = Calc();
			Assert::AreEqual(0001, calc.Substract_binary(1000,111));
		}
		TEST_METHOD(multiplication_binary) {

			Calc test = Calc();
			Assert::AreEqual(111000, calc.multiplication_binary(1000,111));

		}
		//ósemkowy
		TEST_METHOD(add_octal) {
			Calc test = Calc();
			Assert::AreEqual(442, calc.Add_octal(135, 305));
		}
		TEST_METHOD(substract_octal) {
			Calc test = Calc();
			Assert::AreEqual(7570, calc.Substract_octal(7654, 64));
		}
		TEST_METHOD(multiplication_octal) {

			Calc test = Calc();
			Assert::AreEqual(721060, calc.multiplication_octal(744, 754));	
		}

		*/
	};
}
