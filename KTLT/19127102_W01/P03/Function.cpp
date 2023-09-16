#include "Function.h"

void loadPoint(point a[], int& n)
{
    FILE* fp = fopen("input.txt", "r");
    if (fp == NULL) {
        std::cout << "Error while opening file";
    }
    else {
        while (!feof(fp)) {
            fscanf_s(fp, "%d", &n);
            for (int i = 0; i < n; i++) {
                fscanf_s(fp, "%d%d", &a[i].x, &a[i].y);
            }
        }
    }
}

void sortPointInDescendingOrder(point a[], int n)
{
    double distance1, distance2;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j < n; j++) {
            distance1 = sqrt(pow(a[i].x, 2) + pow(a[i].y, 2));
            distance2 = sqrt(pow(a[j].x, 2) + pow(a[j].y, 2));
            if (distance1 < distance2) {
                point temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void savePoint(point a[], int n)
{
    FILE* file = fopen("output.txt", "w");
    if (file == NULL) {
        std::cout << "Error while opening file";
    }
    else {
        fprintf(file, "%d\n", n);
        for (int i = 0; i < n; i++) {
            fprintf_s(file, "%d %d\n", a[i].x, a[i].y);
        }
        fclose(file);
    }
}
