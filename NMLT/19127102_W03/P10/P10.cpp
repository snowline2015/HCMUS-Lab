/*
MSSV : 19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9

Test case 1
Input: 3 5 7
Output: "Vo nghiem"
Test case 2
Input: 2 -7 5
Output: x1 = 1.58, x2 = -1.58, x3 = 1.00, x4 = -1.00
Test case 3
Input: 3 -6 3
Output: x1 = 1.00, x2 = -1.00
*/

#include <iostream>
#include <math.h>
#include <iomanip>

int main()
{
	double a, b, c;
	double delta;
	double t, t1, t2;
	std::cout << "Nhap a, b, c : " << std::endl;
	std::cin >> a >> b >> c;
	delta = pow(b, 2) - (4 * a * c);
	std::cout << "PT trung phuong : " << a << "x^4 + " << b << "x^2 + " << c << " = " << 0 << std::endl;
	std::cout << "Dat t = x^2 (t >= 0)" << std::endl;
	std::cout << "PT bac 2 : " << a << "t^2 + " << b << "t + " << c << " = " << 0 << std::endl;

	if (a == 0) 
	{
		std::cout << "PT : " << b << "t + " << c << " = " << 0 << std::endl;
		std::cout << "t = " << (-c / b) << std::endl;
		if ((-c / b) < 0) std::cout << "Vo nghiem" << std::endl;
		else
		{
			std::cout << "x1 = " << std::fixed << std::setprecision(2) << sqrt(-c / b) << std::endl;
			std::cout << "x2 = " << std::fixed << std::setprecision(2) << -sqrt(-c / b) << std::endl;
		}
	}
	else if (delta < 0) 
	{
		std::cout << "Vo nghiem" << std::endl;
	}
	else if (delta == 0) 
	{
		t = -b / (2 * a);
		if (t < 0) std::cout << "Vo nghiem" << std::endl;
		else
		{
			std::cout << "x1 = " << std::fixed << std::setprecision(2) << sqrt(t) << std::endl;
			std::cout << "x2 = " << std::fixed << std::setprecision(2) << -sqrt(t) << std::endl;
		}
	}
	else 
	{
		t1 = (-b + sqrt(delta)) / (2 * a);
		t2 = (-b - sqrt(delta)) / (2 * a);
		if (t1 >= 0 && t2 < 0)
		{
			std::cout << "x1 = " << std::fixed << std::setprecision(2) << sqrt(t1) << std::endl;
			std::cout << "x2 = " << std::fixed << std::setprecision(2) << -sqrt(t1) << std::endl;
		}
		if (t1 < 0 && t2 >= 0)
		{
			std::cout << "x1 = " << std::fixed << std::setprecision(2) << sqrt(t2) << std::endl;
			std::cout << "x2 = " << std::fixed << std::setprecision(2) << -sqrt(t2) << std::endl;
		}
		if (t1 >= 0 && t2 >= 0)
		{
			std::cout << "x1 = " << std::fixed << std::setprecision(2) << sqrt(t1) << std::endl;
			std::cout << "x2 = " << std::fixed << std::setprecision(2) << -sqrt(t1) << std::endl;
			std::cout << "x3 = " << std::fixed << std::setprecision(2) << sqrt(t2) << std::endl;
			std::cout << "x4 = " << std::fixed << std::setprecision(2) << -sqrt(t2) << std::endl;
		}
		if (t1 < 0 && t2 < 0) std::cout << "Vo nghiem" << std::endl;
	}

	system("PAUSE");
	return 0;
}