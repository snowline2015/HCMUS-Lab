#include <iostream>
#include <string>

struct node {
	std::string ID;
	double Price, Weight;
	node* next;
};

class Detail {
public:
	std::string id;
	virtual void Input() = 0;
	virtual double Weight() = 0;
	virtual double Price() = 0;
};

class Machine {
protected:
	double weight, price;
	node* head;
public:
	Machine() { head = NULL; weight = price = 0; }
	void AddDetail(Detail* a) {
		if (head != NULL) {
			node* current = this->head;
			while (current->next != NULL) current = current->next;
			current->next = new node;
			current = current->next;
			current->ID = a->id;
			current->Weight = a->Weight();
			current->Price = a->Price();
			current->next = NULL;
		}
		else {
			node* temp = new node;
			temp->ID = a->id;
			temp->Weight = a->Weight();
			temp->Price = a->Price();
			temp->next = NULL;
			head = temp;
		}
	}
	void Total() {
		node* current = head;
		while (current != NULL) {
			weight += current->Weight;
			price += current->Price;
			current = current->next;
		}
	}
	void Find(std::string a) {
		node* current = head;
		while (current != NULL) {
			if (current->ID.std::string::compare(a) == 0) {
				std::cout << "Ma so: " << current->ID << std::endl
					<< "Trong luong: " << current->Weight << std::endl
					<< "Gia thanh: " << current->Price << std::endl;
			}
			else if (current->next == NULL)
				std::cout << "Khong the tim thay chi tiet" << std::endl;
			current = current->next;
		}
	}
	double GetTotalWeight() { return weight; }
	double GetTotalPrice() { return price; }
};

class SingleDetail : public Detail {
protected:
	double weight, price;
public:
	SingleDetail() {
		id = "";
		weight = price = 0;
	}
	void Input() {
		std::cout << "\n*Chi tiet don*\nMa so: ";
		std::getline(std::cin, id);
		std::cout << "Trong luong: ";
		std::cin >> weight;
		std::cout << "Gia thanh: ";
		std::cin >> price;
		std::cin.ignore(1);
	}
	double Price() { return price; }
	double Weight() { return weight; }
};

class ComplexDetail : public Detail {
protected:
	Detail* b;
	double weight, price;
	double Accessories, Wage;
public:
	ComplexDetail() { weight = price = Accessories = Wage = 0; }
	void Input() {
		int type, n;
		std::cout << "\n*Chi tiet phuc*\nMa so: ";
		std::getline(std::cin, id);
		std::cout << "Phu kien ket noi: ";
		std::cin >> this->Accessories;
		std::cout << "Cong lap rap: ";
		std::cin >> this->Wage;
		std::cout << "Chi tiet con la don hay phuc (1. don; 2. phuc): ";
		std::cin >> type;
		std::cout << "So chi tiet con: ";
		std::cin >> n;
		std::cin.ignore(1);
		if (type == 1) {
			for (int i = 0; i < n; i++) {
				b = new SingleDetail;
				std::cout << "*Danh sach cac chi tiet con don*" << std::endl;
				b->Input();
				weight += b->Weight();
				price += b->Price();
			}
			delete b;
		}
		else {
			for (int i = 0; i < n; i++) {
				b = new ComplexDetail;
				std::cout << "*Danh sach cac chi tiet con phuc*" << std::endl;
				b->Input();
				weight += b->Weight();
				price += b->Price();
			}
			delete b;
		}
	}
	double Price() { return price + 10 * Wage / 100; }
	double Weight() { return weight + 20 * Accessories / 100; }
};

void main() {
	Machine machine;
	int single, complex;
	std::string find;
	Detail* a;
	std::cout << "Nhap cac chi tiet cho co may" << std::endl
		<< "So chi tiet don: ";
	std::cin >> single;
	std::cout << "So chi tiet phuc: ";
	std::cin >> complex;
	std::cin.ignore(1);
	if (single > 0) {
		a = new SingleDetail;
		for (int i = 0; i < single; i++) {
			a->Input();
			machine.AddDetail(a);
		}
		delete a;
	}
	if (complex > 0) {
		a = new ComplexDetail;
		for (int i = 0; i < complex; i++) {
			a->Input();
			machine.AddDetail(a);
		}
		delete a;
	}
	machine.Total();
	std::cout << "Trong luong co may: " << machine.GetTotalWeight() << std::endl;
	std::cout << "Gia thanh co may: " << machine.GetTotalPrice() << std::endl;
	while (true) {
		std::cout << "Nhap ma so chi tiet can tim (khong nhap de thoat): ";
		std::getline(std::cin, find);
		if (find.std::string::compare("") == 0) break;
		else machine.Find(find);
		std::cout << std::endl;
	}
}