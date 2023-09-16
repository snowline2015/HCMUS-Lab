#include "Function.h"

void load(linkedList& lst1, linkedList& lst2)
{
	lst1.head = NULL;
	lst2.head = NULL;
	FILE* fp = fopen("input.txt", "r");
	if (fp == NULL)
		std::cout << "Error while opening file" << std::endl;
	else {
		node* temp = new node;
		fscanf_s(fp, "%d", &temp->data);
		if (temp->data == 0) return;
		lst1.head = temp;
		node* curr1 = lst1.head;
		while (!feof(fp)) {
			curr1->next = new node;
			fscanf_s(fp, "%d", &curr1->next->data);
			if (curr1->next->data == 0) {
				curr1->next = NULL;
				break;
			}
			curr1 = curr1->next;
		}
		temp = new node;
		fscanf_s(fp, "%d", &temp->data);
		if (temp->data == 0) return;
		lst2.head = temp;
		node* curr2 = lst2.head;
		while (!feof(fp)) {
			curr2->next = new node;
			fscanf_s(fp, "%d", &curr2->next->data);
			if (curr2->next->data == 0) {
				curr2->next = NULL;
				break;
			}
			curr2 = curr2->next;
		}
	}
}

void join2Lists(linkedList& lst1, linkedList lst2)
{
	node* curr1 = lst1.head,
		* curr2 = lst2.head;
	while (curr1->next != NULL) {
		curr1 = curr1->next;
	}
	curr1->next = curr2;
}


void save(linkedList lst1)
{
	FILE* file = fopen("output.txt", "w");
	if (file == NULL)
		std::cout << "Error while opening file" << std::endl;
	else {
		node* current = lst1.head;
		while (current != NULL) {
			fprintf_s(file, "%d ", current->data);
			current = current->next;
		}
		fprintf(file, "0");
		fclose(file);
	}
}