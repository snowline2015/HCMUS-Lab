/*
MSSV : 19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9

Test case 1
Input: 6
Output: YES
Test case 2
Input: 9
Output: NO
Test case 3
Input: 28
Output: YES
*/
#include <iostream>
#include <math.h>

int main()
{
	int n;
	int S = 0;
	std::cout << "Input N : ";
	std::cin >> n;
	while (n <= 0)
	{
		std::cout << "Input N : ";
		std::cin >> n;
	}
	for (int i = 1; i < n; i++)
	{
		if (n % i == 0) S = S + i;
	}
	if (S == n) std::cout << "YES" << std::endl;
	else std::cout << "NO" << std::endl;

	system("PAUSE");
	return 0;
}