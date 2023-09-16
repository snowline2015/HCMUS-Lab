#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
template <typename T>
class Mang
{
public:
	Mang() { data = new T[n]; };
	Mang(T* data, int n) {
		this->data = data;
		this->n = n;
	};
	~Mang() { n = 0; delete[] data; };
	void sort() {
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (data[i] > data[j]) {
					T temp;
					temp = data[i];
					data[i] = data[j];
					data[j] = temp;
				}
			}
		}
	};
	int timkiem(const T& key) const {
		for (int i = 0; i < n; i++) {
			
			if (data[i].compare(key) == 0 || data[i] == key) {
				return i + 1;
			}
		}
		return -1;
	};
	void ghifile(const char* tenfile) {
		std::ofstream file(tenfile);
		file << this->n << "\n";
		for (int i = 0; i < n; i++) {
			file << data[i] << "\n";
		}
		file.close();
	};
	void docfile(const char* tenfile) {
		std::ifstream file(tenfile);
		if (!file) {
			std::cout << "Khong the mo file." << std::endl;
			return;
		}
		file >> this->n;
		this->data = new T[this->n];
		for (int i = 0; i < n; i++) {
			file >> data[i];
		}
		file.close();
	};
	int timmax()const {
		if (this->ktRong()) return -1;
		int pos = 0;
		for (int i = 0; i < n; i++) {
			if (i != pos && data[pos] < data[i]) pos = i;
		}
		return pos;
	};
	int timmin()const {
		if (this->ktRong()) return -1;
		int pos = 0;
		for (int i = 0; i < n; i++) {
			if (i != pos && data[pos] > data[i]) pos = i;
		}
		return pos;
	};
	void xuat()const {
		for (int i = 0; i < n; i++) {
			std::cout << data[i] << std::endl;
		}
	};
	void nhap() {
		std::cout << "Nhap so phan tu: ";
		std::cin >> n;
		data = new T[n];
		for (int i = 0; i < n; i++) {
			std::cout << "Phan tu " << i + 1 << ": ";
			std::cin >> data[i];
		}
	};
	bool ktRong()const {
		if (this->n < 1) return true;
		else return false;
	}
private:
	T* data;
	int n;
};

class Hocsinh
{
public:
	Hocsinh() {
		this->hoten[0] = '\0';
		this->tuoi = this->dtb = 0;
	}
	Hocsinh(char hoten1[], int tuoi, float dtb)
	{
		strcpy(this->hoten, hoten1);
		this->tuoi = tuoi;
		this->dtb = dtb;
	}
	friend ostream& operator << (ostream& os, Hocsinh& r) {
		os << "Ho ten: " << r.hoten << "\nTuoi: " << r.tuoi << "\nDiem trung binh: " << r.dtb << "\n";
		return os;
	};
	friend istream& operator >> (istream& is, Hocsinh& r) {
		std::cin.ignore(1);
		std::cout << "\nHo ten: ";
		std::cin.getline(r.hoten, 56);
		std::cout << "Tuoi: "; is >> r.tuoi;
		std::cout << "Diem trung binh: "; is >> r.dtb;
		return is;
	};
	bool operator > (Hocsinh& r) {
		if (this->dtb > r.dtb) return true;
		return false;
	};
	bool operator < (const Hocsinh& r) {
		if (this->dtb < r.dtb) return true;
		return false;
	};
	friend void sapxep(Hocsinh a[], int n) {
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (a[i].hoten[0] > a[j].hoten[0]) {
					Hocsinh temp;
					temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
		}
	};
private:
	char hoten[55];
	int tuoi;
	float dtb;
}; 

int main()
{
	int a1[] = { 10, 2, 13, 24 };
	string s1[] = { "Kim Tan", "Bi Rain", "Le Roi", "Tran Trang" };
	int n1 = 4;
	Mang<int> mi;
	Mang<string> ms;
	Mang<Hocsinh> mhs;
	mhs.nhap();
	mi.nhap();
	ms.nhap();
	mhs.ghifile("hocsinh.txt");
	mhs.sort();
	ms.sort();
	mi.sort();
	ms.xuat();
	mi.xuat();
	mhs.xuat();
	int kq = ms.timkiem(string("Teo"));
	if (kq >= 0)
		cout << "Tim thay Teo o vi tri " << kq << endl;
	else
		cout << "Khong tim thay Teo" << endl;
	return 0;
}