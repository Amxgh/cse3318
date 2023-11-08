#include <stdio.h>
/*
void swap(int *SwapA, int *SwapB) - Swaps two integers in an array

int partition(int A[], int low, int high) - Partitions the array into two
    subarrays, one with elements smaller than/equal to the pivot and one with
    elements larger than the pivot. Returns the final index of the pivot.

void QuickSort(int A[], int low, int high) - Recursively calls itself and partition() to
    divide the array into smaller and smaller subarrays until the array is
    "conquered" (sorted).

*/

void swap(int *SwapA, int *SwapB) {
    // A simple swap function that swaps the values of two integers.
    //
    // Psuedo-code:
    // 1) Create a temporary variable that stores the value of the first
    //    integer.
    // 2) Overwrite the value of the first integer with the value of the
    //    second integer.
    // 3) Overwrite the value of the second integer with the value stored inside
    //    the temporary variable.

    int temp = *SwapA;
    *SwapA = *SwapB;
    *SwapB = temp;
}

int partition(int A[], int low, int high) {
    /*
    READ THIS FUNCTION AFTER QuickSort().

    ? Call #1:
        A = {1,3,4,0,2}
        low = 0
        high = 4
        So the subarray we are dealing with is {1,3,4,0,2}

        pivot = A[high] = A[4] = 2
        i = low - 1 = 0 - 1 = -1
        j = low = 0

        * Iteration 1:
            - A[j] = A[0] = 1
            - Is (A[j] < pivot) that is, Is (1 < 2)?
                - Yes, so we increment i by 1, that is, i = 0
                - We swap A[i] and A[j], that is, A[0] and A[0]
        * Post Iteration 1: A = {1,3,4,0,2}, i = 0, j = 0

        * Iteration 2: (j is incremented in the for loop, so j = 1)
            - A[j] = A[1] = 3
            - Is (A[j] < pivot) that is, Is (3 < 2)?
                - No, so we do nothing
        * Post Iteration 2: A = {1,3,4,0,2}, i = 0, j = 1

        * Iteration 3: (j is incremented in the for loop, so j = 2)
            - A[j] = A[2] = 4
            - Is (A[j] < pivot) that is, Is (4 < 2)?
                - No, so we do nothing
        * Post Iteration 3: A = {1,3,4,0,2}, i = 0, j = 2

        * Iteration 4: (j is incremented in the for loop, so j = 3)
            - A[j] = A[3] = 0
            - Is (A[j] < pivot) that is, Is (0 < 2)?
                - Yes, so we increment i by 1, that is, i = 1
                - We swap A[i] and A[j], that is, A[1] and A[3]
        * Post Iteration 4: A = {1,0,4,3,2}, i = 1, j = 3

        * Iteration 5: (j is incremented in the for loop, so j = 4)
            - A[j] = A[4] = 2
            - Is (A[j] < pivot) that is, Is (2 < 2)?
                - No, so we do nothing
        * Post Iteration 5: A = {1,0,4,3,2}, i = 1, j = 4

        The for loop has ended, so we swap A[i+1] and A[high], that is, A[2] and
        A[4]
        Post Swap: A = {1,0,2,3,4}

        We return i+1, that is, 2

    */

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
    /*
    Assume the array is {1,3,4,0,2}

    low = 0
    high = 4

    ? Call #1 to partition():
    ndx = partition(A, 0, 4)   REFER TO CALL #1 in the comments of Partition()
    ndx = 2 (returned value from Call #1)

    ? Recursive Call: QuickSort(A, low, ndx - 1): QuickSort(A, 0, 1)
    ? Call #2 to partition():
    ndx = partition(A, 0, 1)   REFER TO CALL #2 in the comments of Partition()

    */

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