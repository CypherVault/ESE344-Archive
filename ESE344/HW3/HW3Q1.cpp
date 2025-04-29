#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

//qsort compare function
int compare(const void* a, const void* b) {
    return (*(long*)a - *(long*)b);
}

// find nearby almost duplicate elements
bool containsNearbyAlmostDuplicate(int* nums, int numsSize, int indexDiff, int valueDiff) {
    if (numsSize == 0 || indexDiff <= 0 || valueDiff < 0) {
        return false; // basic test case right away to know wether or not it is an invalid set of information  
    }

    long* window = (long*)malloc(sizeof(long) * (indexDiff + 1));
    int windowSize = 0;

    for (int i = 0; i < numsSize; i++) {
        if (windowSize > 0) {
            // Check for nearby almost duplicate conditiion
            for (int j = 0; j < windowSize; j++) {
                if (labs((long)nums[i] - window[j]) <= valueDiff) {
                    free(window);
                    return true;
                }
            }
        }

        // Add current element to window
        window[windowSize++] = (long)nums[i];

        // Sort window
        qsort(window, windowSize, sizeof(long), compare);

        // Remove oldest element from that chosen window as index difference dictates
        if (windowSize > indexDiff) {
            int removeIndex = 0;
            for (int j = 1; j < windowSize; j++) {
                if (window[j] == (long)nums[i - indexDiff]) {
                    removeIndex = j;
                    break;
                }
            }
            for (int j = removeIndex; j < windowSize - 1; j++) {
                window[j] = window[j + 1];
            }
            windowSize--;
        }
    }

    free(window);
    return false;
}

int main() {
    // Test case which the hw provides
    int nums[] = {1, 2, 3, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int indexDiff = 3;
    int valueDiff = 0;
    
    bool result = containsNearbyAlmostDuplicate(nums, numsSize, indexDiff, valueDiff);
    
    printf("Input: nums = [1, 2, 3, 1], indexDiff = 3, valueDiff = 0\n");
    printf("Output: %s\n", result ? "true" : "false");
    
    if (result) {
        // Find and print when found.
        for (int i = 0; i < numsSize; i++) {
            for (int j = 0; j < numsSize; j++) {
                if (i != j && 
                    abs(i - j) <= indexDiff && 
                    abs(nums[i] - nums[j]) <= valueDiff) {
                    printf("Explanation: The pair (i, j) = (%d, %d) satisfies the conditions.\n", i, j);
                    // Just print the first pair found
                    goto found_pair;
                }
            }
        }
        found_pair:;
    }
    
    return 0;
}
