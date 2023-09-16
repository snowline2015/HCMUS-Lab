/*
MSSV : 19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9

Test case 1
Input: 14
Output: 2 7
Test case 2
Input: 2 19
Output: 366
Test case 3
Input: 1080
Output: 2 2 2 3 3 3 5
*/

#include <iostream>
#include <math.h>

int main()
{
	int N;
	int count = 0;
	std::cout << "Input N : ";
	std::cin >> N;
	int temp = N;
	
	for (int i = 2; i <= N; i++)
	{
		if (N % i == 0)
		{
			for (int j = 2; j <= i; j++)
			{
				if (i % j == 0) count++;
				if (count > 1) break;
			}
			if (count <= 1)
				while (temp % i == 0)
				{
					temp = temp / i;
					std::cout << i << " ";
				}
		}
		count = 0;
	}
	std::cout << std::endl;

	system("PAUSE");
	return 0;
}