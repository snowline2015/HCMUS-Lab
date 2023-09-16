#include "Function.h"

void inputString(char str[100])
{
	std::cin.getline(str, 101);
	std::cin.getline(str, 101);
}

void reverseString(char str[100], char str1[100])
{
	int m = 0;
	for (int i = strlen(str) - 1; i >= 0; i--) {
		str1[m] = str[i];
		m++;
	}
	str1[m] = '\0';
}

void reverseWordsInString(char str[100], char str1[100])
{
	int m = 0;
	int count = 0;
	for (int i = strlen(str) - 1; i >= 0; i--) {
		count++;
		if (str[i] == ' ') {
			int temp = i + 1;
			for (int j = 1; j < count; j++) {
				str1[m] = str[temp];
				m++;
				temp++;
			}
			str[i] = '\0';
			count = 0;
			str1[m] = ' ';
			m++;
		}
		if (i == 0) {
			int temp = i;
			for (int j = 0; j < count; j++) {
				str1[m] = str[temp];
				m++;
				temp++;
			}
			break;
		}
	}
	str1[m] = '\0';
}

void normalizeName(char str[100]) 
{
	while (str[0] == ' ') {
		int i = 0;
		for (int j = 1; j < strlen(str); j++) {
			str[i] = str[j];
			i++;
		}
		str[i] = '\0';
	}
	
	for (int i = 0; i < strlen(str); i++) {
		if (str[0] <= 'z' && str[0] >= 'a') {
			str[0] -= 32;
			continue;
		}
		if (str[i - 1] == ' ' && str[i] <= 'z' && str[i] >= 'a') {
			str[i] -= 32;
			continue;
		}
		if (str[i - 1] == ' ' && str[i] <= 'Z' && str[i] >= 'A') continue;
		if (str[i] != ' ' && str[i] >= 'A' && str[i] <= 'Z') {
			str[i] += 32;
			continue;
		}
	}
}

void printIntegerInString(char str[100])
{
	int count = 0;
	for (int i = strlen(str) - 1; i >= 0; i--) {
		count++;
		if (count == 3 && i != 0) {
			for (int j = strlen(str); j > i; j--) 
				str[j] = str[j - 1];
			str[i] = ',';
			count = 0;
		}
		str[strlen(str) + 1] = '\0';
	}
}

void inputStudents(hocSinh a[], int &num)
{
	std::cout << "Input number of student : ";
	std::cin >> num;
	std::cin.ignore(1);
	for (int i = 0; i < num; i++) {
		std::cin.getline(a[i].name, 101);
	}
	for (int i = 0; i < num; i++) {
		for (int j = strlen(a[i].name) - 1; j >= 0; j++) {
			if (a[i].name[j] == ' ')
				a[i].name[j] = '\0';
			else break;
		}
	}
}

void arrangeStudents(hocSinh a[], int num)
{
	for (int i = 0; i < num - 1; i++) {
		for (int j = i + 1; j < num; j++) {
			for (int k = strlen(a[i].name) - 1; k >= 0; k--) {
				if (a[i].name[k - 1] == ' ') {
					for (int l = strlen(a[j].name) - 1; l >= 0; l--) {
						if (a[j].name[l - 1] == ' ' && a[i].name[k] > a[j].name[l]) {
							hocSinh temp = a[i];
							a[i] = a[j];
							a[j] = temp;
							break;
						}
					}
					break;
				}
			}
		}
	}
}

void input2DArray(int& m, int& n, int a[][100])
{
	std::cout << "Input rows : ";
	std::cin >> m;
	std::cout << "Input columns : ";
	std::cin >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> a[i][j];
		}
	}
}

void output2DArray(int m, int n, int a[][100])
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << a[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int sumOfPositiveElementsIn2DArray(int m, int n, int a[][100])
{
	int sum = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] >= 0) sum += a[i][j];
		}
	}
	return sum;
}

int countMaxInMatrix(int m, int n, int a[][100])
{

	int count = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] > a[i - 1][j - 1] && a[i][j] > a[i - 1][j] && a[i][j] > a[i - 1][j + 1] && a[i][j] > a[i][j - 1] && a[i][j] > a[i][j + 1] && a[i][j] > a[i + 1][j - 1] && a[i][j] > a[i + 1][j] && a[i][j] > a[i + 1][j + 1]) {
				count++;
			}
		}
	}
	return count;
}

int countSaddleInMatrix(int m, int n, int a[][100])
{
	int count = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (a[i][j] < a[i][k]) break;
				if (k == n - 1) {
					for (int l = 0; l < m; l++) {
						if (a[i][j] > a[l][j]) break;
						if (l == m - 1) count++;
					}
				}
			}
		}
	}
	return count;
}

void rightShiftRotateClockwiseMatrixBoundary(int m, int n, int a[][100])
{
	int empty = a[0][0];
	int i = 0, count = 1;
	while (count <= 4) {
		if (count == 1) {
			for (int j = 0; j < m; j++) {
				a[j][0] = a[j + 1][0];
			}
		}
		if (count == 2) {
			for (int j = 0; j < n; j++) {
				a[m - 1][j] = a[m - 1][j + 1];
			}
		}
		if (count == 3) {
			for (int j = m - 1; j > 0; j--) {
				a[j][n - 1] = a[j - 1][n - 1];
			}
		}
		if (count == 4) {
			for (int j = n - 1; j > 0; j--) {
				a[0][j] = a[0][j - 1];
			}
		}
		count++;
	}
	a[0][1] = empty;
}

void rotateMatrix90Degree(int m, int n, int a[][100], int &p, int &q, int b[][100])
{
	if (m != n) {
		int temp = m;
		m = n;
		n = temp;
	}
	p = m; q = n;
	for (int i = 0; i < m; i++) {
		int temp = m - 1;
		for (int j = 0; j < n; j++) {
			b[i][j] = a[temp][i];
			temp--;
		}
	}
}
