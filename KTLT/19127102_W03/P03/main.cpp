#include "Function.h"

int main()
{
	char temp[101];
	char* str;
	std::cin.getline(temp, 101);
	str = new char[strlen(temp) + 1];
	strcpy(str, temp);
	std::cout << isPalindrome(str) << std::endl;
	delete[] str;
	return 0;
}