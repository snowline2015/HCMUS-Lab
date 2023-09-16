/*
MSSV : 19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9

Test case 1
Input: 1980 2
Output: 29
Test case 2
Input: 1941 3
Output: 31
Test case 3
Input: 2020 2
Output: 29
*/
#include <iostream>;
#include <math.h>

int main()
{
	int year, month;
	std::cout << "Nhap nam : ";
	std::cin >> year;
	std::cout << "Nhap thang : ";
	std::cin >> month;
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		std::cout << "Day la nam nhuan" << std::endl;
		switch (month)
		{
		case 1: std::cout << "thang nay co 31 ngay"; break;
		case 2: std::cout << "thang nay co 29 ngay"; break;
		case 3: std::cout << "thang nay co 31 ngay"; break;
		case 4: std::cout << "thang nay co 30 ngay"; break;
		case 5: std::cout << "thang nay co 31 ngay"; break;
		case 6: std::cout << "thang nay co 30 ngay"; break;
		case 7: std::cout << "thang nay co 31 ngay"; break;
		case 8: std::cout << "thang nay co 31 ngay"; break;
		case 9: std::cout << "thang nay co 30 ngay"; break;
		case 10: std::cout << "thang nay co 31 ngay"; break;
		case 11: std::cout << "thang nay co 30 ngay"; break;
		case 12: std::cout << "thang nay co 31 ngay"; break;
		default: std::cout << "Loi thang";
		}
	}
	else
	{
		std::cout << "Day la nam khong nhuan" << std::endl;
		switch (month)
		{
		case 1: std::cout << "thang nay co 31 ngay"; break;
		case 2: std::cout << "thang nay co 28 ngay"; break;
		case 3: std::cout << "thang nay co 31 ngay"; break;
		case 4: std::cout << "thang nay co 30 ngay"; break;
		case 5: std::cout << "thang nay co 31 ngay"; break;
		case 6: std::cout << "thang nay co 30 ngay"; break;
		case 7: std::cout << "thang nay co 31 ngay"; break;
		case 8: std::cout << "thang nay co 31 ngay"; break;
		case 9: std::cout << "thang nay co 30 ngay"; break;
		case 10: std::cout << "thang nay co 31 ngay"; break;
		case 11: std::cout << "thang nay co 30 ngay"; break;
		case 12: std::cout << "thang nay co 31 ngay"; break;
		default: std::cout << "Loi thang";
		}
	}
	std::cout << std::endl;

	system("PAUSE");
	return 0;
}