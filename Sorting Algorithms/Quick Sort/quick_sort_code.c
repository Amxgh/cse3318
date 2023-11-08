#include <stdio.h>

void swap(int *SwapA, int *SwapB) {
    int temp = *SwapA;
    *SwapA = *SwapB;
    *SwapB = temp;
}

int partition(int A[], int low, int high) {
    int i, j = 0;
    int pivot = A[high];
    i = (low - 1);
    for (j = low; j < high; j++) {
        if (A[j] < pivot) {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[high]);
    return (i + 1);
}

void QuickSort(int A[], int low, int high) {
    if (low < high) {
        int ndx = partition(A, low, high);
        QuickSort(A, low, ndx - 1);
        QuickSort(A, ndx + 1, high);
    }
}

// EVERYTHING BELOW THIS IS FOR DEMONSTRATION PURPOSES
void printArray(int A[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() {
    int array[] = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6};
    int size = sizeof(array) / sizeof(array[0]);

    printf("Unsorted array: \n");
    printArray(array, size);

    QuickSort(array, 0, size - 1);

    printf("Sorted array: \n");
    printArray(array, size);

    return 0;
}