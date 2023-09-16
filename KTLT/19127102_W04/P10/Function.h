#ifndef _FUNCTION_H_
#define _FUNCTION_H_
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
void load(linkedList& lst, int& count);
void computeListIntoNumber(linkedList lst, int count, int& sum);
void save(linkedList lst, int sum);


#endif

