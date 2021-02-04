/***********************
 * Author:  AttitudeAnil
 * Date:    03-02-2001
*************************/

// Prototypes------------
void BubbleSort(int array[], int arrayLength);
void BubbleSwap(int *a, int *b);
// End of Prototypes-----------

// bubble sort works by bubbling the larger numbers to end of the array.
void BubbleSort(int array[], int arrayLength)
{
    int swap = 0;
    do
    {
        swap = 0;
        for (int i = 0; i < arrayLength - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                BubbleSwap(&array[i], &array[i + 1]);
                swap = 1;
            }
        }
    } while (swap != 0);
}

void BubbleSwap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}