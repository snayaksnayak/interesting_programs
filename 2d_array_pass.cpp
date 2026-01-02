#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

int hourglassSum(int arr_rows, int arr_columns, int** arr)
{
    int i,j;

    int** out;
    out = (int**)malloc(arr_rows*sizeof(int*));
    for(i=0;i<arr_rows;i++)
    {
        *(out+i) = (int*)malloc(arr_columns*sizeof(int));
        for(j=0;j<arr_columns;j++)
        {
            //*( *(out+i) + j) = 0;
            out[i][j]=0;
        }
    }

    int max=-63;

    for(i=1;i<arr_rows-1;i++)
    {
        for(j=1;j<arr_columns-1;j++)
        {
            out[i][j]=arr[i-1][j-1]+arr[i-1][j]+arr[i-1][j+1] //hour glass shape
                        +arr[i][j]
                        +arr[i+1][j-1]+arr[i+1][j]+arr[i+1][j+1];
            if(out[i][j]>max)
                max=out[i][j];
        }
    }

    return max;
}


int main()
{
    int i,j;

    int** arr;
    arr = (int**)malloc(6*sizeof(int*));
    for(i=0;i<6;i++)
    {
        *(arr+i) = (int*)malloc(6*sizeof(int));
        for(j=0;j<6;j++)
        {
            //*( *(arr+i) + j) = 0;
            arr[i][j]=0;
        }
    }

    printf("%d\n", hourglassSum(6, 6, arr));
    return 0;
}

