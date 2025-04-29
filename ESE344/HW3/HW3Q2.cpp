#include <stdio.h>
#include <stdlib.h>

// qsort compare helper function for this problem 
int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a); // Sort in descending order
}

// h-index calculate 
int hIndex(int* citations, int citationsSize) {
    // Sort the citations array in descending order
    qsort(citations, citationsSize, sizeof(int), compare);
    
    // Find the h-index
    int h = 0;
    for (int i = 0; i < citationsSize; i++) {
        // If current citation count is greater than or equal to paper position (1-indexed)
        if (citations[i] >= i + 1) {
            h = i + 1; // Update h-index
        } else {
            break; 
        }
    }
    
    return h;
}

// Main function to test the solution
int main() {
    // test 1
    int citations1[] = {3, 0, 6, 1, 5};
    int size1 = sizeof(citations1) / sizeof(citations1[0]);
    printf("test 1: h-index = %d\n", hIndex(citations1, size1));
    
    // test 2
    int citations2[] = {1, 3, 1};
    int size2 = sizeof(citations2) / sizeof(citations2[0]);
    printf("test 2: h-index = %d\n", hIndex(citations2, size2));
    
    // test 3
    int citations3[] = {100};
    int size3 = sizeof(citations3) / sizeof(citations3[0]);
    printf("test 3: h-index = %d\n", hIndex(citations3, size3));
    
    // test 4
    int citations4[] = {0, 0, 0};
    int size4 = sizeof(citations4) / sizeof(citations4[0]);
    printf("test 4: h-index = %d\n", hIndex(citations4, size4));
    
    return 0;
}
