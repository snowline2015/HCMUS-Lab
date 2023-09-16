#include "Function.h"


void conversion(stack& s, unsigned long num)
{
	unsigned long temp = num;
	int surplus;
	s.top = -1;
	s.size = 0;
	do {
		s.size++;
		temp = temp / 2;
	} while (temp != 0);
	s.data = new int[s.size];
	temp = num;
	do {
		surplus = temp % 2;
		push(s, surplus);
		temp = temp / 2;
	} while (temp != 0);
}

void push(stack& s, int x)
{
	s.top++;
	s.data[s.top] = x;
}

void pop(stack& s)
{
	if (s.top < 0) {
		std::cout << "Stack is empty" << std::endl;
	}
	else {
		while (s.top >= 0) {
			std::cout << s.data[s.top] << " ";
			s.top--;
		}
	}
}

