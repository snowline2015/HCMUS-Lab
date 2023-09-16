#include "Function.h"

int main()
{
	int menu, array[100], n;
	Date date[100];
	std::cout << "1. Input an array of dates from keyboard\n"
		<< "2. Load an array of dates from a binary file\n"
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
			findNewestDate(date, array);
			std::cout << "Newest date : " << date[0].day << "/" << date[0].month << "/" << date[0].year << std::endl;
		}
		std::cout << "Choose your option : ";
		std::cin >> menu;
	}
	return 0;
}