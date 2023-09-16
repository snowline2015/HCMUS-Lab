#include "Function.h"

int main()
{
	stack myStack;
	unsigned long num;
	std::cout << "Input unsigned integer : ";
	std::cin >> num;
	conversion(myStack, num);
	std::cout << "Binary number : ";
	pop(myStack);
	return 0;
}