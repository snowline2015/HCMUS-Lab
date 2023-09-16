#include <iostream>
#include <math.h>

class PS1 {
protected:
	double numer, deno;
public:
	PS1() {
		numer = 0;
		deno = 1;
	}
	PS1(double a, double b) {
		if (b != 0) {
			numer = roundf(a);
			deno = roundf(b);
		}
	}
	~PS1() {
		numer = 0;
		deno = 1;
	}
	PS1 InputFraction() {
		PS1 fraction;
		std::cout << "Input numerator : ";
		std::cin >> fraction.numer;
		std::cout << "Input denominator : ";
		std::cin >> fraction.deno;
		return fraction;
	}
	void show() {
		std::cout << this->numer << "/" << this->deno << std::endl;
	}
	int CountDecimal(double a) {
		int count = 0;
		double temp = a;
		while (temp - (int)temp != 0) {
			temp *= 10;
			count++;
		}
		return count;
	}
	void simplify() {
		if (CountDecimal(abs(this->numer)) >= CountDecimal(abs(this->deno))) {
			this->numer *= pow(10, CountDecimal(abs(this->numer)));
			this->deno *= pow(10, CountDecimal(abs(this->numer)));
		}
		else {
			this->numer *= pow(10, CountDecimal(abs(this->deno)));
			this->deno *= pow(10, CountDecimal(abs(this->deno)));
		}
		if (abs(this->numer) >= abs(this->deno)) {
			for (int i = 2; i <= (int)this->numer; i++) {
				if ((int)this->numer % i == 0 && (int)this->deno % i == 0) {
					this->numer /= i;
					this->deno /= i;
				}
			}
		}
		else {
			for (int i = 2; i <= (int)this->deno; i++) {
				if ((int)this->numer % i == 0 && (int)this->deno % i == 0) {
					this->numer /= i;
					this->deno /= i;
				}
			}
		}
	}
	friend PS1 operator +(PS1 fraction1, PS1 fraction2) {
		PS1 temp1 = fraction1,
			temp2 = fraction2;
		temp1.simplify(); temp2.simplify();
		temp1.numer = temp1.numer * temp2.deno + temp1.deno * temp2.numer;
		temp1.deno = temp1.deno * temp2.deno;
		temp1.simplify();
		return temp1;
	}
};

class PS2 : PS1 {
private:
	bool Postive;
public:
	PS2() {
		numer = 0;
		deno = 1;
	}
	PS2(double a, double b) {
		if (b != 0) {
			numer = roundf(a);
			deno = roundf(b);
		}
	}
	~PS2() {
		numer = 0;
		deno = 1;
	}
	friend std::ostream& operator <<(std::ostream& os, PS2& fraction) {
		os << fraction.numer << "/" << fraction.deno;
		return os;
	}
	friend std::istream& operator >>(std::istream& os, PS2& fraction) {
		os >> fraction.numer >> fraction.deno;
		return os;
	}
	friend PS2 operator -(PS2 fraction1, PS2 fraction2) {
		PS2 temp1 = fraction1,
			temp2 = fraction2;
		temp1.simplify(); temp2.simplify();
		temp1.numer = temp1.numer * temp2.deno - temp1.deno * temp2.numer;
		temp1.deno = temp1.deno * temp2.deno;
		temp1.simplify();
		return temp1;
	}
	friend PS2 operator *(PS2 fraction1, PS2 fraction2) {
		PS2 temp1 = fraction1,
			temp2 = fraction2;
		temp1.simplify(); temp2.simplify();
		temp1.numer = temp1.numer * temp2.numer;
		temp1.deno = temp1.deno * temp2.deno;
		temp1.simplify();
		return temp1;
	}
	friend PS2 operator /(PS2 fraction1, PS2 fraction2) {
		PS2 temp1 = fraction1,
			temp2 = fraction2;
		temp1.simplify(); temp2.simplify();
		temp1.numer = temp1.numer * temp2.deno;
		temp1.deno = temp1.deno * temp2.numer;
		temp1.simplify();
		return temp1;
	}
	friend bool operator ==(PS2 fraction1, PS2 fraction2) {
		PS2 temp1 = fraction1,
			temp2 = fraction2;
		temp1.simplify(); temp2.simplify();
		if (temp1.numer == temp2.numer && temp1.deno == temp2.deno) return true;
		else return false;
	}
	friend bool operator !=(PS2 fraction1, PS2 fraction2) {
		PS2 temp1 = fraction1,
			temp2 = fraction2;
		temp1.simplify(); temp2.simplify();
		if (temp1.numer != temp2.numer || temp1.deno == temp2.deno) return true;
		else return false;
	}
	friend bool operator >(PS2 fraction1, PS2 fraction2) {
		PS2 temp1 = fraction1,
			temp2 = fraction2;
		temp1.simplify(); temp2.simplify();
		temp1.numer *= temp2.deno;
		temp2.numer *= temp1.deno;
		temp1.deno *= temp2.deno; temp2.deno = temp1.deno;
		if (temp1.numer > temp2.numer) return true;
		else return false;
	}
	friend bool operator >=(PS2 fraction1, PS2 fraction2) {
		return operator >(fraction1, fraction2);
	}
	friend bool operator <(PS2 fraction1, PS2 fraction2) {
		PS2 temp1 = fraction1,
			temp2 = fraction2;
		temp1.simplify(); temp2.simplify();
		temp1.numer *= temp2.deno;
		temp2.numer *= temp1.deno;
		temp1.deno *= temp2.deno; temp2.deno = temp1.deno;
		if (temp1.numer < temp2.numer) return true;
		else return false;
	}
	friend bool operator <=(PS2 fraction1, PS2 fraction2) {
		return operator <(fraction1, fraction2);
	}
	PS2& operator++() {
		this->numer += this->deno;
		return *this;
	}
	PS2& operator--() {
		this->numer -= this->deno;
		return *this;
	}
	PS2& operator++(int) {
		PS2 temp = *this;
		this->numer += this->deno;
		return temp;
	}
	PS2& operator--(int) {
		PS2 temp = *this;
		this->numer -= this->deno;
		return temp;
	}
};

void main() {
	PS1 a(15.7, 6), b(13, 4);
	PS1 c = a + b;
	c.show();
	PS2 d, e;
	std::cout << "Input fraction 1: ";
	std::cin >> d;
	std::cout << "Input fraction 2: ";
	std::cin >> e;
	d > e ? std::cout << "d >= e || d > e" : d < e ? std::cout << "d <= e || d < e" : std::cout << "d == e";
}

