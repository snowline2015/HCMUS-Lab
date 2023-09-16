#include <iostream>

struct node {
    int data, height;
	node* left,
		* right;
};

struct tree {
	node* root;
};

int height(node* N) {
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b) { return (a > b) ? a : b; }

node* rightRotate(node* y) {
    node* x = y->left;
    node* temp = x->right;

    x->right = y;
    y->left = temp;

    y->height = max(height(y->left),
        height(y->right)) + 1;
    x->height = max(height(x->left),
        height(x->right)) + 1;

    return x;
}

node* leftRotate(node* x) {
    node* y = x->right;
    node* temp = y->left;

    y->left = x;
    x->right = temp;

    x->height = max(height(x->left),
        height(x->right)) + 1;
    y->height = max(height(y->left),
        height(y->right)) + 1;

    return y;
}

int getBalance(node* root) {
    if (root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}

node* Insert(node* root, int key) {
    if (root == NULL) {
        node* temp = new node;
        temp->data = key;
        temp->left = NULL;
        temp->right = NULL;
        temp->height = 1;
        return(temp);
    }

    if (key < root->data)
        root->left = Insert(root->left, key);
    else if (key > root->data)
        root->right = Insert(root->right, key);
    else
        return root;

    root->height = 1 + max(height(root->left),
        height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && key < root->left->data)
        return rightRotate(root);

    if (balance < -1 && key > root->right->data)
        return leftRotate(root);

    if (balance > 1 && key > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && key < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

bool check(node* root, int level, int leafLevel) {
    if (root == NULL) return true;
    if (root->left == NULL && root->right == NULL) {
        if (leafLevel == 0) {
            leafLevel = level;
            return true;
        }
        return (level == leafLevel);
    }

    return check(root->left, level + 1, leafLevel) && check(root->right, level + 1, leafLevel);
}

int main() {
    tree avl;
    avl.root = NULL;

    avl.root = Insert(avl.root, 12);
    avl.root = Insert(avl.root, 5);
    avl.root = Insert(avl.root, 7);
    avl.root = Insert(avl.root, 3);
    avl.root = Insert(avl.root, 1);
    

    if (check(avl.root, 0, 0) == true)
        std::cout << "Yes" << std::endl;
    else std::cout << "No" << std::endl;

    return 0;
}
