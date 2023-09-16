/*
MSSV : 19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9
*/

#include "function.h"

int main()
{
	int enterOption;
	std::cout << "1. P09 : Giai phuong trinh bac 2" << std::endl;
	std::cout << "2. P15 : Ngay mai" << std::endl;
	std::cout << "3. P16 : Ngay hom qua" << std::endl;
	std::cout << "4. P30 : Kiem tra so hoan thien" << std::endl;
	std::cout << "5. P31 : Kiem tra so nguyen to" << std::endl;
	std::cout << "6. P51 : Kiem tra chu so lon nhat" << std::endl;
	std::cout << "7. P56 : Kiem tra toan chu so chan" << std::endl;
	std::cout << "8. P60 : Uoc chung lon nhat cua 2 so" << std::endl;
	std::cout << "9. P78 : In cac thua so nguyen to" << std::endl;
	std::cout << "10. P80 : So nguyen to gan nhat" << std::endl;
	std::cout << "\nEnter option : ";
	std::cin >> enterOption;
	std::cout << std::endl;

	switch (enterOption)
	{
	case 1:
		/*
		Test case 1
		Input: 3 5 7
		Output : "Vo nghiem"
		Test case 2
		Input: 2 - 7 5
		Output : x1 = 2.50, x2 = 1.00
		Test case 3
		Input: 1 2 1
		Output : x = -1
		*/
	{
		double a, b, c;
		double x1, x2;
		std::cout << "Input a, b, c : ";
		std::cin >> a >> b >> c;
		int ans = solveQuadratic(a, b, c, x1, x2);
		if (ans == 0) std::cout << "x = " << std::fixed << std::setprecision(2) << x1 << std::endl;
		if (ans == 1) std::cout << "Vo nghiem" << std::endl;
		if (ans == 2) std::cout << "Nghiem kep x = " << std::fixed << std::setprecision(2) << x1 << std::endl;
		if (ans == 3)
		{
			std::cout << "x1 = " << std::fixed << std::setprecision(2) << x1 << std::endl;
			std::cout << "x2 = " << std::fixed << std::setprecision(2) << x2 << std::endl;
		}
		break;
	}
	case 2:
		/*
		Test case 1
		Input: 29  2  1980
		Output: 1 / 3 / 1980
		Test case 2
		Input: 31 12 2019
		Output: 1 / 1 / 2020
		Test case 3
		Input: 18 6 2001
		Output: 19 / 6 / 2001
		*/
	{
		int day, month, year;
		int day2, month2, year2;
		std::cout << "Input day, month, year : ";
		std::cin >> day >> month >> year;
		tomorrow(day, month, year, day2, month2, year2);
		std::cout << day2 << " / " << month2 << " / " << year2 << std::endl;
		break;
	}
	case 3:
		/*
		Test case 1
		Input: 29  2  1980
		Output: 1 / 3 / 1980
		Test case 2
		Input: 31 12 2019
		Output: 1 / 1 / 2020
		Test case 3
		Input: 18 6 2001
		Output: 19 / 6 / 2001
		*/
	{
		int day, month, year;
		int day2, month2, year2;
		std::cout << "Input day, month, year : ";
		std::cin >> day >> month >> year;
		yesterday(day, month, year, day2, month2, year2);
		std::cout << day2 << " / " << month2 << " / " << year2 << std::endl;
		break;
	}
	case 4:
		/*
		Test case 1
		Input: 6
		Output: 6 is perfect
		Test case 2
		Input: 28
		Output: 28 is perfect
		Test case 3
		Input:	5
		Output: 5 is not perfect
		*/
	{
		int x;
		std::cout << "Input x : ";
		std::cin >> x;

		bool ans = isPerfect(x);
		if (ans == true) std::cout << x << " is perfect" << std::endl;
		else std::cout << x << " is not perfect" << std::endl;
		break;
	}
	case 5:
		/*
		Test case 1
		Input: 11
		Output: 11 is prime
		Test case 2
		Input: 5
		Output: 5 is prime
		Test case 3
		Input:	6
		Output: 6 is not prime
		*/
	{
		int x;
		std::cout << "Input x : ";
		std::cin >> x;

		bool ans = isPrime(x);
		if (ans == true) std::cout << x << " is prime" << std::endl;
		else std::cout << x << " is not prime" << std::endl;
		break;
	}
	case 6:
		/*
		Test case 1
		Input: 19127102
		Output: 9
		Test case 2
		Input: 18062001
		Output: 8
		Test case 3
		Input:	19042001
		Output: 9
		*/
	{
		long long int x;
		std::cout << "Input x : ";
		std::cin >> x;
		std::cout << "The biggest digit : " << biggest(x) << std::endl;
		break;
	}
	case 7:
		/*
		Test case 1
		Input: 19127102
		Output : NO
		Test case 2
		Input: 333
		Output : NO
		Test case 3
		Input: 246
		Output : YES
		*/
	{
		long long int x;
		std::cout << "Input x : ";
		std::cin >> x;
		int ans = checkAllEven(x);
		if (ans == true) std::cout << "YES" << std::endl;
		if (ans == false) std::cout << "NO" << std::endl;
		break;
	}
	case 8:
		/*
		Test case 1
		Input: 12 20
		Output : 4
		Test case 2
		Input: 30 90
		Output : 30
		Test case 3
		Input: 100 101
		Output : 1
		*/
	{
		int a, b;
		int max;
		std::cout << "Input a, b : ";
		std::cin >> a >> b;
		std::cout << findGreatestCommonDivisior(a, b, max) << std::endl;
		break;
	}
	case 9:
		/*
		Test case 1
		Input: 14
		Output : 2 7
		Test case 2
		Input: 28
		Output : 2 7
		Test case 3
		Input: 145
		Output : 5 29
		*/
	{
		int x;
		std::cout << "Input x : ";
		std::cin >> x;
		findPrimeFactors(x);
		break;
	}
	case 10:
		/*
		Test case 1
		Input: 102
		Output : 101
		Test case 2
		Input: 18
		Output : 17
		Test case 3
		Input: 1806
		Output : 1801
		*/
	{
		long long int x;
		std::cout << "Input x : ";
		std::cin >> x;
		std::cout << "Nearest prime number : " << findNearestPrimeNum(x) << std::endl;
	}
	default: break;
	}

	system("PAUSE");
	return 0;
}