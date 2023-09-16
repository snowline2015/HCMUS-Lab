/*
MSSV : 19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9

Test case 1
Input: 4.0
Output: 4.0
Test case 2
Input: 3.8
Output: 3.5
Test case 3
Input: 4.1
Output: 4
*/

#include <iostream>
#include <math.h>
#include <iomanip>

int main()
{
	double a;
	std::cout << "Nhap 1 so thuc : ";
	std::cin >> a;
	if (a == (int)a) std::cout << "So thuc da lam tron : " << std::fixed << std::setprecision(1) << a << std::endl;
	else if (a >= ((int)a) + 0.5) std::cout << "So thuc da lam tron : " << ((int)a) + 0.5 << std::endl;
	else if (a < ((int)a) + 0.5) std::cout << "So thuc da lam tron : " << std::fixed << std::setprecision(1) << (int)a << std::endl;

	system("PAUSE");
	return 0;
}