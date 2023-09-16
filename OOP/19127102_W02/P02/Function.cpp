#include "Function.h"

std::ostream& operator << (std::ostream& a, ThoiGian& b)
{
	return a << std::setfill('0') << std::setw(2) <<  b.hr << ":" 
		<< std::setfill('0') << std::setw(2) << b.min << ":"
		<< std::setfill('0') << std::setw(2) << b.sec;
}

ThoiGian::ThoiGian(int s) {
	if (s >= 60) { 
		this->min = (int)(s / 60);
		this->sec = s - this->min * 60;
		if (this->min >= 60) {
			this->hr = (int)(this->min / 60);
			this->min -= this->hr * 60;
		}
		else this->hr = 0;
	}
	else { 
		this->hr = this->min = 0;
		this->sec = s;
	}
}

ThoiGian::ThoiGian(int m, int s) {
	if (s < 0) this->sec = -s;
	else this->sec = s;
	if (this->sec >= 60) {
		this->min = (int)(this->sec / 60);
		this->sec -= this->min * 60;
		this->min += m;
		if (this->min >= 60) {
			this->hr = (int)(this->min / 60);
			this->min -= this->hr * 60;
		}
		else this->hr = 0;
	}
	else {
		this->min = m;
		if (this->min >= 60) {
			this->hr = (int)(this->min / 60);
			this->min -= this->hr * 60;
		}
		else this->hr = 0;
	}
}

ThoiGian::ThoiGian(int h, int m, int s)
{
	if (s < 0) this->sec = -s;
	else this->sec = s;
	if (this->sec >= 60) {
		this->min = (int)(this->sec / 60);
		this->sec -= this->min * 60;
		if (m < 0) 	this->min += -m;
		else this->min += m;
		if (this->min >= 60) {
			this->hr = (int)(this->min / 60);
			this->min -= this->hr * 60;
			this->hr += h;
		}
		else this->hr = h;
	}
	else {
		if (m < 0) 	this->min = -m;
		else this->min = m;
		if (this->min >= 60) {
			this->hr = (int)(this->min / 60);
			this->min -= this->hr * 60;
			this->hr += h;
		}
		else this->hr = h;
	}
}

ThoiGian operator + (const int& a, const ThoiGian& b)
{
	ThoiGian time(a);
	return operator + (time, b);
}

ThoiGian operator + (const ThoiGian& a, const int& b) {
	return operator + (b, a);
}

ThoiGian operator + (const ThoiGian& a, const ThoiGian& b) {
	ThoiGian time;
	time.sec = a.sec + b.sec;
	time.min = a.min + b.min;
	time.hr = a.hr + b.hr;
	if (time.sec >= 60) {
		time.sec -= 60;
		time.min += 1;
	}
	if (time.min >= 60) {
		time.min -= 60;
		time.hr += 1;
	}
	return time;
}

ThoiGian operator - (const int& a, const ThoiGian& b)
{
	ThoiGian time(a);
	return operator - (time, b);
}

ThoiGian operator - (const ThoiGian& a, const int& b) {
	int temp = b;
	ThoiGian time(a.hr, a.min, a.sec);
	temp -= time.sec;
	time.sec = 0;
	while (temp >= 60) {
		temp -= 60;
		time.min -= 1;
		if (time.min < 0) {
			time.hr -= 1;
			time.min = 59;
		}
	}
	if (temp != 0) {
		time.min -= 1;
		time.sec = 60 - temp;
	}
	if (time.hr < 0) {
		time.hr = 0; time.min = 0; time.sec = 0;
	}
	return time;
}

ThoiGian operator - (const ThoiGian& a, const ThoiGian& b)
{
	ThoiGian time;
	time.hr = a.hr - b.hr;
	time.min = a.min - b.min;
	time.sec = a.sec - b.sec;
	if (time.sec < 0) {
		while (time.sec <= -60) {
			time.sec += 60;
			time.min -= 1;
		}
		time.min -= 1;
		time.sec = 60 + time.sec;
	}
	if (time.min < 0) {
		while (time.min <= -60) {
			time.min += 60;
			time.hr -= 1;
		}
		time.hr -= 1;
		time.min = 60 + time.min;
	}
	if (time.hr < 0) {
		time.hr = 0; time.min = 0; time.sec = 0;
	}
	return time;
}

bool operator <= (const ThoiGian& a, const ThoiGian& b)
{
	if (a.hr <= b.hr || a.hr == b.hr && a.min <= b.min ||
		a.hr == b.hr && a.min == b.min && a.sec <= b.sec)
		return true;
	else return false;
}

bool operator <= (const int& a, const ThoiGian& b)
{
	ThoiGian time(a);
	return operator <= (time, b);
}
