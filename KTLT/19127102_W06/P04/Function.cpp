#include "Function.h"

void init(queue& s, int size)
{
	s.head = NULL;
	node* current = s.head;
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
			if (s.count == 0) {
				s.head = temp;
				current = s.head;
				current->next = NULL;
			}
			else {
				s.tail = temp;
				current->next = s.tail;
				current = current->next;
				current->next = NULL;
			}
		}
		else break;
	}
}

void enqueue(queue& s, int x)
{
	if (s.count == s.size - 1)
		std::cout << "Queue is full" << std::endl;
	else {
		s.count++;
		node* temp = new node;
		temp->data = x;
		s.tail->next = temp;
		s.tail = s.tail->next;
		s.tail->next = NULL;
	}
}

int dequeue(queue& s)
{
	if (s.count < 0) {
		std::cout << "Queue is empty" << std::endl;
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

bool isEmpty(queue s)
{
	if (s.count < 0 && s.head == NULL) return true;
	else return false;
}

void empty(queue& s)
{
	node* current;
	while (s.head != NULL) {
		s.count--;
		current = s.head;
		s.head = s.head->next;
		delete current;
	}
}

int size(queue& s)
{
	return s.count + 1;
}

void displayAll(queue s)
{
	for (node* current = s.head; current != NULL; current = current->next) {
		std::cout << current->data << " ";
	}
	std::cout << std::endl;
}