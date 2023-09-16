#include "Function.h"

int main()
{
	char* s1, * s2;
	doublyLinkedList myList1, myList2;
	load(s1, s2);
	sum2Lists(myList1, myList2, s1, s2);
	save(myList1, myList2, s1, s2);
	return 0;
}