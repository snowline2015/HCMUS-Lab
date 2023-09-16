#include "Function.h"

void main()
{
	SoNguyenLon snl1;
	SoNguyenLon snl2(44667733);
	SoNguyenLon snl3(5, 9);
	SoNguyenLon snl4(7, 30);
	SoNguyenLon snl5 = snl3 - snl2;
	SoNguyenLon snl6 = 1098765432 - snl2;
	SoNguyenLon snl7 = snl4 - snl3 + 123456789;
	SoNguyenLon snl8 = snl2 * snl3;

	std::cout << snl1 << std::endl << snl2 << std::endl << snl3 << std::endl;
	std::cout << snl4 << std::endl << snl5 << std::endl << snl6 << std::endl;
	std::cout << snl7 << std::endl << snl8 << std::endl << std::endl;
}