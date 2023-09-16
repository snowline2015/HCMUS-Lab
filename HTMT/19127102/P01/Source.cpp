#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int x, temp;
	std::vector<int> vec;
	std::cout << "Input an integer (16-bit): ";
	std::cin >> x;
	temp = x;

	while (true) {
		vec.push_back(temp % 2);
		if (temp / 2 == 0) 
			break;
		temp = temp / 2;
	}

	if (vec.size() < 16) {
		temp = vec.size();
		for (int i = 0; i < 16 - temp; i++)
			vec.push_back(0);
	}
	reverse(vec.begin(), vec.end());

	std::cout << "Binary bit pattern of " << x << ": ";
	for (int i = 0; i < vec.size(); i++)
		std::cout << vec[i];

	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == 1) vec[i] = 0;
		else vec[i] = 1;
	}
	for (int i = vec.size() - 1; i >= 0; i--) {
		if (vec[i] == 1) vec[i] = 0;
		else {
			vec[i] = 1;
			break;
		}
	}

	std::cout << "\nBinary bit pattern of -" << x << ": ";
	for (int i = 0; i < vec.size(); i++)
		std::cout << vec[i];

	return 0;
}