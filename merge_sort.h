/***********************
 * Author:  AttitudeAnil
 * Date:    03-02-2001
*************************/

/***********************************
   Conceptually, a merge sort works as follows:

    1. Divide the unsorted list into n sublists, each containing one element (a list of one element is considered sorted).
    2. Repeatedly merge sublists to produce new sorted sublists until there is only one sublist remaining. This will be the sorted list.
*************************************/

// Prototypes------------
void MergeSort(int array[], int arrayLength);
void MergeSortHelper(int left, int right, int array[]);
void Merge(int low, int mid, int high, int array[]);
// End of Prototypes-----------


void MergeSort(int array[], int arrayLength)
{
    MergeSortHelper(0, arrayLength - 1, array);
}

void MergeSortHelper(int low, int high, int array[])
{
    if(high > low)
    {
        // Dividing Array into two parts and call recursively MergeSort on Both.
        // And Merge the two parts to one array
        int middle = (low + high) / 2;
        MergeSortHelper(low, middle, array);
        MergeSortHelper(middle + 1, high, array);
        Merge(low, middle, high, array);
    }
}

void Merge(int left , int middle, int right, int array[])
{
    int temp[right + 10];

    int arr1index = left;
    int tempIndex = left;
    int arr2index = middle + 1;

    // Merging...
    while ((arr1index <= middle) && (arr2index <= right))
    {
        if (array[arr1index] <= array[arr2index])
        {
            temp[tempIndex] = array[arr1index];
            arr1index++;
        }
        else
        {
            temp[tempIndex] = array[arr2index];
            arr2index++;
        }
        tempIndex++;
    }

    // copying remaining numbers after the merge
    if (arr1index > middle)
    {
        for (int k = arr2index; k <= right; k++)
        {
            temp[tempIndex] = array[k];
            tempIndex++;
        }
    }
    else
    {
        for (int k = arr1index; k <= middle; k++)
        {
            temp[tempIndex] = array[k];
            tempIndex++;
        }
    }

    // Copying numbers from temporary array to main arrray
    for (int k = left; k <= right; k++)
    {
        array[k] = temp[k];
    }
}
