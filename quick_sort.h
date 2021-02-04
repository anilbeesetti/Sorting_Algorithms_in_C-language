/***********************
 * Author:  AttitudeAnil
 * Date:    03-02-2001
*************************/

/***********************************
    Quicksort is a divide and conquer algorithm. It first divides the input array into two smaller sub-arrays: the low elements and the high elements. It then recursively sorts the sub-arrays. The steps for in-place Quicksort are:

    1. Pick an element, called a pivot, from the array.
    2. Partitioning: reorder the array so that all elements with values less than the pivot come before the pivot, while all elements with values greater than the pivot come after it (equal values can go either way). After this partitioning, the pivot is in its final position. This is called the partition operation.
    3. Recursively apply the above steps to the sub-array of elements with smaller values and separately to the sub-array of elements with greater values.

    4. The base case of the recursion is arrays of size zero or one, which are in order by definition, so they never need to be sorted.
    5.The pivot selection and partitioning steps can be done in several different ways; the choice of specific implementation schemes greatly affects the algorithm's performance. 
*************************************/

// Prototypes------------
void QuickSortHelper(int low, int high, int array[]);
int QuickPartition(int low , int high, int array[]);
void QuickSwap(int *a, int *b);
void QuickSort(int array[], int arrayLength);
// End of Prototypes-----------

void QuickSort(int array[], int arrayLength)
{
    QuickSortHelper(0, arrayLength - 1, array);
}

void QuickSortHelper(int low, int high, int array[])
{
    if(low < high)
    {
        // pivot is the number which is returned by partition function
        // call QuickSort on first half excluding pivot
        // call QucikSort on Second half excluding pivot
        int pivot = QuickPartition(low, high, array);
        QuickSortHelper(low, pivot - 1, array);
        QuickSortHelper(pivot + 1, high, array);
    }
}

int QuickPartition(int low , int high, int array[])
{
    // Selecting pivot as the last index
    int pivot = high;
    int lowIndex = low;
    // highIndex excluding pivot
    int highIndex = high - 1;

    while(1)
    {
        // Checking for number greater than the number at pivot
        while(array[lowIndex] < array[pivot])
        {
            lowIndex++;
        }
        // Checking for number less than the number at pivot
        while (array[highIndex] > array[pivot] && highIndex > 0)
        {
            highIndex--;
        }

        // Swaping numbers at lowIndex and highIndex to satisfy QuickSort only 
        // if lowIndex is less than highIndex
        if(lowIndex >= highIndex)
        {
            break;
        }
        else
        {
            QuickSwap(&array[lowIndex], &array[highIndex]);
        }
    }

    // Placing pivot at its sorted position
    QuickSwap(&array[lowIndex], &array[pivot]);
    return lowIndex;
}

void QuickSwap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}