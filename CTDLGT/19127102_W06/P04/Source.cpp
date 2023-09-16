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

node* LeastCommonAncestor(node* root, int n1, int n2) {
    if (root == NULL) return NULL;

    if (root->data > n1 && root->data > n2)
        return LeastCommonAncestor(root->left, n1, n2);

    if (root->data < n1 && root->data < n2)
        return LeastCommonAncestor(root->right, n1, n2);

    return root;
}

int main() {
    tree avl;
    avl.root = NULL;

    avl.root = Insert(avl.root, 20);
    avl.root = Insert(avl.root, 8);
    avl.root = Insert(avl.root, 22);
    avl.root = Insert(avl.root, 4);
    avl.root = Insert(avl.root, 12);
    avl.root = Insert(avl.root, 10);
    avl.root = Insert(avl.root, 14);

    int n1 = 8, n2 = 4;
    node* ok = LeastCommonAncestor(avl.root, n1, n2);
    std::cout << "Lowest common ancestor of " << n1 << " and " << n2 << " is " << ok->data << std::endl;

    n1 = 22, n2 = 8;
    ok = LeastCommonAncestor(avl.root, n1, n2);
    std::cout << "Lowest common ancestor of " << n1 << " and " << n2 << " is " << ok->data << std::endl;

    n1 = 14, n2 = 22;
    ok = LeastCommonAncestor(avl.root, n1, n2);
    std::cout << "Lowest common ancestor of " << n1 << " and " << n2 << " is " << ok->data << std::endl;
    return 0;
   
}
