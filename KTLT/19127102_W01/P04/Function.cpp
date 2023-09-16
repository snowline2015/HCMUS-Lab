#include "Function.h"

void loadCircles(circles a[], int& n)
{
	FILE* file = fopen("input.txt", "r");
	if (file == NULL)
		std::cout << "Error while opening file";
	else {
		while (!feof(file)) {
			fscanf(file, "%d", &n);
			for (int i = 0; i < n; i++) 
				fscanf_s(file, "%d%d%lf", &a[i].x, &a[i].y, &a[i].radius);
		}
	}
}

void sumCirclesArea(circles a[], int n, double &sum)
{
	sum = 0;
	for (int i = 0; i < n; i++) 
		sum += PI * pow(a[i].radius, 2);
}

void saveCircles(circles a[], int n, double sum)
{	
	FILE* file = fopen("output.txt", "w");
	if (file == NULL)
		std::cout << "Error while opening file";
	else {
		fprintf_s(file, "%lf", sum);
		fclose(file);
	}
}