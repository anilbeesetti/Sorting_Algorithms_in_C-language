/***********************
 * Author:  AttitudeAnil
 * Date:    03-02-2001
*************************/

// Prototypes------------
void SelectionSort(int array[], int arrayLength);
void SelectionSwap(int *a, int *b);
// End of Prototypes-----------

// selection sort works by selecting the smallest number and swaping them to front of the array.
void SelectionSort(int array[], int arrayLength)
{
    int smallNumberIndex;
    for (int i = 0; i < arrayLength; i++)
    {
        smallNumberIndex = i;
        for (int j = i + 1; j < arrayLength; j++)
        {
            if (array[smallNumberIndex] > array[j])
            {
                smallNumberIndex = j;
            }
        }

        SelectionSwap(&array[i], &array[smallNumberIndex]);
    }
}

void SelectionSwap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}