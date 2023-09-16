#include <iostream> 
#include <string>

struct node {
	Data* data;
	node* next, * ok;
};

class Data {
public:
	std::string name;
	int level;
	virtual std::string GetName() = 0;
	virtual double GetSize() = 0;
	//virtual void Show() = 0;
};

class Folder : public Data {
protected:
	node* pHead;
public:
	Folder() { pHead = NULL; }
	Folder(std::string a) { pHead = NULL; name = a; level = 0; }
	void AddFolder(Data* a) {
		if (this->pHead != NULL) {
			node* current = this->pHead;
			while (current->next != NULL) current = current->next;
			current->next = new node;
			current = current->next;
			current->data = new Folder;
			current->data = a;
			current->next = NULL;
		}
		else {
			node* temp = new node;
			temp->data = new Folder;
			temp->data = a;
			temp->next = NULL;
			this->pHead = temp;
		}
	}
	void AddFile(Data* a) {
		if (this->pHead != NULL) {
			node* current = this->pHead;
			while (current->ok != NULL) current = current->ok;
			current->ok = new node;
			current = current->next;
			current->data = new File;
			current->data = a;
			current->ok = NULL;
		}
		else {
			node* temp = new node;
			temp->data = new File;
			temp->data = a;
			temp->ok = NULL;
			this->pHead = temp;
		}
	}
	std::string GetName() { return name; }
	double GetSize() {
		double size = 0;
		node* current = this->pHead;
		while (current != NULL) {
			if (current->data->level == 0 && current->ok != NULL) {
				node* temp = current->ok;
				while (temp != NULL) {
					size += temp->ok->data->GetSize();
					temp = temp->ok;
				}
			}
			current = current->next;
		}
		return size;
	}
	int CountFolder() {
		int count = 0;
		node* current = this->pHead;
		while (current != NULL) {
			if (current->data->level == 0) count++;
			current = current->next;
		}
		return count;
	}
	int CountFile() {
		int count = 0;
		node* current = this->pHead;
		while (current != NULL) {
			if (current->data->level == 1) count++;
			current = current->next;
		}
		return count;
	}
	/*void Show() {
		node* current = pHead;
		while (current != NULL) {
			if (current->data->level == 0) 
				std::cout << "[" << current->data->GetName << "]" << std::endl;
			current->data->Show();
			current = current->next;
		}
	}*/
	
};

class File : public Data {
protected:
	double size;
public:
	File() { name = ""; size = 0; level = 1; }
	File(std::string a, double b) {
		name = a;
		size = b;
		level = 1;
	}
	std::string GetName() { return name; }
	double GetSize() { return size; }
	void SetName(std::string a) {}
	void Show() { std::cout << "[" << name << "]\t" << size << std::endl; }
};

void main() {
	Folder a("C:");
	Folder b("Bai tap");
	Folder c("Bai tap C");
	Folder d("Ly thuyet");
	File e("BT1.doc", 123.456);
	File f("BT2.cpp", 1.280);
	File g("BT2.xls", 23.456);
	File h("Ch1.ppt", 34567);
	a.AddFolder(&b); a.AddFolder(&d);
	b.AddFile(&e); b.AddFile(&g);
	b.AddFolder(&c);
	c.AddFile(&f);
	d.AddFile(&h);
	//a.ShowFolder();
	std::cout << "So tap tin va thu muc co trong [C:]: " << a.CountFile() << "   -   " << a.CountFolder() << std::endl;
	std::cout << "So tap tin va thu muc co trong [Bai tap]: " << b.CountFile() << "   -   " << b.CountFolder() << std::endl;
	std::cout << "So tap tin va thu muc co trong [Bai tap C]: " << c.CountFile() << "   -   " << c.CountFolder() << std::endl;
	std::cout << "So tap tin va thu muc co trong [Ly thuyet]: " << d.CountFile() << "   -   " << d.CountFolder() << std::endl;
	std::cout << "Kich thuoc cua [C:]: " << a.GetSize() << std::endl;
	std::cout << "Kich thuoc cua [Bai tap]: " << b.GetSize() << std::endl;
	std::cout << "Kich thuoc cua [Bai tap C]: " << c.GetSize() << std::endl;
	std::cout << "Kich thuoc cua [Ly thuyet]: " << d.GetSize() << std::endl;
}

