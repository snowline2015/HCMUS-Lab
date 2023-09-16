#include "Function.h"

void inputArray(int *&a, int& n)
{
	std::cout << "Input number of elements : ";
	std::cin >> n;
	std::cout << "Input elements : " << std::endl;
	a = new int[n];
	for (int i = 0; i < n; i++) 
		std::cin >> a[i];
}

int findValueOccursGreatestFrequency(int *a, int *&b, int n)
{
	int ans;
	b = new int[n];
	for (int i = 0; i < n; i++) {
		int count = 0;
		for (int j = 0; j < n; j++) 
			if (a[i] == a[j]) count++;
		b[i] = count;
	}

	int max = b[0], temp = 0;
	for (int i = 0; i < n; i++) {
		if (b[i] == 1) ans = -1;
		else {
			ans = 1;
			break;
		}
	}
	if (ans == -1) {
		delete[] a; delete[] b;
		return ans;
	}
	else {
		for (int i = 1; i < n; i++) {
			if (b[i] > max) {
				max = b[i];
				temp = i;
			}
		}
		return a[temp];
		delete[] a; delete[] b;
	}
}