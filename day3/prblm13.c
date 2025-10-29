#include <stdio.h>

void findPairsWithSum(int arr[], int n, int target) {
    int found = 0;
    
    printf("Pairs with sum %d:\n", target);
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                printf("(%d, %d)\n", arr[i], arr[j]);
                found = 1;
            }
        }
    }
    
    if (!found) {
        printf("No pairs found\n");
    }
}

void findPairsWithSumOptimized(int arr[], int n, int target) {
    int hash[100000] = {0};
    int offset = 50000;
    int found = 0;
    
    printf("Pairs with sum %d:\n", target);
    
    for (int i = 0; i < n; i++) {
        int complement = target - arr[i];
        
        if (complement >= -50000 && complement <= 50000) {
            if (hash[complement + offset] > 0) {
                printf("(%d, %d)\n", complement, arr[i]);
                found = 1;
            }
        }
        
        if (arr[i] >= -50000 && arr[i] <= 50000) {
            hash[arr[i] + offset]++;
        }
    }
    
    if (!found) {
        printf("No pairs found\n");
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
    int arr1[] = {1, 5, 7, -1, 5};
    int n1 = 5;
    int target1 = 6;
    
    printf("Array: ");
    printArray(arr1, n1);
    findPairsWithSum(arr1, n1, target1);
    printf("\n");
    
    int arr2[] = {2, 4, 3, 5, 7, 8, 9};
    int n2 = 7;
    int target2 = 10;
    
    printf("Array: ");
    printArray(arr2, n2);
    findPairsWithSum(arr2, n2, target2);
    printf("\n");
    
    int arr3[] = {1, 2, 3, 4, 5};
    int n3 = 5;
    int target3 = 10;
    
    printf("Array: ");
    printArray(arr3, n3);
    findPairsWithSum(arr3, n3, target3);
    printf("\n");
    
    printf("--- Using Optimized Method (O(n)) ---\n\n");
    
    int arr4[] = {1, 5, 7, -1, 5};
    int n4 = 5;
    int target4 = 6;
    
    printf("Array: ");
    printArray(arr4, n4);
    findPairsWithSumOptimized(arr4, n4, target4);
    
    return 0;
}