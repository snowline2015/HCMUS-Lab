/*
MSSV : 19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9

Test case 1
Input: 1223579
Output: YES
Test case 2
Input: 1357946
Output: NO
Test case 3
Input: 12235749
Output: NO
*/

#include <iostream>
#include <math.h>

int main()
{
	int N;
	int count = 0;
	std::cout << "Input N : ";
	std::cin >> N;
	while (N <= 0)
	{
		std::cout << "Input N : ";
		std::cin >> N;
	}

	int temp;
	int t = N;

	while (t >= 1)
	{
		t = t / 10;
		count++;
	}

	for (int i = 1; i <= count; i++)
	{
		temp = N % 10;
		if (temp >= (N / 10) % 10) N = N / 10;
		if (temp < (N / 10) % 10 || N == 0)
			break;
	}
	if (N == 0) std::cout << "YES" << std::endl;
	else std::cout << "NO" << std::endl;

	system("PAUSE");
	return 0;
}