#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

struct node {
    int data;
    node* next;
};
struct linkedList {
    node* head;
};
void load(linkedList& lst);
void reverseList(linkedList& lst, node* current1, node* current2, node* current3);
void save(linkedList lst);


#endif


