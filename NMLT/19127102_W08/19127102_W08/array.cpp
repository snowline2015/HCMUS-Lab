#include "array.h"

void inputArray(int a[100], int n)
{
	for (int i = 0; i < n; i++) 
		std::cin >> a[i];
}

void outputArray(int a[100], int n)
{
	for (int i = 0; i < n; i++)
		std::cout << a[i] << " ";
}

double averageEvenNums(int a[100], int n)
{
	double avg;
	double count = 0, temp = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			temp += a[i];
			count++;
		}
	}
	avg = temp / count;
	return avg;
}

void findPrimeNums(int a[100], int n, int b[100], int &m)
{
	m = 0;
	for (int i = 0; i < n; i++) {
		int count = 0;
		if (a[i] == 1 || a[i] == 0) continue;
		for (int j = 2; j <= a[i]; j++) {
			if (a[i] % j == 0) count++;
			if (count > 1) break;
		}
		if (count <= 1) {
			b[m] = a[i];
			m++;
		}
	}
}

void findLargestEvenSmallestOddNums(int a[100], int n, int b[100], int& m, int c[100], int& p, int& max, int& min)
{
	m = 0; p = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			b[m] = a[i];
			m++;
		}
		else {
			c[p] = a[i];
			p++;
		}
	}
	max = b[0];
	for (int i = 0; i < m; i++) {
		if (max < b[i]) max = b[i];
	}

	min = c[0];
	for (int i = 0; i < p; i++) {
		if (min > c[i]) min = c[i];
	}
}

void arrangeIncreasingEvenNums(int a[100], int n)
{
	for (int i = 0; i < n - 1; i++) {
		if (a[i] % 2 == 0)
		{
			for (int j = i + 1; j < n; j++) {
				if (a[j] % 2 == 0 && a[i] > a[j]) {
					int temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
		}
	}
}

void checkArraySorted(int a[100], int n, int &ans)
{
	for (int i = 0; i < (n - 2); i++) {
		if (a[i] < a[i + 1]) {
			ans = 1;
			if (a[i + 1] > a[i + 2]) {
				ans = 0;
				break;
			}
		}
		if (a[i] > a[i + 1]) {
			ans = 2;
			if (a[i + 1] < a[i + 2]) {
				ans = 0;
				break;
			}
		}
	}
	if (ans != 1 && ans != 2) ans = 0;
}

int countDifferentElements(int a[100], int n)
{
	int count = 1;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			}
		}
	}
	for (int i = 1; i < n; i++) {
		if (a[i] == a[i - 1]) continue;
		else count++;
	}
	return count;
}

int findSecondLargestElement(int a[100], int n)
{
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	return a[n - 2];
}

void reverseArray(int a[100], int n, int b[100], int &m)
{
	m = 0;
	for (int i = n - 1; i >= 0; i--) {
		b[m] = a[i];
		m++;
	}
}

void mix2ArraysWithoutReduction(int a[100], int n, int b[100], int& m, int c[100], int& p)
{
	p = m + n;
	for (int i = 0; i < n; i++) 
		c[i] = a[i];
	int j = 0;
	for (int i = n; i < p; i++) {
		c[i] = b[j];
		j++;
	}
	for (int i = 0; i < p - 1; i++) {
		for (int j = i + 1; j < p; j++) {
			if (c[i] > c[j]) {
				int temp = c[i];
				c[i] = c[j];
				c[j] = temp;
			}
		}
	}
}

void findElementsAppearOnBothArrays(int a[100], int n, int b[100], int& m, int c[100], int& p)
{
	p = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i] == b[j]) {
				c[p] = a[i];
				p++;
			}
		}
	}
}