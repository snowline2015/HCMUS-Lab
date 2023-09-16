/*
MSSV : 19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9

Test case 1
Input: 1234512
Output: 2
Test case 2
Input: 10101000
Output: 5
Test case 3
Input: 997993
Output: 1
*/

#include <iostream>
#include <math.h>

int main()
{
	long long int N;
	int count = 0;
	int min;
	int t;
	std::cout << "Input N : ";
	std::cin >> N;
	long long int temp = N;
	while (N <= 0)
	{
		std::cout << "Input N : ";
		std::cin >> N;
	}

	min = N % 10;
	while (temp >= 1)
	{
		t = temp % 10;
		if (min > t) min = t;
		temp = temp / 10;
	}

	while (N >= 1)
	{
		t = N % 10;
		if (min == t) count++;
		N = N / 10;
	}

	std::cout << count << std::endl;

	system("PAUSE");
	return 0;
}