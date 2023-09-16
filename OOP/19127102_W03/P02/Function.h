#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#include <iostream>

struct node
{
	int data;
	node* next;
};
class SoNguyenLon
{
private:
	node* head;
public:
	SoNguyenLon() {
		node* p = CreateNode(0);
		head = p;
		head->next = NULL;
	}
	SoNguyenLon(const int& a) {
		head = NULL;
		int temp = a;
		while (temp >= 1) {
			AddHead(temp % 10);
			temp /= 10;
		}
	}
	SoNguyenLon(const int& a, const int& b) {
		AddHead(a);
		node* current = head;
		for (int i = 1; i < b; i++) {
			current->next = CreateNode(a);
			current = current->next;
		}
	}
	friend SoNguyenLon Destructor(SoNguyenLon& a) {
		node* current = a.head;
		while (current != NULL) {
			node* next = current->next;
			delete current;
			current = next;
		}
		a.head = NULL;
		return a;
	}
	static node* CreateNode(const int& n);
	node* AddHead(const int& n);
	node* AddTail(const int& n);
	//node* RemoveHead();
	//node* RemoveTail();
	int getLength(const SoNguyenLon& a) {
		int count = 0;
		node* current = a.head;
		while (current != NULL) {
			count++;
			current = current->next;
		}
		return count;
	}
	friend SoNguyenLon operator - (const int& a, const SoNguyenLon& b) {
		SoNguyenLon temp(a);
		return operator - (temp, b);
	}
	friend SoNguyenLon operator - (const SoNguyenLon& a, const int& b) {
		SoNguyenLon temp(b);
		return operator - (a, temp);
	}
	friend SoNguyenLon operator + (const SoNguyenLon& a, const int& b) {
		SoNguyenLon temp(b);
		return operator + (a, temp);
	}
	friend SoNguyenLon operator + (const int& a, const SoNguyenLon& b) {
		SoNguyenLon temp(a);
		return operator + (b, temp);
	}
	friend SoNguyenLon operator - (const SoNguyenLon& a, const SoNguyenLon& b);
	friend SoNguyenLon operator + (const SoNguyenLon& a, const SoNguyenLon& b);
	friend SoNguyenLon operator * (const SoNguyenLon& a, const SoNguyenLon& b);
	friend std::ostream& operator<<(std::ostream& os, const SoNguyenLon& lst);
};

#endif

