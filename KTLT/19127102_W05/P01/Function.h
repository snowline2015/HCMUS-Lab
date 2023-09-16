#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

struct node {
	int data;
	node* next;
};

struct circularLinkedList {
	node* head;
};
void load(circularLinkedList& lst);
void removeDuplicate(circularLinkedList& list);
void save(circularLinkedList lst);

#endif
