#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
 
int main() {
    FILE* fp = fopen("output.txt", "w");
    if (fp == NULL) 
        std::cout << "Error while opening file." << std::endl;
    else {
        fprintf(fp, "Hello, Word\n");
        fclose(fp);
    }  
    return 0;
}