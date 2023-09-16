#include "Function.h"

int main()
{
	stack myStack;
	int Size, data, menu;
	std::cout << "Input size of stack : ";
	std::cin >> Size;
	while (Size == 0) {
		std::cout << "Size cannot be 0. Please input another size : ";
		std::cin >> Size;
	}
	std::cout << "Input elements of stack : " << std::endl;
	init(myStack, Size);
	std::cout << "* Menu *\n"
		<< "1. Add an integer to stack.\n"
		<< "2. Remove the top element from stack, return the value of the removed one.\n"
		<< "3. Check whether a stack is empty or not.\n"
		<< "4. Make a stack empty.\n"
		<< "5. Get the number of elements in the stack.\n"
		<< "Press any key else to end program.\n"
		<< "Choose your option : ";
	std::cin >> menu;
	while (1 <= menu && menu <= 5) {
		if (menu == 1) {
			std::cout << "Input an integer to add to stack : ";
			std::cin >> data;
			push(myStack, data);
			displayAll(myStack);
		}

		if (menu == 2) {
			std::cout << "The removed element : " << pop(myStack) << std::endl;
			displayAll(myStack);
		}

		if (menu == 3) {
			bool answer = isEmpty(myStack);
			if (answer == 1) std::cout << "True" << std::endl;
			else std::cout << "False" << std::endl;
		}

		if (menu == 4) {
			empty(myStack);
			std::cout << "Your stack is now empty" << std::endl;
		}

		if (menu == 5)
			std::cout << "Number of element in stack : " << size(myStack) << std::endl;
		
		std::cout << "Choose your option : ";
		std::cin >> menu;
	}
	return 0;
}