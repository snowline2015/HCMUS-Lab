#include <iostream>
#include <string>
#include <algorithm>

std::string lowercase(const std::string& in)
{
	std::string out;
	std::transform(in.begin(), in.end(), std::back_inserter(out), ::tolower);
	return out;
}

class NhanVien {
public:
	std::string name, birthday;
	double BasicSalary;
	virtual void input() = 0;
	virtual double getSalary() = 0;
	virtual int getType() = 0;
};

class CongTy {
	struct node {
		std::string Name, Birthday;
		int Salary;
		int Type;
		node* next;
	};
protected:
	node* head;
public:
	CongTy() { head = NULL; }
	void AddStaff(NhanVien* a) {
		if (head != NULL) {
			node* current = head;
			while (current->next != NULL) current = current->next;
			current->next = new node;
			current = current->next;
			current->Name = a->name;
			current->Birthday = a->birthday;
			current->Salary = a->getSalary();
			current->Type = a->getType();
			current->next = NULL;
		}
		else {
			node* temp = new node;
			temp->Name = a->name;
			temp->Birthday = a->birthday;
			temp->Salary = a->getSalary();
			temp->Type = a->getType();
			temp->next = NULL;
			head = temp;
		}
	}
	double TotalSalary() {
		double total = 0;
		node* current = head;
		while (current != NULL) {
			total += current->Salary;
			current = current->next;
		}
		return total;
	}
	void Find(std::string a) {
		bool check = false;
		node* current = head;
		while (current != NULL) {
			std::string b = lowercase(current->Name);
			if (b.std::string::compare(a) == 0) {
				std::cout << "\nName: " << current->Name << std::endl
					<< "Day of Birth: " << current->Birthday << std::endl
					<< "Salary: " << current->Salary << std::endl;
				check = true;
			}
			if (check == false && current->next == NULL)
				std::cout << "Cannot find staff" << std::endl;
			current = current->next;
		}
	}
	void Output() {
		node* current = head;
		while (current != NULL) {
			if (current->Type == 1) std::cout << "\n*Nhan vien van phong*" << std::endl;
			else if (current->Type == 2) std::cout << "\n*Nhan vien san xuat*" << std::endl;
			else std::cout << "\n*Nhan vien quan ly*" << std::endl;
			std::cout << "Name: " << current->Name << std::endl
				<< "Day of Birth: " << current->Birthday << std::endl
				<< "Salary: " << current->Salary << std::endl;
			current = current->next;
		}
	}
};

class NhanVienVanPhong : public NhanVien {
protected:
	double subsidize, workday;
	int Secretary, Business;
public:
	NhanVienVanPhong() {
		name = "";
		birthday = "";
		BasicSalary = workday = subsidize = 0;
	}
	void input() {
		std::cout << "\n*Nhan vien van phong*" << std::endl
			<< "Input name: ";
		std::getline(std::cin, name);
		std::cout << "Input day of birth: ";
		std::getline(std::cin, birthday);
		std::cout << "Input basic salary: ";
		std::cin >> BasicSalary;
		std::cout << "Input workdays: ";
		std::cin >> workday;
		std::cout << "Input subsidize: ";
		std::cin >> subsidize;
		std::cout << "Secretary ? (1. Yes; 0. No): ";
		std::cin >> Secretary;
		std::cout << "Gone business with boss ? (1. Yes; 0. No): ";
		std::cin >> Business;
		std::cin.ignore(1);
	}
	double getSalary() { 
		double salary = BasicSalary + workday * 100000 + subsidize;
		if (Secretary == 1 && Business == 1) return salary + salary * 10 / 100;
		else return salary;
	}
	int getType() { return 1; }
};

class NhanVienSanXuat : public NhanVien {
protected:
	int product;
public:
	NhanVienSanXuat() {
		name = "";
		birthday = "";
		BasicSalary = product = 0;
	}
	void input() {
		std::cout << "\n*Nhan vien san xuat*" << std::endl
			<< "Input name: ";
		std::getline(std::cin, name);
		std::cout << "Input day of birth: ";
		std::getline(std::cin, birthday);
		std::cout << "Input basic salary: ";
		std::cin >> BasicSalary;
		std::cout << "Input products: ";
		std::cin >> product;
		std::cin.ignore(1);
	}
	double getSalary() { return BasicSalary + product * 2000; }
	int getType() { return 2; }
};

class NhanVienQuanLy : public NhanVien {
protected:
	int position;
	double bonus;
public:
	NhanVienQuanLy() {
		name = "";
		birthday = "";
		position = bonus = 0;
	}
	void input() {
		std::cout << "\n*Nhan vien quan ly*" << std::endl
			<< "Input name: ";
		std::getline(std::cin, name);
		std::cout << "Input day of birth: ";
		std::getline(std::cin, birthday);
		std::cout << "Input basic salary: ";
		std::cin >> BasicSalary;
		std::cout << "Input position coefficient: ";
		std::cin >> position;
		std::cout << "Input bonus: ";
		std::cin >> bonus;
		std::cin.ignore(1);
	}
	double getSalary() { return BasicSalary * position + bonus; }
	int getType() { return 3; }
};

void main()
{
	CongTy manager;
	std::string name;
	NhanVien* a, * b, * c;
	a = new NhanVienVanPhong;
	b = new NhanVienSanXuat;
	c = new NhanVienQuanLy;
	a->input(); manager.AddStaff(a);
	b->input(); manager.AddStaff(b);
	c->input(); manager.AddStaff(c);
	std::cout << "\n*List of staffs*" << std::endl;
	manager.Output();
	std::cout << "\nTotal Salary: " << manager.TotalSalary() << std::endl;
	std::cout << "Input name of staff to find: ";
	std::getline(std::cin, name);
	manager.Find(name);
}