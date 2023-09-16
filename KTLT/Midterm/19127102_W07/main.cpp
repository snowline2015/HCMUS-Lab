#include "Function.h"

int main()
{
	int menu, x;
	linkedList myList, myList2;
	std::cout << "1. Exercise 1\n" << "2. Excercise 2\n"
		<< "Enter your option : ";
	std::cin >> menu;
	if (menu == 1) {
		load(myList);
		appearOneTime(myList, myList2);
		save(myList2);
	}
	else if (menu == 2) {
		load2(myList);
		std::cout << "Input a number to insert : ";
		std::cin >> x;
		insertNodeBeforePrimeNum(myList, x);
		save2(myList);
	}
	return 0;
}