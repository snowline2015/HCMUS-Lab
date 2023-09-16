#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

struct node {
	int data;
	node* next;
};

struct linkedList {
	node* head;
};

void init(linkedList& lst) {
	int answer;
	node* current = lst.head;
	while (true) {
		std::cout << "Enter 1 to continue, 0 to stop : ";
		std::cin >> answer;
		if (answer == 1) {
			std::cout << "Input data: ";
			if (lst.head == NULL) {
				node* temp = new node;
				std::cin >> temp->data;
				lst.head = temp;
				lst.head->next = NULL;
				current = lst.head;
			}
			else {
				current->next = new node;
				std::cin >> current->next->data;
				current = current->next;
				current->next = NULL;
			}
		}
		else break;
	}
}

void sort(linkedList& lst) {
	for (node* current = lst.head; current != NULL; current = current->next) {
		for (node* current2 = current->next; current2 != NULL; current2 = current2->next) {
			if (current->data > current2->data) {
				int temp = current->data;
				current->data = current2->data;
				current2->data = temp;
			}
		}
	}
}

void display(linkedList lst)
{
	for (node* current = lst.head; current != NULL; current = current->next) {
		std::cout << current->data << " ";
	}
	std::cout << std::endl;
}

int main() {
	linkedList myList;
	myList.head = NULL;
	init(myList);
	display(myList);
	sort(myList);
	display(myList);
	return 0;
}
