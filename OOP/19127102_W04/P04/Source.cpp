#include <iostream>
#include <math.h>
#include <vector>

class HinhHocPhang {
public:
	HinhHocPhang() {}
	virtual double Area() = 0;
	virtual double Perimeter() = 0;
};

class QuanLyHinhHocPhang {
	struct node {
		double Area, Perimeter;
		node* next;
	};
protected:
	node* head;
public:
	QuanLyHinhHocPhang() {
		head = NULL;
	}
	void AddHinh(HinhHocPhang* a) {
		if (head != NULL) {
			node* current = this->head;
			while (current->next != NULL) current = current->next;
			current->next = new node;
			current = current->next;
			current->Area = a->Area();
			current->Perimeter = a->Perimeter();
			current->next = NULL;
		}
		else {
			node* temp = new node;
			temp->Area = a->Area();
			temp->Perimeter = a->Perimeter();
			temp->next = NULL;
			head = temp;
		}
	}
	double TongDienTich() {
		double sum = 0;
		node* current = head;
		while (current != NULL) {
			sum += current->Area;
			current = current->next;
		}
		return sum;
	}
	double TongChuVi() {
		double sum = 0;
		node* current = head;
		while (current != NULL) {
			sum += current->Perimeter;
			current = current->next;
		}
		return sum;
	}
};

class HinhChuNhat : public HinhHocPhang {
protected:
	double length, width;
public:
	HinhChuNhat() { length = width = 0; }
	HinhChuNhat(double a, double b) {
		length = abs(a);
		width = abs(b);
	}
	double Area() { 
		double area = this->length* this->width;
		return area;
	}
	double Perimeter() { 
		double perimeter = (this->length + this->width) * 2; 
		return perimeter;
	}
};

class HinhTamGiac : public HinhHocPhang {
protected:
	double c1, c2, c3;
public:
	HinhTamGiac() { c1 = c2 = c3 = 0; }
	HinhTamGiac(double a, double b, double c) {
		c1 = abs(a); c2 = abs(b); c3 = abs(c);
	}
	double Area() { 
		double P = (this->c1 + this->c2 + this->c3) / 2;
		double area = sqrt(P * (P - this->c1) * (P - this->c2) * (P - this->c3));
		return area;
	}
	double Perimeter() {
		double perimeter = this->c1 + this->c2 + this->c3;
		return perimeter;
	}
};

class HinhTron : public HinhHocPhang {
protected:
	double rad;
public:
	HinhTron() { rad = 0; }
	HinhTron(double a) { rad = abs(a); }
	double Area() { 
		double area = pow(this->rad, 2) * 3.14; 
		return area;
	}
	double Perimeter() { 
		double perimeter = this->rad * 2 * 3.14; 
		return perimeter;
	}
};

class HinhThangVuong : public HinhHocPhang {
protected:
	double a, b, h;
public:
	HinhThangVuong() { a = b = h = 0; }
	HinhThangVuong(double c1, double c2, double c3) {
		a = abs(c1); b = abs(c2); h = abs(c3);
	}
	double Area() { 
		double area = (this->a + this->b) * h / 2; 
		return area;
	}
	double Perimeter() { 
		double perimeter = this->a + this->b + this->h + sqrt(pow(h, 2) + pow(a - b, 2)); 
		return perimeter;
	}
};

void main()
{
	QuanLyHinhHocPhang ql;
	ql.AddHinh(new HinhChuNhat(5.6, 2.3));
	ql.AddHinh(new HinhTamGiac(-1.5, 6.7, 5.9));
	ql.AddHinh(new HinhTron(12.7));
	ql.AddHinh(new HinhThangVuong(10.1, 8.6, 3.5));
	std::cout << "Tong Dien tich: " << ql.TongDienTich() << std::endl;
	std::cout << "Tong Chu vi: " << ql.TongChuVi() << std::endl;
	std::cout << std::endl << std::endl;
}