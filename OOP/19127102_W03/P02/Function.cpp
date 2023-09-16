#include "Function.h"

std::ostream& operator<<(std::ostream& os, const SoNguyenLon& lst) {
	node* curr = lst.head;
	while (curr != NULL) {
		os << curr->data;
		curr = curr->next;
	}
	return os;
}

node* SoNguyenLon::CreateNode(const int& n)
{
	node* p = new node;
	p->data = n;
	p->next = NULL;
	return p;
}

node* SoNguyenLon::AddHead(const int& n)
{
	node* p = new node;
	p->data = n;
	p->next = head;
	head = p;
	return head;
}

node* SoNguyenLon::AddTail(const int& n) {
	node* p = CreateNode(n),
		* curr = head;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = p;
	return curr;
}

SoNguyenLon operator + (const SoNguyenLon& a, const SoNguyenLon& b)
{
	static SoNguyenLon temp;
	temp.head = NULL;
	node* current1 = a.head, * current2 = b.head;
	int count = 1, save = 0;
	int temp1 = temp.SoNguyenLon::getLength(a),
		temp2 = temp.SoNguyenLon::getLength(b);
	if (temp1 >= temp2) {
		for (int i = temp.SoNguyenLon::getLength(a); i >= 1; i--) {
			if (temp2 == 0) {
				count = 1; current1 = a.head;
				while (count != temp1) {
					count++;
					current1 = current1->next;
				}
				if (save == 1) {
					if (current1->data < 9) {
						temp.AddHead(current1->data + 1);
						save = 0;
					}
					else {
						temp.AddHead(0);
						save = 0;
					}
				}
				else 
					temp.AddHead(current1->data);
				temp1--;
			}
			else {
				count = 1; current1 = a.head; current2 = b.head;
				while (count != temp1) {
					count++;
					current1 = current1->next;
					if (count <= temp2) current2 = current2->next;
				}
				if (current1->data + current2->data >= 10) {
					if (save == 0)
						temp.AddHead(current1->data + current2->data - 10);
					else
						temp.AddHead(current1->data + current2->data - 9);
					save = 1;
				}
				else {
					if (save == 1) {
						if (current1->data + current2->data + 1 >= 10) {
							temp.AddHead(0);
							save = 1;
						}
						else {
							temp.AddHead(current1->data + current2->data + 1);
							save = 0;
						}
					}
					else {
						temp.AddHead(current1->data + current2->data);
						save = 0;
					}
				}
				temp1--; temp2--;
			}
		}
	}
	else {
		current1 = b.head; current2 = a.head;
		temp2 = temp.SoNguyenLon::getLength(a),
		temp1 = temp.SoNguyenLon::getLength(b);
		for (int i = temp.SoNguyenLon::getLength(b); i >= 1; i--) {
			if (temp2 == 0) {
				count = 1; current1 = b.head;
				while (count != temp1) {
					count++;
					current1 = current1->next;
				}
				if (save == 1) {
					if (current1->data < 9) {
						temp.AddHead(current1->data + 1);
						save = 0;
					}
					else {
						temp.AddHead(0);
						save = 0;
					}
				}
				else
					temp.AddHead(current1->data);
				temp1--;
			}
			else {
				count = 1; current1 = b.head; current2 = a.head;
				while (count != temp1) {
					count++;
					current1 = current1->next;
					if (count <= temp2) current2 = current2->next;
				}
				if (current1->data + current2->data >= 10) {
					if (save == 0)
						temp.AddHead(current1->data + current2->data - 10);
					else
						temp.AddHead(current1->data + current2->data - 9);
					save = 1;
				}
				else {
					if (save == 1) {
						if (current1->data + current2->data + 1 >= 10) {
							temp.AddHead(0);
							save = 1;
						}
						else {
							temp.AddHead(current1->data + current2->data + 1);
							save = 0;
						}
					}
					else {
						temp.AddHead(current1->data + current2->data);
						save = 0;
					}
				}
				temp1--; temp2--;
			}
		}
	}
	return temp;
}

SoNguyenLon operator - (const SoNguyenLon& a, const SoNguyenLon& b)
{
	static SoNguyenLon temp;
	temp.head = NULL;
	node* current1 = a.head, * current2 = b.head;
	int count = 1, save = 0;
	int temp1 = temp.SoNguyenLon::getLength(a),
		temp2 = temp.SoNguyenLon::getLength(b);
	for (int i = temp.SoNguyenLon::getLength(a); i >= 1; i--) {
		if (temp2 == 0) {
			count = 1; current1 = a.head;
			while (count != temp1) {
				count++; 
				current1 = current1->next;
			}
			if (save == 1) {
				if (current1->data == 0) {
					temp.AddHead(9);
					save = 1;
				}
				else {
					temp.AddHead(current1->data - 1);
					save = 0;
				}
			}
			else
				temp.AddHead(current1->data);
			temp1--;
		}
		else {
			count = 1; current1 = a.head; current2 = b.head;
			while (count != temp1) {
				count++;
				current1 = current1->next;
				if (count <= temp2) current2 = current2->next;
			}
			if (current1->data - current2->data < 0) {
				if (save == 0)
					temp.AddHead(10 + current1->data - current2->data);
				else
					temp.AddHead(9 + current1->data - current2->data);
				save = 1;
			}
			else {
				if (save == 1) {
					if (current1->data - current2->data - 1 < 0) {
						temp.AddHead(9);
						save = 1;
					}
					else {
						temp.AddHead(current1->data - current2->data - 1);
						save = 0;
					}
				}
				else {
					temp.AddHead(current1->data - current2->data);
					save = 0;
				}
			}
			temp1--; temp2--;
		}
	}
	return temp;
}

SoNguyenLon operator * (const SoNguyenLon& a, const SoNguyenLon& b)
{
	static SoNguyenLon temp;
	SoNguyenLon calc;
	temp.head = NULL, calc.head = NULL;
	temp.AddHead(0);
	node* current1 = a.head, * current2 = b.head;
	int save = 0;
	int temp1 = temp.SoNguyenLon::getLength(a),
		temp2 = temp.SoNguyenLon::getLength(b);
	for (int i = 0; i < temp.SoNguyenLon::getLength(b); i++) {
		temp1 = temp.SoNguyenLon::getLength(a);
		while(true) {
			int count = 1; current1 = a.head; current2 = b.head;
			if (temp1 == 0) {
				if (save != 0)
					calc.AddHead(save);
				save = 0;
				break;
			}
			while (count != temp1) {
				count++;
				current1 = current1->next;
				if (count <= temp2) current2 = current2->next;
			}
			if (current1->data * current2->data >= 10) {
				if (save != 0) {
					calc.AddHead(((current1->data * current2->data) % 10) + save);
					save = (current1->data * current2->data + save) / 10;
				}
				else {
					calc.AddHead((current1->data * current2->data) % 10);
					save = (current1->data * current2->data) / 10;
				}
			}
			else {
				if (save != 0) {
					if (current1->data * current2->data + save >= 10) {
						calc.AddHead(current1->data * current2->data + save - 10);
						save = 1;
					}
					else {
						calc.AddHead(current1->data * current2->data + save);
						save = 0;
					}
				}
				else {
					calc.AddHead(current1->data * current2->data);
					save = 0;
				}
			}
			temp1--;
		}
		int count1 = 0;
		if (i >= 1) {
			while (count1 != i) {
				count1++;
				calc.AddTail(0);
			}
		}
		temp = calc + temp;
		calc = Destructor(calc);
		temp2--;
	}
	return temp;
}