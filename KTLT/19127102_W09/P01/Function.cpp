#include "Function.h"

void inputArray(int arr[], int& n)
{
	std::cout << "Input number of elements : ";
	std::cin >> n;
	arr[0] = n;
	std::cout << "Input elements :\n";
	for (int i = 1; i <= n; i++) 
		std::cin >> arr[i];
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

double findMedian(int arr[])
{
	for (int i = 1; i < arr[0]; i++) {
		for (int j = i + 1; j < arr[0] + 1; j++) {
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	int temp = arr[0] / 2;
	if (arr[0] % 2 == 0) 
		return (double)(arr[temp] + arr[temp + 1]) / 2;
	else return (int)arr[temp + 1];
}