/*
MSSV :19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9
Chương trình : DIỆN TÍCH HÌNH

Test case 1
Input: 3 5
Output: 50.94
Test case 2
Input: 25 18
Output: 1320.58
Test case 3
Input: 56 69
Output: 11548.55
*/

#include <iostream>
#include <math.h>
#include <iomanip>

int main()
{
	double edge, radius;
	double tamgiac, tron, area;
	const double PI = 3.14;
	std::cout << "Nhap canh tam giac deu va ban kinh hinh tron : ";
	std::cin >> edge >> radius;
	while (edge <= 0 || radius <= 0)
	{
		std::cout << "Nhap sai so\nXin vui long nhap canh tam giac deu va ban kinh hinh tron : ";
		std::cin >> edge >> radius;
	}
	tamgiac = sqrt(3) / 4 * pow(edge, 2);
	tron = PI * pow(radius, 2);
	area = tamgiac * 3 + tron - tron * 3 / 6;
	std::cout << "Dien tich hinh la : " << std::fixed << std::setprecision(2) << area << std::endl;

	system("PAUSE");
	return 0;
}