#include "Function.h"

void loadDates(dates a[], int& n)
{
    FILE* fp = fopen("input.txt", "r");
    if (fp == NULL) {
        std::cout << "Error while opening file";
    }
    else {
        while (!feof(fp)) {
            fscanf_s(fp, "%d", &n);
            for (int i = 0; i < n; i++) {
                fscanf_s(fp, "%d%d%d", &a[i].year, &a[i].month, &a[i].day);
            }
        }
    }
}

void sortDatesInAscendingOrder(dates a[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j < n; j++) {
            if (a[i].year > a[j].year) {
                dates temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    for (int i = 0; i < n - 1; i++) {
        if (a[i].year == a[i + 1].year) {
            for (int j = i + 1; j < n; j++) {
                if (a[i].month > a[j].month) {
                    dates temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
    }
    for (int i = 0; i < n - 1; i++) {
        if (a[i].year == a[i + 1].year && a[i].month == a[i + 1].month) {
            for (int j = i + 1; j < n; j++) {
                if (a[i].day > a[j].day) {
                    dates temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
    }
}

void saveDates(dates a[], int n)
{
    FILE* file = fopen("output.txt", "w");
    if (file == NULL) {
        std::cout << "Error while opening file";
    }
    else {
        fprintf(file, "%d\n", n);
        for (int i = 0; i < n; i++) {
            fprintf_s(file, "%d %d %d\n", a[i].year, a[i].month, a[i].day);
        }
        fclose(file);
    }
}
