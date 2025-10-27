#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void findKthMinMax(int arr[], int n, int k, int *kthMin, int *kthMax) {
    qsort(arr, n, sizeof(int), compare);

    // Kth minimum element is at index k-1
    *kthMin = arr[k - 1];

    // Kth maximum element is at index n-k
    *kthMax = arr[n - k];
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    int kthMin, kthMax;

    if (k <= 0 || k > n) {
        printf("Invalid value of K.\n");
        return 1;
    }

    findKthMinMax(arr, n, k, &kthMin, &kthMax);

    printf("Kth (%d) smallest element: %d\n", k, kthMin);
    printf("Kth (%d) largest element: %d\n", k, kthMax);

    return 0;
}