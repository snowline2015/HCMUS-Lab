#include <iostream>
#include <limits.h>

int main() {
	std::cout << "All unsigned types have minimum value of 0" << std::endl
		<< "\nThe maximum value of unsigned char is " << UCHAR_MAX << std::endl
		<< "\nThe maximum value of char is " << CHAR_MAX << std::endl
		<< "The minimum value of char is " << CHAR_MIN << std::endl
		<< "\nThe maximum value of unsigned short is " << USHRT_MAX << std::endl
		<< "\nThe maximum value of short is " << SHRT_MAX << std::endl
		<< "The minimum value of short is " << SHRT_MIN << std::endl
		<< "\nThe maximum value of unsigned int is " << UINT_MAX << std::endl
		<< "\nThe maximum value of int is " << INT_MAX << std::endl
		<< "The minimum value of int is " << INT_MIN << std::endl
		<< "\nThe maximum value of unsigned long is " << ULONG_MAX << std::endl
		<< "\nThe maximum value of long is " << LONG_MAX << std::endl
		<< "The minimum value of long is " << LONG_MIN << std::endl
		<< "\nThe maximum value of float is " << FLT_MAX << std::endl
		<< "The minimum value of float is " << FLT_MIN << std::endl
		<< "\nThe maximum value of double is " << DBL_MAX << std::endl
		<< "The minimum value of double is " << DBL_MIN << std::endl;
	return 0;
}