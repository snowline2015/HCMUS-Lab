#include <iostream>
#include <string>

struct stack {
	char* data;
	int top;
	int size;
};

void init(stack& s, int size) {
	int answer;
	s.size = size;
	s.data = new char[s.size];
	s.top = -1;
	while (s.top < s.size - 1) {
		std::cout << "Enter 1 to continue, 0 to stop : ";
		std::cin >> answer;
		if (answer == 1) {
			s.top++;
			std::cout << "Input element : ";
			std::cin >> s.data[s.top];
		}
		else break;
	}
}

void push(stack& s, char x) {
	if (s.top == s.size - 1)
		std::cout << "Stack is full" << std::endl;
	else {
		s.top++;
		s.data[s.top] = x;
	}
}

char pop(stack& s) {
	if (s.top < 0) {
		std::cout << "Stack is empty" << std::endl;
		return NULL;
	}
	else {
		char x = s.data[s.top];
		s.top--;
		return x;
	}
}

bool isEmpty(stack s) {
	if (s.top < 0) return true;
	else return false;
}

void empty(stack& s) { s.top = -1; }

int size(stack& s) { return s.top + 1; }

void displayAll(stack s) {
	for (int i = 0; i <= s.top; i++) {
		std::cout << s.data[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	stack myStack;
	int Size, menu;
	char data;
	std::cout << "Input size of stack : ";
	std::cin >> Size;
	while (Size == 0) {
		std::cout << "Size cannot be 0. Please input another size : ";
		std::cin >> Size;
	}
	std::cout << "Input elements of stack : " << std::endl;
	init(myStack, Size);
	std::cout << "* Menu *\n"
		<< "1. Add an character to stack.\n"
		<< "2. Remove the top element from stack, return the value of the removed one.\n"
		<< "3. Check whether a stack is empty or not.\n"
		<< "4. Make a stack empty.\n"
		<< "5. Get the number of elements in the stack.\n"
		<< "Press any key else to end program.\n"
		<< "Choose your option : ";
	std::cin >> menu;
	while (1 <= menu && menu <= 5) {
		if (menu == 1) {
			std::cout << "Input an character to add to stack : ";
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
