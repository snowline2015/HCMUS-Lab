/*
MSSV :19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9
Chương trình : ĐỔI TIỀN

Test case 1
Input: 2500
Output: 
So to 500d la : 5
So to 200d la : 0
So to 100d la : 0
So to 50d la : 0
So to 20d la : 0
So to 10d la : 0
So to 5d la : 0
So to 2d la : 0
So to 1d la : 0

Test case 2
Input: 999999
Output:
So to 500d la : 1999
So to 200d la : 2
So to 100d la : 0
So to 50d la : 1
So to 20d la : 2
So to 10d la : 0
So to 5d la : 1
So to 2d la : 2
So to 1d la : 0

Test case 3
Input: 590338
Output:
So to 500d la : 1180
So to 200d la : 1
So to 100d la : 1
So to 50d la : 0
So to 20d la : 1
So to 10d la : 1
So to 5d la : 1
So to 2d la : 1
So to 1d la : 1
*/

#include <iostream>
#include <math.h>

int main()
{
	unsigned int money;
	int T500, T200, T100, T50, T20, T10, T5, T2, T1;

	std::cout << "Nhap so tien can doi : ";
	std::cin >> money;
	T500 = money / 500000;
	T200 = (money - T500 * 500000) / 200000;
	T100 = (money - T500 * 500000 - T200 * 200000) / 100000;
	T50 = (money - T500 * 500000 - T200 * 200000 - T100 * 100000) / 50000;
	T20 = (money - T500 * 500000 - T200 * 200000 - T100 * 100000 - T50 * 50000) / 20000;
	T10 = (money - T500 * 500000 - T200 * 200000 - T100 * 100000 - T50 * 50000 - T20 * 20000) / 10000;
	T5 = (money - T500 * 500000 - T200 * 200000 - T100 * 100000 - T50 * 50000 - T20 * 20000 - T10 * 10000) / 5000;
	T2 = (money - T500 * 500000 - T200 * 200000 - T100 * 100000 - T50 * 50000 - T20 * 20000 - T10 * 10000 - T5 * 5000) / 2000;
	T1 = (money - T500 * 500000 - T200 * 200000 - T100 * 100000 - T50 * 50000 - T20 * 20000 - T10 * 10000 - T5 * 5000 - T2 * 2000) / 1000;
	std::cout << "So to 500000d la : " << T500 << std::endl;
	std::cout << "So to 200000d la : " << T200 << std::endl;
	std::cout << "So to 100000d la : " << T100 << std::endl;
	std::cout << "So to 50000d la : " << T50 << std::endl;
	std::cout << "So to 20000d la : " << T20 << std::endl;
	std::cout << "So to 10000d la : " << T10 << std::endl;
	std::cout << "So to 5000d la : " << T5 << std::endl;
	std::cout << "So to 2000d la : " << T2 << std::endl;
	std::cout << "So to 1000d la : " << T1 << std::endl;

	system("PAUSE");
	return 0;
}