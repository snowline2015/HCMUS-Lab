#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

struct node {
	int data;
	node* next, * prev;
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
				temp->prev = temp->next = NULL;
				lst.head = temp;
				current = lst.head;
			}
			else {
				current->next = new node;
				std::cin >> current->next->data;
				current->next->prev = current;
				current = current->next;
				current->next = NULL;
			}
		}
		else break;
	}
}

int countNodes(linkedList lst) {
	int count = 0;
	node* current = lst.head;
	if (lst.head == NULL) return 0;
	while (current != NULL) {
		count++;
		current = current->next;
	}
	return count;
}

void bubbleSort(linkedList& lst) {
	int nodes = countNodes(lst);
	node* current = lst.head;
	for (int i = 0; i < nodes - 1; i++) {
		for (int j = 0; j < nodes - i - 1; j++) {
			if (current->next == NULL) break;
			if (current->data > current->next->data) {
				if (current == lst.head) {
					node* temp = current->next, * temp2 = current;
					temp2->next = temp->next;
					temp2->next->prev = temp2;
					temp->next = temp2;
					temp2->prev = temp;
					temp->prev = NULL;
					lst.head = temp;
					current = temp2;
				}
				else {
					node* temp = current->prev, * temp2 = current;
					temp->next = current->next;
					temp->next->prev = temp;
					temp2->prev = temp->next;
					temp2->next = temp->next->next;
					temp2->prev->next = temp2;
					current = temp2;
				}
			}
			else current = current->next;
		}
		current = lst.head;
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
	bubbleSort(myList);
	display(myList);
	return 0;
}
