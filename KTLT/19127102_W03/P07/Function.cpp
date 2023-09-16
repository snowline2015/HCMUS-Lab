#include "Function.h"

void loadAnswers(char *&a, char *&b, int& n)
{
    //char temp[21];
    a = new char[21];
    b = new char[21];
    FILE* correct = fopen("correctanswer.txt", "r");
    if (correct == NULL) {
        std::cout << "Error while opening file correct answers";
    }
    else {
        while (!feof(correct)) {
            fscanf_s(correct, "%d", &n);
            for (int i = 0; i < n; i++) {
                fscanf(correct, "%c\n", &a[i]);
            }
        }
    }
    FILE* student = fopen("studentanswer.txt", "r");
    if (student == NULL) {
        std::cout << "Error while opening file student's answers";
    }
    else {
        while (!feof(student)) {
            fscanf_s(student, "%d", &n);
            for (int i = 0; i < n; i++) {
                fscanf(student, "%c\n", &b[i]);
            }
        }
    }
    fclose(correct); fclose(student);
}

int calculateCorrectAnswer(char* a, char* b, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] == a[i]) count++;
    }
    double percentage = count * 100 / n;
    std::cout << std::fixed << std::setprecision(1) << percentage << "%" << std::endl;
    delete[] a; delete[] b;
    if (percentage >= 70) return 1;
    else return 0;
}

