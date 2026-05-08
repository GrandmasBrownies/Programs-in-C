// 2026 Group 10: Joel Tann, Isak Johnson

#include <stdlib.h>

// Swap helper
void swap(unsigned int *a, unsigned int *b) {
    unsigned int temp = *a;
    *a = *b;
    *b = temp;
}

// Ordered
void gen_ordered(unsigned int *array, unsigned int size){
    for (unsigned int i = 0; i < size; i++){
        array[i] = i + 1;
    }
}

// Reverse order
void gen_reverse(unsigned int *array, unsigned int size){
    for (unsigned int i = 0; i < size; i++){
        array[i] = size - i;
    }
}
// Random order
void gen_random(unsigned int *array, unsigned int size){
    gen_ordered(array, size);

    for (unsigned int i = size - 1; i > 0; i--){

        unsigned int j = rand() % (i + 1);
        swap(&array[i], &array[j]);
    }
}
// Almost ordered
void gen_almost(unsigned int *array, unsigned int size){
    gen_ordered(array, size);

    // Calculate 4% of size
    // size * 0.02 because each swap affects 2 elements
    int num_swap = (int)(size * 0.02);
    if (num_swap < 1 && size > 1) num_swap = 1; // Ensures one swap

    for (int i = 0; i < num_swap; i++){
        unsigned int id1 = rand() % size;
        unsigned int id2 = rand() % size;
        swap(&array[id1], &array[id2]);
    }

}