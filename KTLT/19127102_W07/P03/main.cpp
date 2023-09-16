#include "Function.h"

int main()
{
	int* arr, n;
	std::cout << "Input number of elements : ";
	std::cin >> n;
	while (n == 0) {
		std::cout << "Input number of elements : ";
		std::cin >> n;
	}
	arr = new int[n];
	std::cout << "Input array : " << std::endl;
	for (int i = 0; i < n; i++) 
		std::cin >> arr[i];

	int menu;
	std::cout << "1. Output the array of integer values to screen. " << std::endl;
	std::cout << "2. Output the array of integer values to screen in reversed order." << std::endl;
	std::cout << "3. Find the sum of positive numbers in the array. " << std::endl;
	std::cout << "4. Count all distinct values in the array. " << std::endl;
	std::cout << "5. Check whether the array only contains odd numbers." << std::endl;
	std::cout << "6. Find the maximum value in the array." << std::endl;
	std::cout << "Press any keys else to exit." << std::endl;
	std::cout << "Enter your option : ";
	std::cin >> menu;

	switch (menu)
	{
	case 1: {
		outputArray(arr, n, 0);
		break;
	}
	case 2: {
		reversedOutputArray(arr, n);
		break;
	}
	case 3: {
		std::cout << "Sum of Positive Numbers : " << sumPositiveNum(arr, n) << std::endl;
		break;
	}
	case 4: {
		std::cout << "Distinct Values : " << countAllDistinctValue(arr, n) << std::endl;
		break;
	}
	case 5: {
		bool ans = haveOddNum(arr, n);
		if (ans == true) std::cout << "The array contains odd number." << std::endl;
		else std::cout << "The array doesn't contain odd number" << std::endl;
		break;
	}
	case 6: {
		std::cout << "Max value : " <<  max(arr, n) << std::endl;
		break;
	}
	default: break;
	}
	return 0;
}