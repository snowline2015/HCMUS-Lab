#include <iostream>
#include <string>

class stack {
private:
	double* data;
	int top, size;
public:
	stack() { top = -1, size = 0; }
	~stack() { top = -1; delete[] data; }
	void push(double x) {
		if (top == size - 1) return;
		else {
			top++;
			data[top] = x;
		}
	}
	double pop() {
		if (top == -1) { return NULL; }
		else return data[top--];
	}
	void setSize(int Size) {
		size = Size;
		data = new double[size];
	}
	void InfixReversePolishNotation(std::string formula) {
		std::string temp = "";
		stack RPN;
		double x, y;
		RPN.setSize(formula.length());
		for (int i = 0; i < formula.length() + 1; i++) {
			if ((int)formula[i] == 32) continue;
			else if ((48 <= (int)formula[i] && (int)formula[i] <= 57) || (int)formula[i] == 44 || (int)formula[i] == 46) {
				if ((48 <= (int)formula[i + 1] && (int)formula[i + 1] <= 57) || (int)formula[i + 1] == 44 || (int)formula[i + 1] == 46) {
					temp.append(1, formula[i]);
					continue;
				}
				else {
					RPN.push(stod(temp.append(1, formula[i])));
					temp = "";
				}
			}
			else if ((int)formula[i] == 43 || (int)formula[i] == 45 || (int)formula[i] == 42 || (int)formula[i] == 47) {
				x = RPN.pop(); y = RPN.pop();
				switch ((int)formula[i]) {
				case 43: {
					RPN.push(x + y);
					break;
				}
				case 45: {
					RPN.push(y - x);
					break;
				}
				case 42: {
					RPN.push(x * y);
					break;
				}
				case 47: {
					RPN.push(y / x);
					break;
				}
				}
			}
		}
		RPN.display();
	}
	void display() {
		for (int i = 0; i <= top; i++) {
			std::cout << data[i] << " ";
		}
		std::cout << std::endl;
	}
};

int main() {
	stack RPN;
	std::string formula;
	std::cout << "Input postfix formula: ";
	getline(std::cin, formula);
	RPN.InfixReversePolishNotation(formula);
	return 0;
}