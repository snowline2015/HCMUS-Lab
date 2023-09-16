/*
MSSV : 19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9

Test case 1
Input: 12345
Output: 54321
Test case 2
Input: 13579
Output: 97531
Test case 3
Input: 997993
Output: 399799
*/

#include <iostream>
#include <math.h>

int main()
{
	int N;
	int t;
	std::cout << "Input N : ";
	std::cin >> N;
	while (N <= 0)
	{
		std::cout << "Input N : ";
		std::cin >> N;
	}

	while (N >= 1)
	{
		t = N % 10;
		std::cout << t;
		N = N / 10;
	}

	std::cout << std::endl;
	system("PAUSE");
	return 0;
}