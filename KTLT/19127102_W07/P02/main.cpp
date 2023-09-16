#include "Function.h"

int main()
{
	char temp[101];
	char* str;
	std::cout << "Input string : ";
	std::cin.getline(temp, 101);
	str = new char[strlen(temp) + 1];
	strcpy(str, temp);
	bool answer = isPalindrome(0, strlen(str) - 1, str);
	if (answer == true)
		std::cout << "The given string is palindrome" << std::endl;
	else std::cout << "The given string is not palindrome" << std::endl;
	delete[] str;
	return 0;
}