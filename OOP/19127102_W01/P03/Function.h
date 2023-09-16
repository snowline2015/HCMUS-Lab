#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>

struct Temperature {
	double* data;
};

void loadFile(Temperature& temper, int& day);
void saveFile(Temperature temper, int day);


#endif
