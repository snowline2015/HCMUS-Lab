#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <iostream>
#include <math.h>
#include <iomanip>

bool isPerfect(int n);
bool isPrime(int m);
int biggest(long long int p);
int solveQuadratic(double a, double b, double c, double& x1, double& x2);
void tomorrow(int day, int month, int year, int& day2, int& month2, int& year2);
void yesterday(int day, int month, int year, int& day2, int& month2, int& year2);
bool checkAllEven(long long int q);
int findGreatestCommonDivisior(int a, int b, int &max);
void findPrimeFactors(int w);
int findNearestPrimeNum(int e);

#endif

