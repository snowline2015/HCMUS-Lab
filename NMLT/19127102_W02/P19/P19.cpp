/*
MSSV :19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9
Chương trình : HOÁN ĐỔI 3 SỐ

Test case 1
Input: 3 4 5
Output: 4 5 3
Test case 2
Input: 3 8 7
Output: 7 8 3
Test case 3
Input: 3 6 9
Output: 6 9 3
*/
#include<iostream>
#include<math.h>

int main()
{
	int a, b, c;
	std::cout << "Nhap 3 so a, b, c : ";
	std::cin >> a >> b >> c;
	b = b + c;
	c = b - c;
	b = b - c;
	a = a + c;
	c = a - c;
	a = a - c;
	std::cout << "a, b, c sau khi hoan vi la " << a << " " << b << " " << c << std::endl;

	system("PAUSE");
	return 0;
}