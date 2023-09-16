#include <iostream>
#include <fstream>
#include <algorithm>

int* linearSearch(int arr[], int n, int x) {
    int* array = new int[n + 1], m = 1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            array[m] = i;
            m++;
        }
    }
    if (array[1] < 0) array[0] = -1;
    else array[0] = m - 1;
    return array;
}

int* sentinelLinearSearch(int arr[], int n, int x)
{
    int* array = new int[n + 1],
        last = arr[n - 1],
        i = 0, m = 1;
    arr[n - 1] = x;

    while (i < n - 1) {
        if (arr[i] == x) {
            array[m] = i;
            m++;
        }
        i++;
    }
    arr[n - 1] = last;
    if (arr[n - 1] == x) {
        array[m] = n - 1;
        m++;
    }
    if (array[1] < 0) array[0] = -1;
    else array[0] = m - 1;
    return array;
}

void binarySearch(int arr[], int begin, int end, int val, int array[], int a) {
    if (end >= begin) {
        int mid = begin + (end - begin) / 2;
        if (arr[mid] == val) {
            array[a] = mid;
            a++;
        }
        if (arr[mid] > val) 
            return binarySearch(arr, begin, mid - 1, val, array, a);
        return binarySearch(arr, mid + 1, end, val, array, a);
    }
    else {
        if (array[1] < 0) array[0] = -1;
        else array[0] = a - 1;
    }
}

void loadFile(std::string path, int*& arr, int& size) {
    std::ifstream file(path);
    if (file.fail()) {
        std::cout << "Cannot open file";
        return;
    }
    else {
        file >> size;
        arr = new int[size];
        int i = 0;
        while (!file.eof()) {
            file >> arr[i];
            i++;
        }
    }
    file.close();
}

void saveFile(std::string path, int arr[]) {
    std::ofstream file(path);
    if (arr[0] == -1) file << -1;
    else {
        for (int i = 1; i < arr[0] + 1; i++)
            file << arr[i] << " ";
    }
    file.close();
}

int main(int argc, const char* argv[]) {
    if (argc != 5) {
        std::cout << "This is not recognized as an internal or external command.\n" << "Try typing the right format.\n"
            << "E.g: 19127102_Lab1.exe 1 3 test1.txt out1.txt" << std::endl;
        return 0;
    }
    
    std::string input = argv[3], output = argv[4];
    int option = atoi(argv[1]), key = atoi(argv[2]),
        * arr, * array, size;
    loadFile(input, arr, size);
    if (option == 1) {
        array = linearSearch(arr, size, key);
        saveFile(output, array);
    }
    else if (option == 2) {
        array = sentinelLinearSearch(arr, size, key);
        saveFile(output, array);
    }
    else if (option == 3) {
        array = new int[size];
        std::sort(arr, arr + size);
        binarySearch(arr, 0, size - 1, key, array, 1);
        saveFile(output, array);
    }
    else {
        std::cout << "No algorithm matched";
        return 0;
    }
    delete[] arr, array;
    return 0;
}

