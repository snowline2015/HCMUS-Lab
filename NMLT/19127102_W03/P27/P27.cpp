/*
MSSV : 19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9

Test case 1
Input: 1500000 1 2
Output: 1530000
Test case 2
Input: 1500000 2 2
Output: 1560600
Test case 3
Input: 999999000 12 12.5
Output: 4109886563
*/
#include <iostream>
#include <math.h>
#include <iomanip>

int main()
{
	double rate;
	long int balance;
	int	month;
	std::cout << "Nhap so tien gui : ";
	std::cin >> balance;
	std::cout << "\nNhap so thang gui : ";
	std::cin >> month;
	while (month < 0)
	{
		std::cout << "\nNhap lai so thang gui : ";
		std::cin >> month;
	}
	std::cout << "\nNhap lai suat : ";
	std::cin >> rate;
	while (rate <= 0 || 100 <= rate)
	{
		std::cout << "\nNhap lai lai suat : ";
		std::cin >> rate;
	}
	rate = rate / 100;
	std::cout << "Tong so ten lai : " << std::fixed << std::setprecision(0) << balance * pow(1 + rate, month) << std::endl;

	system("PAUSE");
	return 0;
}