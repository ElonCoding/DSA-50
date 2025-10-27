#include <stdio.h>

void findMinMax(int arr[], int n, int *min, int *max) {
    if (n <= 0) {
        *min = *max = -1; // Indicate error or empty array
        return;
    }

    *min = arr[0];
    *max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < *min) {
            *min = arr[i];
        }
        if (arr[i] > *max) {
            *max = arr[i];
        }
    }
}

int main() {
    int arr[] = {10, 5, 20, 8, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int min, max;

    findMinMax(arr, n, &min, &max);

    if (n > 0) {
        printf("Minimum element: %d\n", min);
        printf("Maximum element: %d\n", max);
    } else {
        printf("Array is empty.\n");
    }

    return 0;
}