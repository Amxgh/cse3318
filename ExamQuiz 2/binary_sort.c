int binarySearch(int* array, int N, int searchValue){
    int left = 0;
    int right = N - 1;
    int middle = (left + right)/2;

    while ((left <= right) && (array[middle] != searchValue))
    {
        if (array[middle] < searchValue)
            left = middle + 1;
        else
            right = middle - 1;
        
        middle = (left + right)/2;
    }

    if (array[middle] == searchValue)
        return middle;
    else
        return -1;
        
}