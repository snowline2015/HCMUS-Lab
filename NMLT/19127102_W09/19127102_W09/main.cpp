/*
MSSV : 19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9
*/
#include "Function.h"

int main()
{
	int enterOption;
	char str[100], str1[100];
	int m, n, a[100][100], p, q, b[100][100];
	std::cout << "*** String ***\n";
	std::cout << "1. P01: Dao chuoi\n";
	std::cout << "2. P02: Dao nguoc thu tu cac chu\n";
	std::cout << "3. P03: Chuan hoa ho va ten\n";
	std::cout << "4. P07: In so nguyen o dang chuoi\n";
	std::cout << "5. P10: Danh sach hoc sinh\n" << std::endl;
	std::cout << "*** 2D Array ***\n";
	std::cout << "6. P320: Tinh tong cac so duong trong ma tran cac so nguyen\n";
	std::cout << "7. P342: Dem so luong phan tu cuc dai trong ma tran cac so thuc (1 phan tu duoc goi la cuc dai khi no lon hon lan can cac 8 phan tu xung quanh)\n";
	std::cout << "8. P347: Dem so luong gia tri 'Yen Ngua' tren ma tran (1 phan tu duoc goi la Yen Ngua khi no lon nhat tren dong va nho nhat tren cot)\n";
	std::cout << "9. P398: Dich phai xoay vong theo chieu kim dong ho cac gia tri nam tren bien ma tran\n";
	std::cout << "10. P402: Xoay ma tran 1 goc 90 do\n" << std::endl;
	std::cout << "Enter Option : ";
	std::cin >> enterOption;
	std::cout << std::endl;

	switch (enterOption)
	{
	case 1:
		/*
		Test case 1
		Input: hello world
		Output: dlrow olleh
		Test case 2
		Input: string
		Output: gnirts
		Test case 3
		Input: information
		Output: noitamrofni
		*/
	{
		std::cout << "Input string : ";
		inputString(str);
		reverseString(str, str1);
		std::cout << str1 << std::endl;
		break;
	}
	case 2:
		/*
		Test case 1
		Input: con nghe thong tin
		Output: tin thong nghe cong
		Test case 2
		Input: vo hoang gia bao
		Output: bao gia hoang vo
		Test case 3
		Input: haha hihi hoho
		Output: hoho hihi haha
		*/
	{
		std::cout << "Input string : ";
		inputString(str);
		reverseWordsInString(str, str1);
		std::cout << str1 << std::endl;
		break;
	}
	case 3: 
		/*
		Test case 1
		Input: vo hoang gia bao
		Output: Vo Hoang Gia Bao
		Test case 2
		Input:                vo hoang gia bao
		Output: Vo Hoang Gia Bao
		Test case 3
		Input: VO HOANG GIA BAO
		Output: Vo Hoang Gia Bao
		*/
	{
		std::cout << "Input string : ";
		inputString(str);
		normalizeName(str);
		std::cout << str << std::endl;
		break;
	}
	case 4:
		/*
		Test case 1
		Input: 19127102
		Output: 19,127,102
		Test case 2
		Input: 9000000000
		Output: 9,000,000,000
		Test case 3
		Input: 7546789876
		Output: 7,546,789,876
		*/
	{
		std::cout << "Input string : ";
		inputString(str);
		printIntegerInString(str);
		std::cout << str << std::endl;
		break;
	}
	case 5:
	{
		hocSinh a[100];
		int num;
		inputStudents(a, num);
		std::cout << std::endl;
		arrangeStudents(a, num);
		for (int i = 0; i < num; i++) {
			std::cout << a[i].name << std::endl;
		}
		break;
	}
	case 6:
		/*
		Test case 1
		Input: 3 3 1 2 3 4 -5 6 7 8 9
		Output: 40
		*/
	{
		input2DArray(m, n, a);
		std::cout << std::endl;
		output2DArray(m, n, a);
		std::cout << "S = " << sumOfPositiveElementsIn2DArray(m, n, a) << std::endl;
		break;
	}
	case 7:
		/*
		Test case 1
		Input:	3 5
			2 9 8 3 0
			1 5 7 6 7
			2 4 6 9 1
		Output: 2
		*/
	{
		input2DArray(m, n, a);
		std::cout << std::endl;
		output2DArray(m, n, a);
		std::cout << countMaxInMatrix(m, n, a) << std::endl;
		break;
	}
	case 8:
		/*
		Test case 1
		Input:	4 4
			12 32 34 90
			1 31 30 5
			4 33 20 44
			3 34 35 23
		Output: 2
		*/
	{
		input2DArray(m, n, a);
		std::cout << std::endl;
		output2DArray(m, n, a);
		std::cout << countSaddleInMatrix(m, n, a) << std::endl;
		break;
	}
	case 9:
		/*
		Test case 1
		Input:	4 5
			12 11 22 30 21
			21 89 22 33 22
			11 29 43 78 23
			23 44 66 96 24
		Output: 
			21 12 11 22 30
			11 89 22 33 21
			23 29 43 78 22
			44 66 96 24 23
		*/
	{
		input2DArray(m, n, a);
		std::cout << std::endl;
		output2DArray(m, n, a);
		std::cout << std::endl;
		rightShiftRotateClockwiseMatrixBoundary(m, n, a);
		output2DArray(m, n, a);
		break;
	}
	case 10:
		/*
		Test case 1
		Input:	4 5
			12 11 22 30
			21 89 22 33
			11 29 43 78
			23 44 66 96
		Output:
			23 11 21 12
			44 29 89 11
			66 43 22 22
			96 78 33 30
		*/
	{
		input2DArray(m, n, a);
		std::cout << std::endl;
		output2DArray(m, n, a);
		std::cout << std::endl;
		rotateMatrix90Degree(m, n, a, p, q, b);
		output2DArray(p, q, b);
		break;
	}
	case 0:
	{
		std::cout << "Program is now exiting..." << std::endl;
		break;
	}
	default: break;
	}

	system("PAUSE");
	return 0;
}