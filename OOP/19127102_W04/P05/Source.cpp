#include <iostream>

class NhanVien {
public:
	std::string name, address;
	NhanVien() {};
	virtual int getCompleted() = 0;
	virtual std::string getCertificate() = 0;
	virtual bool getType() = 0;
};

class CongTy {
	struct node {
		std::string Name, Address, Certification;
		int N;
		bool Type;
		node* next;
	};
protected:
	node* head;
	NhanVien* nv;
public:
	CongTy() { head = NULL; }
	void ThemNhanVien(NhanVien* a) {
		if (head != NULL) {
			node* current = this->head;
			while (current->next != NULL) current = current->next;
			current->next = new node;
			current = current->next;
			current->Name = a->name;
			current->Address = a->address;
			current->Certification = a->getCertificate();
			current->N = a->getCompleted();
			current->Type = a->getType();
			current->next = NULL;
		}
		else {
			node* temp = new node;
			temp->Name = a->name;
			temp->Address = a->address;
			temp->Certification = a->getCertificate();
			temp->N = a->getCompleted();
			temp->Type = a->getType();
			temp->next = NULL;
			head = temp;
		}
	}
	void DanhSachNV(std::ostream& stream) {
		node* current = head;
		while (current != NULL) {
			stream << current->Name << " (" << current->Address << ") ";
			if (current->Type == false) {
				stream << "[NN: " << current->Certification << "], bao cao hoan thanh: " << current->N << std::endl;
			}
			else {
				stream << "[Nganh: " << current->Certification << "], sang tao: " << current->N << std::endl;
			}
			current = current->next;
		}
	}
	void DanhSachNVXuatSac(std::ostream& stream) {
		node* current = head;
		while (current != NULL) {
			if (current->Type == false && current->N >= 12) {
				stream << current->Name << " (" << current->Address << ") "
					<< "[NN: " << current->Certification << "], bao cao hoan thanh: " << current->N << std::endl;
			}
			if (current->Type == true && current->N >= 6) {
				stream << current->Name << " (" << current->Address << ") "
					<< "[Nganh: " << current->Certification << "], sang tao: " << current->N << std::endl;
			}
			current = current->next;
		}
	}
};

class NhanVienThuKy : public NhanVien {
protected:
	std::string certification;
	int completed;
	bool type;
public:
	NhanVienThuKy() {
		name = "";
		address = "";
		certification = "";
		completed = 0;
		type = false;
	}
	NhanVienThuKy(std::string a, std::string b, std::string c, int d) {
		name = a;
		address = b;
		certification = c;
		completed = d;
		type = false;
	}
	int getCompleted() { return this->completed; }
	std::string getCertificate() { return this->certification; }
	bool getType() { return this->type; }
};

class NhanVienKyThuat : public NhanVien {
protected:
	std::string certification;
	int completed;
	bool type;
public:
	NhanVienKyThuat() {
		name = "";
		address = "";
		certification = "";
		completed = 0;
		type = true;
	}
	NhanVienKyThuat(std::string a, std::string b, std::string c, int d) {
		name = a;
		address = b;
		certification = c;
		completed = d;
		type = true;
	}
	int getCompleted() { return this->completed; }
	std::string getCertificate() { return this->certification; }
	bool getType() { return this->type; }
};

void main()
{
	CongTy cty;
	cty.ThemNhanVien(new NhanVienThuKy("Nguyen Thi A", "Tp Ho Chi Minh", "Toefl iBT 100", 15));
	cty.ThemNhanVien(new NhanVienKyThuat("Tran Van B", "Tp Ho Chi Minh", "CNTT", 8));
	cty.ThemNhanVien(new NhanVienThuKy("Le Nguyen Z", "Tp Ha Noi", "TOEIC 700", 10));
	cty.ThemNhanVien(new NhanVienKyThuat("Do Lan T", "Binh Duong", "Hoa thuc pham", 4));
	cty.ThemNhanVien(new NhanVienKyThuat("Hoang Van D", "Khanh Hoa", "Dien tu", 10));
	cty.ThemNhanVien(new NhanVienThuKy("Ngo E", "Tp Ha Noi", "IELTS 7.0", 12));
	std::cout << "DS Nhan vien trong cong ty:" << std::endl;
	cty.DanhSachNV(std::cout);
	std::cout << std::endl << "DS Nhan vien xuat sac:" << std::endl;
	cty.DanhSachNVXuatSac(std::cout);
	std::cout << std::endl << std::endl;
}