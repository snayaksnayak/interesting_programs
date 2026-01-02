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

int cmp(char* a, char* b)
{
    while(*a != '\0' && *b != '\0')
    {
        if(*a < *b) {return -1;}
        else if(*a > *b) {return 1;}
        else {a++; b++;}
    }
    if(*a == '\0'){return 1;}
    else if(*b == '\0'){return -1;}
    else return 0;
}
// Complete the morganAndString function below.

// Please either make the string static or allocate on the heap. For example,
// static char str[] = "hello world";
// return str;
//
// OR
//
// char* str = "hello world";
// return str;
//
char* morganAndString(char* a, char* b)
{
    size_t blocksz = 1024;
    char* r = (char*)malloc(blocksz);
    size_t allocsz = blocksz;
    int i = 0;
    int add_from_a = 0;
    int add_from_b = 0;

    while(*a != '\0' || *b != '\0')
    {
        if(*a == '\0')
        {
            r[i] = *b; b++; i++;
        }
        else if(*b == '\0')
        {
            r[i] = *a; a++; i++;
        }
        else
        {
            if(add_from_a)
            {
                if(r[i-1] == *a)
                    {r[i] = *a; a++; i++;}
                else
                    {add_from_a = 0;}
            }
            else if(add_from_b)
            {
                if(r[i-1] == *b)
                    {r[i] = *b; b++; i++;}
                else
                    {add_from_b = 0;}
            }
            else
            {
                if(*a < *b)
                {
                    r[i] = *a; a++; i++;
                }
                else if(*a > *b)
                {
                    r[i] = *b; b++; i++;
                }
                else
                {
                    int ans = cmp(a, b);
                    if(ans < 0)
                    {
                        r[i] = *a; a++; i++;
                        add_from_a = 1;
                    }
                    else if(ans > 0)
                    {
                        r[i] = *b; b++; i++;
                        add_from_b = 1;
                    }
                    else //same
                    {
                        r[i] = *a; a++; i++;
                        add_from_a = 1;
                    }
                }
            }
        }

        if(i == allocsz - 1)
        {
            allocsz = allocsz + blocksz;
            r = realloc(r, allocsz);
            if(!r)
            {
                free(r); return 0;
            }
        }
    }

    r[i] = '\0';
    return r;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* t_endptr;
    char* t_str = readline();
    int t = strtol(t_str, &t_endptr, 10);

    if (t_endptr == t_str || *t_endptr != '\0') { exit(EXIT_FAILURE); }

    for (int t_itr = 0; t_itr < t; t_itr++) {
        char* a = readline();

        char* b = readline();

        char* result = morganAndString(a, b);

        fprintf(fptr, "%s\n", result);
    }

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}
