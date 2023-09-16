#include "Function.h"

void init(stack& s, int size)
{
	s.head = NULL;
	int answer;
	s.size = size;
	s.count = -1;
	while (s.count < s.size) {
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