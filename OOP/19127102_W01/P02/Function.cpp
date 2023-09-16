#include "Function.h"

void loadFile(Word& lst)
{
    std::ifstream fp;
    fp.open("input.txt");
    if (fp.fail())
        std::cout << "Error while opening file." << std::endl;
    else {
        lst.head = NULL;
        node* tempo = new node;
        getline(fp, tempo->s, ' ');
        lst.head = tempo;
        node* current = lst.head;
        while (!fp.eof()) {
            current->next = new node;
            getline(fp, current->next->s, ' ');
            current = current->next;
        }
        current->next = NULL;
        displayFileContent(lst);
        std::cout << "Number of distinct words : " << countDistinctWords(lst) << std::endl;
        fp.close();
    }
}

void displayFileContent(Word lst)
{
    for (node* current = lst.head; current != NULL; current = current->next) {
        std::cout << current->s << " ";
    }
    std::cout << std::endl;
}

int countDistinctWords(Word lst)
{
    Word lst2;
    int count = 0;
    lst2.head = lst.head;
    node* current2, * prev, * temp;
    for (current2 = lst2.head; current2 != NULL; current2 = current2->next) {
        node* tempo = lst2.head;
        while (tempo != NULL) {
            if (current2 != tempo && current2->s.compare(tempo->s) == 0) {
                temp = tempo;
                prev = lst2.head;
                while (prev->next != tempo)
                    prev = prev->next;
                prev->next = tempo->next;
                tempo = lst2.head;
                delete temp;
            }
            else tempo = tempo->next;
        }
    }
    for (current2 = lst2.head; current2 != NULL; current2 = current2->next) {
        count++;
    }
    return count;
}
