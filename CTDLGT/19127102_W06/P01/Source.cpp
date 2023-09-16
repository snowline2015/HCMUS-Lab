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

node* doubleLeftRotate(node*& t) {
    t->right = rightRotate(t->right);
    return leftRotate(t);
}

node* doubleRightRotate(node*& t) {
    t->left = leftRotate(t->left);
    return rightRotate(t);
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

void PreOrder(node* root) {
    if (root != NULL) {
        std::cout << root->data << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void PostOrder(node* root) {
    if (root == NULL)
        return;
    PostOrder(root->left);
    PostOrder(root->right);
    std::cout << root->data << " ";
}

void InOrder(node* root) {
    if (root == NULL)
        return;
    InOrder(root->left);
    std::cout << root->data << " ";
    InOrder(root->right);
}

node* minValueNode(node* root)
{
    node* current = root;
    while (current->left != NULL)
        current = current->left;
    return current;
}

node* Delete(node* root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = Delete(root->left, key);

    else if (key > root->data)
        root->right = Delete(root->right, key);

    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            node* temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            }
            else 
                *root = *temp; 
            free(temp);
        }
        else {
            node* temp = minValueNode(root->right);
            root->data = temp->data; 
            root->right = Delete(root->right, temp->data);
        }
    }

    if (root == NULL) return root;
 
    root->height = 1 + max(height(root->left),
        height(root->right));

    int balance = getBalance(root);

    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

bool Search(node* root, int key) {
    while (root != NULL) {
        if (key > root->data)
            root = root->right;
        else if (key < root->data)
            root = root->left;
        else 
            return true;
    }
    return false;
}

int main() {
    tree avl;
    avl.root = NULL;

    avl.root = Insert(avl.root, 50);
    avl.root = Insert(avl.root, 10);
    avl.root = Insert(avl.root, 15);
    avl.root = Insert(avl.root, 23);
    avl.root = Insert(avl.root, 22);
    avl.root = Insert(avl.root, 35);
    avl.root = Insert(avl.root, 70);
    avl.root = Insert(avl.root, 3);
    avl.root = Insert(avl.root, 12);
    avl.root = Insert(avl.root, 18);
    avl.root = Insert(avl.root, 24);
    avl.root = Insert(avl.root, 31);
    avl.root = Insert(avl.root, 48);
    avl.root = Insert(avl.root, 63);
    avl.root = Insert(avl.root, 93);
    avl.root = Insert(avl.root, 20);

    std::cout << "NLR: ";
    PreOrder(avl.root);
    std::cout << "\n\nLRN: ";
    PostOrder(avl.root);
    std::cout << "\n\nLNR: ";
    InOrder(avl.root);
    std::cout << std::endl;

    avl.root = Delete(avl.root, 22);
    avl.root = Delete(avl.root, 20);
    avl.root = Delete(avl.root, 12);
    avl.root = Delete(avl.root, 23);
    avl.root = Delete(avl.root, 70);

    std::cout << "\nNLR: ";
    PreOrder(avl.root);

    std::cout << "\n\nHeight: " << height(avl.root) << std::endl;

    int key;
    std::cout << "\nInput value to check: ";
    std::cin >> key;
    if (Search(avl.root, key))
        std::cout << key << " exists in tree" << std::endl;
    else std::cout << key << " not exists in tree" << std::endl;

    avl.root = doubleLeftRotate(avl.root);
    std::cout << "\nNLR: ";
    PreOrder(avl.root);

    avl.root = doubleRightRotate(avl.root);
    std::cout << "\nNLR: ";
    PreOrder(avl.root);

    return 0;
}