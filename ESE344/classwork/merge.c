#include <stdio.h>

void printArray(int A[], int n, int highlight1, int highlight2) {
    for(int i = 0; i < n; i++) {
        if(i == highlight1 || i == highlight2)
            printf("[%d] ", A[i]);
        else
            printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int A[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Create temp arrays
    int L[n1], R[n2];
    
    // Copy data to temp arrays
    for(i = 0; i < n1; i++)
        L[i] = A[left + i];
    for(j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];
    
    printf("\nMerging subarrays:\n");
    printf("Left subarray: ");
    printArray(L, n1, -1, -1);
    printf("Right subarray: ");
    printArray(R, n2, -1, -1);
    
    // Merge temp arrays back
    i = 0;
    j = 0;
    k = left;
    
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
        printf("Current array state: ");
        printArray(A, right+1, k-1, -1);
    }
    
    // Copy remaining elements of L[]
    while(i < n1) {
        A[k] = L[i];
        i++;
        k++;
        printf("Copying remaining left: ");
        printArray(A, right+1, k-1, -1);
    }
    
    // Copy remaining elements of R[]
    while(j < n2) {
        A[k] = R[j];
        j++;
        k++;
        printf("Copying remaining right: ");
        printArray(A, right+1, k-1, -1);
    }
}

void mergeSort(int A[], int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        
        printf("\nDividing array at mid=%d:\n", mid);
        printf("Current subarray: ");
        printArray(A + left, right - left + 1, -1, -1);
        
        mergeSort(A, left, mid);
        mergeSort(A, mid + 1, right);
        
        merge(A, left, mid, right);
    }
}

int main() {
    int A[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(A) / sizeof(A[0]);
    
    printf("Merge Sort Visualization\n");
    printf("------------------------\n");
    printf("Initial array: ");
    printArray(A, n, -1, -1);
    
    mergeSort(A, 0, n-1);
    
    printf("\nFinal sorted array: ");
    printArray(A, n, -1, -1);
    
    return 0;
}
