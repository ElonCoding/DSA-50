#include <stdio.h>

int trap(int* height, int heightSize) {
    if (heightSize <= 2) {
        return 0;
    }

    int left = 0;
    int right = heightSize - 1;
    int leftMax = 0;
    int rightMax = 0;
    int trappedWater = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= leftMax) {
                leftMax = height[left];
            } else {
                trappedWater += leftMax - height[left];
            }
            left++;
        } else {
            if (height[right] >= rightMax) {
                rightMax = height[right];
            } else {
                trappedWater += rightMax - height[right];
            }
            right--;
        }
    }
    return trappedWater;
}

int main() {
    int height[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(height) / sizeof(height[0]);
    printf("Trapped rain water: %d\n", trap(height, n));
    return 0;
}