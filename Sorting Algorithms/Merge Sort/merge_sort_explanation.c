#include <stdio.h>

void merge(int array[], int left, int mid, int right) {
  /*
  Assume the array is {1,3,4,0,2}
  left = 0
  right = 4
  mid = 2

  After division:
  {1,3,4} and {0, 2}
  NOTE: The subarrays are already sorted. This is because this function is
  called recursively. The explanation in the comments is for the FINAL call to
  this function, that is, for the final array.
  There will never be a situation where the subarrays aren't sorted. 


  size_of_left = mid - left + 1 = 2 - 0 + 1 = 3
  size_of_right = right - mid = 4 - 2 = 2
  */
  int size_of_left = mid - left + 1;
  int size_of_right = right - mid;

  int i, j, k; // Loop variables

  int temp_left[size_of_left], temp_right[size_of_right]; // Temporary Arrays

  // Copy the left part of the array into temp_left
  // Here we do left + i because our given array might not start from 0. It
  // might start from say, 10. In this case left would be 10; so, we use left as
  // an offset
  for (i = 0; i < size_of_left; i++)
    temp_left[i] = array[left + i];

  // Copy the right part of the array into temp_right
  // Here we do mid + 1 + j because we need to set the offset to start AFTER
  // mid. This is because the midpoint is ALWAYS included in left, that would
  // mean you start after the midpoint. So in this case our offset is mid + 1
  for (j = 0; j < size_of_right; j++)
    temp_right[j] = array[mid + 1 + j];

  
  // Now we will begin updating the original array. For this, i and j were
  // initialized to zero. k was initialized to left because our given array
  // might not start from. It's starting point is the number stored inside left.
  // So, we set k to left, again, as an offset. If we are given an entire array
  // (not a sub-array),left will be equal to zero, that means k will also start
  // from zero.
  i = 0;
  j = 0;
  k = left;

  /*
  Reusing the example from the beginning
  array = {1,3,4,0,2}
  left = 0
  right = 4
  mid = 2

  size_of_left = 3
  size_of_right = 2

  temp_left = {1, 3, 4}
  temp_right ={0, 2}

  i=0; j=0; k=0;

  Iteration 1:
    Is 1 <= 0? NO (If condition FAILED. Jumping to else block)
      => array[0] = 0; j++;
      => k++;
  After Iteration 1:
    i=0; j=1; k=1;
    array = {0,3,4,0,2}

  Iteration 2:
    Is 1 <= 2? YES (If condition SATISFIED.)
      => array[1] = 1; i++;
      => k++
  After Iteration 2:
    i=1; j=1; k=2;
    array = {0,1,4,0,2}

  Iteration 3:
    Is 3 <= 2? NO (If condition FAILED. Jumping to else block)
      => array[2] = 2; j++;
      => k++;
  After Iteration 3:
    i=1; j=2; k=3;
    array = {0,1,2,0,2}

  NOW THE WHILE LOOP WILL BREAK.
  This is because j is now equal to size_of_right.
  This causes the condition (j< size_of_right) to fail).
  */
  while ((i < size_of_left) && (j < size_of_right)) {
    if (temp_left[i] <= temp_right[j]) { 
      array[k] = temp_left[i];
      i++;
    }
    else {
      array[k] = temp_right[j];
      j++;
    }

    k++;
  }


  /*
  After the completion of the above loop, we are left with the following:

  temp_left = {1, 3, 4}
  temp_right = {0, 2}

  i=1;
  j=2;
  k=3;

  array = {0,1,2,0,2}

  Based on the above, we can tell that our array does not have 3,4 so we need to
  copy those over.

  The below function will simply copy 3 and 4 into the array.
  */

  while (i < size_of_left) {
    array[k] = temp_left[i];
    i++;
    k++;
  }

  // In our example, we had elements remaining inside temp_left. However, it is
  // possible to have elements remaining inside temp_right. To fix that we need
  // to do the same for temp_right.
  // NOTE: EITHER temp_left OR temp_right will have elements remaining; NOT BOTH
  while (j < size_of_right) {
    array[k] = temp_right[j];
    j++;
    k++;
  }
  
  // End of function
}

void merge_sort(int array[], int left, int right) // N = right-left+1
{
  if (left >= right) // Base case
    return;
  else {
    int mid = (left + right) / 2; // Calculating the midpoint of the array.
    
    merge_sort(array, left, mid); // Sorting array[left:mid] 
    merge_sort(array, mid + 1, right);  // Sorting array[mid+1:right]
    merge(array, left, mid, right); // Merging the final result. 
  }
}

// Everything below this is for demonstration purposes.

// Function to print an array
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
