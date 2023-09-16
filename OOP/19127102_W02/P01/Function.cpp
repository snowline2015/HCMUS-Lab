#include "Function.h"

std::ostream& operator << (std::ostream& a, Ngay& b) {
	return a << b.day << "/" << b.month << "/" << b.year;
}

bool Ngay::NamNhuan(int a) {
	if ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0) return true;
	else return false;
}

Ngay::Ngay(int d, int m, int y) {
	{
		this->day = d;
		this->month = m;
		this->year = y;
		if (this->day < 0)this->day = -this->day;
		while (this->month > 12) {
			this->month -= 12;
			this->year += 1;
		}
		while (this->day > 29) {
			switch (this->month) {
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			{
				if (this->day > 31) {
					this->day -= 31;
					this->month += 1;
				}
				break;
			}
			case 2:
			{
				if (this->day > 29 && this->NamNhuan(this->year) == true) {
					this->day -= 29;
					this->month += 1;
				}
				if (this->day > 28 && this->NamNhuan(this->year) == false) {
					this->day -= 28;
					this->month += 1;
				}
				break;
			}
			case 4:
			case 6:
			case 9:
			case 11:
			{
				if (this->day > 30) {
					this->day -= 30;
					this->month += 1;
				}
				break;
			}
			case 12:
			{
				if (this->day > 31) {
					this->day -= 31;
					this->month = 1;
					this->year += 1;
				}
				break;
			}
			}
		}
	}
}

Ngay::Ngay(int a) {
	Ngay date(0, 1, 1);
	int temp = a;
	while (temp >= 365) {
		if (NamNhuan(date.year) == true) {
			temp -= 366;
			date.year += 1;
		}
		else {
			temp -= 365;
			date.year += 1;
		}
	}
	while (temp != 0 && date.month <= 12) {
		switch (date.month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		{
			if (temp - 31 > 0) {
				date.month += 1;
				temp -= 31;
			}
			else {
				date.day += temp;
				temp = 0;
			}
			break;
		}
		case 2:
		{
			if (NamNhuan(date.year) == true && temp - 29 > 0) {
				date.month += 1;
				temp -= 29;
			}
			else if (temp - 28 > 0) {
				date.month += 1;
				temp -= 28;
			}
			else {
				date.day += temp;
				temp = 0;
			}
			break;
		}
		case 4:
		case 6:
		case 9:
		case 11:
		{
			if (temp - 30 > 0) {
				date.month += 1;
				temp -= 30;
			}
			else {
				date.day += temp;
				temp = 0;
			}
			break;
		}
		case 12:
		{
			date.day += temp;
			temp = 0;
			break;
		}
		}
	}
	this->day = date.day; this->month = date.month; this->year = date.year;
}

Ngay operator + (const int& a, const Ngay& b) {
	Ngay date(b.day, b.month, b.year);
	int temp = a;

	while (temp >= 365) {
		if (date.day == 29 && date.month == 2) {
			date.day = 28;
			temp -= 365;
			date.year += 1;
		}
		if ((date.month > 2 && date.NamNhuan(date.year + 1) == true && temp > 365) ||
			(date.month <= 2 && date.NamNhuan(date.year) == true && temp > 365)) {
			temp -= 366;
			date.year += 1;
		}
		if ((date.month > 2 && date.NamNhuan(date.year + 1) == false && temp >= 365) ||
			(date.month <= 2 && date.NamNhuan(date.year) == false && temp >= 365)) {
			temp -= 365;
			date.year += 1;
		}
	}
	
	while (temp > 0) {
		switch (date.month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		{
			if (date.day + temp > 31) {
				temp = date.day + temp - 32;
				date.day = 1;
				date.month += 1;
			}
			else {
				date.day = date.day + temp;
				temp = 0;
			}
			break;
		}
		case 2:
		{
			if (date.NamNhuan(date.year) == true && date.day + temp > 29) {
				temp = date.day + temp - 30;
				date.day = 1;
				date.month += 1;
			}
			else if (date.day + temp > 28) {
				temp = date.day + temp - 29;
				date.day = 1;
				date.month += 1;
			}
			else {
				date.day = date.day + temp;
				temp = 0;
			}
			break;
		}
		case 4:
		case 6:
		case 9:
		case 11:
		{
			if (date.day + temp > 30) {
				temp = date.day + temp - 31;
				date.day = 1;
				date.month += 1;
			}
			else {
				date.day = date.day + temp;
				temp = 0;
			}
			break;
		}
		case 12:
		{
			if (date.day + temp > 31) {
				temp = date.day + temp - 32;
				date.day = 1;
				date.month = 1;
				date.year += 1;
			}
			else {
				date.day = date.day + temp;
				temp = 0;
			}
			break;
		}
		}
	}
	return date;
}

Ngay operator + (const Ngay& a, const int& b) {
	return operator + (b, a);
}

Ngay operator + (const Ngay& a, const Ngay& b)
{
	Ngay date;
	date.year = a.year + b.year;
	if (a.month + b.month > 12) {
		date.month = a.month + b.month - 12;
		date.year += 1;
	}
	else date.month = a.month + b.month;
	date.day = a.day + b.day;
	while (date.day > 29) {
		switch (date.month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		{
			if (date.day > 31) {
				date.day -= 31;
				date.month += 1;
			}
			else goto ok;
			break;
		}
		case 2:
		{
			if (date.day > 29 && date.NamNhuan(date.year) == true) {
				date.day -= 29;
				date.month += 1;
			}
			else if (date.day > 28 && date.NamNhuan(date.year) == false) {
				date.day -= 28;
				date.month += 1;
			}
			else goto ok;
			break;
		}
		case 4:
		case 6:
		case 9:
		case 11:
		{
			if (date.day > 30) {
				date.day -= 30;
				date.month += 1;
			}
			else goto ok;
			break;
		}
		case 12:
		{
			if (date.day > 31) {
				date.day -= 31;
				date.month = 1;
				date.year += 1;
			}
			else goto ok;
			break;
		}
		}
	}
	ok:
	return date;
}

Ngay operator - (const int& a, const Ngay& b)
{
	Ngay date1(a), date2(b.day, b.month, b.year);
	return operator - (date1, date2);
}

Ngay operator - (const Ngay& a, const int& b)
{
	Ngay date(a.day, a.month, a.year);
	int temp = b;
	if (date.day != 1) {
		temp -= date.day - 1;
		date.day = 1;
	}
	while (temp >= 365) {
		if (date.month <= 2 && date.NamNhuan(date.year - 1) == true) {
			temp -= 366;
			date.year -= 1;
		}
		else {
			temp -= 365;
			date.year -= 1;
		}
	}
	while (temp != 0) {
		switch (date.month) {
		case 5:
		case 7:
		case 10:
		case 12:
		{
			if (temp >= 30) {
				temp -= 30;
				date.month -= 1;
			}
			else {
				if (date.day - temp < 0) {
					date.day = 30;
					date.month -= 1;
					date.day -= temp - 1;
					temp = 0;
				}
				else if (date.day - temp == 0) {
					date.day = 30;
					date.month -= 1;
					temp = 0;
				}
				else {
					date.day -= temp;
					temp = 0;
				}
			}
			break;
		}
		case 3:
		{
			if (temp >= 29 && date.NamNhuan(date.year) == true) {
				temp -= 29;
				date.month -= 1;
			}
			else if (temp >= 28 && date.NamNhuan(date.year) == false) {
				temp -= 28;
				date.month -= 1;
			}
			else {
				if (date.day - temp < 0) {
					if (date.NamNhuan(date.year) == true) date.day = 29;
					else date.day = 28;
					date.month -= 1;
					date.day -= temp - 1;
					temp = 0;
				}
				else if (date.day - temp == 0) {
					if (date.NamNhuan(date.year) == true) date.day = 29;
					else date.day = 28;
					date.month -= 1;
					temp = 0;
				}
				else {
					date.day -= temp;
					temp = 0;
				}
			}
			break;
		}
		case 1:
		case 2:
		case 4:
		case 6:
		case 8:
		case 9:
		case 11:
		{
			if (temp > 30) {
				temp -= 31;
				date.month -= 1;
			}
			else {
				if (date.day - temp < 0) {
					date.day = 31;
					date.month -= 1;
					date.day -= temp - 1;
					temp = 0;
				}
				else if (date.day - temp == 0) {
					date.day = 31;
					date.month -= 1;
					temp = 0;
				}
				else {
					date.day -= temp;
					temp = 0;
				}
			}
			break;
		}
		}
	}
	return date;
}

Ngay operator - (const Ngay& a, const Ngay& b)
{
	Ngay date;
	if (a.year - b.year > 0) {
		date.year = a.year - b.year;
		if (a.month - b.month > 0)
			date.month = a.month - b.month;
		else {
			date.month = 12 + (a.month - b.month);
			date.year = date.year - 1;
			if (date.year <= 0)
				std::cout << "Cannot operate this operation" << std::endl;
		}
		if (a.day - b.day > 0)
			date.day = a.day - b.day;
		else {
			switch (date.month) {
			case 1: {
				date.day = 31 + (a.day - b.day);
				date.month = 12;
				date.year -= 1;
				break;
			}
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
			{
				date.day = 31 + (a.day - b.day);
				date.month -= 1;
				break;
			}
			case 2:
			{
				if (date.NamNhuan(date.year) == true) {
					date.day = 29 + (a.day - b.day);
					date.month -= 1;
				}
				else {
					date.day = 28 + (a.day - b.day);
					date.month -= 1;
				}
				break;
			}
			case 4:
			case 6:
			case 9:
			case 11:
			{
				date.day = 30 + (a.day - b.day);
				date.month -= 1;
				break;
			}
			}
		}
		if (date.year <= 0) std::cout << "Cannot operate this operation" << std::endl;
		else return date;
	}
	else std::cout << "Cannot operate this operation" << std::endl;
}

bool operator > (const Ngay& a, const Ngay& b)
{
	if (a.year == b.year && a.month == b.month && a.day > b.day ||
		a.year == b.year && a.month > b.month || a.year > b.year)
		return true;
	else return false;
}