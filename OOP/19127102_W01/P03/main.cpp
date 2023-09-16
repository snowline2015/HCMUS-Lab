#include "Function.h"

int main()
{
	Temperature myFile;
	int day;
	loadFile(myFile, day);
	saveFile(myFile, day);
	return 0;
}