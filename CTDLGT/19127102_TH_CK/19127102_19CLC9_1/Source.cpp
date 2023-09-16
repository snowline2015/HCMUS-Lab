#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

struct node {
	char name[50];
	std::string workpos;
	int sales;
	node* next;
};

struct Manager {
	node* head;
};

void readFile(Manager& lst) {
	std::string str;
	std::ifstream fp("input.txt");
	if (fp.fail()) {
		std::cout << "Cannot open file" << std::endl;
		return;
	}
	while (!fp.eof()) {
		node* temp = new node;
		std::getline(fp, str, '\n');
		if (str == "") break;
		strcpy(temp->name, str.c_str());
		std::getline(fp, str, '\n');
		temp->workpos = str;
		std::getline(fp, str, '\n');
		temp->sales = stoi(str);
		if (lst.head == NULL) {
			temp->next = NULL;
			lst.head = temp;;
		}
		else {
			node* current = lst.head;
			while (current->next != NULL) current = current->next;
			temp->next = NULL;
			current->next = temp;
		}
	}
	fp.close();
}

void searchTopN(Manager lst, int N) {		
	std::cout << "\nTop " << N << " employees with best sales:\n";
	std::vector<std::pair<std::string, int>> vec;
	for (node* current = lst.head; current != NULL; current = current->next)
		vec.push_back(std::pair<std::string, int>(std::string(current->name), current->sales));

	std::sort(vec.begin(), vec.end(), [](auto& left, auto& right) {
		return left.second > right.second;
		});

	int j = 0;
	for (int i = 0; i < N; i++) {
		for (node* current = lst.head; current != NULL; current = current->next) {
			if (vec[j].first.compare(std::string(current->name)) == 0) {
				std::cout << current->name << "\t\t" << current->workpos << "\t\t" << current->sales << std::endl;
				j++;
				break;
			}
		}
	}
}

int main() {
	Manager list;
	int N;
	list.head = NULL;
	readFile(list);
	std::cout << "Input N: ";
	std::cin >> N;
	searchTopN(list, N);
	return 0;
}