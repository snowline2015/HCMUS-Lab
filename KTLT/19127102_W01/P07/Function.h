#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>

struct students
{
	int id, gpa;
	char fullname[101];
};
void loadStudents(students a[], int& n);
void findStudentMaxGPA(students a[], students b[], int n);
void saveStudent(students a[], students b[], int n);


#endif