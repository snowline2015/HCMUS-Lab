/*
MSSV :19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9
Chương trình : SỐ NÚT BIỂN XE

Test case 1
Input: 12345
Output: 5
Test case 2
Input: 99999
Output: 5
Test case 3
Input: 97635
Output: 0
*/

#include <iostream>
#include <math.h>

int main()
{
	int plate;
	int x1, x2, x3, x4, x5;
	std::cout << "Nhap bien so xe : ";
	std::cin >> plate;
	while (plate < 10000 || 99999 < plate)
	{
		std::cout << "Nhap sai so\nXin vui long nhap lai bien so xe : ";
		std::cin >> plate;
	}
	x1 = plate % 10;
	x2 = (plate / 10) % 10;
	x3 = (plate / 100) % 10;
	x4 = (plate / 1000) % 10;
	x5 = (plate / 10000) % 10;
	std::cout << "So nut cua bien xe : " << (x1 + x2 + x3 + x4 + x5) % 10 << std::endl;

	system("PAUSE");
	return 0;
}