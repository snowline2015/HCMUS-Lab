#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

struct node {
	int data;
	node* next;
};
struct stack {
	int size;
	int count;
	node* head;
};
void init(stack& s, int size);
void push(stack& s, int x);
int pop(stack& s);
bool isEmpty(stack s);
void empty(stack& s);
int size(stack& s);
void displayAll(stack s);

#endif



