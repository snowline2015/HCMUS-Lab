/*
MSSV : 19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9

Test case 1
Input: 12345
Output: 3
Test case 2
Input: 999999
Output: 6
Test case 3
Input: 35780
Output: 3
*/

#include <iostream>
#include <math.h>

int main()
{
	int N;
	int x;
	int count = 0;
	std::cout << "Input N : ";
	std::cin >> N;
	while (N <= 0)
	{
		std::cout << "Input N : ";
		std::cin >> N;
	}

	while (N >= 1)
	{
		x = N % 10;
		if (x % 2 == 1) count++;
		N = N / 10;
	}
	std::cout << count << std::endl;

	system("PAUSE");
	return 0;
}