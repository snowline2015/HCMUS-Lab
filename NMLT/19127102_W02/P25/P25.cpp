/*
MSSV :19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9
Chương trình : PACE, SPEED

Test case 1
Input: 10 1 2 30
Output: 6.25 9.60
Test case 2
Input: 200 8 35 42
Output: 2.58 23.27
Test case 3
Input: 3000 24 56 32
Output: 0.50 120.28
*/

#include <iostream>
#include <math.h>
#include <iomanip>

int main()
{
	double km;
	double hour, minute, second;
	double pace, speed;
	std::cout << "Nhap so lieu cho km, hour, minute, second : ";
	std::cin >> km >> hour >> minute >> second;
	while (km <= 0 || (hour + minute / 60 + second / 3600) <= 0)
	{
		std::cout << "Nhap sai so\nXin vui long nhap lai so lieu cho km, hour, minute, second : ";
		std::cin >> km >> hour >> minute >> second;
	}
	std::cout << "pace = " << std::fixed << std::setprecision(2) << (hour * 60 + minute + second / 60) / km << " minute/km" << std::endl;
	std::cout << "speed = " << std::fixed << std::setprecision(2) << km / (hour + minute / 60 + second / 3600) << " km/h" << std::endl;

	system("PAUSE");
	return 0;
}