#include "Function.h"

void loadProducts(products a[], int& n)
{
	FILE* file = fopen("input.txt", "r");
	if (file == NULL) {
		std::cout << "Error while opening file";
	}
	else {
		while (!feof(file)) {
			fscanf_s(file, "%d", &n);
			for (int i = 0; i < n; i++) {
				fscanf(file, "%d\n%[^\n]\n%d%d", &a[i].id, &a[i].name, &a[i].stock, &a[i].price);
			}
		}
	}
}

void total(products a[], int n, long int &money)
{
	money = 0;
	for (int i = 0; i < n; i++) {
		money += a[i].price * a[i].stock;
	}
}

void saveProducts(products a[], int n, long int money)
{
	FILE* file = fopen("output.txt", "w");
	if (file == NULL)
		std::cout << "Error while opening file";
	else {
		fprintf_s(file, "%d", money);
		fclose(file);
	}
}