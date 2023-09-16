#include "Function.h"

int main()
{
	int* ptr;
	int a = 1806;
	ptr = &a;
	addOne(ptr);
	std::cout << *ptr << std::endl;
	return 0;
}