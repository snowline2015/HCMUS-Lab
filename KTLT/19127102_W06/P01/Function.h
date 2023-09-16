#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

struct stack {
	int* data; 
	int top; 
	int size; 
};
void init(stack& s, int size);
void push(stack& s, int x);
int pop(stack& s);
bool isEmpty(stack s);
void empty(stack& s);
int size(stack& s);
void displayAll(stack s);

#endif


