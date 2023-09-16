#include <iostream>
#include <math.h>

int main()
{
	int id = 19127102;
	int min, max;
	int temp = id, temp2 = id;
	int t, y;
	int x = 0;
	int count = 0;
	std::cout << "|{NMLT} 19CLC9| Vo Hoang Gia Bao @ " << id << std::endl;

	min = temp % 10;
	max = temp % 10;

	while (temp >= 1)
	{
		temp = temp / 10;
		t = temp % 10;
		if (min > t) min = t;
	}
	temp = id;
	while (temp >= 1)
	{
		t = temp % 10;
		if (t == min) count++;
		temp = temp / 10;
	}
	x += min * count;
	count = 0;

	temp = id;
	while (temp >= 1)
	{
		temp = temp / 10;
		t = temp % 10;
		if (max < t) max = t;
	}
	temp = id;
	while (temp >= 1)
	{
		t = temp % 10;
		if (t == max) count++;
		temp = temp / 10;
	}
	x += max * count;

	temp = id;
	while (temp >= 1)
	{
		t = temp % 10;
		if (t % 2 == 1) x += t;
		temp = temp / 10;
	}
	if (max % 2 == 1) x -= max;
	if (min % 2 == 1) x -= min;


	system("PAUSE");
	return 0;
}