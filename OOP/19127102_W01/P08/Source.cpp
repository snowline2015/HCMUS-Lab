#include <iostream>
#include <fstream>
#include <string>

struct Student {
	std::string FullName, Address;
	int Age;
};

int main() {
	Student student;
	std::ifstream fp("record.bin", std::ios::binary);
	if (fp.fail())
		std::cout << "Error while opening file." << std::endl;
	else {
		getline(fp, student.FullName);
		fp >> student.Age;
		getline(fp, student.Address);
		getline(fp, student.Address);
		fp.close();
		std::cout << student.FullName << "\n" << student.Age << "\n" << student.Address << std::endl;
	}
	return 0;
}