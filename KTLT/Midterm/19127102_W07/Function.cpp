#include "Function.h"

void load(linkedList& lst)
{
	lst.head = NULL;
	FILE* fp = fopen("input1.txt", "r");
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

void load2(linkedList& lst)
{
	lst.head = NULL;
	FILE* fp = fopen("input2.txt", "r");
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

void appearOneTime(linkedList lst, linkedList& lst2)
{
	lst2.head = NULL;
	node* current3 = lst2.head;
	for (node* current = lst.head; current != NULL; current = current->next) {
		for (node* current2 = lst.head; current2 != NULL; current2 = current2->next) {
			if (current == current2) continue;
			if (current->data == current2->data) break;
			if (current2->next == NULL) {
				node* temp = new node;
				temp->data = current->data;
				if (lst2.head == NULL) {
					lst2.head = temp;
					current3 = lst2.head;
				}
				else {
					current3->next = temp;
					current3 = current3->next;
				}
			}
		}
	}
	current3->next = NULL;
}

void insertNodeBeforePrimeNum(linkedList& lst, int x)
{
	for (node* current = lst.head; current != NULL; current = current->next) {
		int count = 0;
		if (current == lst.head) {
			for (int i = 2; i < current->data; i++) {
				if (current->data % i == 0) count++;
				if (count >= 1) break;
			}
			if (count == 0) {
				node* temp = new node;
				temp->data = x;
				temp->next = lst.head;
				lst.head = temp;
			}
		}
		else {
			int count = 0;
			for (int i = 2; i < current->data; i++) {
				if (current->data % i == 0) count++;
				if (count >= 1) break;
			}
			if (count == 0) {
				node* prev = lst.head;
				while (prev->next != current)
					prev = prev->next;
				node* temp = new node;
				temp->data = x;
				prev->next = temp;
				temp->next = current;
			}
		}
	}
}

void save(linkedList lst)
{
	FILE* file = fopen("Exercise1.txt", "w");
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

void save2(linkedList lst)
{
	FILE* file = fopen("Exercise2.txt", "w");
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