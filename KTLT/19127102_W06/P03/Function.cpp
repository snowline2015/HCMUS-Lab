#include "Function.h"

void init(queue& s, int size)
{
	int answer;
	s.size = size;
	s.data = new int[s.size];
	s.in = -1;
	s.out = 0;
	while (s.in < s.size) {
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

void enqueue(queue& s, int x)
{
	if (s.in == s.size - 1)
		std::cout << "Queue is full" << std::endl;
	else {
		s.in++;
		s.data[s.in] = x;
	}
}

int dequeue(queue& s)
{
	if (s.in < 0) {
		std::cout << "Queue is empty" << std::endl;
		return NULL;
	}
	else {
		int x = s.data[s.out];
		for (int i = 0; i < s.in; i++) {
			s.data[i] = s.data[i + 1];
		}
		s.in--;
		return x;
	}
}

bool isEmpty(queue s)
{
	if (s.in < 0) return true;
	else return false;
}

void empty(queue& s)
{
	s.in = -1;
}

int size(queue& s)
{
	return s.in + 1;
}

void displayAll(queue s)
{
	for (int i = 0; i <= s.in; i++) {
		std::cout << s.data[i] << " ";
	}
	std::cout << std::endl;
}