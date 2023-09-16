#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#define SIZE 10

template <class X>
class stack {
	X* arr;
	int top;
	int capacity;
public:
	stack(int size = SIZE) {
		this->capacity = size;
		this->arr = new X[size];
		this->top = -1;
	}
	void push(X val) {
		if (this->isFull() == true) {
			std::cout << "Stack is full" << std::endl;
			return;
		}
		else {
			this->top++;
			this->arr[this->top] = val;
		}
	}
	X pop() {
		if (this->isEmpty() == true) {
			std::cout << "Stack is empty" << std::endl;
			return 0;
		}
		else {
			X temp = this->arr[this->top];
			this->top--;
			return temp;
		}
	}
	X peek() { return arr[top]; }
	int size() { return this->capacity; }
	bool isEmpty() {
		if (this->top < 0) return true;
		return false;
	}
	bool isFull() {
		if (this->top >= this->capacity - 1) return true;
		return false;
	}
	~stack() { delete[] arr; }
};

int main() {
	stack<int> ok;
	ok.push(1);
	ok.push(2);
	ok.push(3);
	ok.pop();
	if (ok.isFull() == true) std::cout << "Stack da day" << std::endl;
	else std::cout << "Stack chua day" << std::endl;
	std::cout << "Phan tu tren cung la: " << ok.peek() << std::endl;
	std::cout << "Kich thuoc stack la: " << ok.size() << std::endl;
	ok.pop();
	ok.pop();
	if (ok.isEmpty() == true) std::cout << "Stack trong" << std::endl;
	else std::cout << "Stack chua trong" << std::endl;
	return 0;
}