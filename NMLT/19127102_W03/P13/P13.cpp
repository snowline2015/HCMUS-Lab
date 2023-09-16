/*
MSSV : 19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9

Test case 1
Input: 1941
Output: Nam khong nhuan
Test case 2
Input: 1945
Output: Nam khong nhuan
Test case 3
Input: 1980
Output: Nam nhuan
*/
#include <iostream>;
#include <math.h>

int main()
{
	int nam, thang;
	std::cout << "Nhap nam : ";
	std::cin >> nam;
	if (nam % 4 == 0 && nam % 100 != 0) std::cout << "Nam nhuan" << std::endl;
	else std::cout << "Nam khong nhuan" << std::endl;

	system("PAUSE");
	return 0;
}