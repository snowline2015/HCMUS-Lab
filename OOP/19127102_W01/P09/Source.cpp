#include <iostream>

char* ptr(char* pc) {
	return pc;
}

float* ptr1(int* pi) {
	return (float*) pi;
}

void OddorEven(int* pi) {
	if (*pi % 2 == 0)
		std::cout << "Number is even" << std::endl;
	else std::cout << "Number is odd" << std::endl;
}

void action1() {
	std::cout << "Catfish" << std::endl;
}

void action2() {
	std::cout << "chrisname" << std::endl;
}

void action3() {
	std::cout << "devonrevenge" << std::endl;
}

int main()
{
	char* ex1;
	char** ex2 = &ex1;
	char* ex3[10];
	char* ex4 = new char[30];
	char ch[500];
	char* ex5[10] = { new char[500] };
	int const* ex6;
	const int* ex7; 

	int option;
	static void(* dispatch[]) (void) = {action1, action2, action3};
	std::cout << "1. Catfish\n2. chrisname\n3. devonrevenge\n"
		<< "Choose your option : ";
	std::cin >> option;
	(*dispatch[option - 1]) ();
	return 0;
}
