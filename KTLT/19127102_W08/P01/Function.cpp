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

void removeAllX(linkedList& lst, node* current, int x)
{
	if (current == NULL) {
		return;
	}
	else {
		if (current->data == x) {
			node* prev = lst.head;
			while (prev->next != current) {
				prev = prev->next;
			}
			node* temp = prev->next;
			prev->next = temp->next;
			delete temp;
			current = prev;
		}
	}
	removeAllX(lst, current->next, x);
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