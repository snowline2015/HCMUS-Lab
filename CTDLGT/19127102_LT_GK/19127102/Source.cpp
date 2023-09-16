#include <iostream>

struct node {
    int data;
    node* left;
    node* right;
};

int Left(int value, node* root) { return value <= root->data; }

int Right(int value, node* root) { return value > root->data; }

int LeftMost(const node* root) {
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

node* insertionRoot(node* root, int value) {
    if (root == NULL) {
        node* Node = new node;
        Node->left = Node->right = NULL;
        Node->data = value;
        return Node;
    }
    if (Left(value, root))
        root->left = insertionRoot(root->left, value);
    else if (Right(value, root))
        root->right = insertionRoot(root->right, value);
    return root;
}

node* Deletion(node* root, int data) {
    if (root == NULL) return root;
    else if (data < root->data) root->left = Deletion(root->left, data);
    else if (data > root->data) root->right = Deletion(root->right, data);
	
    else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        }
        else if (root->left == NULL) {
            node* temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL) {
            node* temp = root;
            root = root->left;
            delete temp;
        }
        else {
            node* temp = new node;
            temp->data = LeftMost(root->right);
            root->data = temp->data;
            root->right = Deletion(root->right, temp->data);
        }
    }
    return root;
}

void print(node* root, int space) {
    if (root == NULL)
        return;
    space += 2;
    print(root->right, space);
    for (int i = 2; i < space; i++)
        std::cout << "\t";
    std::cout << root->data << "\n";
    print(root->left, space);
}

bool areIdentical(node* root1, node* root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;
    return (root1->data == root2->data &&
        areIdentical(root1->left, root2->left) &&
        areIdentical(root1->right, root2->right));
}

bool Subset(node* T, node* S)
{
    if (S == NULL)
        return true;
    if (T == NULL)
        return false;
    if (areIdentical(T, S))
        return true;
    return Subset(T->left, S) ||
        Subset(T->right, S);
}

int main() {
    node* root = NULL;

    root = insertionRoot(root, 50);
    root = insertionRoot(root, 10);
    root = insertionRoot(root, 15);
    root = insertionRoot(root, 23);
    root = insertionRoot(root, 22);
    root = insertionRoot(root, 35);
    root = insertionRoot(root, 70);
    root = insertionRoot(root, 3);
    root = insertionRoot(root, 12);
    root = insertionRoot(root, 18);
    root = insertionRoot(root, 24);
    root = insertionRoot(root, 31);
    root = insertionRoot(root, 48);
    root = insertionRoot(root, 63);
    root = insertionRoot(root, 93);
    root = insertionRoot(root, 20);

    root = Deletion(root, 22);
    root = Deletion(root, 20);
    root = Deletion(root, 12);
    root = Deletion(root, 23);
    root = Deletion(root, 70);

    print(root, 0);

    node* root2 = NULL;

    root2 = insertionRoot(root, 2);
    root2 = insertionRoot(root, 9);
    root2 = insertionRoot(root, 11);
    root2 = insertionRoot(root, 1);

    if (Subset(root, root2))
        std::cout << "Tree 2 is subtree of Tree 1";
    else
        std::cout << "Tree 2 is not a subtree of Tree 1";

    return 0;
}