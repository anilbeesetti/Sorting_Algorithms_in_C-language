#include <stdio.h>
#include "quick_sort.h"
#include "bubble_sort.h"
#include "merge_sort.h"
#include "selection_sort.h"

int main()
{
    int numbers[] = {34,23,23,11,5,2,66,25,16,155,123,121,352,1232,1212,122,1212,11,5,11,7,97,9,7,9};
    BubbleSort(numbers,25);
    for(int i = 0; i < 25; i++)
    {
        printf("%i\n", numbers[i]);
    }
}
