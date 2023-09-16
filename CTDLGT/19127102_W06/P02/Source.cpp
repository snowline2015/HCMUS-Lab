#include <iostream>
#include <string>
#include <stack>
#include <fstream>
#include <algorithm>
#include <vector>

struct node {
	int data, height;
	node* left,
		* right;
};

struct tree {
	node* root;
};

node* buildTree(std::vector<int> vec, int preIndex, int low, int high, int size) {
	if (preIndex >= size || low > high)
		return NULL;

	node* root = new node;
	root->data = vec[preIndex];
	root->left = root->right = NULL;
	preIndex = preIndex + 1;

	if (low == high)
		return root;

	int i;
	for (i = low; i <= high; ++i)
		if (vec[i] > root->data)
			break;

	root->left = buildTree(vec, preIndex, preIndex, i - 1, size);
	root->right = buildTree(vec, preIndex, i, high, size);

	return root;
}

int height(node* ptr)
{
	int h_left, h_right;

	if (ptr == NULL)
		return 0;

	h_left = height(ptr->left);
	h_right = height(ptr->right);

	if (h_left > h_right)
		return 1 + h_left;
	else
		return 1 + h_right;
}

int isAVL(node* ptr)
{
	int h_l, h_r, diff;
	if (ptr == NULL)
		return 1;
	h_l = height(ptr->left);
	h_r = height(ptr->right);
	diff = h_l > h_r ? h_l - h_r : h_r - h_l;
	if (diff <= 1 && isAVL(ptr->left) && isAVL(ptr->right))
		return 1;
	return 0;
}

void readAndSave(node*& root) {
	std::vector<int> Avl;
	std::string temp;
	tree ok;
	ok.root = NULL;
	std::ifstream fp("input.txt");
	std::ofstream fs("output.txt");
	if (fp.fail() || fs.fail()) {
		std::cout << "Cannot open file" << std::endl;
		return;
	}
	getline(fp, temp);
	while (!fp.eof()) {
		Avl.clear();
		getline(fp, temp);
		if (temp == "") break;
		int checkpos = -1;
		for (int i = 0; i < temp.length(); i++) {
			if (temp[i] != ' ' && checkpos == -1) {
				checkpos = i;
				if (i + 1 == temp.length())
					Avl.push_back(atoi(&temp[i]));
			}
			if (temp[i] == ' ') {
				if (i - 1 == 0)
					Avl.push_back(stoi(temp.substr(checkpos, 1)));
				else 
					Avl.push_back(stoi(temp.substr(checkpos, i - 1)));
				checkpos = -1;
			}
		}
		ok.root = buildTree(Avl, 0, 0, Avl.size() - 1, Avl.size());
		if (isAVL(ok.root) == true)
			fs << "yes" << std::endl;
		else 
			fs << "no" << std::endl;
	}
	fs.close(); fp.close();
}

int main() {
	tree avl;
	avl.root = NULL;
	readAndSave(avl.root);
}