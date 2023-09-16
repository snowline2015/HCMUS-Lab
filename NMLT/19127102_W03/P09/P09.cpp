/*
MSSV : 19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9

Test case 1
Input: 3 5 7
Output: "Vo nghiem"
Test case 2
Input: 2 -7 5
Output: x1 = 2.50, x2 = 1.00
Test case 3
Input: 1 2 1
Output: x = -1
*/

#include <iostream>
#include <math.h>
#include <iomanip>

int main()
{
	double a, b, c;
	double delta;
	std::cout << "Nhap a, b, c : " << std::endl;
	std::cin >> a >> b >> c;
	delta = pow(b, 2) - (4 * a * c);
	std::cout << "PT bac 2 la: " << a << "x^2 + " << b << "x + " << c << " = " << 0 << std::endl;
	if (a == 0) {
		std::cout << "PT la: " << b << "x + " << c << " = " << 0;
		std::cout << "x = " << (-c / b);
	}
	else if (delta < 0) {
		std::cout << "Vo nghiem" << std::endl;
	}
	else if (delta == 0) {
		std::cout << "Nghiem kep. x = " << std::fixed << std::setprecision(2) << -b / (2 * a) << std::endl;
	}
	else {
		std::cout << "2 nghiem phan biet " << std::endl;
		std::cout << "x1 = " << std::fixed << std::setprecision(2) << (-b + sqrt(delta)) / (2 * a) << std::endl;
		std::cout << "x2 = " << std::fixed << std::setprecision(2) << (-b - sqrt(delta)) / (2 * a) << std::endl;
	}

	system("PAUSE");
	return 0;
}