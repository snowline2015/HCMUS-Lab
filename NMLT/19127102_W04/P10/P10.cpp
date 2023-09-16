/*
MSSV : 19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9

Test case 1
Input: 2 3
Output: 8.00
Test case 2
Input: 3 2
Output: 9.00
Test case 3
Input: 5 5
Output: 3125.00
*/

#include <iostream>
#include <math.h>
#include <iomanip>

int main()
{
	double S = 1;
	int N, x;
	std::cout << "Input x : ";
	std::cin >> x;
	std::cout << "Input N : ";
	std::cin >> N;
	while (N <= 0)
	{
		std::cout << "Input N : ";
		std::cin >> N;
	}
	for (int i = 1; i <= N; i++) S = S * x;
	std::cout << "S = " << std::fixed << std::setprecision(2) << S << std::endl;

	system("PAUSE");
	return 0;
}