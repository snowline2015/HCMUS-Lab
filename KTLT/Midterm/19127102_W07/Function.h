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
void load2(linkedList& lst);
void appearOneTime(linkedList lst, linkedList& lst2);
void insertNodeBeforePrimeNum(linkedList& lst, int x);
void save(linkedList lst);
void save2(linkedList lst);

#endif
