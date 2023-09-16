#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#include <iostream>
#include <fstream>
#include <string>

class Ngay {
private:
	int day, month, year;
public:
	Ngay() { day = 1; month = 1; year = 1; }
	Ngay(int d, int m, int y);
	Ngay(int a);
	bool NamNhuan(int a);
	friend Ngay operator + (const int& a, const Ngay& b);
	friend Ngay operator + (const Ngay& a, const int& b);
	friend Ngay operator + (const Ngay& a, const Ngay& b);
	friend Ngay operator - (const int& a, const Ngay& b);
	friend Ngay operator - (const Ngay& a, const int& b);
	friend Ngay operator - (const Ngay& a, const Ngay& b);
	friend bool operator > (const Ngay& a, const Ngay& b);
	friend std::ostream& operator << (std::ostream& a, Ngay& b);
};

#endif