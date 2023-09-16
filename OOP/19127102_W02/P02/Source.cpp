#include "Function.h"

void main()
{
	ThoiGian tg1; //00:00:00
	ThoiGian tg2(1212); //00:20:12
	ThoiGian tg3(125, 45); //02:05:45
	ThoiGian tg4(12, 239, -78); //16:00:18
	ThoiGian tg5 = tg2 + tg3; //02:25:57
	ThoiGian tg6 = 5000 + tg2; //01:43:32
	ThoiGian tg7 = tg4 - tg6; //14:16:46
	ThoiGian tg8 = 12300 - tg4; //00:00:00
	ThoiGian tg9, tg10;
	if (tg8 <= tg3)
	{
		tg9 = tg1 + tg2 + 36000; //10:20:12
	}
	if (12345 <= tg5)
	{
		tg10 = tg5 + 12345; //05:51:42
	}
	std::cout << tg1 << std::endl << tg2 << std::endl << tg3 << std::endl << tg4 << std::endl;
	std::cout << tg5 << std::endl << tg6 << std::endl << tg7 << std::endl << tg8 << std::endl;
	std::cout << tg9 << std::endl << tg10 << std::endl;
}