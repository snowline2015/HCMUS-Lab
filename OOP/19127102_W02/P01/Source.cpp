#include "Function.h"

int main()
{
	Ngay n1; //1/1/1
	Ngay n2(02, 10, 2014); //2/10/2014
	Ngay n3(-10, 16, 2000); //10/04/2001
	Ngay n4(1000); //27/9/3
	Ngay n5 = n2 + n3; //12/2/4016
	Ngay n6 = n1 + 5000; //10/10/15
	Ngay n7 = 1234 + n4; //14/2/7
	Ngay n8 = 190 + n6 + n7; //2/7/23
	Ngay n9 = n8 - n6; //1/9/7
	Ngay n10 = 12000 - n9; //9/2/26
	if (n10 > n6)
	{
		n10 = n2 - 1000 + n6;
	}
	std::cout << n1 << std::endl
		<< n2 << std::endl
		<< n3 << std::endl
		<< n4 << std::endl;
	std::cout << n5 << std::endl
		<< n6 << std::endl
		<< n7 << std::endl
		<< n8 << std::endl;
	std::cout << n9 << std::endl
		<< n10 << std::endl;
	return 0;
}