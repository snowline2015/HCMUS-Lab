#include "Function.h"

bool copyFile(std::string a, std::string b)
{
	const char* temp1 = a.c_str();
	const char* temp2 = b.c_str();
	FILE* fp = fopen(temp1, "rb");
	FILE* fs = fopen(temp2, "wb");
	if (fp == NULL) {
		std::cout << "Error while opening file" << std::endl;
		return false;
	}
	else {
		fseek(fp, 0, SEEK_END);
		long long int size = ftell(fp);
		fseek(fp, -size, SEEK_END);
		while (!feof(fp)) {
			char* buffer = new char[1025];
			fread(buffer, 1024, 1, fp);
			fwrite(buffer, 1024, 1, fs);
			delete[] buffer;
		}
		fclose(fp);
		fclose(fs);
		return true;
	}
}