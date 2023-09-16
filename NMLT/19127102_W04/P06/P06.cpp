/*
MSSV : 19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9

Test case 1
Input: 5
Output: 0.83
Test case 2
Input: 6
Output: 0.86
Test case 3
Input: 7
Output: 0.88
*/

#include <iostream>
#include <math.h>
#include <iomanip>

int main()
{
	int N;
	double S = 0;
	std::cout << "Input N : ";
	std::cin >> N;
	while (N <= 0)
	{
		std::cout << "Input N : ";
		std::cin >> N;
	}
	for (double i = 1; i <= N; i++)
	{
		S = S + (1 / (i * (i + 1)));
	}
	std::cout << "S = " << std::fixed << std::setprecision(2) << S << std::endl;

	system("PAUSE");
	return 0;
}