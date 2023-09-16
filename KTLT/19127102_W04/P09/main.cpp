#include "Function.h"

int main()
{
	linkedList my1stList, my2ndList;
	load(my1stList, my2ndList);
	join2Lists(my1stList, my2ndList);
	save(my1stList);
	return 0;
}