#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#include <iostream>
#include <iomanip>

class ThoiGian {
private:
	int hr, min, sec;
public:
	ThoiGian() { hr = 0; min = 0; sec = 0; }
	ThoiGian(int h, int m, int s);
	ThoiGian(int m, int s);
	ThoiGian(int s);
	friend ThoiGian operator + (const int& a, const ThoiGian& b);
	friend ThoiGian operator + (const ThoiGian& a, const int& b);
	friend ThoiGian operator + (const ThoiGian& a, const ThoiGian& b);
	friend ThoiGian operator - (const int& a, const ThoiGian& b);
	friend ThoiGian operator - (const ThoiGian& a, const int& b);
	friend ThoiGian operator - (const ThoiGian& a, const ThoiGian& b);
	friend bool operator <= (const ThoiGian& a, const ThoiGian& b);
	friend bool operator <= (const int& a, const ThoiGian& b);
	friend std::ostream& operator << (std::ostream& a, ThoiGian& b);
};

#endif