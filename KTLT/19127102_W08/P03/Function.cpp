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

void reverseList(linkedList& lst, node* current1, node* current2, node* current3)
{
	if (current2 == NULL) {
		lst.head = current1;
		return;
	}
	else {
		current2->next = current1;
		current1 = current2;
		current2 = current3;
	}
	if (current3 != NULL) 
		reverseList(lst, current1, current2, current3->next);
	else reverseList(lst, current1, current2, current3);
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