/*
MSSV :19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9
Chương trình : SỐ KWH ĐIỆN TIÊU THỤ

Test case 1
Input: 1000 1100
Output: 100
Test case 2
Input: 1000 1000
Output: 0
Test case 3
Input: 10000 20000
Output: 10000
*/

#include<iostream>
#include<math.h>

int main()
{
	int previous, current, use;
	std::cout << "Nhap chi so dien thang truoc va chi so dien hien tai: ";
	std::cin >> previous >> current;
	if (0 <= previous && previous <= current)
	{
		use = current - previous;
		std::cout << "Chi so dien tieu thu la: " << use << std::endl;
	}
	else
	{
		std::cout << "Loi so" << std::endl;
	}
	system("PAUSE");
		return 0;
}