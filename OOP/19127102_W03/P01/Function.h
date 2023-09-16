#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#include <iostream>

struct Node
{
	int info;
	Node* pNext;
};
class LinkedList
{
private:
	Node* pHead, * pTail;
	int curN;
public:
	LinkedList(void);
	~LinkedList(void);
	static Node* CreateNode(const int& n);
	Node* AddHead(const int& n);
	Node* AddTail(const int& n);
	Node* RemoveHead();
	Node* RemoveTail();
	friend std::ostream& operator<<(std::ostream& os, const LinkedList& ll);
	int& operator[](const int& i);
};

#endif
