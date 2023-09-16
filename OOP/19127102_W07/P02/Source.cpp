#include <iostream> 

class Mammal {
protected:
	int itsAge;
public:
	Mammal() { std::cout << "Mammal constructor..." << std::endl; }
	virtual ~Mammal() { std::cout << "Mammal destructor..." << std::endl; }
	virtual void speak() { std::cout << "What does a mammal speak ? Mammilian !" << std::endl; }
};

class Dog : public Mammal {
public:
	Dog() { std::cout << "Dog constructor..." << std::endl; }
	~Dog() { std::cout << "Dog destructor..." << std::endl; }
	void speak() { std::cout << "What does a dog speak ? Woof !" << std::endl; }
};

class Cat : public Mammal {
public:
	Cat() { std::cout << "Cat constructor..." << std::endl; }
	~Cat() { std::cout << "Cat destructor..." << std::endl; }
	void speak() { std::cout << "What does a cat speak ? Meow !" << std::endl; }
};

class Horse : public Mammal {
public:
	Horse() { std::cout << "Horse constructor..." << std::endl; }
	~Horse() { std::cout << "Horse destructor..." << std::endl; }
	void speak() { std::cout << "What does a horse speak ? Ney !" << std::endl; }
};

class GuineaPig : public Mammal {
public:
	GuineaPig() { std::cout << "GuineaPig constructor..." << std::endl; }
	~GuineaPig() { std::cout << "GuineaPig destructor..." << std::endl; }
	void speak() { std::cout << "What does a guinea pig speak ? Wheep Wheep !" << std::endl; }
};

int main() {
	Mammal* theArray[5];
	Mammal* ptr;
	int choice;
	for (int i = 0; i < 5; i++) {
		std::cout << "(1)dog (2)cat (3)horse (4)guinea pig: ";
		std::cin >> choice;
		switch (choice) {
		case 1: ptr = new Dog;
			break;
		case 2: ptr = new Cat;
			break;
		case 3: ptr = new Horse;
			break;
		case 4: ptr = new GuineaPig;
			break;
		default: ptr = new Mammal;
			break;
		}
		theArray[i] = ptr;
	}

	for (int i = 0; i < 5; i++) {
		theArray[i]->speak();
	}

	for (int i = 0; i < 5; i++) {
		delete theArray[i];
	}
	return 0;
}