#include "Function.h"

int main()
{
	linkedList myList;
	load(myList);
	node* curr1 = NULL,
		* curr2 = myList.head,
		* curr3 = myList.head->next;
	reverseList(myList, curr1, curr2, curr3);
	save(myList);
	return 0;
}