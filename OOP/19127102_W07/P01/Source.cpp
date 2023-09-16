#include <iostream>

class Mammal {
protected:
	int itsAge;
public:
	Mammal() { std::cout << "Mammal constructor..." << std::endl; }
	~Mammal() { std::cout << "Mammal destructor..." << std::endl; }
	virtual void move() const { std::cout << "Mammal moves a step !" << std::endl; }
	virtual void speak() const { std::cout << "What does a mammal speak ? Mammilian !" << std::endl; }
};

class Dog : public Mammal {
public:
	Dog() { std::cout << "Dog constructor..." << std::endl; }
	~Dog() { std::cout << "Dog destructor..." << std::endl; }
	void move() const { std::cout << "Dog moves a step !" << std::endl; }
	void speak() const { std::cout << "Woof !" << std::endl; }
};

int main() {
	Mammal* pDog = new Dog;
	pDog->move();
	pDog->speak();
	delete pDog;
	return 0;
}