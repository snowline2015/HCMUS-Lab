/*
MSSV : 19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9
*/
#include "Function.h"

int main()
{
	int n;
	students a[100], b[100];
	loadStudents(a, n);
	findStudentMaxGPA(a, b, n);
	saveStudent(a, b, n);
	return 0;
}
