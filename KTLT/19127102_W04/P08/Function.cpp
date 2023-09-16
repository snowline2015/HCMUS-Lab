#include "Function.h"

void load(linkedList& lst1, linkedList& lst2, int& count1, int& count2)
{
	count1 = 1; count2 = 1;
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
			count1++;
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
			count2++;
		}
	}
}

void _2ListsTo1Lists(linkedList& lst1, linkedList& lst2, int count1, int count2)
{
	int count = 1;
	node* curr1 = lst1.head,
		* curr2 = lst2.head,
		* temp = lst1.head->next;
	if (count1 >= count2) {
		while (curr1 != NULL) {
			if (count % 2 == 1) {
				curr1->next = curr2;
				curr2 = curr2->next;
			}
			else {
				curr1->next = temp;
				temp = temp->next;
			}
			curr1 = curr1->next;
			
			if (curr2 == NULL) {
				curr1->next = temp;
				break;
			}
			count += 1;
		}
	}
	else {
		curr1 = lst2.head;
		curr2 = lst1.head;
		temp = lst2.head->next;
		while (curr1 != NULL) {
			if (count % 2 == 1) {
				curr1->next = curr2;
				curr2 = curr2->next;
			}
			else {
				curr1->next = temp;
				temp = temp->next;
			}
			curr1 = curr1->next;

			if (curr2 == NULL) {
				curr1->next = temp;
				break;
			}
			count += 1;
		}
	}
}


void save(linkedList lst1, linkedList lst2, int count1, int count2)
{
	FILE* file = fopen("output.txt", "w");
	if (file == NULL)
		std::cout << "Error while opening file" << std::endl;
	else {
		node* current;
		if (count1 >= count2) current = lst1.head;
		else current = lst2.head;
		while (current != NULL) {
			fprintf_s(file, "%d ", current->data);
			current = current->next;
		}
		fprintf(file, "0");
		fclose(file);
	}
}