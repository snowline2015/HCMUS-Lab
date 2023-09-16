/*
MSSV : 19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9

Test case 1
Input: 9 8 10 0 PASSED
Output: 9.1
Test case 2
Input: 8 8 8 1
Output: 0.0 FAILED
Test case 3
Input: 7 6 8 0
Output: 7.1 PASSED
*/

#include <iostream>
#include <math.h>
#include <iomanip>

int main()
{
	double assignment, lab, final;
	double total;
	int cheating;
	std::cout << "Nhap diem bai tap :" << std::endl;
	std::cin >> assignment;
	while (assignment < 0 || assignment > 10)
	{
		std::cout << "Nhap lai diem bai tap :" << std::endl;
		std::cin >> assignment;
	}
	std::cout << "Nhap diem thuc hanh :" << std::endl;
	std::cin >> lab;
	while (lab < 0 || lab > 10)
	{
		std::cout << "Nhap lai diem thuc hanh :" << std::endl;
		std::cin >> lab;
	}
	std::cout << "Nhap diem ly thuyet :" << std::endl;
	std::cin >> final;
	while (final < 0 || final > 10)
	{
		std::cout << "Nhap lai diem ly thuyet :" << std::endl;
		std::cin >> final;
	}
	std::cout << "Sinh vien co gian lan khong, 1 neu co, 0 neu khong :" << std::endl;
	std::cin >> cheating;
	while (cheating != 0 && cheating != 1)
	{
		std::cout << "Sinh vien co gian lan khong, 1 neu co, 0 neu khong :" << std::endl;
		std::cin >> cheating;
	}
	total = (assignment * 30 + lab * 30 + final * 40) / 100;
	if (cheating == 1) total = 0.0;
	std::cout << "Diem tong cong : " << std::fixed << std::setprecision(1) << total << std::endl;
	if (total >= 5) std::cout << "PASSED" << std::endl;
	else std::cout << "FAILED" << std::endl;

	system("PAUSE");
	return 0;
}