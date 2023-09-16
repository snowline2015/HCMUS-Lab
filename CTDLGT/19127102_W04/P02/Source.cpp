#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

struct node {
	int data;
	node* next;
};
struct queue {
	int size;
	int count;
	node* head,
		* tail;
};

void init(queue& s, int size)
{
	s.head = NULL;
	node* current = s.head;
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