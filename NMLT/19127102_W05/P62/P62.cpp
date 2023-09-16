/*
MSSV : 19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9

Test case 1
Input: 12 20
Output: 2 -1
Test case 2
Input: 99 33
Output: 0 1
Test case 3
Input: 100 33
Output: 1 -3
*/

#include <iostream>
#include<math.h>

int main()
{
	int a, b;
	int temp;
	int max;
	std::cout << "Input a, b : ";
	std::cin >> a >> b;
	while (a <= 0 || b <= 0)
	{
		std::cout << "Input a, b : ";
		std::cin >> a >> b;
	}

	if (a >= b)
	{
		for (int i = 1; i <= a; i++)
			if (a % i == 0 && b % i == 0) max = i;
		for (int x = 0; x <= a; x++)
		{
			temp = a * x;
			if (((max - temp) / b) - (int)(((max - temp) / b)) == 0 && max == a * x + b * ((max - temp) / b))
			{
				std::cout << x << " " << (max - temp) / b << std::endl;
				break;
			}
		}
	}

	if (a <= b)
	{
		for (int i = 1; i <= b; i++)
			if (a % i == 0 && b % i == 0) max = i;
		for (int x = 0; x <= b; x++)
		{
			temp = a * x;
			if (((max - temp) / b) - (int)(((max - temp) / b)) == 0 && max == a * x + b * ((max - temp) / b))
			{
				std::cout << x << " " << (max - temp) / b << std::endl;
				break;
			}
		}
	}


	system("PAUSE");
	return 0;
}