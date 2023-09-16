#include "Function.h"

int main()
{
	int menu, array[100], n;
	std::cout << "1. Input an array of integers from keyboard\n"
		<< "2. Load an array of integers from a binary file\n"
		<< "Press any keys else to end program\n"
		<< "Choose your option : ";
	std::cin >> menu;
	while (1 <= menu && menu <= 2) {
		if (menu == 1) {
			inputArray(array, n);
			saveBin(array, n);
		}
		if (menu == 2) {
			loadBin(array);
			std::cout << "Median of array : " 
				<< findMedian(array) << std::endl;
		}
		std::cout << "Choose your option : ";
		std::cin >> menu;
	}
	return 0;
}