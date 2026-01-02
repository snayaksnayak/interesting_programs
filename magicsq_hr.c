//find minimum changes to make a 3x3 magic square of numbers.
//if you change 7 to 5, change is 2
//if you change 3 to 6, change is 3
//add all changes to get the total change
//this total change should be minimum

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

int cmp(const void* pa, const void* pb)
{
    int a = *(int*)pa;
    int b = *(int*)pb;

    if(a > b) return 1;
    else if(a < b) return -1;
    else return 0;
}
// Complete the formingMagicSquare function below.
int formingMagicSquare(int s_rows, int s_columns, int** s) {
    int ms[8][9]={
        {2,9,4,7,5,3,6,1,8},
        {2,7,6,9,5,1,4,3,8},
        {4,9,2,3,5,7,8,1,6},
        {4,3,8,9,5,1,2,7,6},
        {6,7,2,1,5,9,8,3,4},
        {6,1,8,7,5,3,2,9,4},
        {8,1,6,3,5,7,4,9,2},
        {8,3,4,1,5,9,6,7,2},
    };

    int i, j;
    int gs[9];
    for(i=0; i<s_rows; i++)
        for(j=0; j<s_columns; j++)
        {
            gs[i*3+j] = *(*(s+i)+j);
            //printf("%d - %d\n", i*3+j, gs[i*3+j]);
        }

    int c[8];
    for(i=0; i<8; i++)
    {
        c[i]=0;
        for(j=0; j<9; j++)
        {
            c[i] += abs(ms[i][j]-gs[j]);
        }
    }

    qsort(c, 8, sizeof(int), cmp);

    //for(i=0; i<8; i++)
        //printf("%d ", c[i]);
    //printf("\n");

    return c[0];
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int** s = malloc(3 * sizeof(int*));

    for (int i = 0; i < 3; i++) {
        *(s + i) = malloc(3 * (sizeof(int)));

        char** s_item_temp = split_string(readline());

        for (int j = 0; j < 3; j++) {
            char* s_item_endptr;
            char* s_item_str = *(s_item_temp + j);
            int s_item = strtol(s_item_str, &s_item_endptr, 10);

            if (s_item_endptr == s_item_str || *s_item_endptr != '\0') { exit(EXIT_FAILURE); }

            *(*(s + i) + j) = s_item;
        }
    }

    int s_rows = 3;
    int s_columns = 3;

    int result = formingMagicSquare(s_rows, s_columns, s);

    //fprintf(fptr, "%d\n", result);

    //fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!line) {
            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);
    } else {
        data = realloc(data, data_length + 1);

        data[data_length] = '\0';
    }

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}
