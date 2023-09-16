/*
MSSV : 19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9

Test case 1
Input: 2 3
Output: 0.09
Test case 2
Input: 3 5
Output: 0.86
Test case 3
Input: 9 10
Output: 0.29
*/

#include <iostream>
#include <math.h>
#include <iomanip>

int main()
{
	int x, N;
	double S = 1;
	double up = 1;
	double down = 1;
	std::cout << "Input x : ";
	std::cin >> x;
	std::cout << "Input N : ";
	std::cin >> N;
	while (N <= 0)
	{
		std::cout << "Input N : ";
		std::cin >> N;
	}

	for (int i = 1; i <= 2 * N + 1; i++)
	{
		up *= x;
		down *= i;
		if (i % 2 == 1 && (i - 1) % 4 != 0) S += up / down;
		if (i % 2 == 1 && (i - 1) % 4 == 0) S -= up / down;
	}
	std::cout << std::fixed << std::setprecision(2) << S << std::endl;

	system("PAUSE");
	return 0;
}