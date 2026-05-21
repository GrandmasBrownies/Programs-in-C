// 2026 Joel Tann

#include "boyer_moore.h"
#include "input_gen.h"

#define MAX_PATTERN_LENGTH 101
#define MAX_TEXT_LENGTH 256

int main()
{
    int runs = 0; // To count how many runs the program performs
    int max_runs = 0; // Max amount of runs (user defines later)
    
    unsigned int op_boyer = 0;
    unsigned int op_force = 0;
    
    char text_type[30];
    char pat_pos[30];

    char text[MAX_TEXT_LENGTH];
    char pat[MAX_PATTERN_LENGTH];

    int position = 0;
    
    printf("Type pattern to search for:\n");
    scanf("%s", pat);

    int patlen = strlen(pat);
    int textlen = MAX_TEXT_LENGTH - 1;

    int choice_pattern = 0;
    int choice_text = 0;

    do
    {
        if (choice_text == 0) // If program runs more then once it won't print this agian
        {
            printf("Type of text:\n");
            printf("(1) Text contains characters that is not part of the pattern\n");
            printf("(2) Random Characters\n");
            printf("(3) Text contains characters that is part of the patter\n");

            scanf("%d", &choice_text);
        }
        
        int valid = 0; // false for now
    
        while (!valid) // Run while loop is false to catch wrong input
        {
            switch (choice_text)
            {
                {
                case 1:
                    char_not_in_pat(textlen, patlen, text, pat);
                    strcpy(text_type, "Patern characters not in text");
                    valid = 1; // Becomes true
                    break;
                case 2:
                    random(textlen, patlen, text, pat);
                    strcpy(text_type, "Random characters in text");
                    valid = 1; // Becomes true
                    break;
                case 3:
                    char_in_pat(textlen, patlen, text, pat);
                    strcpy(text_type, "Patern characters in text");
                    valid = 1; // Becomes true
                    break;
                default:
                    printf("Invalid choice. Please try agian\n");
                }
            }
        }
        
        if (runs == 0)
        {
            printf("How many runs should this pattern on this text type perform? (1-30):\n");
            scanf("%d", &max_runs);
        }
        
        if (choice_pattern == 0)
        {
            printf("Chose where to find pattern:\n");
            printf("(1) pattern being first word\n");
            printf("(2) pattern in the middle\n");
            printf("(3) pattern not in text\n");
            
            scanf("%d", &choice_pattern);
        }
        
        int middle = textlen / 2; // Used for upcoming case 2
    
        valid = 0; // false for now
    
        while (!valid) // Run while loop is false to catch wrong input
        {
            switch (choice_pattern)
            {
                {
                case 1:
                    for (int i = 0; i < patlen; i++)
                    {
                        text[i] = pat[i];
                    }
    
                    strcpy(pat_pos, "Begining");
                    valid = 1; // Becomes true
                    break;
    
                case 2:
                    for (int i = 0; i < patlen; i++)
                    {
                        text[middle + i] = pat[i];
                    }
    
                    strcpy(pat_pos, "Middle");
                    valid = 1; // Becomes true
                    break;
    
                case 3:
                    strcpy(pat_pos, "Not in text");
                    valid = 1; // Becomes true
                    break;
    
                default:
                    printf("Invalid choice. Please try agian\n");
                }
            }
        }

        brute_force(text, pat, textlen, patlen, &op_force);
        position = boyer_moore(text, pat, textlen, patlen, &op_boyer);

        runs++;
    } while (runs < max_runs);

    op_boyer /= runs;
    op_force /= runs;
    
    printf("%s\n", text);

    if (position >= 0) {
        printf("Found match at text[%d]\n", position);
    }
    else {
        printf("Could not find pattern in text\n");
    }

    char *pattern_pos = malloc(position + 2 * sizeof(*pattern_pos)); // simply used to show in output_text.txt where pattern is found
    if (!pattern_pos) {
        printf("Could not allocate memory\n");
        exit(1);
    }

    int j = 0;
    while(j <= position)
    {
        pattern_pos[j] = ' ';
        j++;
    }
    pattern_pos[j] = '\0';

    char *arrow_pos = malloc(patlen * sizeof(*arrow_pos)); // simply used to show in output_text.txt where pattern is found
    if (!arrow_pos) {
        printf("Could not allocate memory\n");
        exit(1);
    }

    int k = 0;
    while (k < patlen)
    {
        arrow_pos[k] = '^';
        k++;
    }
    arrow_pos[k] = '\0';

    FILE *pfile = NULL;

    pfile = fopen("output_text.txt", "w");
    if (!pfile) {
        printf("Could not write to file\n");
        fclose(pfile);
    }
    else if (choice_pattern == 3) { // pattern not in text. Another output_text.txt is desired
        fprintf(pfile, "Text:    %s\n", text);
        fprintf(pfile, "Pattern: not in text\n");
    }
    else { // Pattern is in text. Shows where, by writing to output_text.txt
        fprintf(pfile, "Text:     %s\n", text);
        fprintf(pfile, "         %s%s\n", pattern_pos, arrow_pos);
        fprintf(pfile, "Pattern: %s%s\n", pattern_pos, pat);
    }
    fclose(pfile);

    free (pattern_pos);
    free (arrow_pos);
    
    pfile = fopen("output_values.txt", "a");
    if (!pfile) {
        printf("Could not write to file\n");
        fclose(pfile);
    }
    else {
        fprintf(pfile, "Type of text:      %s\n", text_type);
        fprintf(pfile, "Pattern position:  %s\n", pat_pos);
        fprintf(pfile, "Pattern length:    %d\n", patlen);
        fprintf(pfile, "--------------------------------\n");
        fprintf(pfile, "Boyer-Moore:            %u\n", op_boyer);
        fprintf(pfile, "Brute-Force:            %u\n\n\n", op_force);
    }
    fclose(pfile);

    return 0;
}