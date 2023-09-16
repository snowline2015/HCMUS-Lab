#include "Function.h"

void inputArray(int a[100], int n)
{
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		while (a[i] < 100000 || a[i] > 999999) {
			std::cout << "Wrong number. Input again : ";
			std::cin >> a[i];
		}
	}
}

void luckyTicket(int a[100], int n, int b[100], int &m)
{
	m = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 10 == 8 || a[i] / 100000 == 8) {
			b[m] = a[i];
			m++;
		}
	}
}

int jackpot(int a[100], int n, int b[100], int& m, int &ticket, int &ans)
{
	int count = 0;
	std::cout << "Input a ticket : ";
	std::cin >> ticket;
	for (int i = 0; i < m; i++) {
		if (ticket == b[i]) {
			ans = 0;
			break;
		}
	}
	if (ans != 0) {

		for (int i = 0; i < m; i++) {
			int temp = ticket;
			for (int j = 0; j < 6; j++) {
				if (temp % 10 == a[i] % 10)
					count++;
				temp /= 10;
				a[i] /= 10;
			}
			if (count == 5) {
				ans = 1;
				break;
			}
			else count = 0;
		}
	}
	if (ans != 0 && ans != 1) ans = 2;
	return ans;
}