/*
MSSV : 19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9

Test case 1
Input: 10 1 2019
Output: 10
Test case 2
Input: 31 12 1980
Output: 366
Test case 3
Input: 2 2 2019
Output: 33
*/

#include <iostream>
#include <math.h>

int main()
{
	int day, month, year;
	int S;
	int day1, day2, day3, day4, day5, day6, day7, day8, day9, day10, day11, day12;
	std::cout << "Input day, month, year : ";
	std::cin >> day >> month >> year;
	while (month <= 0 || 12 < month)
	{
		std::cout << "Input month : ";
		std::cin >> month;
	}

	switch (month)
	{
	case 1:
	{
		while (day > 31)
		{
			std::cout << "Input day : ";
			std::cin >> day;
		}break;
	}
	case 2:
	{
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		{
			while (day > 29)
			{
				std::cout << "Input day : ";
				std::cin >> day;
			}
		}
		else
			while (day > 28)
			{
				std::cout << "Input day : ";
				std::cin >> day;
			}break;
	}
	case 3:
	{
		while (day > 31)
		{
			std::cout << "Input day : ";
			std::cin >> day;
		}break;
	}
	case 4:
	{
		while (day > 30)
		{
			std::cout << "Input day : ";
			std::cin >> day;
		}break;
	}
	case 5:
	{
		while (day > 31)
		{
			std::cout << "Input day : ";
			std::cin >> day;
		}break;
	}
	case 6:
	{
		while (day > 30)
		{
			std::cout << "Input day : ";
			std::cin >> day;
		}break;
	}
	case 7:
	{
		while (day > 31)
		{
			std::cout << "Input day : ";
			std::cin >> day;
		}break;
	}
	case 8:
	{
		while (day > 31)
		{
			std::cout << "Input day : ";
			std::cin >> day;
		}break;
	}
	case 9:
	{
		while (day > 30)
		{
			std::cout << "Input day : ";
			std::cin >> day;
		}break;
	}
	case 10:
	{
		while (day > 31)
		{
			std::cout << "Input day : ";
			std::cin >> day;
		}break;
	}
	case 11:
	{
		while (day > 30)
		{
			std::cout << "Input day : ";
			std::cin >> day;
		}break;
	}
	case 12:
	{
		while (day > 31)
		{
			std::cout << "Input day : ";
			std::cin >> day;
		}break;
	}
	default: break;
	}

	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		day1 = 31;
		day2 = 29;
		day3 = 31;
		day4 = 30;
		day5 = 31;
		day6 = 30;
		day7 = 31;
		day8 = 31;
		day9 = 30;
		day10 = 31;
		day11 = 30;
		day12 = 31;
	}
	else
	{
		day1 = 31;
		day2 = 28;
		day3 = 31;
		day4 = 30;
		day5 = 31;
		day6 = 30;
		day7 = 31;
		day8 = 31;
		day9 = 30;
		day10 = 31;
		day11 = 30;
		day12 = 31;
	}
	switch (month)
	{
	case 1: S = day; break;
	case 2: S = day1 + day; break;
	case 3: S = day1 + day2 + day; break;
	case 4: S = day1 + day2 + day3 + day; break;
	case 5: S = day1 + day2 + day3 + day4 + day; break;
	case 6: S = day1 + day2 + day3 + day4 + day5 + day; break;
	case 7: S = day1 + day2 + day3 + day4 + day5 + day6 + day; break;
	case 8: S = day1 + day2 + day3 + day4 + day5 + day6 + day7 + day; break;
	case 9: S = day1 + day2 + day3 + day4 + day5 + day6 + day7 + day8 + day; break;
	case 10: S = day1 + day2 + day3 + day4 + day5 + day6 + day7 + day8 + day9 + day; break;
	case 11: S = day1 + day2 + day3 + day4 + day5 + day6 + day7 + day8 + day9 + day10 + day; break;
	case 12: S = day1 + day2 + day3 + day4 + day5 + day6 + day7 + day8 + day9 + day10 + day11 + day; break;
	}
	std::cout << S << std::endl;

	system("PAUSE");
	return 0;
}