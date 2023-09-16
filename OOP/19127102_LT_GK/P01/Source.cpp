#include <iostream>

struct node {
	double money;
	node* next;
};
class Person {
protected:
	std::string name, address, telephone;
public:
	Person() {
		name = "";
		address = "";
		telephone = "";
	}
	Person(std::string a, std::string b, std::string c) {
		name = a;
		address = b;
		telephone = c;
	}
	void setName(std::string a) { this->name = a; }
	void setAddress(std::string a) { this->address = a; }
	void setTelephone(std::string a) { this->telephone = a; }

	std::string getName() { return this->name; }
	std::string getAddress() { return this->address; }
	std::string getTelephone() { return this->telephone; }
};

class Customer : public Person {
protected:
	Customer* spouse;
	std::string number;
	bool MailingList;
public:
	Customer() {
		number = "";
		MailingList = false;
	}
	Customer(std::string a, bool b) {
		number = a;
		MailingList = b;
	}
	void setSpouse(Customer b) { this->spouse = new Customer(b); }
	void setNumer(std::string a) { this->number = a; }
	void setMailingList(bool a) { this->MailingList = a; }

	std::string getNumber() { return this->number; }
	bool getWish() { return this->MailingList; }
	Customer* getSpouse() { return this->spouse; }
};

class PreferredCustomer : public Customer {
private:
	node* head;
protected:
	double purchase;
	double discount;
public:
	PreferredCustomer() {
		purchase = 0;
		discount = 0;
	}
	PreferredCustomer(double a) {
		purchase = a;
	}
	void setPurchase(double a) { 
		if (this->discount == 0) {
			this->purchase += a;
		}
		else {
			this->purchase += a * (1 - (this->discount / 100));
		}
		if (a >= 500 && a < 1000 && this->discount <= (5)) {
			this->discount = 5;
		}
		else if (a >= 1000 && a < 1500 && this->discount <= (6)) {
			this->discount = 6;
		}
		else if (a >= 1500 && a < 2000 && this->discount <= (7)) {
			this->discount = 7;
		}
		else if (a >= 2000 && a < 2500 && this->discount <= (10)) {
			this->discount = 1;
		}
		else {
			this->discount = 15;
		}
	}
	double getPurchase() { return this->purchase; }
};

void main() {
	PreferredCustomer Van, Khang, Lam;
	Van.setName("van"); Khang.setName("Khang"); Lam.setName("Lam");
	Van.setSpouse(Lam);
	Van.setPurchase(700); Van.setPurchase(700); Van.setPurchase(1500);
	Khang.setPurchase(850); Khang.setPurchase(750); Khang.setPurchase(2000);
	Lam.setPurchase(850); Lam.setPurchase(750); Lam.setPurchase(2000);
	std::cout << Van.getName() << "'s total: " << Van.getPurchase() << "$" << std::endl;
	std::cout << Khang.getName() << "'s total: " << Khang.getPurchase() << "$" << std::endl;
	std::cout << Lam.getName() << "'s total: " << Lam.getPurchase() << "$" << std::endl;
}