/*
MSSV :19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9
Chương trình : KHUYẾN MÃI HOÀN TIỀN

Test case 1
Input: 40 100000
Output: 250000.00
Test case 2
Input: 50 300000
Output: 600000
Test case 3
Input: 30 699000
Output: 2330000
*/

#include <iostream>
#include <math.h>
#include <iomanip>

int main()
{
	double percent, quota;
	std::cout << "Nhap so phan tram va muc hoan tien toi da : ";
	std::cin >> percent >> quota;
	while (percent <= 0 || quota <= 0)
	{
		std::cout << "Nhap sai so, xin vui long nhap lai" << std::endl;
		std::cout << "Nhap so phan tram va muc hoan tien toi da : ";
		std::cin >> percent >> quota;
	}
	std::cout << "So tien mua hang : " << std::fixed << std::setprecision(2) << quota * 100 / percent << std::endl;

	system("PAUSE");
	return 0;
}