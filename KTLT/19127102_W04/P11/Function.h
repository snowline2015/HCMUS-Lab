#ifndef _FUNCTION_H_
#define _FUNTION_H_
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <math.h>

struct node {
	int data;
	node* next;
};

struct linkedList {
	node* head;
};

void load(int& x);
void reverseTheList(linkedList& lst);
void numberToList(linkedList& lst, int& x);
void save(linkedList lst);

#endif