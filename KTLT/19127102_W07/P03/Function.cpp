#include "Function.h"

void outputArray(int* a, int n, int curr)
{
	if (curr != n) {
		std::cout << a[curr] << " ";
		outputArray(a, n, curr + 1);
	}
	else return;
}

void reversedOutputArray(int* a, int n)
{
	if (n != 0) {
		std::cout << a[n - 1] << " ";
		reversedOutputArray(a, n - 1);
	}
	else return;
}

int sumPositiveNum(int* a, int n)
{
	if (n == 0)
		return 0;
	else if (a[n - 1] >= 0) 
		return sumPositiveNum(a, n - 1) + a[n - 1];
	else sumPositiveNum(a, n - 1);
}

int countAllDistinctValue(int* a, int n)
{
	if (n <= 1)
		return 1;
	else {
		int temp = countAllDistinctValue(a, n - 1);
		for (int i = 0; i < n - 1; i++) {
			if (a[n - 1] == a[i]) {
				return temp;
				break;
			}
			if (i + 1 == n - 1) return temp + 1;
		}
	}
}

bool haveOddNum(int* a, int n)
{
	if (n == 1) {
		if (a[0] % 2 == 1) return true;
		else return false;
	}
	else {
		if (a[n - 1] % 2 == 0)
			return haveOddNum(a, n - 1);
		else return true;
	}
}

int max(int* a, int n)
{
	if (n == 1)
		return a[0];
	int temp = max(a, n - 1);
	if (a[n - 1] > temp)
		return a[n - 1];
	else
		return temp;
}