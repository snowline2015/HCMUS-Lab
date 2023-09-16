#include <iostream>

struct node {
	int data;
	node* next;
};

struct LinkedList {
	node* head;
};

void init(LinkedList& lst) {
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

void display(LinkedList lst)
{
	for (node* current = lst.head; current != NULL; current = current->next) {
		std::cout << current->data << " ";
	}
	std::cout << std::endl;
}

void deleteNode(LinkedList& lst) {
	int key;
	std::cout << "Input x to delete: ";
	std::cin >> key;
	for (node* current = lst.head; current != NULL; current = current->next) {
		if (current->data == key) {
			if (current == lst.head) {
				lst.head = current->next;
				current = lst.head;
			}
			else {
				node* temp = lst.head;
				while (temp->next != current) temp = temp->next;
				temp->next = current->next;
				current = temp;
			}
		}
	}
}

int main() {
	LinkedList myList;
	myList.head = NULL;
	init(myList);
	display(myList);
	deleteNode(myList);
	display(myList);
	return 0;
}