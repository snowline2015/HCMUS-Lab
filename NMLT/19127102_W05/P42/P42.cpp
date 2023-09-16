/*
MSSV : 19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9

Test case 1
Input: 20
Output: 5
Test case 2
Input: 21
Output: 5
Test case 3
Input: 22
Output: 6
*/

#include <iostream>
#include <math.h>

int main()
{
	int n;
	int S = 0;
	std::cout << "Input N : ";
	std::cin >> n;
	while (n < 0)
	{
		std::cout << "Input N : ";
		std::cin >> n;
	}

	for (int i = 1; i <= n; i++)
	{
		S = S + i;
		if (S >= n)
		{
			std::cout << i - 1;
			break;
		}
	}
	std::cout << std::endl;

	system("PAUSE");
	return 0;
}