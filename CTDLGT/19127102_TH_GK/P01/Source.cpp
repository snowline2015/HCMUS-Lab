#include <iostream>
#include <ctime>

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int left = low;
    int right = high - 1;
    while (true) {
        while (left <= right && arr[left] > pivot) left++;
        while (right >= left && arr[right] < pivot) right--;
        if (left >= right) break;
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
    int temp = arr[left];
    arr[left] = arr[high];
    arr[high] = temp;
    return left;
}

void quickSort(int arr[], int begin, int end) {
    if (begin < end)
    {
        int pi = partition(arr, begin, end);
        quickSort(arr, begin, pi - 1);
        quickSort(arr, pi + 1, end);
    }
}

void merge(int arr[], int begin, int mid, int end) {
    int i, j, k;
    int n1 = mid - begin + 1;
    int n2 = end - mid;
    int* arr1 = new int[n1],
        * arr2 = new int[n2];

    for (i = 0; i < n1; i++)
        arr1[i] = arr[begin + i];
    for (j = 0; j < n2; j++)
        arr2[j] = arr[mid + 1 + j];
    i = 0;
    j = 0;
    k = begin;
    while (i < n1 && j < n2) {
        if (arr1[i] >= arr2[j]) {
            arr[k] = arr1[i];
            i++;
        }
        else {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = arr2[j];
        j++;
        k++;
    }
    delete[] arr1, arr2;
}

void mergeSort(int arr[], int begin, int end) {
    if (begin < end)
    {
        int mid = begin + (end - begin) / 2;
        mergeSort(arr, begin, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, begin, mid, end);
    }
}

int* randomArray(int size) {

    int* array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
    return array;
}

void display(int arr[], int size) {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main() {
    int size;
    std::cout << "Input size of array: ";
    std::cin >> size;
    std::cout << std::endl;
    srand((int)time(NULL));

    std::cout << "\nQuick sort: " << std::endl;
    int* arr = randomArray(size);
    display(arr, size);
    //clock_t begin = clock();
    quickSort(arr, 0, size - 1);
    display(arr, size);
    //clock_t end = clock();
    //std::cout << "Quick sort run: " << (float)(end - begin) / CLOCKS_PER_SEC << " s" << std::endl << std::endl;
    delete arr;

    std::cout << "\nMerge sort: " << std::endl;
    arr = randomArray(size);
    display(arr, size);
    //clock_t begin1 = clock();
    mergeSort(arr, 0, size - 1);
    display(arr, size);
    //clock_t end1 = clock();
    //std::cout << "Merge sort run: " << (float)(end1 - begin1) / CLOCKS_PER_SEC << " s" << std::endl << std::endl;
    delete arr;

    return 0;
}