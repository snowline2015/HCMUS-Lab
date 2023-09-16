#include <iostream>
#include <fstream>
#include <string>

struct Student {
	std::string FullName, Address;
	int age;
};

int main() {
	Student student;
	student.FullName = "Vo Hoang Gia Bao";
	student.age = 18;
	student.Address = "98/14 Bui Van Ba, Tan Thuan Dong, Quan 7";
	std::ofstream fp("record.bin", std::ios::binary);
	if (fp.fail())
		std::cout << "Error while opening file." << std::endl;
	else {
		fp << student.FullName << "\n" << student.age << "\n" << student.Address;
		fp.close();
	}
	return 0;
}