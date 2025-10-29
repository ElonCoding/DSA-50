#include <stdio.h>

int countOccurrences(int arr[], int n, int target) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            count++;
        }
    }
    return count;
}

void printArray(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    int arr[] = {1, 2, 3, 2, 4, 2, 5, 2};
    int n = 8;
    
    printf("Array: ");
    printArray(arr, n);
    printf("\n");
    
    int target = 2;
    int count = countOccurrences(arr, n, target);
    printf("Element %d occurs %d times\n\n", target, count);
    
    target = 5;
    count = countOccurrences(arr, n, target);
    printf("Element %d occurs %d times\n\n", target, count);
    
    target = 10;
    count = countOccurrences(arr, n, target);
    printf("Element %d occurs %d times\n\n", target, count);
    
    printf("--- Count all elements ---\n");
    int arr2[] = {5, 2, 5, 2, 5, 3, 3, 5};
    int n2 = 8;
    printf("Array: ");
    printArray(arr2, n2);
    
    for (int i = 0; i < n2; i++) {
        int current = arr2[i];
        int alreadyCounted = 0;
        
        for (int j = 0; j < i; j++) {
            if (arr2[j] == current) {
                alreadyCounted = 1;
                break;
            }
        }
        
        if (!alreadyCounted) {
            int count = countOccurrences(arr2, n2, current);
            printf("Element %d occurs %d times\n", current, count);
        }
    }
    
    return 0;
}