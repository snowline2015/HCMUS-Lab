#include "function.h"

bool isPerfect(int n)
{
	int S = 0;
	for (int i = 1; i < n; i++)
	{
		if (n % i == 0) S += i;
	}
	if (S == n) return true;
	else return false;
}

bool isPrime(int m)
{
	int count = 0;
	for (int i = 2; i <= m; i++)
	{
		if (m % i == 0) count++;
		if (count > 1) break;
	}
	if (count <= 1) return true;
	else return false;
}

int biggest(long long int p)
{
	int count = 0;
	int t = p;
	int temp, max;
	while (t >= 1)
	{
		t = t / 10;
		count++;
	}

	max = p % 10;
	for (int i = 1; i <= count; i++)
	{
		temp = p % 10;
		if (max < temp) max = temp;
		p = p / 10;
	}
	return max;
}

int solveQuadratic(double a, double b, double c, double& x1, double& x2)
{
	double delta = pow(b, 2) - 4 * a * c;
	if (a == 0)
	{
		x1 = -c / b;
		return 0;
	}
	if (delta < 0) return 1;
	if (delta == 0)
	{
		x1 = -b / (2 * a);
		return 2;
	}
	if (delta > 0)
	{
		x1 = (-b + sqrt(delta)) / (2 * a);
		x2 = (-b - sqrt(delta)) / (2 * a);
		return 3;
	}
}

void tomorrow(int day, int month, int year, int& day2, int& month2, int& year2)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		switch (month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
		{
			while (day > 31) {
				std::cout << "Input day ";
				std::cin >> day;
			}
			if (day < 31) {
				day2 = day + 1; month2 = month; year2 = year;
			}
			if (day == 31) {
				day2 = 1; month2 = month + 1; year2 = year;
				if (month == 12) {
					month2 = 1; year2 = year + 1;
				}
			}
			break;
		}
		case 4:
		case 6:
		case 9:
		case 11:
		{
			while (day > 30) {
				std::cout << "Input day ";
				std::cin >> day;
			}
			if (day < 30) {
				day2 = day + 1; month2 = month; year2 = year;
			}
			if (day == 30) {
				day2 = 1; month2 = month + 1; year2 = year;
			}
			break;
		}
		default:
		{
			while (day > 29) {
				std::cout << "Input day ";
				std::cin >> day;
			}
			if (day < 29) {
				day2 = day + 1; month2 = month; year2 = year;
			}
			if (day == 29) {
				day2 = 1; month2 = month + 1; year2 = year;
			}
			break;
		}
		}
	}
	else
	{
		switch (month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
		{
			while (day > 31) {
				std::cout << "Input day ";
				std::cin >> day;
			}
			if (day < 31) {
				day2 = day + 1; month2 = month; year2 = year;
			}
			if (day == 31) {
				day2 = 1; month2 = month + 1; year2 = year;
				if (month == 12) {
					month2 = 1; year2 = year + 1;
				}
			}
			break;
		}
		case 4:
		case 6:
		case 9:
		case 11:
		{
			while (day > 30) {
				std::cout << "Input day ";
				std::cin >> day;
			}
			if (day < 30) {
				day2 = day + 1; month2 = month; year2 = year;
			}
			if (day == 30) {
				day2 = 1; month2 = month + 1; year2 = year;
			}
			break;
		}
		default:
		{
			while (day > 28) {
				std::cout << "Input day ";
				std::cin >> day;
			}
			if (day < 28) {
				day2 = day + 1; month2 = month; year2 = year;
			}
			if (day == 28) {
				day2 = 1; month2 = month + 1; year2 = year;
			}
			break;
		}
		}
	}
}

void yesterday(int day, int month, int year, int& day2, int& month2, int& year2)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		switch (month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
		{
			while (day > 31) {
				std::cout << "Input day ";
				std::cin >> day;
			}
			if (day <= 31 && day > 1) {
				day2 = day - 1; month2 = month; year2 = year;
			}
			else {
				day2 = 30; month2 = month - 1; year2 = year;
				if (month == 1) {
					day2 = 31; month2 = 12; year2 = year - 1;
				}
				if (month == 3) {
					day2 = 29;
				}
			}
			break;
		}
		case 4:
		case 6:
		case 9:
		case 11:
		{
			while (day > 30) {
				std::cout << "Input day ";
				std::cin >> day;
			}
			if (day <= 30 && day > 1) {
				day2 = day - 1; month2 = month; year2 = year;
			}
			else {
				day2 = 31; month2 = month - 1; year2 = year;
			}
			break;
		}
		default:
		{
			while (day > 29) {
				std::cout << "Input day ";
				std::cin >> day;
			}
			if (day <= 29 && day > 1) {
				day2 = day - 1; month2 = month; year2 = year;
			}
			else {
				day2 = 31; month2 = month - 1; year2 = year;
			}
			break;
		}
		}
	}
	else
	{
		switch (month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
		{
			while (day > 31) {
				std::cout << "Input day ";
				std::cin >> day;
			}
			if (day <= 31 && day > 1) {
				day2 = day - 1; month2 = month; year2 = year;
			}
			else {
				day2 = 30; month2 = month - 1; year2 = year;
				if (month == 1) {
					day2 = 31; month2 = 12; year2 = year - 1;
				}
				if (month == 3) {
					day2 = 28;
				}
			}
			break;
		}
		case 4:
		case 6:
		case 9:
		case 11:
		{
			while (day > 30) {
				std::cout << "Input day ";
				std::cin >> day;
			}
			if (day <= 30 && day > 1) {
				day2 = day - 1; month2 = month; year2 = year;
			}
			else {
				day2 = 31; month2 = month - 1; year2 = year;
			}
			break;
		}
		default:
		{
			while (day > 28) {
				std::cout << "Input day ";
				std::cin >> day;
			}
			if (day <= 28 && day > 1) {
				day2 = day - 1; month2 = month; year2 = year;
			}
			else {
				day2 = 31; month2 = month - 1; year2 = year;
			}
			break;
		}
		}
	}
}

bool checkAllEven(long long int q)
{
	while (q >= 1)
	{
		int temp = q % 10;
		if (temp % 2 == 0)  q = q / 10;
		if (temp % 2 == 1) {
			return false;
			break;
		}
	}
	if (q < 1) return true;
}

int findGreatestCommonDivisior(int a, int b, int &max)
{
	if (a >= b) {
		for (int i = 1; i <= a; i++) 
			if (a % i == 0 && b % i == 0) max = i;
	}
	else {
		for (int i = 1; i <= b; i++) 
			if (b % i == 0 && a % i == 0) max = i;
	}
	return max;
}

void findPrimeFactors(int w)
{
	for (int i = 2; i <= w; i++)
	{
		int count = 0;
		for (int j = 2; j <= i; j++)
		{
			if (i % j == 0) count++;
			if (count > 1) break;
		}
		if (count <= 1) {
			if (w % i == 0) {
				std::cout << i << " ";
				w = w / i;
			}
		}
	}
	std::cout << std::endl;
}
int findNearestPrimeNum(int e)
{
	for (int i = e; i >= 2; i--) {
		int count = 0;
		for (int j = 2; j <= i; j++) {
			if (i % j == 0) count++;
			if (count > 1) break;
		}
		if (count <= 1) {
			return i;
			break;
		}
	}
}