#include "Function.h"

void inputArray(int arr[], int& n)
{
	std::cout << "Input number of dates : ";
	std::cin >> n;
	arr[0] = n;
	int count = 1;
	for (int i = 1; i <= n * 3; i+=3) {
		std::cout << "Input day, month, year of date " << count << " : ";
		std::cin >> arr[i] >> arr[i + 1] >> arr[i + 2];
		count++;
	}
}

void saveBin(int arr[], int n)
{
	FILE* fp = fopen("input.bin", "wb");
	if (fp == NULL)
		std::cout << "Error while opening file" << std::endl;
	else fwrite(&arr, n, 1, fp);
}

void loadBin(int arr[])
{
	FILE* fp = fopen("input.bin", "rb");
	if (fp == NULL)
		std::cout << "Error while opening file" << std::endl;
	else {
		fread(&arr, sizeof(arr), 1, fp);
		fclose(fp);
	}
}

void findNewestDate(Date a[], int arr[]) {
	int count = 0;
	for (int i = 1; i <= arr[0] * 3; i+=3) {
		a[count].day = arr[i];
		a[count].month = arr[i + 1];
		a[count].year = arr[i + 2];
		count++;
	}
	for (int i = 0; i < arr[0]; i++) {
		for (int j = 1; j <= arr[0]; j++) {
			if (a[i].year < a[j].year) {
				Date temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	for (int i = 0; i < arr[0]; i++) {
		for (int j = 1; j <= arr[0]; j++) {
			if (a[i].month < a[j].month && a[i].year == a[j].year) {
				Date temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	for (int i = 0; i < arr[0]; i++) {
		for (int j = 1; j <= arr[0]; j++) {
			if (a[i].day < a[j].day && a[i].month == a[j].month && a[i].year == a[j].year) {
				Date temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}