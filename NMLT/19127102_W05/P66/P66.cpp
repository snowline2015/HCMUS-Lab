/*
MSSV : 19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9

Test case 1
Input: 5
Output: 0.80
Test case 2
Input: 6
Output: 0.75
Test case 3
Input: 3
Output: 0.83
*/

#include <iostream>
#include <math.h>
#include <iomanip>

int main()
{
	int N;
	double S = 0;
	int temp = 0;
	std::cout << "Input N : ";
	std::cin >> N;
	while (N <= 0)
	{
		std::cout << "Input N : ";
		std::cin >> N;
	}
	
	for (int i = 1; i <= N; i++)
	{
		temp = temp + i;
		if (i % 2 == 1) S = S + 1.0 / temp;
		if (i % 2 == 0) S = S - 1.0 / temp;
	}

	std::cout << std::fixed << std::setprecision(2) << S << std::endl;

	system("PAUSE");
	return 0;
}