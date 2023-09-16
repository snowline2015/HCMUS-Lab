#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>

std::string inputFile() {
	std::ifstream file("input.txt");
	if (!file) {
		std::cout << "Khong the mo file." << std::endl;
		return "";
	}
	std::string ok, temp;
	std::getline(file, ok, '\n');
	while (!file.eof()) {
		std::getline(file, temp, '\n');
		ok = ok.std::string::append("\n").append(temp);
	}
	return ok;
}

int CountWords(std::string a) {
	int CountWords = 0;
	bool check;
	std::vector<char> punc;
	punc.push_back(' ');
	punc.push_back(',');
	punc.push_back('.');
	punc.push_back(';');
	punc.push_back('\n');
	punc.push_back('?');
	punc.push_back('!');
	punc.push_back('"');
	for (int i = 0; i < a.length(); i++) {
		for (std::vector<char>::iterator p = punc.begin(); p != punc.end(); p++) {
			if (a[i] == *p) {
				check = false;
				for (std::vector<char>::iterator j = punc.begin(); j != punc.end(); j++) {
					if (i == 0) break;
					if (a[i - 1] == *j) break;
					else if (j + 1 == punc.end()) check = true;	
				}
				if (check == true) CountWords++;
				break;
			}
		}
	}
	return CountWords;
}

int main() {
	std::cout << inputFile() << std::endl;
	std::cout << "\nNumber of words in document: " << CountWords(inputFile()) << std::endl;
	return 0;
}