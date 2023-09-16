#include "Function.h"

int main()
{
    char a = 'A', b = 'B', c = 'C';
    int n, i = 1;
    std::cout << "Input number of disks : ";
    std::cin >> n;
    Tower(n, a, b, c, i);
}