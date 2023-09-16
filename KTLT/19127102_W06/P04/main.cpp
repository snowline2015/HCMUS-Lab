#include "Function.h"

int main()
{
	queue myQueue;
	int Size, data, menu;
	std::cout << "Input size of queue : ";
	std::cin >> Size;
	while (Size == 0) {
		std::cout << "Size cannot be 0. Please input another size : ";
		std::cin >> Size;
	}
	std::cout << "Input elements of queue : " << std::endl;
	init(myQueue, Size);
	std::cout << "* Menu *\n"
		<< "1. Add an integer to queue.\n"
		<< "2. Remove the oldest element from queue, return the value of the removed one.\n"
		<< "3. Check whether a queue is empty or not.\n"
		<< "4. Make a queue empty.\n"
		<< "5. Get the number of elements in the queue.\n"
		<< "Press any key else to end program.\n"
		<< "Choose your option : ";
	std::cin >> menu;
	while (1 <= menu && menu <= 5) {
		if (menu == 1) {
			std::cout << "Input an integer to add to queue : ";
			std::cin >> data;
			enqueue(myQueue, data);
			displayAll(myQueue);
		}

		if (menu == 2) {
			std::cout << "The removed element : " << dequeue(myQueue) << std::endl;
			displayAll(myQueue);
		}

		if (menu == 3) {
			bool answer = isEmpty(myQueue);
			if (answer == 1) std::cout << "True" << std::endl;
			else std::cout << "False" << std::endl;
		}

		if (menu == 4) {
			empty(myQueue);
			std::cout << "Your queue is now empty" << std::endl;
		}

		if (menu == 5)
			std::cout << "Number of element in queue : " << size(myQueue) << std::endl;

		std::cout << "Choose your option : ";
		std::cin >> menu;
	}
	return 0;
}