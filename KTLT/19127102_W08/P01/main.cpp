#include "Function.h"

int main()
{
	linkedList myList;
	load(myList);
	node* curr = myList.head;
	int x;
	std::cout << "Enter x to remove : ";
	std::cin >> x;
	removeAllX(myList, curr, x);
	save(myList);
	return 0;
}