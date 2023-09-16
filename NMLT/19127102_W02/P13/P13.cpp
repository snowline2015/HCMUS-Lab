/*
MSSV :19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9
Chương trình : TÍNH CHU VI VÀ DIỆN TÍCH TAM GIÁC
sss
Test case 1 
Input: 3 4 5 
Output: 12.00, 6.00
Test case 2
Input: 3 3 3
Output: 9, 3.9
Test case 3
Input: 2 2 3
Output: 7, 1.98
*/

#include<iostream>
#include<math.h>
#include<iomanip>

int main()
{
	double edge1, edge2, edge3;
	double nuachuvi, P, S;
	std::cout << "Nhap 3 canh tam giac : ";
	std::cin >> edge1 >> edge2 >> edge3;
	while (edge1 <= 0 || edge2 <= 0 || edge3 <= 0)
	{
		std::cout << "Nhap sai so\nXin vui long nhap lai 3 canh tam giac : ";
		std::cin >> edge1 >> edge2 >> edge3;
	}
	P = edge1 + edge2 + edge3;
	nuachuvi = P/2;
	S = sqrt(nuachuvi * (nuachuvi - edge1) * (nuachuvi - edge2) * (nuachuvi - edge3));
	std::cout << "Chu vi tam giac : " << std::fixed << std::setprecision(2) << P << std::endl;
	std::cout << "Dien tich tam giac : " << std::fixed << std::setprecision(2) << S << std::endl;

	system("PAUSE");
	return 0;
}
