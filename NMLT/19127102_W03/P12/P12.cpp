/*
MSSV : 19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9

Test case 1
Input: 1 2 3 4
Output: 4 1
Test case 2
Input: 10 9 8 7
Output: 10 7
Test case 3
Input: 100 65 88 35
Output: 100 35
*/
#include <iostream>
#include <math.h>

int main()
{
	int a, b, c, d;
	int max, min;
	std::cout << "Nhap 4 so a, b, c, d khac nhau : " << std::endl;
	std::cin >> a >> b >> c >> d;
	while (a == b || a == c || a == d || b == c || b == d || c == d)
	{
		std::cout << "Nhap lai 4 so a, b, c, d khac nhau : " << std::endl;
		std::cin >> a >> b >> c >> d;
	}
	max = a;
	if (b > a) max = b;
	if (c > b) max = c;
	if (d > c) max = d;
	std::cout << "max = " << max << std::endl;
	min = a;
	if (a > b) min = b;
	if (b > c) min = c;
	if (c > d) min = d;
	std::cout << "min = " << min << std::endl;

	system("PAUSE");
	return 0;
}