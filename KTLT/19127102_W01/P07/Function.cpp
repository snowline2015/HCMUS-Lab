#include "Function.h"

void loadStudents(students a[], int& n)
{
	FILE* file = fopen("input.txt", "r");
	if (file == NULL)
		std::cout << "Error while opening file";
	else {
		while (!feof(file)) {
			fscanf_s(file, "%d", &n);
			for (int i = 0; i < n; i++)
				fscanf(file, "%d\n%[^\n]\n%d", &a[i].id, &a[i].fullname, &a[i].gpa);
		}
	}
}

void findStudentMaxGPA(students a[], students b[], int n)
{
	int m = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 1; j < n; j++) {
			if (a[i].id > a[j].id) {
				students temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	students max = a[0];
	for (int i = 1; i < n; i++) 
		if (a[i].gpa > max.gpa) max = a[i];
	for (int i = 0; i < n; i++) {
		if (a[i].gpa == max.gpa) {
			b[m] = a[i];
			m++;
		}
	}
}

void saveStudent(students a[], students b[], int n)
{
	FILE* file = fopen("output.txt", "w");
	if (file == NULL)
		std::cout << "Error while opening file";
	else {
		fprintf_s(file, "%d\n%s\n%d", b[0].id, b[0].fullname, b[0].gpa);
		fclose(file);
	}
}