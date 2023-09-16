/*
MSSV : 19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9

Test case 1
Input: 29  2  1980
Output: 1 / 3 / 1980
Test case 2
Input: 31 12 2019
Output: 1 / 1 / 2020
Test case 3
Input: 18 6 2001
Output: 19 / 6 / 2001
*/

#include <iostream>
#include <math.h>

int main()
{
	int day, month, year;
	std::cout << "Nhap ngay thang nam " << std::endl;
	std::cin >> day >> month >> year;
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		switch (month)
		{
		case 1: {
			while (day > 31) {
				std::cout << "Nhap lai ngay ";
				std::cin >> day;
			}
			if (day < 31) std::cout << "Ngay mai : " << day + 1 << " / " << month << " / " << year;
			if (day == 31) std::cout << "Ngay mai : " << 1 << " / " << month + 1 << " / " << year;
			break; }
		case 2: {
			while (day > 29) {
				std::cout << "Nhap lai ngay ";
				std::cin >> day;
			}
			if (day < 29) std::cout << "Ngay mai : " << day + 1 << " / " << month << " / " << year;
			if (day == 29) std::cout << "Ngay mai : " << 1 << " / " << month + 1 << " / " << year;
			break; }
		case 3: {
			while (day > 31) {
				std::cout << "Nhap lai ngay ";
				std::cin >> day;
			}
			if (day < 31) std::cout << "Ngay mai : " << day + 1 << " / " << month << " / " << year;
			if (day == 31) std::cout << "Ngay mai : " << 1 << " / " << month + 1 << " / " << year;
			break; }
		case 4: {
			while (day > 30) {
				std::cout << "Nhap lai ngay ";
				std::cin >> day;
			}
			if (day < 30) std::cout << "Ngay mai : " << day + 1 << " / " << month << " / " << year;
			if (day == 30) std::cout << "Ngay mai : " << 1 << " / " << month + 1 << " / " << year;
			break; }
		case 5: {
			while (day > 31) {
				std::cout << "Nhap lai ngay ";
				std::cin >> day;
			}
			if (day < 31) std::cout << "Ngay mai : " << day + 1 << " / " << month << " / " << year;
			if (day == 31) std::cout << "Ngay mai : " << 1 << " / " << month + 1 << " / " << year;
			break; }
		case 6: {
			while (day > 30) {
				std::cout << "Nhap lai ngay ";
				std::cin >> day;
			}
			if (day < 30) std::cout << "Ngay mai : " << day + 1 << " / " << month << " / " << year;
			if (day == 30) std::cout << "Ngay mai : " << 1 << " / " << month + 1 << " / " << year;
			break; }
		case 7: {
			while (day > 31) {
				std::cout << "Nhap lai ngay ";
				std::cin >> day;
			}
			if (day < 31) std::cout << "Ngay mai : " << day + 1 << " / " << month << " / " << year;
			if (day == 31) std::cout << "Ngay mai : " << 1 << " / " << month + 1 << " / " << year;
			break; }
		case 8: {
			while (day > 31) {
				std::cout << "Nhap lai ngay ";
				std::cin >> day;
			}
			if (day < 31) std::cout << "Ngay mai : " << day + 1 << " / " << month << " / " << year;
			if (day == 31) std::cout << "Ngay mai : " << 1 << " / " << month + 1 << " / " << year;
			break; }
		case 9: {
			while (day > 30) {
				std::cout << "Nhap lai ngay ";
				std::cin >> day;
			}
			if (day < 30) std::cout << "Ngay mai : " << day + 1 << " / " << month << " / " << year;
			if (day == 30) std::cout << "Ngay mai : " << 1 << " / " << month + 1 << " / " << year;
			break; }
		case 10: {
			while (day > 31) {
				std::cout << "Nhap lai ngay ";
				std::cin >> day;
			}
			if (day < 31) std::cout << "Ngay mai : " << day + 1 << " / " << month << " / " << year;
			if (day == 31) std::cout << "Ngay mai : " << 1 << " / " << month + 1 << " / " << year;
			break; }
		case 11: {
			while (day > 30) {
				std::cout << "Nhap lai ngay ";
				std::cin >> day;
			}
			if (day < 30) std::cout << "Ngay mai : " << day + 1 << " / " << month << " / " << year;
			if (day == 30) std::cout << "Ngay mai : " << 1 << " / " << month + 1 << " / " << year;
			break; }
		case 12: {
			while (day > 31) {
				std::cout << "Nhap lai ngay ";
				std::cin >> day;
			}
			if (day < 31) std::cout << "Ngay mai : " << day + 1 << " / " << month << " / " << year;
			if (day == 31) std::cout << "Ngay mai : " << 1 << " / " << 1 << " / " << year + 1;
			break; }
		}
	}
	else
	{
		switch (month)
		{
		case 1: {
			while (day > 31) {
				std::cout << "Nhap lai ngay ";
				std::cin >> day;
			}
			if (day < 31) std::cout << "Ngay mai : " << day + 1 << " / " << month << " / " << year;
			if (day == 31) std::cout << "Ngay mai : " << 1 << " / " << month + 1 << " / " << year;
			break; }
		case 2: {
			while (day > 28) {
				std::cout << "Nhap lai ngay ";
				std::cin >> day;
			}
			if (day < 28) std::cout << "Ngay mai : " << day + 1 << " / " << month << " / " << year;
			if (day == 28) std::cout << "Ngay mai : " << 1 << " / " << month + 1 << " / " << year;
			break; }
		case 3: {
			while (day > 31) {
				std::cout << "Nhap lai ngay ";
				std::cin >> day;
			}
			if (day < 31) std::cout << "Ngay mai : " << day + 1 << " / " << month << " / " << year;
			if (day == 31) std::cout << "Ngay mai : " << 1 << " / " << month + 1 << " / " << year;
			break; }
		case 4: {
			while (day > 30) {
				std::cout << "Nhap lai ngay ";
				std::cin >> day;
			}
			if (day < 30) std::cout << "Ngay mai : " << day + 1 << " / " << month << " / " << year;
			if (day == 30) std::cout << "Ngay mai : " << 1 << " / " << month + 1 << " / " << year;
			break; }
		case 5: {
			while (day > 31) {
				std::cout << "Nhap lai ngay ";
				std::cin >> day;
			}
			if (day < 31) std::cout << "Ngay mai : " << day + 1 << " / " << month << " / " << year;
			if (day == 31) std::cout << "Ngay mai : " << 1 << " / " << month + 1 << " / " << year;
			break; }
		case 6: {
			while (day > 30) {
				std::cout << "Nhap lai ngay ";
				std::cin >> day;
			}
			if (day < 30) std::cout << "Ngay mai : " << day + 1 << " / " << month << " / " << year;
			if (day == 30) std::cout << "Ngay mai : " << 1 << " / " << month + 1 << " / " << year;
			break; }
		case 7: {
			while (day > 31) {
				std::cout << "Nhap lai ngay ";
				std::cin >> day;
			}
			if (day < 31) std::cout << "Ngay mai : " << day + 1 << " / " << month << " / " << year;
			if (day == 31) std::cout << "Ngay mai : " << 1 << " / " << month + 1 << " / " << year;
			break; }
		case 8: {
			while (day > 31) {
				std::cout << "Nhap lai ngay ";
				std::cin >> day;
			}
			if (day < 31) std::cout << "Ngay mai : " << day + 1 << " / " << month << " / " << year;
			if (day == 31) std::cout << "Ngay mai : " << 1 << " / " << month + 1 << " / " << year;
			break; }
		case 9: {
			while (day > 30) {
				std::cout << "Nhap lai ngay ";
				std::cin >> day;
			}
			if (day < 30) std::cout << "Ngay mai : " << day + 1 << " / " << month << " / " << year;
			if (day == 30) std::cout << "Ngay mai : " << 1 << " / " << month + 1 << " / " << year;
			break; }
		case 10: {
			while (day > 31) {
				std::cout << "Nhap lai ngay ";
				std::cin >> day;
			}
			if (day < 31) std::cout << "Ngay mai : " << day + 1 << " / " << month << " / " << year;
			if (day == 31) std::cout << "Ngay mai : " << 1 << " / " << month + 1 << " / " << year;
			break; }
		case 11: {
			while (day > 30) {
				std::cout << "Nhap lai ngay ";
				std::cin >> day;
			}
			if (day < 30) std::cout << "Ngay mai : " << day + 1 << " / " << month << " / " << year;
			if (day == 30) std::cout << "Ngay mai : " << 1 << " / " << month + 1 << " / " << year;
			break; }
		case 12: {
			while (day > 31) {
				std::cout << "Nhap lai ngay ";
				std::cin >> day;
			}
			if (day < 31) std::cout << "Ngay mai : " << day + 1 << " / " << month << " / " << year;
			if (day == 31) std::cout << "Ngay mai : " << 1 << " / " << 1 << " / " << year + 1;
			break; }
		}
	}
	std::cout << std::endl;

	system("PAUSE");
	return 0;
}