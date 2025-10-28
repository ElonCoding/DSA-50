#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int getMinDiff(int arr[], int n, int k) {
    qsort(arr, n, sizeof(int), compare);

    int ans = arr[n - 1] - arr[0];

    int small = arr[0] + k;
    int big = arr[n - 1] - k;

    if (small > big) {
        int temp = small;
        small = big;
        big = temp;
    }

    for (int i = 1; i < n - 1; i++) {
        int subtract = arr[i] - k;
        int add = arr[i] + k;

        if (subtract >= small || add <= big) {
            continue;
        }

        if (big - subtract <= add - small) {
            small = subtract;
        } else {
            big = add;
        }
    }
    return (big - small < ans) ? big - small : ans;
}

int main() {
    int arr[] = {1, 5, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    printf("Minimum difference is %d\n", getMinDiff(arr, n, k));

    return 0;
}