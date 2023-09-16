#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>

// String
void inputString(char str[100]);
void reverseString(char str[100], char str1[100]);
void reverseWordsInString(char str[100], char str1[100]);
void normalizeName(char str[100]);
void printIntegerInString(char str[100]);
struct hocSinh
{
	char name[100];
};
void inputStudents(hocSinh a[], int &num);
void arrangeStudents(hocSinh a[], int num);

// 2D Array
void input2DArray(int& m, int& n, int a[][100]);
void output2DArray(int m, int n, int a[][100]);
int sumOfPositiveElementsIn2DArray(int m, int n, int a[][100]);
int countMaxInMatrix(int m, int n, int a[][100]);
int countSaddleInMatrix(int m, int n, int a[][100]);
void rightShiftRotateClockwiseMatrixBoundary(int m, int n, int a[][100]);
void rotateMatrix90Degree(int m, int n, int a[][100], int& p, int& q, int b[][100]);



#endif
