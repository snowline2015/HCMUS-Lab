#include <iostream>
#include <string>
#include <fstream>

struct Monster {
    std::string name = "";
    long long int phone = 0;
};

class LinearProbing {
private:
    Monster hashTable[21];
    int hashTableSize = 21;
public:
    LinearProbing() { 
        for (int i = 0; i < hashTableSize; i++) {
            hashTable[i].name = "";
            hashTable[i].phone = 0;
        }
    }
    ~LinearProbing() {
        for (int i = 0; i < hashTableSize; i++) {
            hashTable[i].name = "";
            hashTable[i].phone = 0;
        }
    }

    int hashCode(std::string s) {
        int sti = 0;
        for (int i = 0; i < s.length(); i++) 
            sti += s[i];
        return sti;
    }

    int h(int val) { return val % this->hashTableSize; }

    void add(Monster m, long long int p) {
        int hashIndex = h(hashCode(m.name));
        while (hashTable[hashIndex].name != "" && hashTable[hashIndex].phone != 0) {
            hashIndex++;
            hashIndex %= this->hashTableSize;
        }
        hashTable[hashIndex] = m;
    }

    long long int find(Monster m) {
        int index = h(hashCode(m.name));
        while (hashTable[index].name != m.name && hashTable[index].name != "" && hashTable[index].phone != 0)
            index = (index + 1) % hashTableSize;
        if (hashTable[index].name.compare(m.name) == 0)
            return hashTable[index].phone;
        else return NULL;
    }

    bool Delete(Monster m) {
        int index = h(hashCode(m.name));
        while (hashTable[index].name != m.name && hashTable[index].name != "" && hashTable[index].phone != 0)
            index = (index + 1) % hashTableSize;
        if (hashTable[index].name.compare(m.name) == 0) {
            hashTable[index].name = "";
            hashTable[index].phone = 0;
            return true;
        }
        else return false; 
    }

    bool Updates(Monster m, long long int p) {
        int index = h(hashCode(m.name));
        while (hashTable[index].name != m.name && hashTable[index].name != "" && hashTable[index].phone != 0)
            index = (index + 1) % hashTableSize;
        if (hashTable[index].name == m.name) {
            hashTable[index].phone = p;
            return true;
        }
        else return false;
    }

    void readFile() {
        std::ifstream fp("phonebook.txt");
        if (fp.fail()) {
            std::cout << "Cannot open file !" << std::endl;
            return;
        }
        std::string str;
        Monster mon;
        while (!fp.eof()) {
            std::getline(fp, str, '\n');
            if (str != "") {
                for (int i = str.length(); i > 0; i--) {
                    if (str[i] == ' ') {
                        mon.name = str.substr(0, i);
                        mon.phone = stoll(str.substr(i + 1));
                        add(mon, mon.phone);
                        break;
                    }
                }
            }
        }
        fp.close();
    }
};

int main() {
    LinearProbing list;
    list.readFile();

    std::string str;
    Monster monster;
    
    std::cout << "\nInput monster's name to add: ";
    std::getline(std::cin, monster.name);
    std::cout << "Input monster's phone number to add: ";
    std::cin >> monster.phone;
    std::cin.ignore(1);
    list.add(monster, monster.phone);

    std::cout << "\nInput monster's name to delete: ";
    std::getline(std::cin, monster.name);
    if (list.Delete(monster))
        std::cout << monster.name << " deleted succesfully!" << std::endl;
    else std::cout << monster.name << " not found!" << std::endl;

    std::cout << "\nInput monster's name to find: ";
    std::getline(std::cin, monster.name);
    if (list.find(monster) == NULL)
        std::cout << monster.name << " not found!" << std::endl;
    else std::cout << monster.name << "'s phone number: " << list.find(monster) << std::endl;

    std::cout << "\nInput monster's name to update: ";
    std::getline(std::cin, monster.name);
    std::cout << "Input new monster's phone number to update: ";
    std::cin >> monster.phone;
    std::cin.ignore(1);
    if (list.Updates(monster, monster.phone))
        std::cout << monster.name << " updated succesfully!" << std::endl;
    else std::cout << monster.name << " not found!" << std::endl;

    return 0;
}