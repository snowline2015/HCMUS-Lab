/*
MSSV : 19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9

Test case 1
Input: 2 3
Output: 170
Test case 2
Input: 3 5
Output: 199290
Test case 3
Input: 1 2
Output: 3
*/

#include <iostream>;
#include <math.h>

int main()
{
	long int S = 0;
	int N, x;
	std::cout << "Input x : ";
	std::cin >> x;
	long int t = 1;
	std::cout << "Input N : ";
	std::cin >> N;
	while (N <= 0)
	{
		std::cout << "Input N : ";
		std::cin >> N;
	}
	for (int i = 1; i <= (2*N + 1); i++)
	{
		t = t * x;
		if (i % 2 == 1) S += t;
	}
	std::cout << "S = " << S << std::endl;
	system("PAUSE");
	return 0;
}