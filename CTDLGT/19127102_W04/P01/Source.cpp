#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

struct node {
	int data;
	node* next;
};
struct stack {
	int size;
	int count;
	node* head;
};

void init(stack& s, int size)
{
	s.head = NULL;
	int answer;
	s.size = size;
	s.count = -1;
	while (s.count < s.size - 1) {
		std::cout << "Enter 1 to continue, 0 to stop : ";
		std::cin >> answer;
		if (answer == 1) {
			s.count++;
			std::cout << "Input element : ";
			node* temp = new node;
			std::cin >> temp->data;
			temp->next = s.head;
			s.head = temp;
		}
		else break;
	}
}

void push(stack& s, int x)
{
	if (s.count == s.size - 1)
		std::cout << "Stack is full" << std::endl;
	else {
		s.count++;
		node* temp = new node;
		temp->data = x;
		temp->next = s.head;
		s.head = temp;
	}
}

int pop(stack& s)
{
	if (s.count < 0) {
		std::cout << "Stack is empty" << std::endl;
		return NULL;
	}
	else {
		int x = s.head->data;
		s.count--;
		node* temp = s.head;
		s.head = s.head->next;
		delete temp;
		return x;
	}
}

bool isEmpty(stack s)
{
	if (s.count < 0 && s.head == NULL) return true;
	else return false;
}

void empty(stack& s)
{
	node* current;
	while (s.head != NULL) {
		s.count--;
		current = s.head;
		s.head = s.head->next;
		delete current;
	}
}

int size(stack& s)
{
	return s.count + 1;
}

void displayAll(stack s)
{
	for (node* current = s.head; current != NULL; current = current->next) {
		std::cout << current->data << " ";
	}
	std::cout << std::endl;
}

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