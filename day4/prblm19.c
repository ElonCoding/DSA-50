#include <stdio.h>
#include <stdlib.h>

void merge(int arr1[], int arr2[], int n, int m) {
    int i = n - 1; // Pointer for arr1's actual elements
    int j = m - 1; // Pointer for arr2
    int k = n + m - 1; // Pointer for merged array (end of arr1)

    while (i >= 0 && j >= 0) {
        if (arr1[i] > arr2[j]) {
            arr1[k--] = arr1[i--];
        } else {
            arr1[k--] = arr2[j--];
        }
    }

    while (j >= 0) {
        arr1[k--] = arr2[j--];
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr1[10] = {1, 3, 5, 7, 9}; // Array 1 with extra space
    int arr2[] = {2, 4, 6, 8}; // Array 2
    int n = 5; // Actual size of arr1
    int m = sizeof(arr2) / sizeof(arr2[0]); // Size of arr2

    printf("Array 1 before merge: ");
    printArray(arr1, n);
    printf("Array 2: ");
    printArray(arr2, m);

    merge(arr1, arr2, n, m);

    printf("Merged array: ");
    printArray(arr1, n + m);

    return 0;
}