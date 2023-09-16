#include "Function.h"

void load(linkedList& lst)
{
	lst.head = NULL;
	FILE* fp = fopen("input.txt", "r");
	if (fp == NULL)
		std::cout << "Error while opening file" << std::endl;
	else {
		node* temp = new node;
		fscanf_s(fp, "%d", &temp->data);
		if (temp->data == 0) return;
		lst.head = temp;
		node* current = lst.head;
		while (!feof(fp)) {
			current->next = new node;
			fscanf_s(fp, "%d", &current->next->data);
			if (current->next->data == 0) {
				current->next = NULL;
				break;
			}
			current = current->next;
		}
	}
}

void removeAllX(linkedList& lst)
{
	int x;
	std::cout << "Enter x to remove : ";
	std::cin >> x;
	node* current = lst.head;
	while (current->next != NULL) {
		if (lst.head != NULL && lst.head->data == x) {
			node* temp = lst.head;
			lst.head = lst.head->next;
			delete temp;
			current = lst.head;
		}
		else {
			if (current->next->data == x) {
				node* temp1 = current, * temp2 = current->next, * temp;
				while (temp2->next->data == x) {
					temp1 = temp2;
					temp2 = temp2->next;
					temp = temp1;
					delete temp;
				}
				current->next = temp2->next;
				delete temp2, temp1;
			}
			else current = current->next;
		}
	}
}


void save(linkedList lst)
{
	FILE* file = fopen("output.txt", "w");
	if (file == NULL)
		std::cout << "Error while opening file" << std::endl;
	else {
		node* current = lst.head;
		while (current != NULL) {
			fprintf_s(file, "%d ", current->data);
			current = current->next;
		}
		fprintf(file, "0");
		fclose(file);
	}
}