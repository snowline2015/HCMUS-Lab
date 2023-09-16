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
void load(linkedList& lst1, linkedList& lst2, int& count1, int& count2);
void _2ListsTo1Lists(linkedList& lst1, linkedList& lst2, int count1, int count2);
void save(linkedList lst1, linkedList lst2, int count1, int count2);


#endif
