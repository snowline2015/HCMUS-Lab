#include "Function.h"

bool isPalindrome(int l, int r, char* s)
{
	if (l == r || l + 1 == r && s[l] == s[r])
		return true;
	if (s[l] == s[r]) {
		return isPalindrome(l + 1, r - 1, s);
	}
	else return false;
}