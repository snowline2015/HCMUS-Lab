#include "Function.h"

int main(int argc, const char* argv[])
{
	//argc = 6;
	if (argc != 6) {
		std::cout << "This is not recognized as an internal or external command.\n";
		std::cout << "Try typing the right format.\n"
			<< "E.g. P05.exe -s <C:\\\\Documents> -d <D:\\\\Games> <File Name>" << std::endl;
		return 0;
	}

	//argv[2] = "D:";
	//argv[4] = "D:";
	//argv[5] = "438_emiri_04_800.jpg";
	std::string sourceFilePath = argv[2],
		destinationPath = argv[4],
		fileName = argv[5];

	int ans = mergeFiles(sourceFilePath, destinationPath, fileName);
	if (ans == 1)
		std::cout << "Merged successfully" << std::endl;
	else if (ans == 0) std::cout << "Try typing the right format.\n"
		<< "E.g. P03.exe -s <C:\\\\Documents> -d <D:\\\\Games> <File Name>" << std::endl;
	else std::cout << "\nPlease check for the missing parts and try again" << std::endl;
	return 0;
}