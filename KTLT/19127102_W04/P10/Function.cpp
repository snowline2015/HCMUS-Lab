#include "Function.h"

void load(linkedList& lst, int& count)
{
	count = 1;
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
			if (current->next->data == -1) {
				current->next = NULL;
				break;
			}
			current = current->next;
			count++;
		}
	}
}

void computeListIntoNumber(linkedList lst, int count, int& sum)
{
	node* current = lst.head;
	sum = 0;
	for (int i = count - 1; i >= 0; i--) {
		sum += current->data * pow(10, i);
		current = current->next;
	}
}


void save(linkedList lst, int sum)
{
	FILE* file = fopen("output.txt", "w");
	if (file == NULL)
		std::cout << "Error while opening file" << std::endl;
	else {
		fprintf(file, "%d", sum);
		fclose(file);
	}
}