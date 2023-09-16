#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::ifstream f1("f1.txt");
	std::ifstream f2("f2.txt");
	if (f1.fail() || f2.fail())
		std::cout << "Error while opening file." << std::endl;
	else {
		std::string s1, s2;
		while (!f1.eof() && !f2.eof()) {
			getline(f1, s1, '\n');
			getline(f2, s2, '\n');
			if (s1.compare(s2) != 0) {
				std::cout << "< " << s1 << std::endl;
				std::cout << "> " << s2 << std::endl;
			}
		}
	}
	f1.close(); f2.close();
	return 0;
}