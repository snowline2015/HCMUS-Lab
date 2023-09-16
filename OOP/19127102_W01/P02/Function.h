#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>

struct node {
    std::string s;
    node* next;
};

struct Word {
    node* head;
};

void loadFile(Word& lst);
void displayFileContent(Word lst);
int countDistinctWords(Word lst);


#endif
