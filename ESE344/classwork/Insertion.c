#include <stdio.h>

void printArray(int A[], int n, int i, int j) {
    printf("\nArray state: ");
    for(int k = 0; k < n; k++) {
        if(k == i)
            printf("[i:%d] ", A[k]);
        else if(k == j)
            printf("[j:%d] ", A[k]);
        else
            printf("%d ", A[k]);
    }
    printf("\n");
}

void insertionSort(int A[], int n) {
    int i, j, key;
    
    printf("Initial array: ");
    printArray(A, n, -1, -1);
    
    for(j = 1; j < n; j++) {
        printf("\n--- Iteration %d ---\n", j);
        key = A[j];
        printf("Key = %d\n", key);
        
        i = j - 1;
        
        while(i >= 0 && A[i] > key) {
            A[i + 1] = A[i];
            printf("Shifting %d to right\n", A[i]);
            printArray(A, n, i, j);
            i = i - 1;
        }
        A[i + 1] = key;
        printf("Inserting key %d at position %d\n", key, i + 1);
        printArray(A, n, i + 1, j);
    }
    
    printf("\nFinal sorted array: ");
    printArray(A, n, -1, -1);
}

int main() {
    // Using a small array for easy visualization
    int A[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(A) / sizeof(A[0]);
    
    printf("Insertion Sort Visualization\n");
    printf("---------------------------\n");
    
    insertionSort(A, n);
    
    return 0;
}
