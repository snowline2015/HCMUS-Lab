#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include <math.h>

struct node {
	int data;
	char* number;
	node* next, * prev;
};

struct doublyLinkedList {
	node* head;
};
void load(char*& s1, char*& s2);
void sum2Lists(doublyLinkedList& lst1, doublyLinkedList& lst2, char* s1, char* s2);
void save(doublyLinkedList lst1, doublyLinkedList lst2, char* s1, char* s2);

#endif

