#include <iostream>
#include <math.h>

struct point{
	double x, y;
};

void inputArrayOfPoints(point a[100], int &n)
{
	std::cout << "Input number of elemtents : ";
	std::cin >> n;
	std::cout << "Input coordinate of points : " << std::endl;
	for (int i = 0; i < n; i++) {
		std::cout << "Point " << i + 1 << " : ";
		std::cin >> a[i].x >> a[i].y;
	}
}

void outputArrayOfPoints(point a[100], int n) 
{
	for (int i = 0; i < n; i++) {
		std::cout << "Point " << i + 1 << " (" << a[i].x << ", " << a[i].y << ")" << std::endl;
	}
}

int countPositiveCoordinates(point a[100], int n)
{
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (a[i].x > 0 && a[i].y > 0) count++;
	}
	return count;
}

void findLargestAndSmallestXComponentValue(point a[100], int n, point &max, point &min)
{
	int temp1, temp2;
	max = a[0]; 
	min = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i].x > max.x) {
			max = a[i];
			temp1 = i;
		}
		if (a[i].x < min.x) {
			min = a[i];
			temp2 = i;
		}
	}
	std::cout << "The point has the largest X-component value : Point " << temp1 + 1 << std::endl;
	std::cout << "The point has the smallest X-component value : Point " << temp2 + 1 << std::endl;
}

int main()
{
	point a[100], max, min;
	int n;
	inputArrayOfPoints(a, n);
	outputArrayOfPoints(a, n);
	std::cout << "Points have posivite coords : " << countPositiveCoordinates(a, n) << std::endl;
	findLargestAndSmallestXComponentValue(a, n, max, min);
	return 0;
}