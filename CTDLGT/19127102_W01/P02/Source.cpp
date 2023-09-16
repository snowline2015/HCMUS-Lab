#include <iostream>
#include <ctime>

int main() {
	int size;
	int odd = 0, even = 0;
	std::cout << "Input size of array: ";
	std::cin >> size;
	int* arr = new int[size];
	srand(unsigned int(time(NULL)));
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 100;
		std::cout << arr[i] << " ";
	}
	std::cout << "\n\nSorted: " << std::endl;
	/*std::cout << "Input array: ";
	for (int i = 0; i < size; i++) {
		std::cin >> arr[i];
	}*/
	for (int i = 0; i < size; i++) {
		if (arr[i] % 2 == 0) even += 1;
		else odd += 1;
	}
	int * arrEven = new int[even],
		* arrOdd = new int[odd];
	int temp1 = 0, temp2 = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] % 2 == 0) {
			arrEven[temp1] = arr[i];
			temp1++;
		}
		else {
			arrOdd[temp2] = arr[i];
			temp2++;
		}
	}
	for (int i = 0; i < even; i++) {
		for (int j = i + 1; j < even; j++) {
			if (arrEven[i] > arrEven[j]) {
				int temp = arrEven[i];
				arrEven[i] = arrEven[j];
				arrEven[j] = temp;
			}
		}
	}
	for (int i = 0; i < odd; i++) {
		for (int j = i + 1; j < odd; j++) {
			if (arrOdd[i] < arrOdd[j]) {
				int temp = arrOdd[i];
				arrOdd[i] = arrOdd[j];
				arrOdd[j] = temp;
			}
		}
	}
	temp1 = 0, temp2 = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] % 2 == 0) {
			arr[i] = arrEven[temp1];
			temp1++;
		}
		else {
			arr[i] = arrOdd[temp2];
			temp2++;
		}
	}
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	delete[] arr, arrEven, arrOdd;
	return 0;
}