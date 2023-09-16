/*
MSSV :19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9
Chương trình : TÍNH GIÁ TRỊ BIỂU THỨC

Test case 1
Input: 10
Output: 1788.9110640674, 0.0000000217
Test case 2
Input: 1
Output: 60.0000000000, 0.1758440388
Test case 3
Input: 8
Output: 1261.0966799188, 0.0000009407
*/

#include<iostream>
#include<math.h>
#include<iomanip>

int main()
{
	double x, y1, y2;
	const double PI = 3.14, e = 2.71;
	std::cout << "Nhap so thuc khong am ";
	std::cin >> x;
	y1 = 4 * (pow(x,2) + 10 * x * sqrt(x) + 3 * x + 1);
	y2 = (sin(PI * pow(x,2)) + sqrt(pow(x,2) + 1)) / (pow(e,2*x) + cos(PI / 4 * x));
	std::cout << "y1 = "; 
	std::cout << std::fixed << std::setprecision(10) << y1 << std::endl;
	std::cout << "y2 = ";
	std::cout << std::fixed << std::setprecision(10) << y2 << std::endl;

	system("PAUSE");
	return 0;
}