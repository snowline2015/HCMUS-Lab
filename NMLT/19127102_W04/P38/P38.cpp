/*
MSSV : 19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9

Test case 1
Input: 5
Output: 1.36
Test case 2
Input: 6
Output: 1.33
Test case 3
Input: 7
Output: 1.30
*/

#include <iostream>
#include <math.h>
#include <iomanip>

int main()
{
	double n;
	double t;
	double S = 1;
	std::cout << "Input N : ";
	std::cin >> n;
	while (n <= 1 || pow(10, 9) <= n)
	{
		std::cout << "Input n : ";
		std::cin >> n;
	}
	for (double i = 2; i <= n; i++)
	{
		t = 1 / (i + 1);
		S = exp(t * log(i + S));
	}
	std::cout << "S = " << std::fixed << std::setprecision(2) <<  S << std::endl;

	system("PAUSE");
	return 0;
}