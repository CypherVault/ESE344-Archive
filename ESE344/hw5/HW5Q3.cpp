#include <stdio.h>
#include <stdlib.h>

//extra credit Number 2 leetcode attempt

int** findTriplets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // Count valid triplets
    int count = 0;
    for (int i = 0; i < numsSize - 2; ++i) {
        for (int j = i + 1; j < numsSize - 1; ++j) {
            if (nums[i] >= nums[j]) continue;
            for (int k = j + 1; k < numsSize; ++k) {
                count += (nums[j] < nums[k]);
            }
        }
    }

    // Allocate result memory
    int** result = (int**)malloc(count * sizeof(int*));
    *returnColumnSizes = (int*)malloc(count * sizeof(int));
    *returnSize = count;

    // Populate results
    int idx = 0;
    for (int i = 0; i < numsSize - 2; ++i) { //triple nested apprioach , i, then j>i, then k>j in final nest.
        for (int j = i + 1; j < numsSize - 1; ++j) {
            if (nums[i] >= nums[j]) continue;
            for (int k = j + 1; k < numsSize; ++k) {
                if (nums[j] < nums[k]) {
                    result[idx] = (int*)malloc(3 * sizeof(int));
                    result[idx][0] = i;
                    result[idx][1] = j;
                    result[idx][2] = k;
                    (*returnColumnSizes)[idx] = 3;
                    idx++;
                }
            }
        }
    }
    return result;
}

int main() {
    int nums[] = {1, 2, 3, 4, 5};
    int size = sizeof(nums) / sizeof(nums[0]);

    int returnSize;
    int* returnColumnSizes;
    int** triplets = findTriplets(nums, size, &returnSize, &returnColumnSizes); //brute force verification technique, nothing classy or clever here.

    printf("Input: nums = [1, 2, 3, 4, 5]\n"); // example from pdf 
    printf("Output:\n");
    for (int i = 0; i < returnSize; ++i) {
        printf("(%d %d %d) ", triplets[i][0], triplets[i][1], triplets[i][2]);
        free(triplets[i]);
    }
    free(triplets);
    free(returnColumnSizes);
    
    return 0;
}
