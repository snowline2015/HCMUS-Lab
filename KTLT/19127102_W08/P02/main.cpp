#include "Function.h"

int main()
{
	linkedList myList;
	load(myList);
	node* curr = myList.head;
	removeDuplicate(myList, curr);
	save(myList);
	return 0;
}