#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>

void input(int& monkeys, int** &ptr);
void averageAmountOfFoodEatenPerDay(int monkeys, int** ptr, double& average);
void leastAndGreatestAmountOfFoodEatenAWeekByAMonkey(int monkeys, int** ptr, int*& ptr1, int& least, int& greatest);

#endif
