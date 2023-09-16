#include "Function.h"

void load(char*& s1, char*& s2)
{
	char sequence[201];
	FILE* fp = fopen("input.txt", "r");
	if (fp == NULL)
		std::cout << "Error while opening file" << std::endl;
	else {
		while (!feof(fp)) {
			fscanf(fp, "%[^\n]\n", &sequence);
			s1 = new char[strlen(sequence) + 1];
			strcpy(s1, sequence);
			fscanf(fp, "%[^\n]\n", &sequence);
			s2 = new char[strlen(sequence) + 1];
			strcpy(s2, sequence);
		}
	}
}

void sum2Lists(doublyLinkedList& lst1, doublyLinkedList& lst2, char* s1, char* s2)
{
	lst1.head = NULL;
	lst2.head = NULL;
	
	node* temp = new node;
	temp->data = s1[0] - 48;
	lst1.head = temp;
	lst1.head->prev = NULL;
	node* current = lst1.head;
	for (int i = 1; i <= strlen(s1); i++) {
		node* temp = new node;
		temp->data = s1[i] - 48;
		current->next = temp;
		temp->prev = current;
		current = current->next;
	}
	current->prev->next = NULL;

	temp = new node;
	temp->data = s2[0] - 48;
	lst2.head = temp;
	lst2.head->prev = NULL;
	current = lst2.head;
	for (int i = 1; i <= strlen(s2); i++) {
		node* temp = new node;
		temp->data = s2[i] - 48;
		current->next = temp;
		temp->prev = current;
		current = current->next;
	}
	current->prev->next = NULL;

	if (strlen(s1) >= strlen(s2)) {
		node* current1 = lst1.head,
			*current2 = lst2.head;
		while (current1->next != NULL)
			current1 = current1->next;
		while (current2->next != NULL)
			current2 = current2->next;
		while (current2 != NULL) {
			current1->data += current2->data;
			if (current1->data >= 10) {
				current1->data -= 10;
				current1->prev->data += 1;
			}
			current1 = current1->prev;
			current2 = current2->prev;
		}
	}
	else {
		node* current1 = lst2.head,
			* current2 = lst1.head;
		while (current1->next != NULL)
			current1 = current1->next;
		while (current2->next != NULL)
			current2 = current2->next;
		while (current2 != NULL) {
			current1->data += current2->data;
			if (current1->data >= 10) {
				current1->data -= 10;
				current1->prev->data += 1;
			}
			current1 = current1->prev;
			current2 = current2->prev;
		}
	}
}

void save(doublyLinkedList lst1, doublyLinkedList lst2, char* s1, char* s2)
{
	FILE* file = fopen("output.txt", "w");
	if (file == NULL)
		std::cout << "Error while opening file" << std::endl;
	else {
		if (strlen(s1) >= strlen(s2)) {
			node* current = lst1.head;
			while (current != NULL) {
				fprintf_s(file, "%d", current->data);
				current = current->next;
			}
		}
		else {
			node* current = lst2.head;
			while (current != NULL) {
				fprintf_s(file, "%d", current->data);
				current = current->next;
			}
		}
		fprintf(file, "\n");
		fclose(file);
	}
}