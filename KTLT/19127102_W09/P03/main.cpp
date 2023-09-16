#include "Function.h"

int main(int argc, const char* argv[])
{
	//argc = 5;
	if (argc != 5) {
		std::cout << "This is not recognized as an internal or external command.\n";
		std::cout << "Try typing the right format.\n"
			<< "E.g. P03.exe -s C:\\\\LOL.exe -d C:\\\\Users\\\\ASUS\\\\Desktop" << std::endl;
		return 0;
	}

	//argv[2] = "";
	//argv[4] = "";
	std::string sourceFilePath = argv[2],
		destinationPath = argv[4];

	for (int32_t i = sourceFilePath.std::string::length() - 1; i >= 0; i--) {
		if (sourceFilePath[i] == '\\') {
			destinationPath.std::string::append(sourceFilePath.std::string::substr(i));
			break;
		}
	}
	if (copyFile(sourceFilePath, destinationPath) == true)
		std::cout << "Copied successfully" << std::endl;
	else std::cout << "Try typing the right format.\n"
		<< "E.g. P03.exe -s C:\\\\LOL.exe -d C:\\\\Users\\\\ASUS\\\\Desktop" << std::endl;
	return 0;
}