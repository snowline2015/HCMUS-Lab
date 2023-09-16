#include <iostream>
#include <string>

class NhanVien {
public:
	std::string name, id;
	NhanVien() {};
	virtual void input() = 0;
	virtual int getSalary() = 0;
	virtual int getType() = 0;
};

class CongTy {
	struct node {
		std::string Name, ID;
		int Salary;
		int Type;
		node* next;
	};
protected:
	node* head;
public:
	CongTy() { head = NULL; }
	void ThemNhanVien(NhanVien* a) {
		if (head != NULL) {
			node* current = this->head;
			while (current->next != NULL) current = current->next;
			current->next = new node;
			current = current->next;
			current->Name = a->name;
			current->ID = a->id;
			current->Salary = a->getSalary();
			current->Type = a->getType();
			current->next = NULL;
		}
		else {
			node* temp = new node;
			temp->Name = a->name;
			temp->ID = a->id;
			temp->Salary = a->getSalary();
			temp->Type = a->getType();
			temp->next = NULL;
			head = temp;
		}
	}
	int CountEmployee() {
		int count = 0;
		node* current = head;
		while (current != NULL) {
			count++;
			current = current->next;
		}
		return count;
	}
	int CountEmployee3() {
		int count = 0;
		node* current = head;
		while (current != NULL) {
			if (current->Type == 3) count++;
			current = current->next;
		}
		return count;
	}
	void OutputEmployee() {
		node* current = head;
		for (int i = 1; i <= 3; i++) {
			if (i == 1) std::cout << "\n*Nhan Vien San Xuat*" << std::endl;
			else if (i == 2) std::cout << "\n*Nhan Vien Cong Nhat*" << std::endl;
			else std::cout << "\n*Nhan Vien Quan Ly*" << std::endl;
			while (current != NULL) {
				if (current->Type == i)
					std::cout << current->Name << " <" << current->ID << "> Salary: " << current->Salary << std::endl;
				current = current->next;
			}
			current = head;
		}
	}
};

class NhanVienSanXuat : public NhanVien {
protected:
	int product;
public:
	NhanVienSanXuat() {
		name = "";
		id = "";
		product = 0;
	}
	void input() {
		std::cout << "\n*Nhan vien san xuat*" << std::endl
			<< "Input name: ";
		std::getline(std::cin, name);
		std::cout << "Input ID: ";
		std::getline(std::cin, id);
		std::cout << "Input products: ";
		std::cin >> product;
		std::cin.ignore(1);
	}
	int getSalary() { return this->product * 20000; }
	int getType() { return 1; }
};

class NhanVienCongNhat : public NhanVien {
protected:
	int day;
public:
	NhanVienCongNhat() {
		name = "";
		id = "";
		day = 0;
	}
	void input() {
		std::cout << "\n*Nhan vien cong nhat*" << std::endl
			<< "Input name: ";
		std::getline(std::cin, name);
		std::cout << "Input ID: ";
		std::getline(std::cin, id);
		std::cout << "Input workdays: ";
		std::cin >> day;
		std::cin.ignore(1);
	}
	int getSalary() { return this->day * 50000; }
	int getType() { return 2; }
};

class NhanVienQuanLy : public NhanVien {
protected:
	int x, y;
public:
	NhanVienQuanLy() {
		name = "";
		id = "";
		x = y = 0;
	}
	void input() {
		std::cout << "\n*Nhan vien quan ly*" << std::endl
			<< "Input name: ";
		std::getline(std::cin, name);
		std::cout << "Input ID: ";
		std::getline(std::cin, id);
		std::cout << "Input basic salary: ";
		std::cin >> x;
		std::cout << "Input coefficients salary: ";
		std::cin >> y;
		std::cin.ignore(1);
	}
	int getSalary() { return x * y; }
	int getType() { return 3; }
};

void main()
{
	CongTy manager;
	NhanVien* a;
	int menu;
	do {
		std::cout << "\n1. Nhap danh sach cac nhan vien\n2. Them mot nhan vien moi vao cong ty\n"
			<< "3. Xuat danh sach cong ty theo thu tu cap bac\n4. Cho biet cong ty co bao nhieu nhan vien\n"
			<< "5. Cho biet cong ty co bao nhieu nhan vien quan ly\n0. Exit\nInput menu: ";
		std::cin >> menu;
		switch (menu) {
			int n, type;
		case 1: {
			std::cout << "Input number of employees: ";
			std::cin >> n;
			for (int i = 0; i < n; i++) {
				std::cout << "\n1. Nhan Vien San Xuat\n2. Nhan Vien Cong Nhat\n3. Nhan Vien Quan Ly\nInput type: ";
				std::cin >> type;
				std::cin.ignore(1);
				if (type == 1) a = new NhanVienSanXuat;
				else if (type == 2) a = new NhanVienCongNhat;
				else a = new NhanVienQuanLy;
				a->input();
				manager.ThemNhanVien(a);
				delete a;
			}
			break;
		}
		case 2: {
			std::cout << "\n1. Nhan Vien San Xuat\n2. Nhan Vien Cong Nhat\n3. Nhan Vien Quan Ly\nInput type: ";
			std::cin >> type;
			std::cin.ignore(1);
			if (type == 1) a = new NhanVienSanXuat;
			else if (type == 2) a = new NhanVienCongNhat;
			else a = new NhanVienQuanLy;
			a->input();
			manager.ThemNhanVien(a);
			delete a;
			break;
		}
		case 3: {
			manager.OutputEmployee();
			break;
		}
		case 4: {
			std::cout << "\nNumber of Employees: " << manager.CountEmployee() << std::endl;
			break;
		}
		case 5: {
			std::cout << "Number of Management Staffs: " << manager.CountEmployee3() << std::endl;
			break;
		}
		default: break;
		}
	} while (menu != 0);
}