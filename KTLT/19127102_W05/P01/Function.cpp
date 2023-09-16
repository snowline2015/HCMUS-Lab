#include "Function.h"

void load(circularLinkedList& lst)
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
				current->next = lst.head;
				break;
			}
			current = current->next;
		}
	}
}

void removeDuplicate(circularLinkedList& lst)
{
	node* current = lst.head;
	do {
		node* temp = current,
			* temp1 = current->next;
		while (temp1 != lst.head) {
			if (temp1->data == current->data) {
				node* temp2 = temp1;
				if (temp1->next->data != current->data) {
					temp->next = temp1->next;
					temp = temp->next;
				}
				temp1 = temp1->next;
				delete temp2;
				temp2 = NULL;
			}
			else temp1 = temp1->next;
		}
		if (current->next->data == -572662307) {
			current->next = current;
			break;
		}
		current = current->next;
	} while (current != lst.head);
}

void save(circularLinkedList lst)
{
	FILE* fp = fopen("output.txt", "w");
	if (fp == NULL)
		std::cout << "Error while opening file" << std::endl;
	else {
		node* current = lst.head;
		do {
			fprintf_s(fp, "%d ", current->data);
			current = current->next;
		} while (current != lst.head);
		fprintf(fp, "0");
		fclose(fp);
	}
}