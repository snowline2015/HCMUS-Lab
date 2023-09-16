#include <iostream>

struct queue {
	int* data;
	int in;
	int size;
};

void init(queue& s, int size) {
	int answer;
	s.size = size;
	s.data = new int[s.size];
	s.in = -1;
	while (s.in < s.size - 1) {
		std::cout << "Enter 1 to continue, 0 to stop : ";
		std::cin >> answer;
		if (answer == 1) {
			s.in++;
			std::cout << "Input element : ";
			std::cin >> s.data[s.in];
		}
		else break;
	}
}

void enqueue(queue& s, int x) {
	if (s.in == s.size - 1)
		std::cout << "Queue is full" << std::endl;
	else {
		s.in++;
		s.data[s.in] = x;
	}
}

int dequeue(queue& s) {
	if (s.in < 0) {
		std::cout << "Queue is empty" << std::endl;
		return NULL;
	}
	else {
		int x = s.data[0];
		for (int i = 0; i < s.in; i++) {
			s.data[i] = s.data[i + 1];
		}
		s.in--;
		return x;
	}
}

bool isEmpty(queue s) {
	if (s.in < 0) return true;
	else return false;
}

void empty(queue& s) { s.in = -1; }

int size(queue& s) { return s.in + 1; }

void displayAll(queue s) {
	for (int i = 0; i <= s.in; i++) {
		std::cout << s.data[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
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