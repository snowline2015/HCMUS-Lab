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

void maxFraction(fraction a[], int n, fraction &max)
{
    int b, c;
    max = a[0];
    for (int i = 1; i < n; i++) {
        b = max.numberator * a[i].denominator;
        c = max.denominator * a[i].numberator;
        if (c > b) max = a[i];
    }
}

void saveFraction(fraction a[], int n, fraction max)
{
    FILE* file = fopen("output.txt", "w");
    if (file == NULL) {
        std::cout << "Error while opening file";
    }
    else {
        fprintf_s(file, "%d %d\n", max.numberator, max.denominator);
        fclose(file);
    }
}
