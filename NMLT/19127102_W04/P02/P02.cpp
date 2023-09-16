/*
MSSV : 19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9

Test case 1
Input: 5
Output: 55
Test case 2
Input: 3
Output: 14
Test case 3
Input: 7
Output: 140
*/
#include <iostream>
#include <math.h>

int main()
{
	int N;
	int t;
	int S = 0;
	std::cout << "Input N : ";
	std::cin >> N;
	while (N < 0)
	{
		std::cout << "Input N : ";
		std::cin >> N;
	}
	for (int i = 1; i <= N; i++)
	{
		t = i * i;
		S = S + t;
	}
	std::cout << "S = " << S << std::endl;

	system("PAUSE");
	return 0;
}