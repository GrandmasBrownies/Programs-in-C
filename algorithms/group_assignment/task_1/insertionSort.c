// 2026 Group 10: Joel Tann, Isak Johnson

void insertion_sort(unsigned int *array, unsigned int size)
{
    for (int i = 1; i < size; i++){
        unsigned int key = array[i];
        int j = i - 1;

        while(j >= 0 && array[j] > key){
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}