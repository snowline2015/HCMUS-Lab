#include <iostream>
#include <string>
#include <fstream>
#include <math.h>

int main() {
	std::ifstream file("input.txt");
	if (file.fail()) {
		std::cout << "Cannot open file !" << std::endl;
		return 0;
	}

	int dec = 0;
	std::string str;
	std::getline(file, str);

	std::cout << "File input.txt store a string: " << str << std::endl;
	if ((int)str[0] == 48) 
		std::cout << "Output: ";
	else {
		std::cout << "Output: -";
		for (int i = 0; i < str.length(); i++) {
			if ((int)str[i] == 49) str[i] = '0';
			else str[i] = '1';
		}
		for (int i = str.length() - 1; i >= 0; i--) {
			if ((int)str[i] == 49) str[i] = '0';
			else {
				str[i] = '1';
				break;
			}
		}
	}
	
	for (int i = 0; i < str.length(); i++) 
		dec += ((int)str[i] - 48) * pow(2, 15 - i);
	std::cout << dec;

	return 0;
}