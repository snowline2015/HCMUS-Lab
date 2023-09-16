#include <iostream>
#include <ctime>

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

void display(int arr[], int size) {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main() {
    int* a, m, * b, n;
    std::cout << "Input m, n: ";
    std::cin >> m >> n;
    a = new int[m];
    b = new int[n];

    std::cout << "Nhap mang a giam dan: ";
    for (int i = 0; i < m; i++)
        std::cin >> a[i];
    std::cout << "Nhap mang b giam dan: ";
    for (int i = 0; i < n; i++)
        std::cin >> b[i];

    int* c = new int[m + n];
    int temp = 0;
    for (int i = 0; i < m; i++) {
        c[temp] = a[i];
        temp++;
    }
    for (int i = 0; i < n; i++) {
        c[temp] = b[i];
        temp++;
    }

    clock_t begin = clock();
    mergeSort(c, 0, m + n - 1);
    display(c, m + n);
    clock_t end = clock();
    std::cout << "Merge sort run: " << (float)(end - begin) / CLOCKS_PER_SEC << " s" << std::endl << std::endl;
}