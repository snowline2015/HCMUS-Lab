#include "Function.h"

void Tower(int n, char a, char b, char c, int& i) {
    if (n == 1) {
        std::cout << "Step " << i++ << " : " << a << " ---> " << c << std::endl;
        return;
    }
    Tower(n - 1, a, c, b, i);
    Tower(1, a, b, c, i);
    Tower(n - 1, b, a, c, i);
}