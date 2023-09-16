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

void insertEvenNumbers(linkedList& lst)
{
	int num = 2;
	node* temp = new node;
	temp->data = num;
	temp->next = lst.head;
	lst.head = temp;
	node* prev = lst.head->next,
		* current = lst.head->next->next;
	while (current != NULL) {
		num += 2;
		temp = new node;
		temp->data = num;
		prev->next = temp;
		temp->next = current;
		prev = current;
		current = current->next;
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