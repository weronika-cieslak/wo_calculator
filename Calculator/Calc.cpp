#include <iostream>
#include "Calc.h"
Calc::Calc() {
	this->result = 0;
	this->System = System_Dec;
	this->Typ = WORD;
	this->position = 0;
}
int Calc::get_result() {
	return this->result;
}
int Calc::get_unset_bits() {
	return this->bin_arr.size() - this->bin_arr.count();
}
Calc_System Calc::get_system() {
	return this->System;
}
Calc_Typ Calc::get_typ() {
	return this->Typ;
}
void Calc::set_system(Calc_System system) {
	this->System = system;
}
void Calc::set_values_as_string(std::string values) {
	this->values.push_back(values);
}
void Calc::extract_values() {
	std::string bin = "01+-*/%";
	std::string dec = "0123456789+-*/%";
	std::string oct = "01234567+-*/%";
	std::string hex = "0123456789ABCDEF+-*/%";
	std::string choice = "";
	std::string temp = "";
	std::string last = this->values.back();
	switch (this->get_system()) {
	case System_Dec:
		choice = dec;
		break;
	case System_Bin:
		choice = bin;
		break;
	case System_Hex:
		choice = hex;
		break;
	case System_Oct:
		choice = oct;
		break;
	}

	for (int i = 0; i < last.size(); i++) {
		if (choice.find(last[i]) != std::string::npos) {
			temp += last[i];
		}
	}
	this->values.pop_back();
	this->values.push_back(temp);
}
void Calc::set_postion(int pos) {
	this->position = pos;
}
int Calc::get_postion() {
	return this->position;
}
void Calc::set_values(std::string values) {
	this->set_values_as_string(values);
	this->extract_values();
}
void Calc::convert_values() {
	std::string temp = "";
	std::string temp2 = "";
	
	for (int i = this->get_postion(); i < values.size(); i++) {
		temp += values[i];
	}
	this->set_postion(values.size());
	for (int i = 0; i <= temp.size(); i++) {
		if (temp[i] == '+' || temp[i] == '-' || temp[i] == '*' || temp[i] == '/' || temp[i] == '%'|| i == temp.size()) {
			if (temp2 != "") {
				int next = std::stoi(temp2);
				switch (this->get_typ()) {
				case BYTE:
					while (next < -128 || next > 127) {
						temp2.pop_back();
						next = std::stoi(temp2);
					}
					break;
				case WORD:
					while (next < -32768 || next > 32767) {
						temp2.pop_back();
						next = std::stoi(temp2);
					}
					break;
				case DWORD:
					break;
				case QWORD:
					break;
				}
				this->int_values.push_back(next);
				temp2 = "";
			}
		} else {
			temp2 += temp[i];
		}
	}

}
