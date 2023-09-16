#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

struct queue
{
	int* data;
	int in;
	int out;
	int size;
};
void init(queue& s, int size);
void enqueue(queue& s, int x);
int dequeue(queue& s);
bool isEmpty(queue s);
void empty(queue& s);
int size(queue& s);
void displayAll(queue s);

#endif




