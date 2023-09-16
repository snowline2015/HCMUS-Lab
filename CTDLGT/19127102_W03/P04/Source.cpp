#include <iostream>
#include <string>

class stack {
private:
	std::string* data;
	int top, size;
public:
	stack() { top = -1; }
	~stack() { top = -1; delete[] data; }
	void push(std::string x) {
		if (top == size - 1) return;
		else {
			top++;
			data[top] = x;
		}
	}
	std::string pop() {
		if (top == -1) { return ""; }
		else return data[top--];
	}
	void setSize(int Size) { 
		size = Size;
		data = new std::string[size];
	}
	void PostfixReversePolishNotation(std::string formula) {
		std::string temp = "", x;
		stack RPN1, RPN2;
		RPN1.setSize(formula.length()); RPN2.setSize(formula.length());
		for (int i = 0; i < formula.length() + 1; i++) {
			if ((int)formula[i] == 32) continue;
			else if ((48 <= (int)formula[i] && (int)formula[i] <= 57) || (65 <= (int)formula[i] && (int)formula[i] <= 90) || (97 <= (int)formula[i] && (int)formula[i] <= 122)
				|| (int)formula[i] == 44 || (int)formula[i] == 46) {
				if ((48 <= (int)formula[i + 1] && (int)formula[i + 1] <= 57) || (65 <= (int)formula[i + 1] && (int)formula[i + 1] <= 90) || (97 <= (int)formula[i + 1] && (int)formula[i + 1] <= 122) 
					|| (int)formula[i + 1] == 44 || (int)formula[i + 1] == 46) {
					temp.append(1, formula[i]);
					continue;
				}
				else {
					RPN1.push(temp.append(1, formula[i]));
					temp = "";
				}
			}
			else if ((int)formula[i] == 40) {
				RPN2.push(temp.append(1, formula[i]));
				temp = "";
			}
			else if ((int)formula[i] == 43 || (int)formula[i] == 45) {
				while (true) {
					x = RPN2.pop();
					if (x.compare("") == 0) {
						RPN2.push(temp.append(1, formula[i]));
						temp = "";
						break;
					}
					if (x.compare("+") == 0 || x.compare("-") == 0 || x.compare("*") == 0 || x.compare("/") == 0)
						RPN1.push(x);
					else {
						RPN2.push(x);
						RPN2.push(temp.append(1, formula[i]));
						temp = "";
						break;
					}
				}
			}
			else if ((int)formula[i] == 42 || (int)formula[i] == 47) {
				while (true) {
					x = RPN2.pop();
					if (x.compare("") == 0) {
						RPN2.push(temp.append(1, formula[i]));
						temp = "";
						break;
					}
					if (x.compare("*") == 0 || x.compare("/") == 0)
						RPN1.push(x);
					else {
						RPN2.push(x);
						RPN2.push(temp.append(1, formula[i]));
						temp = "";
						break;
					}
				}
			}
			else if ((int)formula[i] == 41) {
				while (true) {
					x = RPN2.pop();
					if (x.compare("(") == 0 || x.compare("") == 0) break;
					else RPN1.push(x);
				}
			}
			else {
				while (true) {
					x = RPN2.pop();
					if (x.compare("") == 0) break;
					else RPN1.push(x);
				}
			}
		}
		RPN1.display();
	}
	void display() {
		for (int i = 0; i <= top; i++) 
			std::cout << data[i] << " ";
		std::cout << std::endl;
	}
};

int main() {
	stack RPN;
	std::string formula;
	std::cout << "Input math formula: ";
	getline(std::cin, formula);
	RPN.PostfixReversePolishNotation(formula);
	return 0;
}