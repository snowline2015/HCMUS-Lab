/*
MSSV : 19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9

Test case 1
Input: 5
Output: 2.74
Test case 2
Input: 6
Output: 2.96
Test case 3
Input: 33
Output: 6.26
*/

#include <iostream>
#include <math.h>
#include <iomanip>

int main()
{
	double S = 1.0;
	int N;
	std::cout << "Input N : ";
	std::cin >> N;
	while (N <= 0)
	{
		std::cout << "Input N : ";
		std::cin >> N;
	}
	for (int i = 2; i <= N; i++)
	{
		S = i + S;
		S = sqrt(S);
	}

	std::cout << "S = " << std::fixed << std::setprecision(2) << S << std::endl;
	system("PAUSE");
	return 0;
}