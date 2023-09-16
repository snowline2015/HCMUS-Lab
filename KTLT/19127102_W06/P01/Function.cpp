#include "Function.h"

void init(stack& s, int size)
{
	int answer;
	s.size = size;
	s.data = new int[s.size];
	s.top = -1;
	while (s.top < s.size) {
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

void push(stack& s, int x) 
{
	if (s.top == s.size - 1)
		std::cout << "Stack is full" << std::endl;
	else {
		s.top++;
		s.data[s.top] = x;
	}
}

int pop(stack& s)
{
	if (s.top < 0) {
		std::cout << "Stack is empty" << std::endl;
		return NULL;
	}
	else {
		int x = s.data[s.top];
		s.top--;
		return x;
	}
}

bool isEmpty(stack s)
{
	if (s.top < 0) return true;
	else return false;
}

void empty(stack& s)
{
	s.top = -1;
}

int size(stack& s)
{
	return s.top + 1;
}

void displayAll(stack s)
{
	for (int i = 0; i <= s.top; i++) {
		std::cout << s.data[i] << " ";
	}
	std::cout << std::endl;
}