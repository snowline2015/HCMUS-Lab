#include "Function.h"

#include "Function.h"

void loadFraction(fraction a[], int& n)
{
    FILE* fp = fopen("input.txt", "r");
    if (fp == NULL) {
        std::cout << "Error while opening file";
    }
    else {
        while (!feof(fp)) {
            fscanf_s(fp, "%d", &n);
            for (int i = 0; i < n; i++) {
                fscanf_s(fp, "%d%d", &a[i].numberator, &a[i].denominator);
            }
        }
    }
}

void sortFractionInAscendingOrder(fraction a[], int n)
{
    int b, c;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j < n; j++) {
            b = a[i].numberator * a[j].denominator;
            c = a[i].denominator * a[j].numberator;
            if (b > c) {
                fraction temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void saveFraction(fraction a[], int n)
{
    FILE* file = fopen("output.txt", "w");
    if (file == NULL) {
        std::cout << "Error while opening file";
    }
    else {
        fprintf(file, "%d\n", n);
        for (int i = 0; i < n; i++) {
            fprintf_s(file, "%d %d\n", a[i].numberator, a[i].denominator);
        }
        fclose(file);
    }
}
