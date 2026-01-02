#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

//array left rotate

int* rotLeft(int a_count, int* a, int d, int* result_count)
{
    int* p = (int*) malloc(a_count*sizeof(int));
    *result_count = a_count;
    int i, j;

    int r = d % a_count;
    for(i=0; i<a_count; i++)
    {
        //for left rotate
        j = (i-r+a_count) % a_count;
        //for right rotate
        //j = (i+r+a_count) % a_count;
        p[j]=a[i];
    }

    return p;
}

int main()
{
    int i;

    int* arr;
    arr = (int*)malloc(10*sizeof(int));
    for(i=0;i<10;i++)
    {
        arr[i] = i;
    }

    for(i=0;i<10;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int res_count;
    int*p = rotLeft(10, arr, 6, &res_count);

    for(i=0;i<res_count;i++)
    {
        printf("%d ", p[i]);
    }
    printf("\n");

    return 0;
}

