#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

struct node {
	float chem, phys, math;
	char name[51];
	node* next;
};

struct Manager {
	node* head;
};

std::string lowercase(const std::string& in)
{
	std::string out;
	std::transform(in.begin(), in.end(), std::back_inserter(out), ::tolower);
	return out;
}

void search(Manager lst) {
	int option;
	std::string Name, temp;
	float Score;
	std::cout << "\nSearch by (1)name, (2)math score, (3)physics score, (4)chemistry score: ";
	std::cin >> option;
	if (option == 1) {
		std::cin.ignore(1);
		std::cout << "Input student's name to search: ";
		getline(std::cin, Name);
		Name = lowercase(Name);
	}
	else {
		std::cout << "Input score to search: ";
		std::cin >> Score;
		std::cin.ignore(1);
	}
	for (node* current = lst.head; current != NULL; current = current->next) {
		temp = lowercase(std::string(current->name));
		if ((option == 1 && Name.compare(temp) == 0) || (option == 2 && Score == current->math) ||
			(option == 3 && Score == current->phys) || (option == 4 && Score == current->chem))
			std::cout << current->name << "\t\t" << current->math << '\t' << current->phys << "\t" << current->chem << "\t" << std::endl;
	}
}

float averageScore(node* student) { return (student->math + student->phys + student->chem) / 3; }

void deleteByName(Manager& lst) {
	std::string Name, temp;
	std::cout << "\nInput student's name to delete: ";
	getline(std::cin, Name);
	Name = lowercase(Name);
	bool first = true;
	for (node* current = lst.head; current != NULL; current = current->next) {
		temp = lowercase(std::string(current->name));
		if (Name.compare(temp) == 0) {
			if (first == true) {
				first = false;
				continue;
			}
			else {
				node* temp = lst.head;
				while (temp->next != current) temp = temp->next;
				temp->next = current->next;
				current = temp;
			}
		}
	}
}

void deleteByIndex(Manager& lst) {
	int pos, i = 0;
	std::cout << "\nInput index to delete: ";
	std::cin >> pos;
	std::cin.ignore(1);
	for (node* current = lst.head; current != NULL; current = current->next) {
		if (i == pos) {
			if (current == lst.head) {
				lst.head = current->next;
				break;
			}
			node* temp = lst.head;
			while (temp->next != current) temp = temp->next;
			temp->next = current->next;
			current = temp;
			break;
		}
		i++;
	}
}

node* studentInfo() {
	node* student = new node;
	std::string Name;
	std::cout << "\nInput student name: ";
	getline(std::cin, Name);
	strncpy(student->name, Name.c_str(), Name.length());
	student->name[Name.length()] = '\0';
	std::cout << "Input math score: ";
	std::cin >> student->math;
	std::cout << "Input physics score: ";
	std::cin >> student->phys;
	std::cout << "Input chemistry score: ";
	std::cin >> student->chem;
	std::cin.ignore(1);
	return student;
}

void insertStudentEnd(Manager& lst) {
	node* student = studentInfo();
	node* current = lst.head;
	while (current->next != NULL) current = current->next;
	current->next = student;
	student->next = NULL;
}

void insertStudentHead(Manager& lst) {
	node* student = studentInfo();
	student->next = lst.head;
	lst.head = student;
}

void insertStudentAfterHead(Manager& lst) {
	node* student = studentInfo();
	node* current = lst.head->next;
	student->next = current;
	lst.head->next = student;
}

void insertStudentAfterName(Manager& lst) {
	std::string Name, temp;
	node* student = studentInfo();
	std::cout << "Student's name to insert after: ";
	getline(std::cin, Name);
	Name = lowercase(Name);
	for (node* current = lst.head; current != NULL; current = current->next) {
		temp = lowercase(std::string(current->name));
		if (Name.compare(temp) == 0) {
			student->next = current->next;
			current->next = student;
			break;
		}
	}
}

void TopStudents(Manager lst, int k) {
	std::cout << "\nTop " << k << " students:\n";
	std::vector<std::pair<std::string, float>> vec;
	for (node* current = lst.head; current != NULL; current = current->next) 
		vec.push_back(std::pair<std::string, float>(std::string(current->name), averageScore(current)));

	std::sort(vec.begin(), vec.end(), [](auto& left, auto& right) {
		return left.second > right.second;
		});

	int j = 0;
	for (int i = 0; i < k; i++) {
		for (node* current = lst.head; current != NULL; current = current->next) {
			if (vec[j].first.compare(std::string(current->name)) == 0) {
				std::cout << current->name << "\t\t" << current->math << '\t' << current->phys << "\t" << current->chem << std::endl;
				j++;
				break;
			}
		}
	}
}

void display(Manager lst)
{
	std::cout << std::endl;
	for (node* current = lst.head; current != NULL; current = current->next) 
		std::cout << current->name << "\t\t" << current->math << '\t' << current->phys << "\t" << current->chem << std::endl;
	std::cout << std::endl;
}

void readFile(Manager& lst) {
	std::ifstream file("StudentList.bin", std::ios::in, std::ios::binary);
	if (file.fail()) {
		std::cout << "Fail to open file" << std::endl;
		return;
	}
	file.seekg(0, std::ios::end);
	int size = file.tellg();
	file.seekg(0, std::ios::beg);
	while (file.tellg() != size) {
		node* student = new node;
		file.read(student->name, 50);
		file.read(reinterpret_cast<char*>(&student->math), 4);
		file.read(reinterpret_cast<char*>(&student->phys), 4);
		file.read(reinterpret_cast<char*>(&student->chem), 4);
		if (lst.head == NULL) {
			student->next = NULL;
			lst.head = student;
		}
		else {
			node* current = lst.head;
			while (current->next != NULL) current = current->next;
			student->next = NULL;
			current->next = student;
		}
	}
	file.close();
}

void writeFile(Manager lst) {
	std::ofstream file("StudentList.bin", std::ios::out, std::ios::binary);
	if (file.fail()) {
		std::cout << "Fail to open file" << std::endl;
		return;
	}
	for (node* current = lst.head; current != NULL; current = current->next) {
		file.write(current->name, 50);
		file.write(reinterpret_cast<const char*>(&current->math), 4);
		file.write(reinterpret_cast<const char*>(&current->phys), 4);
		file.write(reinterpret_cast<const char*>(&current->chem), 4);
	}
	file.close();
}

int main() {
	Manager StudentList;
	StudentList.head = NULL;
	insertStudentHead(StudentList);
	insertStudentEnd(StudentList);
	insertStudentEnd(StudentList);
	insertStudentEnd(StudentList);
	insertStudentEnd(StudentList);

	insertStudentAfterHead(StudentList);
	insertStudentHead(StudentList);

	display(StudentList);

	search(StudentList);
	search(StudentList);
	search(StudentList);

	insertStudentAfterName(StudentList);
	insertStudentAfterName(StudentList);
	insertStudentAfterName(StudentList);

	display(StudentList);

	TopStudents(StudentList, 3);

	deleteByIndex(StudentList);
	deleteByIndex(StudentList);

	display(StudentList);

	deleteByName(StudentList);
	deleteByName(StudentList);

	display(StudentList);

	writeFile(StudentList);
	StudentList.head = NULL;
	readFile(StudentList);

	display(StudentList);

	return 0;
}