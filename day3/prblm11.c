#include <stdio.h>

void rearrangeAlternate(int arr[], int n) {
    int pos[100], neg[100];
    int posCount = 0, negCount = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            pos[posCount++] = arr[i];
        } else {
            neg[negCount++] = arr[i];
        }
    }
    
    int i = 0, p = 0, ne = 0;
    
    while (p < posCount && ne < negCount) {
        arr[i++] = pos[p++];
        arr[i++] = neg[ne++];
    }
    
    while (p < posCount) {
        arr[i++] = pos[p++];
    }
    
    while (ne < negCount) {
        arr[i++] = neg[ne++];
    }
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
    int arr1[] = {1, 2, 3, -4, -1, 4};
    int n1 = 6;
    printf("Before: ");
    printArray(arr1, n1);
    rearrangeAlternate(arr1, n1);
    printf("After:  ");
    printArray(arr1, n1);
    printf("\n");
    
    int arr2[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    int n2 = 10;
    printf("Before: ");
    printArray(arr2, n2);
    rearrangeAlternate(arr2, n2);
    printf("After:  ");
    printArray(arr2, n2);
    printf("\n");
    
    int arr3[] = {1, -2, -3, 4, 5, -6};
    int n3 = 6;
    printf("Before: ");
    printArray(arr3, n3);
    rearrangeAlternate(arr3, n3);
    printf("After:  ");
    printArray(arr3, n3);
    
    return 0;
}