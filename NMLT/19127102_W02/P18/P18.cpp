/*
MSSV :19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9
Chương trình : HOÁN ĐỔI 2 SỐ

Test case 1
Input: 1 2
Output: 2 1
Test case 2
Input: 4 5
Output: 5 4
Test case 3
Input: 3 8
Output: 8 3
*/
#include<iostream>
#include<math.h>

int main()
{
	int a, b;
	std::cout << "Nhap 2 so a va b : ";
	std::cin >> a >> b;
	a = a + b;
	b = a - b;
	a = a - b;
	std::cout << "a va b sau khi hoan vi la " << a << " " << b << std::endl;

	system("PAUSE");
	return 0;
}