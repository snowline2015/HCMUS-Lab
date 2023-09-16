#include <iostream>
#include <algorithm>
#include <fstream>

struct node {
	int data;
    node* left,
        * right;
};

struct Tree {
	node* root;
};

int Left(int value, node* root) { return value <= root->data; }

int Right(int value, node* root) { return value > root->data; }

int LeftMost(const node* root) {
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

node* insertion(node* root, int value) {
    if (root == NULL) {
        node* Node = new node;
        Node->left = Node->right = NULL;
        Node->data = value;
        return Node;
    }
    if (Left(value, root))
        root->left = insertion(root->left, value);
    else if (Right(value, root))
        root->right = insertion(root->right, value);
    return root;
}

void readFile(node*& root, std::string str) {
    std::ifstream fp(str);
    if (fp.fail()) {
        std::cout << "Cannot open file" << std::endl;
        return;
    }
    int key;
    while (!fp.eof()) {
        fp >> key;
        root = insertion(root, key);
    }
    fp.close();
}

void WritePostorderToFile(node* root, std::ofstream& fs) {
    if (root == NULL)
        return;
    WritePostorderToFile(root->left, fs);
    WritePostorderToFile(root->right, fs);
    fs << root->data << " ";
}

void SumNodes(node* root, int& sum) {
    if (root == NULL)
        return;
    SumNodes(root->left, sum);
    SumNodes(root->right, sum);
    sum += root->data;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "Wrong command. Ex: 19127102_19CLC9_2.exe input.txt ouput.txt";
        return 0;
    }
    Tree BST;
    BST.root = NULL;
    readFile(BST.root, argv[1]);

    std::ofstream fs(argv[2]);
    WritePostorderToFile(BST.root, fs);
    int sum = 0;
    SumNodes(BST.root, sum);
    fs << "\n" << sum;
    fs.close();
    return 0;
}

