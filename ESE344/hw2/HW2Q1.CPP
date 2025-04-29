#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int kthSmallest(int** matrix, int matrixSize, int k) {
    
    int totalSize = matrixSize * matrixSize;
    int* arr = (int*)malloc(totalSize * sizeof(int));
    
    // Copy all elements from matrix to array // create array with passed pointers 
    int index = 0;
    for(int i = 0; i < matrixSize; i++) {
        for(int j = 0; j < matrixSize; j++) {
            arr[index++] = matrix[i][j];
        }
    }
    
    // Sort the array with built in qsort
    qsort(arr, totalSize, sizeof(int), compare);
    
    // Get the kth element (k-1 because array is 0-based)
    //set the result to be that index
    int result = arr[k-1];
    
    // Free allocated memory
    free(arr);
    
    return result;
}

int main() {
    // Test case 1
    int matrix1[3][3] = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };
    
    // Convert to "pointer to pointer" format
    int* matrix1Ptr[3];
    for(int i = 0; i < 3; i++) {
        matrix1Ptr[i] = matrix1[i];
    }
    
    int k1 = 8;
    printf("Test 1 Result: %d\n", kthSmallest(matrix1Ptr, 3, k1));
    
    // Test case 2
    int matrix2[1][1] = {{-5}};
    int* matrix2Ptr[1] = {matrix2[0]};
    int k2 = 1;
    printf("Test 2 Result: %d\n", kthSmallest(matrix2Ptr, 1, k2));
    
    return 0;
}
