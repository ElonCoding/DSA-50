#include <stdio.h>

void findSubarrayWithSum(int arr[], int n, int target) {
    int start = 0;
    int currentSum = 0;
    
    for (int end = 0; end < n; end++) {
        currentSum += arr[end];
        
        while (currentSum > target && start <= end) {
            currentSum -= arr[start];
            start++;
        }
        
        if (currentSum == target) {
            printf("Subarray found: [");
            for (int i = start; i <= end; i++) {
                printf("%d", arr[i]);
                if (i < end) printf(", ");
            }
            printf("]\n");
            printf("Index range: [%d, %d]\n", start, end);
            return;
        }
    }
    
    printf("No subarray found with sum %d\n", target);
}

void findAllSubarraysWithSum(int arr[], int n, int target) {
    int found = 0;
    
    printf("All subarrays with sum %d:\n", target);
    
    for (int start = 0; start < n; start++) {
        int currentSum = 0;
        
        for (int end = start; end < n; end++) {
            currentSum += arr[end];
            
            if (currentSum == target) {
                printf("[");
                for (int i = start; i <= end; i++) {
                    printf("%d", arr[i]);
                    if (i < end) printf(", ");
                }
                printf("] (index %d to %d)\n", start, end);
                found = 1;
            }
        }
    }
    
    if (!found) {
        printf("No subarray found\n");
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
    printf("=== SLIDING WINDOW (First Occurrence) ===\n\n");
    
    int arr1[] = {1, 4, 20, 3, 10, 5};
    int n1 = 6;
    int target1 = 33;
    
    printf("Array: ");
    printArray(arr1, n1);
    printf("Target Sum: %d\n", target1);
    findSubarrayWithSum(arr1, n1, target1);
    printf("\n");
    
    int arr2[] = {1, 4, 0, 0, 3, 10, 5};
    int n2 = 7;
    int target2 = 7;
    
    printf("Array: ");
    printArray(arr2, n2);
    printf("Target Sum: %d\n", target2);
    findSubarrayWithSum(arr2, n2, target2);
    printf("\n");
    
    int arr3[] = {1, 2, 3, 4, 5};
    int n3 = 5;
    int target3 = 15;
    
    printf("Array: ");
    printArray(arr3, n3);
    printf("Target Sum: %d\n", target3);
    findSubarrayWithSum(arr3, n3, target3);
    printf("\n");
    
    printf("\n=== ALL SUBARRAYS WITH GIVEN SUM ===\n\n");
    
    int arr4[] = {10, 2, -2, -20, 10};
    int n4 = 5;
    int target4 = -10;
    
    printf("Array: ");
    printArray(arr4, n4);
    printf("Target Sum: %d\n", target4);
    findAllSubarraysWithSum(arr4, n4, target4);
    printf("\n");
    
    int arr5[] = {1, 2, 3, 7, 5};
    int n5 = 5;
    int target5 = 12;
    
    printf("Array: ");
    printArray(arr5, n5);
    printf("Target Sum: %d\n", target5);
    findAllSubarraysWithSum(arr5, n5, target5);
    
    return 0;
}