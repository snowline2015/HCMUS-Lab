/*
MSSV : 19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9

Test case 1
Input: 2 3
Output: 3.76
Test case 2
Input: 3 5
Output: 10.07
Test case 3
Input: 1 2
Output: 1.54
*/

#include <iostream>
#include <math.h>
#include <iomanip>

int main()
{
	double S = 1.0;
	long int down = 1;
	int N, x;
	std::cout << "Input x : ";
	std::cin >> x;
	long int up = 1;
	std::cout << "Input N : ";
	std::cin >> N;
	while (N <= 0)
	{
		std::cout << "Input N : ";
		std::cin >> N;
	}
	for (int i = 1; i <= (2 * N); i++)
	{
		up = up * x;
		down = down * i;
		if (i % 2 == 0) S = S + (double)up / down;
	}

	std::cout << "S = " << std::fixed << std::setprecision(2) << S << std::endl;
	system("PAUSE");
	return 0;
}