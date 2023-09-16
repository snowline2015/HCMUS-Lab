#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

struct stack {
	int* data;
	int top;
	int size;
};

void conversion(stack& s, unsigned long num);
void push(stack& s, int x);
void pop(stack& s);
#endif
