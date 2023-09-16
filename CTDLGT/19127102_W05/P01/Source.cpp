#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

struct node {
    std::string data;
	std::vector<node*> child;
};

struct Tree {
	node* root;
};

std::string lowercase(const std::string& in)
{
	std::string out;
	std::transform(in.begin(), in.end(), std::back_inserter(out), ::tolower);
	return out;
}

node* search_parent(node* root, const std::string& name) {
	if (root == NULL || lowercase(root->data).compare(lowercase(name)) == 0)
		return root;
	for (std::vector<node*>::iterator p = (root->child).begin(); p != (root->child).end(); p++) {
		node* temp = search_parent((*p), name);
		if (temp != NULL) return temp;
	}
	return NULL;
}

void insert(node*& root, const std::string& parent, std::vector<std::string>& child) {
	node* t = search_parent(root, parent);
	if (t == NULL) {
		t = new node;
		t->data = parent;
		root = t;
	}
	for (auto& item : child) {
		node* temp = new node;
		temp->data = item;
		t->child.push_back(temp);
	}
}

void print_preorder(node* root) {
	if (root == nullptr) return;
	std::cout << root->data << " ";
	for (auto& item : root->child)
		print_preorder(item);
}

void print_postorder(node* root) {
	if (root == nullptr) return;
	for (auto& item : root->child)
		print_postorder(item);
	std::cout << root->data << " ";
}

void print_inorder(node* root) {
	if (root == nullptr) return;
	if (root->child.empty())
	{
		std::cout << root->data << " ";
		return;
	}
	for (unsigned i = 0; i < root->child.size() - 1; i++)
		print_inorder(root->child[i]);
	std::cout << root->data << " ";
	print_inorder(root->child[root->child.size() - 1]);
}

void readFile(Tree& tree) {
	std::ifstream fp("input.txt");
	std::string str;
	getline(fp, str, '\n');
	while (!fp.eof())
	{
		getline(fp, str, '\n');
		str.erase(std::remove(str.begin(), str.end(), '('), str.end());
		str.erase(std::remove(str.begin(), str.end(), ')'), str.end());
		size_t pos;
		std::string token;
		std::vector<std::string> child;
		while ((pos = str.find(' ')) != std::string::npos) {
			child.push_back(str.substr(0, pos));
			str.erase(0, pos + 1);
		}
		child.push_back(str);
		std::string parent = child[0];
		child.erase(child.begin());
		insert(tree.root, parent, child);
	}
	fp.close();
}

int main() {
	Tree tree;
	tree.root = NULL;
	readFile(tree);
	std::cout << "NLR: ";
	print_preorder(tree.root);
	std::cout << "\n\nLRN: ";
	print_postorder(tree.root);
	std::cout << "\n\nLNR: ";
	print_inorder(tree.root);
	std::cout << std::endl;
	return 0;
}