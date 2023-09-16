#include "Function.h"

void input(int& monkeys, int**& ptr)
{
	std::cout << "Input the number of monkeys : ";
	std::cin >> monkeys;
	ptr = new int*[monkeys];
	for (int i = 0; i < monkeys; i++) {
		ptr[i] = new int[7];
	}
	for (int i = 0; i < monkeys; i++) {
		for (int j = 0; j < 7; j++) {
			std::cin >> ptr[i][j];
		}
	}
}

void averageAmountOfFoodEatenPerDay(int monkeys, int** ptr, double& average)
{
	average = 0;
	for (int i = 0; i < monkeys; i++) {

		for (int j = 0; j < 7; j++) {
			average += ptr[i][j];
		}
	}
	average = average / (monkeys * 7);
}

void leastAndGreatestAmountOfFoodEatenAWeekByAMonkey(int monkeys, int** ptr, int *&ptr1, int &least, int &greatest)
{
	ptr1 = new int[monkeys];
	for (int i = 0; i < monkeys; i++) {
		int sum = 0;
		for (int j = 0; j < 7; j++) {
			sum += ptr[i][j];
		}
		ptr1[i] = sum;
	}
	least = ptr1[0];
	greatest = ptr1[0];
	for (int i = 1; i < monkeys; i++) {
		if (ptr1[i] < least) least = ptr1[i];
		if (ptr1[i] > greatest) greatest = ptr1[i];
	}
	delete[] ptr, ptr1;
}

