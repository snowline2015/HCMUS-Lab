#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class stack {
private:
	char* data;
	int top = -1, size;
public:
	void push(char x) {
		if (top == size - 1)
			std::cout << "Stack is full" << std::endl;
		else {
			top++;
			data[top] = x;
		}
	}

	char pop() {
		if (top == -1) {
			std::cout << "Stack is empty" << std::endl;
			return NULL;
		}
		else return data[top--];
	}

	bool _palindrome(std::string& str, std::vector<char> punc, int option) {
		if (option == 1) return Level1(str);
		else return Level2(str, punc);
	}

	bool Level1(std::string& str) {
		size = str.length();
		data = new char[size];
		std::string temp = "";
		for (int i = 0; i < size; i++)
			push(str[i]);
		for (int i = 0; i < size; i++) {
			char x = pop();
			temp += x;
		}
		std::transform(str.begin(), str.end(), str.begin(), ::tolower);
		std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
		if (str.compare(temp) == 0) return true;
		else return false;
	}

	bool Level2(std::string& str, std::vector<char> punc) {
		for (int i = 0; i < str.length(); i++) {
			for (std::vector<char>::iterator p = punc.begin(); p != punc.end();) {
				if (str[i] == *p) {
					str.erase(i, 1);
					p = punc.begin();
				}
				else p++;
			}
		}
		return Level1(str);
	}
};

class queue : public stack {
private:
	char* data;
	int in = -1, size;
public:
	void enqueue(char x) {
		if (in == size - 1)
			std::cout << "Queue is full" << std::endl;
		else {
			in++;
			for (int i = in; i > 0; i--) 
				data[i] = data[i - 1];
			data[0] = x;
		}
	}

	char dequeue() {
		if (in == -1) {
			std::cout << "Queue is empty" << std::endl;
			return NULL;
		}
		else {
			char temp = data[0];
			for (int i = 0; i < in; i++)
				data[i] = data[i + 1];
			in--;
			return temp;
		}
	}

	bool _palindrome(std::string& str, std::vector<char> punc, int option) {
		if (option == 1) return Level1(str);
		else return Level2(str, punc);
	}

	bool Level1(std::string& str) {
		size = str.length();
		data = new char[size];
		std::string temp = "";
		for (int i = 0; i < size; i++)
			enqueue(str[i]);
		for (int i = 0; i < size; i++) {
			char x = dequeue();
			temp += x;
		}
		std::transform(str.begin(), str.end(), str.begin(), ::tolower);
		std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
		if (str.compare(temp) == 0) return true;
		else return false;
	}

	bool Level2(std::string& str, std::vector<char> punc) {
		for (int i = 0; i < str.length(); i++) {
			for (std::vector<char>::iterator p = punc.begin(); p != punc.end();) {
				if (str[i] == *p) {
					str.erase(i, 1);
					p = punc.begin();
				}
				else p++;
			}
		}
		return Level1(str);
	}
};

int main() {
	int option;
	std::string ok;
	std::vector<char> punc;
	punc.push_back(' ');
	punc.push_back(',');
	punc.push_back('.');
	punc.push_back(';');
	punc.push_back('\n');
	punc.push_back('?');
	punc.push_back('!');
	punc.push_back('"');
	punc.push_back('\'');
	punc.push_back(':');
	punc.push_back('!');
	std::cout << "Input string: ";
	getline(std::cin, ok);
	std::cout << "1. Stack\n2. Queue\nChoose your option to implement: ";
	std::cin >> option;
	std::cout << "1. Level 1\n2. Level 2\nChoose your level to check for palindrome: ";
	if (option == 1) {
		std::cin >> option;
		stack Stack;
		if (Stack._palindrome(ok, punc, option) == true) std::cout << "Yes" << std::endl;
		else std::cout << "No" << std::endl;
	}
	else {
		std::cin >> option;
		queue Queue;
		if (Queue._palindrome(ok, punc, option) == true) std::cout << "Yes" << std::endl;
		else std::cout << "No" << std::endl;
	}
	return 0;
}