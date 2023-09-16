/*
MSSV : 19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9
*/
#include "array.h"

int main()
{
	int a[100], n, b[100], m, c[100], p;
	int enterOption;

	std::cout << "1. P01: Tim so chan lon nhat va so le nho nhat\n";
	std::cout << "2. P02: Tinh trung binh cong cac so chan\n";
	std::cout << "3. P04: Tim cac so nguyen to\n";
	std::cout << "4. P05: Sap xep cac so chan tang dan\n";
	std::cout << "5. P06: Kiem tra thu tu cac phan tu cua mang\n";
	std::cout << "6. P09: Dem cac phan tu khac nhau trong mang\n";
	std::cout << "7. P12: Tim phan tu lon thu 2 thuoc mang\n";
	std::cout << "8. P15: Dao nguoc mang\n";
	std::cout << "9. P25: Tron 2 mang khong giam\n";
	std::cout << "10. P26: Cac phan tu cung xuat hien tren 2 mang\n";
	std::cout << "0. Exit\n";
	std::cout << "\nEnter option : ";
	std::cin >> enterOption;
	std::cout << std::endl;


	switch (enterOption)
	{
	case 1:
		/*
		Test case 1
		Input: 5 - 2 6 3 8 5
		Output: 8 3
		Test case 2
		Input: 5 - 1 3 5 10 4
		Output: 10 1
		Test case 3
		Input: 5 - 12 23 34 45 56
		Output: 56 23
		*/
	{
		int max, min;
		std::cout << "Input size : ";
		std::cin >> n;
		std::cout << "Input array : ";
		inputArray(a, n);
		findLargestEvenSmallestOddNums(a, n, b, m, c, p, max, min);
		std::cout << max << " " << min << std::endl;
		break;
	}
	case 2:
		/*
		Test case 1
		Input: 5 - 1 3 4 6 8
		Output: 6.67
		Test case 2
		Input: 5 - 2 6 3 8 5
		Output: 5.33
		Test case 3
		Input: 5 - 1 1 10 10 10
		Output: 10
		*/
	{
		std::cout << "Input size : ";
		std::cin >> n;
		std::cout << "Input array : ";
		inputArray(a, n);
		std::cout << std::fixed << std::setprecision(2) << averageEvenNums(a, n) << std::endl;
		break;
	}
	case 3:
		/*
		Test case 1
		Input: 5 - 2 6 1 8 7
		Output: 2 - 2 7
		Test case 2
		Input: 5 - 1 2 3 4 5
		Output: 3 - 2 3 5
		Test case 3
		Input: 5 - 12 23 34 45 56
		Output: 1 - 23
		*/
	{
		std::cout << "Input size : ";
		std::cin >> n;
		std::cout << "Input array : ";
		inputArray(a, n);
		findPrimeNums(a, n, b, m);
		std::cout << m << std::endl;
		outputArray(b, m);
		break;
	}
	case 4:
		/*
		Test case 1
		Input: 5 - 2 6 1 4 7
		Output: 2 4 1 6 7
		Test case 2
		Input: 5 - 1 3 5 10 4
		Output: 1 3 5 4 10
		Test case 3
		Input: 5 - 8 1 3 2 6
		Output: 2 1 3 6 8
		*/
	{
		std::cout << "Input size : ";
		std::cin >> n;
		std::cout << "Input array : ";
		inputArray(a, n);
		arrangeIncreasingEvenNums(a, n);
		std::cout << std::endl;
		outputArray(a, n);
		break;
	}
	case 5:
		/*
		Test case 1
		Input: 5 - 2 6 1 4 7
		Output: khong tang khong giam
		Test case 2
		Input: 5 - 1 2 3 4 5
		Output: ham tang
		Test case 3
		Input: 5 - 9 8 7 6 5
		Output: ham giam
		*/
	{
		int ans;
		std::cout << "Input size : ";
		std::cin >> n;
		std::cout << "Input array : ";
		inputArray(a, n);
		checkArraySorted(a, n, ans);
		if (ans == 0) std::cout << "Khong tang khong giam" << std::endl;
		if (ans == 1) std::cout << "Ham tang" << std::endl;
		if (ans == 2) std::cout << "Ham giam" << std::endl;
		break;
	}
	case 6:
		/*
		Test case 1
		Input: 8 - 3 5 12 5 45 87 675 5
		Output: 6
		Test case 2
		Input: 5 - 1 1 1 1 1
		Output: 1
		Test case 3
		Input: 5 - 1 3 5 3 1
		Output: 3
		*/
	{
		std::cout << "Input size : ";
		std::cin >> n;
		std::cout << "Input array : ";
		inputArray(a, n);
		std::cout << countDifferentElements(a, n) << std::endl;
		break;
	}
	case 7:
		/*
		Test case 1
		Input: 5 - 2 6 3 8 5
		Output: 6
		Test case 2
		Input: 5 - 1 3 5 10 4
		Output: 5
		Test case 3
		Input: 8 - 5 12 5 45 87 678 5
		Output: 87
		*/
	{
		std::cout << "Input size : ";
		std::cin >> n;
		std::cout << "Input array : ";
		inputArray(a, n);
		std::cout << findSecondLargestElement(a, n) << std::endl;
		break;
	}
	case 8:
		/*
		Test case 1
		Input: 5 - 2 6 1 4 7
		Output: 7 4 1 6 2
		Test case 2
		Input: 5 - 1 2 3 4 5
		Output: 5 4 3 2 1
		Test case 3
		Input: 7 - 3 5 12 67 45 87 678
		Output: 678 87 45 67 12 5 3
		*/
	{
		std::cout << "Input size : ";
		std::cin >> n;
		std::cout << "Input array : ";
		inputArray(a, n);
		reverseArray(a, n, b, m);
		outputArray(b, m);
		break;
	}
	case 9:
		/*
		Test case 1
		Input: 7 6 - 3 5 12 67 80 87 678 - 5 23 34 45 56 67
		Output: 3 5 5 12 23 34 45 56 67 67 80 87 678
		Test case 2
		Input: 5 5 - 1 3 5 10 4 - 1 2 3 4 5
		Output: 1 1 2 3 3 4 4 5 5 10
		Test case 3
		Input: 5 6 - 11 22 33 44 55 - 12 23 34 45 56 67
		Output: 11 12 22 33 34 44 45 55 56 67
		*/
	{
		std::cout << "Input 2 sizes : ";
		std::cin >> n >> m;
		std::cout << "Input 2 arrays : ";
		inputArray(a, n);
		inputArray(b, m);
		mix2ArraysWithoutReduction(a, n, b, m, c, p);
		outputArray(c, p);
		break;
	}
	case 10:
		/*
		Test case 1
		Input: 7 6 - 3 5 12 67 67 45 678 - 5 23 12 45 12 67
		Output: 5 5 12 12 67 67 45
		Test case 2
		Input: 5 5 - 1 3 5 10 4 - 1 2 3 4 5
		Output: 1 3 5 4
		Test case 3
		Input: 7 6 - 3 5 12 67 80 45 678 - 5 23 12 45 56 67
		Output: 5 12 67 45
		*/
	{
		std::cout << "Input 2 sizes : ";
		std::cin >> n >> m;
		std::cout << "Input 2 arrays : ";
		inputArray(a, n);
		inputArray(b, m);
		findElementsAppearOnBothArrays(a, n, b, m, c, p);
		outputArray(c, p);
		break;
	}
	case 0:
	{
		std::cout << "The program will now exit." << std::endl;
		break;
	}
	default: break;
	}
	std::cout << std::endl;
	system("PAUSE");
	return 0;
}