#include <iostream>
#include <fstream>
#include <string>

void finfichero(int n, std::string dir) {
	std::string lastLine;
	std::ifstream fp(dir);
	if (fp.fail())
		std::cout << "Error while opening file." << std::endl;
	else {
		int count = 1;
		char ch;
		while (!fp.eof()) {
			fp.get(ch);
			if (ch == '\n') count++;
		}
		fp.clear();
		fp.seekg(0, std::ios::beg);
		int i = 0;
		while (!fp.eof()) {
			getline(fp, lastLine);
			if (i == count - n)
				std::cout << lastLine << std::endl;
			else i++;
		}
	}
}

int main() {
	int n;
	std::string fileName = "input.txt";
	std::cout << "Input the last lines to print on the screen : ";
	std::cin >> n;
	finfichero(n, fileName);
	return 0;
}