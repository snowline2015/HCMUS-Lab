#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <stack>
#include <vector>
#include <conio.h>

// Key is code //   <<<<<<<<<<<<<<<<<<<<<<<<<

struct student {
	std::string id, name, birthday;
	bool status;
};

struct node {
	student* data;
	node* left,
		* right;
};

struct Manager {
	node* root;
};

std::string lowercase(const std::string& in)
{
    std::string out;
    std::transform(in.begin(), in.end(), std::back_inserter(out), ::tolower);
    return out;
}

student InputStudent() {
    student stu;
    std::cout << "Name: ";
    std::getline(std::cin, stu.name);
    std::cout << "Code: ";
    std::getline(std::cin, stu.id);
    std::cout << "Birthday: ";
    std::getline(std::cin, stu.birthday);
    std::cout << "Status (0: Undergrad; 1: Graduate): ";
    std::cin >> stu.status;
    std::cin.ignore(1);
    return stu;
}

int Left(student stu, node* root) { return stoi(stu.id) <= stoi(root->data->id); }

int Right(student stu, node* root) { return stoi(stu.id) > stoi(root->data->id); }

student* LeftMost(const node* root) {
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

node* AddStudent(node*& root, student stu) {
    if (root == NULL) {
        node* Node = new node;
        Node->left = Node->right = NULL;
        Node->data = new student(stu);
        return Node;
    }
    if (Left(stu, root))
        root->left = AddStudent(root->left, stu);
    else if (Right(stu, root))
        root->right = AddStudent(root->right, stu);
    return root;
}

bool FindAndUpdate(node* root, std::string code)
{
    while (root != NULL) {
        if (stoi(code) > stoi(root->data->id))
            root = root->right;
        else if (stoi(code) < stoi(root->data->id))
            root = root->left;
        else {
            std::cout << "Student found !!!\nDo you want to update this student's info ? (Y/N)";
            char c = _getch();
            if (c == 'y' || c == 'Y') {
                fflush(stdin);
            }
            else return true; 
            int option;
            std::cout << "\n1. Name\n2. Code\n3. Birthday\n4. Status\nChoose your option: ";
            std::cin >> option;
            switch (option) {
            case 1: {
                std::cout << "Input new name: ";
                std::getline(std::cin, root->data->name);
                std::cout << "Change successfully" << std::endl;
                break;
            }
            case 2: {
                std::cout << "Input new code: ";
                std::getline(std::cin, root->data->id);
                std::cout << "Change successfully" << std::endl;
                break;
            }
            case 3: {
                std::cout << "Input new birthday: ";
                std::getline(std::cin, root->data->birthday);
                std::cout << "Change successfully" << std::endl;
                break;
            }
            case 4: {
                std::cout << "Input new status(0: Undergrad; 1: Graduate): ";
                std::cin >> root->data->status;
                std::cout << "Change successfully" << std::endl;
                std::cin.ignore(1);
                break;
            }
            default: break;
            }
            return true; 
        }
    }
    std::cout << "Student not found !!!" << std::endl;
    return false;
}

void PostOrder(node* root, std::vector<student*>& lst) {
    if (root == NULL)
        return;
    PostOrder(root->left, lst);
    PostOrder(root->right, lst);
    lst.push_back(root->data);
}

bool compareString(const student* a, const student* b) { return lowercase(a->name) < lowercase(b->name); }

void ListAllStudentLexicographicOrder(node* root) {
    std::vector<student*> list;
    PostOrder(root, list);
    std::sort(list.begin(), list.end(), compareString);
    for (std::vector<student*>::iterator p = list.begin(); p != list.end(); p++) {
        std::cout << (*p)->name << "  ###  " << (*p)->id << "  ###  " << (*p)->birthday << "  ###  " << (*p)->status << std::endl;
    }
}

void ListAllGraduated(node* root) {
    std::vector<student*> list;
    PostOrder(root, list);
    for (std::vector<student*>::iterator p = list.begin(); p != list.end(); p++) {
        if ((*p)->status == true)
            std::cout << (*p)->name << "  ###  " << (*p)->id << "  ###  " << (*p)->birthday << "  ###  " << (*p)->status << std::endl;
    }
}

node* DeletionByCode(node*& root, std::string code) {
    if (root == NULL) return root;
    else if (code < root->data->id) root->left = DeletionByCode(root->left, code);
    else if (code > root->data->id) root->right = DeletionByCode(root->right, code);

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
            root->right = DeletionByCode(root->right, temp->data->id);
        }
    }
    return root;
}

void DeleteAll(node*& root) {
    if (root != NULL) {
        DeleteAll(root->left);
        DeleteAll(root->right);
        delete root;
        root = NULL;
    }
}

void DeleteAllGraduated(node* &root) {
    std::vector<student*> list;
    PostOrder(root, list);
    for (std::vector<student*>::iterator p = list.begin(); p != list.end(); p++) {
        if ((*p)->status == true) {
            list.erase(p);
            p = list.begin();
        }
    }
    DeleteAll(root);
    for (std::vector<student*>::iterator p = list.begin(); p != list.end(); p++) {
        student stu;
        stu.name = (*p)->name;
        stu.id = (*p)->id;
        stu.birthday = (*p)->birthday;
        stu.status = (*p)->status;
        root = AddStudent(root, stu);
    }
}

unsigned int CountNodeTree(const node* root) {
    unsigned int count = 1;
    if (root->left != NULL) {
        count += CountNodeTree(root->left);
    }
    if (root->right != NULL) {
        count += CountNodeTree(root->right);
    }
    return count;
}

void SaveAll(node* root) {
    std::ofstream fs("student.data");
    if (fs.fail()) {
        std::cout << "Cannot open file" << std::endl;
        return;
    }
    fs << CountNodeTree(root) << std::endl;
    if (root == NULL)
        return;

    std::stack<node*> nodeStack;
    nodeStack.push(root);

    while (nodeStack.empty() == false) {
        struct node* node = nodeStack.top();
        
        fs << node->data->id << "\n" << node->data->name << "\n" << node->data->birthday << "\n" << node->data->status << "\n";

        nodeStack.pop();

        if (node->right)
            nodeStack.push(node->right);
        if (node->left)
            nodeStack.push(node->left);
    }
    fs.close();
    std::cout << "Save successfully" << std::endl;
}

void LoadContent(std::ifstream& fp, node*& root) {
    std::string temp;
    bool status;
    std::getline(fp, temp, '\n');
    student stu;
    while (!fp.eof()) {
        std::getline(fp, stu.id, '\n');
        if (stu.id.compare("") == 0) break;
        std::getline(fp, stu.name, '\n');
        std::getline(fp, stu.birthday, '\n');
        fp >> stu.status;
        root = AddStudent(root, stu);
    }
    fp.close();
    std::cout << "student.data exists. Load successfully" << std::endl;
}

int main() {
    Manager manager;
    manager.root = NULL;
    std::ifstream fp("student.data");
    if (fp.is_open()) {
        LoadContent(fp, manager.root);
    }
    int option;
    while (true) {
        std::cout << "1. Add new student" << std::endl;
        std::cout << "2. Find and update student by code" << std::endl;
        std::cout << "3. List student in lexicographic order" << std::endl;
        std::cout << "4. List all graduated students" << std::endl;
        std::cout << "5. Delete an student by given code" << std::endl;
        std::cout << "6. Delete all graduated students" << std::endl;
        std::cout << "7. Save to student.data" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Enter your option: ";
        std::cin >> option;
        std::cin.ignore(1);
        if (option == 0) break;
        else if (option == 1) {
            student stu = InputStudent();
            manager.root = AddStudent(manager.root, stu);
        }
        else if (option == 2) {
            std::string temp;
            std::cout << "Input code: ";
            std::getline(std::cin, temp);
            FindAndUpdate(manager.root, temp);
        }
        else if (option == 3) {
            ListAllStudentLexicographicOrder(manager.root);
        }
        else if (option == 4) {
            ListAllGraduated(manager.root);
        }
        else if (option == 5) {
            std::string temp;
            std::cout << "Input code: ";
            std::getline(std::cin, temp);
            manager.root = DeletionByCode(manager.root, temp);
        }
        else if (option == 6) {
            DeleteAllGraduated(manager.root);
        }
        else if (option == 7) {
            SaveAll(manager.root);
        }
        else {
            std::cout << "Invalid option" << std::endl;
        }
    }
	return 0;
}