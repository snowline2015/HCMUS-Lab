/*
MSSV : 19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9
*/
#include "Function.h"

int main()
/* Test case
5
322068
570849
232474
725918
148784
283598

2

579849 
Giai khuyen khich !

322068
Giai doc dac !

100000
Khong trung giai!
*/
{
	int a[100], n, b[100], m;
	int ticket;
	std::cout << "Input number of lottery tickets : ";
	std::cin >> n;
	inputArray(a, n);
	luckyTicket(a, n, b, m);
	std::cout << "So ve may man : " << m << std::endl;
	int ans = jackpot(a, n, b, n, ticket, ans);
	if (ans == 0) std::cout << "Giai doc dac !";
	if (ans == 1) std::cout << "Giai khuyen khich !";
	if (ans == 2) std::cout << "Khong trung giai !";

	system("PAUSE");
	return 0; 
}