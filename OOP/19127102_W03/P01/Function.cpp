#include "Function.h"

LinkedList::LinkedList(void) {
	pHead = NULL;
	pTail = NULL;
}

LinkedList::~LinkedList(void) {
	Node* current = pHead;
	while (current != NULL) {
		Node* next = current->pNext;
		delete current;
		current = next;
	}
	pHead = NULL;
}

Node* LinkedList::CreateNode(const int& n)
{
	Node* p = new Node;
	p->info = n;
	p->pNext = NULL;
	return p;
}

Node* LinkedList::AddHead(const int& n)
{
	Node* p = new Node;
	p->info = n;
	p->pNext = pHead;
	pHead = p;
	return pHead;
}

Node* LinkedList::AddTail(const int& n) {
	Node* p = CreateNode(n),
		* curr = pHead;
	while (curr->pNext != NULL)
		curr = curr->pNext;
	curr->pNext = p; 
	return curr;
}

Node* LinkedList::RemoveHead() {
	Node* p = pHead;
	pHead = pHead->pNext;
	delete p;
	return pHead;
}

Node* LinkedList::RemoveTail() {
	Node* pDel = NULL,
		* curr = pHead;
	while (curr->pNext != NULL) {
		pDel = curr;
		curr = curr->pNext;
	}
	pDel->pNext = NULL;
	delete curr;
	return pDel;
}

std::ostream& operator<<(std::ostream& os, const LinkedList& ll) {
	Node* curr = ll.pHead;
	while (curr != NULL) {
		os << curr->info << ", ";
		curr = curr->pNext;
	}
	return os;
}

int& LinkedList::operator[](const int& i) {
	int count = 0, temp;
	Node* curr = pHead;
	if (i < 0) temp = 0;
	else temp = i;
	while (count != temp) {
		if (curr->pNext == NULL) 
			return curr->info;
		count++;
		curr = curr->pNext;
	}
	return curr->info;
}