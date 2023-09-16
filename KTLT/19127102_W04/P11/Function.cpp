#include "Function.h"

void load(int& x)
{
	FILE* fp = fopen("input.txt", "r");
	if (fp == NULL)
		std::cout << "Error while opening file" << std::endl;
	//while (!feof(fp))
		fscanf_s(fp, "%d", &x);
}

void numberToList(linkedList& lst, int& x)
{
	node* temp = new node;
	lst.head = temp;
	delete temp;
	node* current = lst.head;
	while (x != 0) {
		int a = x % 10;
		current->data = a;
		if (x / 10 == 0) {
			current->next = NULL;
			break;
		}
		current->next = new node;
		current = current->next;
		x = x / 10;
	}
	reverseTheList(lst);
}

void reverseTheList(linkedList& lst)
{
	node* curr1 = NULL,
		* curr2 = lst.head,
		* curr3 = lst.head->next;
	do {
		curr2->next = curr1;
		curr1 = curr2;
		curr2 = curr3;
		if (curr3 != NULL) curr3 = curr3->next;
	} while (curr2 != NULL);
	lst.head = curr1;
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
		fprintf(file, "-1");
		fclose(file);
	}
}