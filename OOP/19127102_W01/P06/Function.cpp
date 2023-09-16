#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::ifstream f1("f1.txt");
	std::ifstream f2("f2.txt");
	std::ofstream f3("f3.txt");
	if (f1.fail() || f2.fail())
		std::cout << "Error while opening file." << std::endl;
	else {
		std::string s1, s2, s3;
		int a, b;
		while (!f1.eof()) {
			getline(f1, s1);
			while (!f2.eof()) {
				getline(f2, s2);
				a = s1.find(':');
				b = s2.find(':');
				if (s1.substr(0, a).compare(s2.substr(0, b)) == 0) {
					s3 = s1.append(s2.substr(b, s2.length()));
					f3 << s3 << "\n";
					break;
				}
			}
			f2.clear();
			f2.seekg(0, std::ios::beg);
		}
	}
	f1.close(); f2.close();
	return 0;
}