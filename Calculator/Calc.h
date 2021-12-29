#include <bitset>
#include <vector>
#pragma once
enum Calc_System { System_Hex, System_Dec, System_Bin, System_Oct };
enum Calc_Typ {BYTE, QWORD, DWORD, WORD};
class Calc
{
	int result;
	int position;
	Calc_System System;
	Calc_Typ Typ;
	std::bitset<64> bin_arr;
public:
	std::vector<std::string> values;
	std::vector<int>int_values;
	Calc();
	int get_result();
	int get_postion();
	int get_unset_bits();
	Calc_System get_system();
	Calc_Typ get_typ();
	void set_values_as_string(std::string values);
	void set_postion(int pos);
	void extract_values();
	void convert_values();
	void set_system(Calc_System system);
	void set_values(std::string values);
};

