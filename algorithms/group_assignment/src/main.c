// 2026 Group 10: Joel Tann, Isak Johnson

#include "sorting.h"
#include "input_gen.h"

#define MAX_ORDER_NAME 30
#define MAX_ALG_NAME 30
#define MAX_SIZE 32768

int main()
{
/*     printf("Enter the size of the array:\n");
    scanf("%d", &size); */
    
    int choice_alg = 0;
    int choice_order = 0;
    unsigned long long int op[8] = {0}; // basic operation counter
    int runs = 0; // To count how many runs the program performs (needed for random and almost random ordered input)
    
    char alg_name[MAX_ALG_NAME]; // To print the right algorithm name to file later
    char order_name[MAX_ORDER_NAME]; // To print the right order name to file later
    
    
    unsigned int size;
    unsigned int *array = malloc(MAX_SIZE * sizeof *array);
    if (!array) {
        printf("memory allocation failure\n");
        exit(1);
    }

    do // To be able to run the program 30 times if the array order is random or almost random
    {
        size = 256;
        for (int i = 0; i < 8; i++) // i is the 8 times the program needs to run for all the input sizes (256, 512.. 32768)
        {
            if (choice_order == 0) { // so when program runs agian for the other sizes, you don't get asked agian
                printf("(1) Ordered array\n");
                printf("(2) Reverse ordered array\n");
                printf("(3) Randomized ordered array\n");
                printf("(4) Almost ordered array\n");
                printf("> ");
    
                scanf("%d", &choice_order);
            }
            
            int valid = 0; // if loop should be repeated or not
            while (!valid)
            {
                switch (choice_order)
                {
                    {
                    case 1:
                        gen_ordered(array, size);
                        strcpy(order_name, "Ordered Input");
                        valid = 1;
                        break;
                    case 2:
                        gen_reverse(array, size);
                        strcpy(order_name, "Reverse Ordered Input");
                        valid = 1;
                        break;
                    case 3:
                        gen_random(array, size);
                        strcpy(order_name, "Randomized Input");
                        valid = 1;
                        break;
                    case 4:
                        gen_almost(array, size);
                        strcpy(order_name, "Almost Ordered Input");
                        valid = 1;
                        break;
                    default:
                        printf("Invalid choice. Please try agian\n");
                    }
                }
            }
        
            
            if (choice_alg == 0) { // so when program runs agian for the other sizes, you don't get asked agian
                printf ("(1) selection sort\n");
                printf ("(2) insertion sort\n");
                printf ("(3) merge sort\n");
                printf("> ");
                
                scanf("%d", &choice_alg);
            }
            
            valid = 0; // if loop should be repeated or not
            while (!valid)
            {
                switch (choice_alg)
                {
                    {
                    case 1:
                        selection_sort(array, size, &op[i]);
                        strcpy(alg_name, "Selection Sort");
                        valid = 1;
                        break;
                    case 2:
                        insertion_sort(array, size, &op[i]);
                        strcpy(alg_name, "Insertion Sort");
                        valid = 1;
                        break;
                    case 3:
                        merge_sort(array, size, &op[i]);
                        strcpy(alg_name, "Merge Sort");
                        valid = 1;
                        break;
                    default:
                        printf("Invalid choice. Please try agian\n");
                    }
                }    
            }
            size *= 2;
        }
        runs++;
    } while ((choice_order == 3 || choice_order == 4) && runs < 30);

    // Since they are at the end of the loop they run 1 more time then they should
    size /= 2;

    if (choice_order == 3 || choice_order == 4) { // If random or almost random ordered input
        for (int i = 0; i < 8; i++) {
            op[i] /= runs; // devide with the amount of runs (30 in this case) to get the average
        }
    }

    FILE *pfile = NULL;
    
    pfile = fopen("output.txt", "a");
    if (!pfile) {
        printf("Could not write to file\n");
        fclose(pfile);
    }
    else {
        fprintf(pfile, "Algorithm: %s\n", alg_name);
        fprintf(pfile, "Input:     %s\n", order_name);
        fprintf(pfile, "Size n     %d\n", size);
        fprintf(pfile, "--------------------------------\n");
        fprintf(pfile, "256          %llu\n", op[0]);
        fprintf(pfile, "512          %llu\n", op[1]);
        fprintf(pfile, "1024         %llu\n", op[2]);
        fprintf(pfile, "2048         %llu\n", op[3]);
        fprintf(pfile, "4096         %llu\n", op[4]);
        fprintf(pfile, "8192         %llu\n", op[5]);
        fprintf(pfile, "16384        %llu\n", op[6]);
        fprintf(pfile, "32768        %llu\n\n", op[7]);
        fclose(pfile);
    }
    
    free (array);

    return 0;
}