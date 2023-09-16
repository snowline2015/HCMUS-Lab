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

void removeDuplicate(linkedList& lst, node* current)
{
	if (current == NULL) {
		return;
	}
	else {
		for (node* temp2 = lst.head; temp2 != current; temp2 = temp2->next) {
			if (current->data == temp2->data) {
				node* prev = lst.head;
				while (prev->next != current) {
					prev = prev->next;
				}
				node* temp = prev->next;
				prev->next = temp->next;
				delete temp;
				current = prev;
				break;
			}
		}
	}
	removeDuplicate(lst, current->next);
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