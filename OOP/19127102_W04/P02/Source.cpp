#include <iostream>
#include <math.h>

class SP1 {
protected:
	double real, imaginary, modun;
public:
	SP1() {
		real = 0;
		imaginary = 0;
		modun = 0;
	}
	SP1(double a, double b) {
		if (b != 0) {
			real = a;
			imaginary = b;
		}
	}
	~SP1() {
		real = 0;
		imaginary = 0;
		modun = 0;
	}
	void input() { std::cin >> real >> imaginary; }
	void show() { std::cout << real << " + " << imaginary << "i" << std::endl; }
	void module() { modun = sqrt(pow(real, 2) + pow(imaginary, 2)); }
	void conjugate() { imaginary = -imaginary; }
};

class SP2 : SP1 {
private:

public:
	SP2() {
		real = 0;
		imaginary = 0;
		modun = 0;
	}
	SP2(double a, double b) {
		if (b != 0) {
			real = a;
			imaginary = b;
			module();
		}
	}
	~SP2() {
		real = 0;
		imaginary = 0;
		modun = 0;
	}
	friend std::ostream& operator <<(std::ostream& os, SP2& complex) {
		os << complex.real << " + " << complex.imaginary << "i";
		return os;
	}
	friend std::istream& operator >>(std::istream& os, SP2& complex) {
		os >> complex.real >> complex.imaginary;
		return os;
	}
	friend SP2 operator +(SP2 complex1, SP2 complex2) {
		SP2 complex;
		complex.real = complex1.real + complex2.real;
		complex.imaginary = complex1.imaginary + complex2.imaginary;
		return complex;
	}
	friend SP2 operator -(SP2 complex1, SP2 complex2) {
		SP2 complex;
		complex.real = complex1.real - complex2.real;
		complex.imaginary = complex1.imaginary + complex2.imaginary;
		return complex;
	}
	friend SP2 operator *(SP2 complex1, SP2 complex2) {
		SP2 complex;
		complex.real = complex1.real * complex2.real - complex1.imaginary * complex2.imaginary;
		complex.imaginary = complex1.real * complex2.imaginary + complex2.real * complex1.imaginary;
		return complex;
	}
	friend SP2 operator /(SP2 complex1, SP2 complex2) {
		SP2 complex;
		complex2.module(); complex2.conjugate();
		complex = complex1 * complex2;
		complex.real /= pow(complex2.modun, 2);
		complex.imaginary /= pow(complex2.modun, 2);
		return complex;
	}
	SP2& operator++() {
		this->real += 1;
		return *this;
	}
	SP2& operator--() {
		this->real -= 1;
		return *this;
	}
	SP2& operator++(int) {
		SP2 temp = *this;
		this->real += 1;
		return temp;
	}
	SP2& operator--(int) {
		SP2 temp = *this;
		this->real -= 1;
		return temp;
	}
	friend bool operator >(SP2 complex1, SP2 complex2) {
		if (complex1.real > complex2.real || 
			complex1.real == complex2.real && complex1.imaginary > complex2.imaginary) return true;
		else return false;
	}
	friend bool operator >=(SP2 complex1, SP2 complex2) { return operator >(complex1, complex2); }
	friend bool operator <(SP2 complex1, SP2 complex2) {
		if (complex1.real < complex2.real ||
			complex1.real == complex2.real && complex1.imaginary < complex2.imaginary) return true;
		else return false;
	}
	friend bool operator <=(SP2 complex1, SP2 complex2) { return operator <(complex1, complex2); }
	friend bool operator ==(SP2 complex1, SP2 complex2) {
		if (complex1.real == complex2.real && complex1.imaginary == complex2.imaginary) return true;
		else return false;
	}
};

void main() {
	SP1 a, b(1, 3);
	a.show(); b.show();
	SP2 c, d;
	std::cout << "Input first complex number : ";
	std::cin >> c;
	std::cout << "Input second complex number: ";
	std::cin >> d;
	SP2 e = c + d,
		f = c - d,
		g = c * d,
		h = c / d;
	std::cout << e << std::endl << f << std::endl << g << std::endl << h << std::endl;
}