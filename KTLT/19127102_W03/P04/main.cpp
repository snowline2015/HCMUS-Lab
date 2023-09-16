#include "Function.h"

int main()
{
	int n; 
	int* a, * b;
	inputArray(a, n);
	std::cout << "the value that occurs most often or with the greatest frequency : "
		<< findValueOccursGreatestFrequency(a, b, n) << std::endl;
	return 0;
}