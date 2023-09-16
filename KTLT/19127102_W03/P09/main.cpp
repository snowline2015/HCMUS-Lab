#include "Function.h"
/*
Test case :
5
11 12 13 14 15 16 17
1 2 3 4 5 6 7
21 22 23 24 25 26 27
37 36 35 34 33 32 31
97 96 95 94 93 92 91
*/
int main()
{
	int monkeys;
	double average;
	int** ptr, * ptr1;
	int least, greatest;
	input(monkeys, ptr);
	averageAmountOfFoodEatenPerDay(monkeys, ptr, average);
	leastAndGreatestAmountOfFoodEatenAWeekByAMonkey(monkeys, ptr, ptr1, least, greatest);
	std::cout << "Average amoung of food eaten per day : " << average << std::endl;
	std::cout << "Least amount of food eaten by a monkey during the week : " << least << std::endl;
	std::cout << "Greatest amount of food eaten by a monkey during the week : " << greatest << std::endl;
	return 0;
}