#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int partition(std::vector<std::string>& vec, int low, int high)
{
    std::string pivot = vec[high];
    int left = low;
    int right = high - 1;
    while (true) {
        while (left <= right && std::stoi(vec[left].substr(vec[left].length() - 3, 3)) > std::stoi(pivot.substr(pivot.length() - 3, 3))) left++;
        while (right >= left && std::stoi(vec[right].substr(vec[right].length() - 3, 3)) < std::stoi(pivot.substr(pivot.length() - 3, 3))) right--;
        if (left >= right) break;
        std::string temp = vec[left];
        vec[left] = vec[right];
        vec[right] = temp;
        left++;
        right--;
    }
    std::string temp = vec[left];
    vec[left] = vec[high];
    vec[high] = temp;
    return left;
}

void quickSort(std::vector<std::string>& vec, int begin, int end) {
    if (begin < end)
    {
        int pi = partition(vec, begin, end);
        quickSort(vec, begin, pi - 1);
        quickSort(vec, pi + 1, end);
    }
}

void heapify(std::vector<std::string>& vec, int n, int i)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && std::stoi(vec[l].substr(vec[l].length() - 3, 3)) < std::stoi(vec[smallest].substr(vec[smallest].length() - 3, 3)))
        smallest = l;
    if (r < n && std::stoi(vec[r].substr(vec[r].length() - 3, 3)) < std::stoi(vec[smallest].substr(vec[smallest].length() - 3, 3)))
        smallest = r;
    if (smallest != i) {
        std::string temp = vec[i];
        vec[i] = vec[smallest];
        vec[smallest] = temp;
        heapify(vec, n, smallest);
    }
}

void heapSort(std::vector<std::string>& vec, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(vec, n, i);
    for (int i = n - 1; i > 0; i--) {
        std::string temp = vec[0];
        vec[0] = vec[i];
        vec[i] = temp;
        heapify(vec, i, 0);
    }
}

void merge(std::vector<std::string>& vec, int begin, int mid, int end) {
    int i, j, k;
    int n1 = mid - begin + 1;
    int n2 = end - mid;
    std::string* arr1 = new std::string[n1],
        * arr2 = new std::string[n2];

    for (i = 0; i < n1; i++)
        arr1[i] = vec[begin + i];
    for (j = 0; j < n2; j++)
        arr2[j] = vec[mid + 1 + j];
    i = 0;
    j = 0;
    k = begin;
    while (i < n1 && j < n2) {
        if (std::stoi(arr1[i].substr(arr1[i].length() - 3, 3)) >= std::stoi(arr2[j].substr(arr2[j].length() - 3, 3))) {
            vec[k] = arr1[i];
            i++;
        }
        else {
            vec[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        vec[k] = arr1[i];
        i++;
        k++;
    }
    while (j < n2) {
        vec[k] = arr2[j];
        j++;
        k++;
    }
    delete[] arr1, arr2;
}

void mergeSort(std::vector<std::string>& vec, int begin, int end) {
    if (begin < end)
    {
        int mid = begin + (end - begin) / 2;
        mergeSort(vec, begin, mid);
        mergeSort(vec, mid + 1, end);
        merge(vec, begin, mid, end);
    }
}

void displayStringVector(std::vector<std::string> vec) {
    for (std::vector<std::string>::iterator p = vec.begin(); p != vec.end(); p++) {
        std::cout << (*p) << std::endl;
    }
}

void sortByName(std::vector<std::string>& vec) {
    for (std::vector<std::string>::iterator p = vec.begin(); p != vec.end(); p++) {
        for (std::vector<std::string>::iterator q = p + 1; q != vec.end(); q++) {
            if (std::stoi((*p).substr((*p).length() - 3, 3)) == std::stoi((*q).substr((*q).length() - 3, 3))) {
                int temp1 = (*p).length() - 1,
                    temp2 = (*q).length() - 1;
                while (temp1 >= 0 && temp2 >= 0) {
                    if (temp1 != 0 && (*p)[temp1 - 1] != ' ') temp1--;
                    if (temp2 != 0 && (*q)[temp2 - 1] != ' ') temp2--;
                    if ((temp1 == 0 && temp2 == 0) || ((*p)[temp1 - 1] == ' ' && (*q)[temp2 - 1] == ' ')) {
                        if ((*p)[temp1] > (*q)[temp2]) break;
                        else if ((*p)[temp1] < (*q)[temp2]) {
                            std::string temp = *p;
                            *p = *q;
                            *q = temp;
                            break;
                        }
                        else { temp1--; temp2--; }
                    }
                }
            }
        }
    }
}

int main() {
	std::ifstream input("employee.txt");
	std::ofstream output("sortedemponage.txt");
	std::vector<std::string> ok;
	std::string temp;
	if (input.fail()) {
		std::cout << "Cannot open file";
		return 0;
	}
	else {
		while (!input.eof()) {
			getline(input, temp);
			ok.push_back(temp);
		}
	}
    int option;
    std::cout << "1. Heap sort\n2. Merge sort\n3. Quick sort\nChoose your sort option: ";
    std::cin >> option;
    if (option == 1) heapSort(ok, ok.size());
    else if (option == 2) mergeSort(ok, 0, ok.size() - 1);
    else if (option == 3) quickSort(ok, 0, ok.size() - 1);
    else {
        std::cout << "Entered option not available";
        return 0;
    }

    sortByName(ok);

    displayStringVector(ok);

    for (std::vector<std::string>::iterator p = ok.begin(); p != ok.end(); p++)
        output << (*p) << "\n";

    input.close(), output.close();
	return 0;
}