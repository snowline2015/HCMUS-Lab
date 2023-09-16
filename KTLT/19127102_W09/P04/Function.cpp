#include "Function.h"

bool splitFileParts(std::string a, std::string b, int n)
{
	const char* temp1 = a.c_str();
	//const char* temp2 = b.c_str();
	int temp = 1;
	FILE* fp = fopen(temp1, "rb");
	//FILE* fs = fopen(temp2, "wb");
	if (fp == NULL) {
		std::cout << "Error while opening file" << std::endl;
		return false;
	}
	else {
		fseek(fp, 0, SEEK_END);
		long long int size = ftell(fp);
		fseek(fp, SEEK_SET, 0);
		double sizeEachPart = size / n; 
		int lastLoop = sizeEachPart / 1024;
		while (!feof(fp)) {
			std::string part = std::to_string(temp);
			std::string str = b;
			str.std::string::append(".part").append(part);
			char* fileName = new char[str.length() + 1];
			strcpy(fileName, str.c_str());
			FILE* fs = fopen(fileName, "wb");
			int count = 0;
			while (true) {
				count++;
				char* buffer = new char[1025];
				fread(buffer, 1024, 1, fp);
				fwrite(buffer, 1024, 1, fs);
				delete[] buffer;
				if (count == lastLoop) {
					char* buffer = new char[sizeEachPart - lastLoop * 1024 + 2];
					fread(buffer, sizeEachPart - lastLoop * 1024 + 1, 1, fp);
					fwrite(buffer, sizeEachPart - lastLoop * 1024 + 1, 1, fs);
					delete[] buffer;
					break;
				}
			}
			temp++;
			delete[] fileName;
			fclose(fs);
		}
		fclose(fp);
		return true;
	}
}


bool splitFileSize(std::string a, std::string b, int n)
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
		char* buffer = new char[n + 1];
		fread(buffer, n, 1, fp);
		fwrite(buffer, n, 1, fs);
		delete[] buffer;
		fclose(fp);
		fclose(fs);
		return true;
	}
}