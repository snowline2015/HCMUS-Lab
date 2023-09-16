/*
MSSV : 19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9

Test case 1
Input: 1 2
Output: -2.00
Test case 2
Input: 9 3
Output: -0.33
Test case 3
Input: 8 -3
Output: 0.38
*/

#include <iostream>
#include <math.h>
#include <iomanip>

int main()
{
	double a, b;
	std::cout << "Nhap a va b : ";
	std::cin >> a >> b;
	std::cout << "PT bac 1 : " << a << "x + " << b << " = 0" << std::endl;
	std::cout << "x = " << std::fixed << std::setprecision(2) << -b / a << std::endl;

	system("PAUSE");
	return 0;
}