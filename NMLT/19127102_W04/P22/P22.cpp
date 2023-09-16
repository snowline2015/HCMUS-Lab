/*
MSSV : 19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9

Test case 1
Input: 6
Output: 36
Test case 2
Input: 3
Output: 3
Test case 3
Input: 9
Output: 27
*/
#include <iostream>
#include <math.h>

int main()
{
	int n;
	int S = 1;
	std::cout << "Input N : ";
	std::cin >> n;
	while (n <= 0)
	{
		std::cout << "Input N : ";
		std::cin >> n;
	}
	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0)
		S = S * i;
	}
	std::cout << "S = " << S << std::endl;
	system("PAUSE");
	return 0;
}