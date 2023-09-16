#include "Function.h"

int main()
{
	linkedList myList;
	int count, sum;
	load(myList, count);
	computeListIntoNumber(myList, count, sum);
	save(myList, sum);
	return 0;
}