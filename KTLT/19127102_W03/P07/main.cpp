#include "Function.h"

int main()
{
	int n;
	char* a, * b;
	loadAnswers(a, b, n);
	int ans = calculateCorrectAnswer(a, b, n);
	if (ans == 1) std::cout << "Student passed the exam" << std::endl;
	else std::cout << "Student failed the exam" << std::endl;
	return 0;
}