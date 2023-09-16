#include "Function.h"

int main()
{
	linkedList my1stList, my2ndList;
	int _1stListNodes, _2ndListNodes;
	load(my1stList, my2ndList, _1stListNodes, _2ndListNodes);
	_2ListsTo1Lists(my1stList, my2ndList, _1stListNodes, _2ndListNodes);
	save(my1stList, my2ndList, _1stListNodes, _2ndListNodes);
	return 0;
}