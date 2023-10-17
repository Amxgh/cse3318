void insertionSort(int *array, int N) // N is the number of elements in the array
{
    int i, j, key;
    for (j = 1; j < N; j++)
    {
        key = array[j];
        i = j - 1;
        while ((i >= 0) && (array[i] > key))
        {
            array[i + 1] = array[i];
            i--;
        }
        array[i + 1] = key;
    }
}