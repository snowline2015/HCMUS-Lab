#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <iostream>
#include <math.h>
#include <iomanip>

void inputArray(int a[100], int n);
void outputArray(int a[100], int n);
void findLargestEvenSmallestOddNums(int a[100], int n, int b[100], int& m, int c[100], int& p, int& max, int& min);
double averageEvenNums(int a[100], int n);
void findPrimeNums(int a[100], int n, int b[100], int& m);
void arrangeIncreasingEvenNums(int a[100], int n);
void checkArraySorted(int a[100], int n, int &ans);
int countDifferentElements(int a[100], int n);
int findSecondLargestElement(int a[100], int n);
void reverseArray(int a[100], int n, int b[100], int &m);
void mix2ArraysWithoutReduction(int a[100], int n, int b[100], int& m, int c[100], int& p);
void findElementsAppearOnBothArrays(int a[100], int n, int b[100], int& m, int c[100], int& p);

#endif
