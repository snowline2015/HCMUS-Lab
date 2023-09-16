#include "Function.h"

int main(int argc, const char* argv[])
{
	//argc = 7;
	if (argc != 7) {
		std::cout << "This is not recognized as an internal or external command.\n";
		std::cout << "Try typing the right format.\n"
			<< "E.g. P04.exe -s C:\\\\LOL.exe -d C:\\\\Users\\\\ASUS\\\\Desktop -numpart 3" << std::endl;
		return 0;
	}

	//argv[2] = "D:\\ASUS\\Documents\\438_emiri_04_800.jpg";
	//argv[4] = "D:";
	//argv[5] = "-numpart";
	//argv[6] = "3";
	std::string sourceFilePath = argv[2],
		destinationPath = argv[4],
		temp = argv[6];
	
	for (int32_t i = sourceFilePath.std::string::length() - 1; i >= 0; i--) {
		if (sourceFilePath[i] == '\\') {
			destinationPath.std::string::append(sourceFilePath.std::string::substr(i));
			break;
		}
	}
	if (strcmp(argv[5],"-numpart") == 0) {
		int parts = std::stoi(temp);
		if (splitFileParts(sourceFilePath, destinationPath, parts) == true)
			std::cout << "Splitted successfully" << std::endl;
		else std::cout << "Try typing the right format.\n"
			<< "E.g. P03.exe -s C:\\\\LOL.exe -d C:\\\\Users\\\\ASUS\\\\Desktop -numpart 3" << std::endl;
	}
	else {
		int size = std::stoi(temp);
		if (splitFileSize(sourceFilePath, destinationPath, size) == true)
			std::cout << "Splitted successfully" << std::endl;
		else std::cout << "Try typing the right format.\n"
			<< "E.g. P03.exe -s C:\\\\LOL.exe -d C:\\\\Users\\\\ASUS\\\\Desktop -sizeapart 1000000" << std::endl;
	}
	return 0;
}