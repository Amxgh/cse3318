#include <stdio.h>

void merge(int array[], int left, int mid, int right) {

    int size_of_left = mid - left + 1;
    int size_of_right = right - mid;

    int i, j, k;

    int temp_left[size_of_left], temp_right[size_of_right];

    for (i = 0; i < size_of_left; i++)
        temp_left[i] = array[left + i];

    for (j = 0; j < size_of_right; j++)
        temp_right[j] = array[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while ((i < size_of_left) && (j < size_of_right)) {
        if (temp_left[i] <= temp_right[j]) {
            array[k] = temp_left[i];
            i++;
        } else {
            array[k] = temp_right[j];
            j++;
        }

        k++;
    }

    while (i < size_of_left) {
        array[k] = temp_left[i];
        i++;
        k++;
    }

    while (j < size_of_right) {
        array[k] = temp_right[j];
        j++;
        k++;
    }
}

void merge_sort(int array[], int left, int right) {
    if (left >= right)
        return;
    else {
        int mid = (left + right) / 2;

        merge_sort(array, left, mid);
        merge_sort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

// Everything below this is for demonstration purposes.

void printArray(int A[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() {
    int arr[] = {4, 0, 3, 1, 2};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    merge_sort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
