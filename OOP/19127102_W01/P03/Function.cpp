#include "Function.h"

void loadFile(Temperature& temper, int& day)
{
	std::ifstream fp("input.txt");
	if (fp.fail())
		std::cout << "Error while opening file." << std::endl;
	else {
		fp >> day;
		temper.data = new double[day * 24];
		while (!fp.eof()) {
			for (int i = 0; i < day * 24; i++) 
				fp >> temper.data[i];
		}
		fp.close();
	}
}

void saveFile(Temperature temper, int day)
{
	std::ofstream fp("output.txt");
	if (fp.fail())
		std::cout << "Error while opening file." << std::endl;
	else {
		fp << "(average\tmax\tmin)\n";
		double max, min, average;
		for (int i = 0; i < day; i++) {
			average = 0;
			max = temper.data[i * 24];
			min = temper.data[i * 24];
			for (int j = i * 24; j < i * 24 + 24; j++) {
				if (temper.data[j] > max) max = temper.data[j];
				if (temper.data[j] < min) min = temper.data[j];
				average += temper.data[j];
			}
			average = average / 24;
			fp << "Day " << i + 1 << " : " << roundf(average * 100) / 100 << " \t" << max << "\t" << min << "\n";
		}
		delete[] temper.data;
	}
	fp.close();
}