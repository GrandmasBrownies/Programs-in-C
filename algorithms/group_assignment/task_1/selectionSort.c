// 2026 Group 10: Joel Tann, Isak Johnson

void selection_sort(unsigned int *array, unsigned int size)
{
    for (int i = 0; i < size-2; i++)
    {
        int min = i;
        for (int j = i+1; j < size-1; j++)
        {
            if (array[j] < array[min]) { // find smallest
                min = j;
            }
        }
        // swap
        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}