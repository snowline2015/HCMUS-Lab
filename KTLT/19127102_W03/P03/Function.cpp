#include "Function.h"

bool isPalindrome(char* cstr)
{
	char* front = cstr;
	char* back = cstr + strlen(cstr) - 1;
	while (front < back)
	{
		if (*front == *back) {
			front += 1;
			back -= 1;
		}
		if (*front != *back) break;
	}
	if (*front != *back) return false;
	else return true;
}