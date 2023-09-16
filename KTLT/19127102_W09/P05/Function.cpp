#include "Function.h"

int mergeFiles(std::string a, std::string b, std::string c)
{
	int temp = 1;;
	const char* temp1 = a.c_str();
	const char* temp2 = b.c_str();
	//const char* temp3 = c.c_str();
	std::string str2 = b;
	str2.std::string::append("\\").append(c);
	char* mergePath = new char[str2.length() + 1];
	strcpy(mergePath, str2.c_str());
	FILE* fs = fopen(mergePath, "wb");
	while (true) {
		std::string str1 = a;
		str1.std::string::append("\\").append(c);
		std::string part = std::to_string(temp);
		str1.std::string::append(".part").append(part);
		char* partsPath = new char[str1.length() + 1];
		strcpy(partsPath, str1.c_str());

		FILE* fp = fopen(partsPath, "rb");
		if (fp == NULL) {
			int m = temp + 1;
			
			while (true) {
				std::string strtemp = a;
				std::string ext = std::to_string(m);
				strtemp.std::string::append("\\").append(c).append(".part").append(ext);
				char* strtemptemp = new char[strtemp.length() + 1];
				strcpy(strtemptemp, strtemp.c_str());
				FILE* fwhat = fopen(strtemptemp, "rb");
				if (fwhat != NULL) {
					std::cout << "Part " << temp << " is missing.";
					fclose(fs);
					fclose(fwhat);
					return -1;
				}
				m++;
				if (m - temp >= 5) break;
			}
			if (m - temp >= 5) 
				break;
			else return 0;
		}
		else {
			int count = 0;
			fseek(fp, 0, SEEK_END);
			long long int size = ftell(fp);
			fseek(fp, SEEK_SET, 0);
			int lastLoop = size / 1024;
			while (!feof(fp)) {
				count++;
				char* buffer = new char[1025];
				fread(buffer, 1024, 1, fp);
				fwrite(buffer, 1024, 1, fs);
				delete[] buffer;
				if (count == lastLoop) {
					char* buffer = new char[size - lastLoop * 1024 + 1];
					fread(buffer, size - lastLoop * 1024, 1, fp);
					fwrite(buffer, size - lastLoop * 1024, 1, fs);
					delete[] buffer;
					break;
				}
			}
			delete[] partsPath;
			temp++;
			fclose(fp);
		}
	}
	fclose(fs);
	return 1;
}