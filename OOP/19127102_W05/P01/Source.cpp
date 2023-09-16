#include <iostream> 
#define PI 3.14

class ManagePlane {
public:
	virtual void Input() = 0;
	virtual void Output()= 0;
	virtual double Perimeter()  = 0;
	virtual double Area() = 0;
};

class ManageStereo {
public:
	virtual void Input() = 0;
	virtual void Output() = 0;
	virtual double Area() = 0;
	virtual double Volume() = 0;
};

class Circle : public ManagePlane {
protected:
	double rad;
public:
	Circle() { rad = 0; }
	Circle(double a) { rad = a; }
	void Input() {
		std::cout << "\n*Circle*" << std::endl << "Input radius: ";
		std::cin >> this->rad;
	}
	void Output() {
		std::cout << "Perimeter: " << this->Perimeter() << std::endl
			<< "Area: " << this->Area() << std::endl;
	}
	double Perimeter() { return this->rad * 2 * PI * 1.0; }
	double Area() { return pow(this->rad, 2) * PI * 1.0; }
};

class Rectangle : public ManagePlane {
protected:
	double length, width;
public:
	void Input() {
		std::cout << "\n*Rectangle*" << std::endl << "Input length and width: ";
		std::cin >> this->length >> this->width;
	}
	void Output() {
		std::cout << "Perimeter: " << this->Perimeter() << std::endl
			<< "Area: " << this->Area() << std::endl;
	}
	double Perimeter() { return (this->length + this->width) * 2 * 1.0; }
	double Area() { return this->length * this->width; }
};

class Square : public ManagePlane {
protected:
	double edge;
public:
	void Input() {
		std::cout << "\n*Square*" << std::endl << "Input edge: ";
		std::cin >> this->edge;
	}
	void Output() {
		std::cout << "Perimeter: " << this->Perimeter() << std::endl
			<< "Area: " << this->Area() << std::endl;
	}
	double Perimeter() { return this->edge * 4 * 1.0; }
	double Area() { return pow(this->edge, 2) * 1.0; }
};

class EquilateralTriangle : public ManagePlane {
protected:
	double edge;
public:
	void Input() {
		std::cout << "\n*Equilateral Triangle*" << std::endl << "Input edge: ";
		std::cin >> this->edge;
	}
	void Output() {
		std::cout << "Perimeter: " << this->Perimeter() << std::endl
			<< "Area: " << this->Area() << std::endl;
	}
	double Perimeter() { return this->edge * 3 * 1.0; }
	double Area() { return pow(this->edge, 2) * sqrt(3) / 4 * 1.0; }
};

class Cube : public ManageStereo {
protected:
	double edge;
public:
	void Input() {
		std::cout << "\n*Cube*" << std::endl << "Input edge: ";
		std::cin >> this->edge;
	}
	void Output() {
		std::cout << "Lateral Area: " << this->Area() << std::endl
			<< "Volume: " << this->Volume() << std::endl;
	}
	double Area() { return pow(this->edge, 2) * 4 * 1.0; }
	double Volume() { return pow(this->edge, 3) * 1.0; }
};

class Sphere : public ManageStereo {
protected:
	double rad;
public:
	void Input() {
		std::cout << "\n*Sphere*" << std::endl << "Input rad: ";
		std::cin >> this->rad;
	}
	void Output() {
		std::cout << "Lateral Area: " << this->Area() << std::endl
			<< "Volume: " << this->Volume() << std::endl;
	}
	double Area() { return pow(this->rad, 2) * 4 * PI * 1.0; }
	double Volume() { return pow(this->rad, 3) * PI * 4 / 3 * 1.0; }
};
void main() {
	ManagePlane* a, * b, * c, * d;
	ManageStereo *e, * f;
	a = new Circle;
	b = new Rectangle;
	c = new EquilateralTriangle;
	d = new Square;
	e = new Cube;
	f = new Sphere;
	a->Input(); a->Output();
	b->Input(); b->Output();
	c->Input(); c->Output();
	d->Input(); d->Output();
	e->Input(); e->Output();
	f->Input(); f->Output();
	delete a, b, c, d, e, f;
}