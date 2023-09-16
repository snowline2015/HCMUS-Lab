#include "Function.h"

int main()
{
	linkedList myList;
	int number;
	load(number);
	numberToList(myList, number);
	save(myList);
	return 0;
}