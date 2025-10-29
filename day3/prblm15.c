#include <stdio.h>

int findMissingUsingSumFormula(int arr[], int n) {
    int totalSum = (n * (n + 1)) / 2;
    
    int arraySum = 0;
    for (int i = 0; i < n - 1; i++) {
        arraySum += arr[i];
    }
    
    return totalSum - arraySum;
}

int findMissingUsingXOR(int arr[], int n) {
    int xor1 = 0, xor2 = 0;
    
    for (int i = 0; i < n - 1; i++) {
        xor1 ^= arr[i];
    }
    
    for (int i = 1; i <= n; i++) {
        xor2 ^= i;
    }
    
    return xor1 ^ xor2;
}

int findMissingUsingHash(int arr[], int n) {
    int present[n + 1];
    
    for (int i = 0; i <= n; i++) {
        present[i] = 0;
    }
    
    for (int i = 0; i < n - 1; i++) {
        present[arr[i]] = 1;
    }
    
    for (int i = 1; i <= n; i++) {
        if (present[i] == 0) {
            return i;
        }
    }
    
    return -1;
}

void printArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    printf("=== METHOD 1: Sum Formula ===\n\n");
    
    int arr1[] = {1, 2, 4, 5, 6};
    int n1 = 6;
    printf("Array: ");
    printArray(arr1, n1 - 1);
    printf("Range: 1 to %d\n", n1);
    printf("Missing Number: %d\n\n", findMissingUsingSumFormula(arr1, n1));
    
    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 9, 10};
    int n2 = 10;
    printf("Array: ");
    printArray(arr2, n2 - 1);
    printf("Range: 1 to %d\n", n2);
    printf("Missing Number: %d\n\n", findMissingUsingSumFormula(arr2, n2));
    
    printf("\n=== METHOD 2: XOR Approach ===\n\n");
    
    int arr3[] = {1, 2, 4, 5, 6};
    int n3 = 6;
    printf("Array: ");
    printArray(arr3, n3 - 1);
    printf("Range: 1 to %d\n", n3);
    printf("Missing Number: %d\n\n", findMissingUsingXOR(arr3, n3));
    
    int arr4[] = {2, 3, 4, 5, 6, 7, 8};
    int n4 = 8;
    printf("Array: ");
    printArray(arr4, n4 - 1);
    printf("Range: 1 to %d\n", n4);
    printf("Missing Number: %d\n\n", findMissingUsingXOR(arr4, n4));
    
    printf("\n=== METHOD 3: Hash Array ===\n\n");
    
    int arr5[] = {3, 1, 4, 5, 6, 2, 8};
    int n5 = 8;
    printf("Array: ");
    printArray(arr5, n5 - 1);
    printf("Range: 1 to %d\n", n5);
    printf("Missing Number: %d\n\n", findMissingUsingHash(arr5, n5));
    
    return 0;
}