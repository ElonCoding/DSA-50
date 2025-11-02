#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int maxProduct(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }

    int max_so_far = nums[0];
    int min_so_far = nums[0];
    int result = max_so_far;

    for (int i = 1; i < numsSize; i++) {
        int curr = nums[i];
        int temp_max = max(curr, max(max_so_far * curr, min_so_far * curr));
        min_so_far = min(curr, min(max_so_far * curr, min_so_far * curr));

        max_so_far = temp_max;

        result = max(max_so_far, result);
    }

    return result;
}

int main() {
    int nums[] = {2, 3, -2, 4};
    int n = sizeof(nums) / sizeof(nums[0]);
    printf("Maximum product subarray: %d\n", maxProduct(nums, n));

    int nums2[] = {-2, 0, -1};
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Maximum product subarray: %d\n", maxProduct(nums2, n2));

    return 0;
}