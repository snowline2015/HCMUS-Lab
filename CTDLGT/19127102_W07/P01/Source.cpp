#include <iostream>
#include <vector>

class ChainingMethod {
private:
	std::vector<int> hashTable[20];
	int hashTableSize = 20;
public:
    int hashFunc(int val) { return val % this->hashTableSize; }
    void insert(int s) {
        int index = hashFunc(s);
        hashTable[index].push_back(s);
    }
    void search(int s) {
        int index = hashFunc(s);
        for (int i = 0; i < hashTable[index].size(); i++) {
            if (hashTable[index][i] == s) {
                std::cout << s << " found!" << std::endl;
                return;
            }
        }
        std::cout << s << " not found!" << std::endl;
    }
};

class LinearProbing {
private:
    int hashTable[21];
    int hashTableSize = 21;
public:
    LinearProbing() { memset(hashTable, NULL, sizeof(hashTable)); }
    ~LinearProbing() { memset(hashTable, NULL, sizeof(hashTable)); }
    int hashFunc(int val) { return val % this->hashTableSize; }
    void insert(int s) {
        int hashIndex = hashFunc(s);
        while (hashTable[hashIndex] != NULL) {
            hashIndex++;
            hashIndex %= this->hashTableSize;
        }
        hashTable[hashIndex] = s;
    }
    void search(int s) {
        int index = hashFunc(s);
        while (hashTable[index] != s && hashTable[index] != NULL)
            index = (index + 1) % hashTableSize;
        if (hashTable[index] == s)
            std::cout << s << " found!" << std::endl;
        else
            std::cout << s << " not found!" << std::endl;
    }
};

class QuadraticProbing {
private:
    int hashTable[21];
    int hashTableSize = 21;
public:
    QuadraticProbing() { memset(hashTable, NULL, sizeof(hashTable)); }
    ~QuadraticProbing() { memset(hashTable, NULL, sizeof(hashTable)); }
    int hashFunc(int val) { return val % this->hashTableSize; }
    void insert(int s) {
        int index = hashFunc(s);
        int h = 1;
        while (hashTable[index] != NULL)
        {
            index = (index + h * h) % hashTableSize;
            h++;
        }
        hashTable[index] = s;
    }
    void search(int s) {
        int index = hashFunc(s);
        int h = 1;
        while (hashTable[index] != s && hashTable[index] != NULL)
        {
            index = (index + h * h) % hashTableSize;
            h++;
        }
        if (hashTable[index] == s)
            std::cout << s << " found!" << std::endl;
        else
            std::cout << s << " not found!" << std::endl;
    }
};

class DoubleHashing {
private:
    int hashTable[21];
    int hashTableSize = 21;
    const int prime = 7;      // must be smaller than hashTableSize
public:
    DoubleHashing() { memset(hashTable, NULL, sizeof(hashTable)); }
    ~DoubleHashing() { memset(hashTable, NULL, sizeof(hashTable)); }
    int hashFunc1(int val) { return val % this->hashTableSize; }
    int hashFunc2(int val) { return this->prime - (val % this->prime); }
    void insert(int s) {
        int index = hashFunc1(s);
        int indexH = hashFunc2(s);
        while (hashTable[index] != NULL)
            index = (index + indexH) % hashTableSize;
        hashTable[index] = s;
    }
    void search(int s) {
        int index = hashFunc1(s);
        int indexH = hashFunc2(s);
        while (hashTable[index] != s && hashTable[index] != NULL)
            index = (index + indexH) % hashTableSize;
        if (hashTable[index] == s)
            std::cout << s << " found!" << std::endl;
        else
            std::cout << s << " not found!" << std::endl;
    }
};

int main() {
    ChainingMethod hash1;
    hash1.insert(1);
    hash1.insert(2);
    hash1.insert(3);
    hash1.insert(4);
    hash1.insert(5);
    hash1.insert(6);
    hash1.insert(7);
    hash1.insert(8);
    hash1.insert(9);
    hash1.insert(10);

    hash1.search(3);

    LinearProbing hash2;
    hash2.insert(1);
    hash2.insert(2);
    hash2.insert(3);
    hash2.insert(4);
    hash2.insert(5);
    hash2.insert(6);
    hash2.insert(7);
    hash2.insert(8);
    hash2.insert(9);
    hash2.insert(10);

    hash2.search(3);


    QuadraticProbing hash3;
    hash3.insert(1);
    hash3.insert(2);
    hash3.insert(3);
    hash3.insert(4);
    hash3.insert(5);
    hash3.insert(6);
    hash3.insert(7);
    hash3.insert(8);
    hash3.insert(9);
    hash3.insert(10);

    hash3.search(3);


    DoubleHashing hash4;
    hash4.insert(1);
    hash4.insert(2);
    hash4.insert(3);
    hash4.insert(4);
    hash4.insert(5);
    hash4.insert(6);
    hash4.insert(7);
    hash4.insert(8);
    hash4.insert(9);
    hash4.insert(10);

    hash4.search(3);
    return 0;
}