#include <iostream>
#include <math.h>

class NGUOI {
protected:
	std::string hoTen, ngaySinh, diaChi;
public:
	NGUOI() {
		hoTen = "";
		ngaySinh = "";
		diaChi = "";
	}
	NGUOI(std::string a, std::string b, std::string c) {
		hoTen = a;
		ngaySinh = b;
		diaChi = c;
	}
	~NGUOI() {
		hoTen = "";
		ngaySinh = "";
		diaChi = "";
	}
	void show() { 
		std::cout << "Name : " << hoTen << std::endl
			<< "Day of Birth : " << ngaySinh << std::endl
			<< "Address : " << diaChi << std::endl;
	}
	void input() {
		std::cout << "Input name : ";
		std::cin >> this->hoTen;
		std::cout << "Input day of birth : ";
		std::cin >> this->ngaySinh;
		std::cout << "Input address : ";
		std::cin >> this->diaChi;
	}
};

class NV : NGUOI {
private:
	std::string phongBan;
	int luong, phuCap;
public:
	NV() {
		hoTen = "";
		ngaySinh = "";
		diaChi = "";
		phongBan = "";
		luong = phuCap = 0;
	}
	NV(std::string a, std::string b, std::string c, std::string d, int e, int f) {
		hoTen = a;
		ngaySinh = b;
		diaChi = c;
		phongBan = d;
		luong = e;
		phuCap = f;
	}
	~NV() {
		hoTen = "";
		ngaySinh = "";
		diaChi = "";
		phongBan = "";
		luong = phuCap = 0;
	}
	void showNV() {
		std::cout << "Name: " << hoTen << std::endl
			<< "Day of Birth: " << ngaySinh << std::endl
			<< "Address: " << diaChi << std::endl
			<< "Department: " << phongBan << std::endl
			<< "Salary: " << luong << std::endl
			<< "Pension: " << phuCap << std::endl;
	}
	void input() {
		std::cout << "Input name : ";
		std::cin >> this->hoTen;
		std::cout << "Input day of birth : ";
		std::cin >> this->ngaySinh;
		std::cout << "Input address : ";
		std::cin >> this->diaChi;
		std::cout << "Input department : ";
		std::cin >> this->phongBan;
		std::cout << "Input salary : ";
		std::cin >> this->luong;
		std::cout << "Input pension : ";
		std::cin >> this->phuCap;
	}
};

void main() {
	int n;
	std::cout << "Input number of employee: ";
	std::cin >> n;
	NV* employee = new NV[n];
	for (int i = 0; i < n; i++) {
		std::cout << "\nInput information for employee " << i + 1 << ": " << std::endl;
		employee[i].input();
	}
	for (int i = 0; i < n; i++) {
		std::cout << "\nEmployee 1: " << std::endl;
		employee[i].showNV();
	}
	delete[] employee;
}