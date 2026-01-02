#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

long arrayManipulation(int n, int queries_rows, int queries_columns, int** queries)
{
    long* p = (long*) malloc(sizeof(long) * n+1);
    memset(p, 0, sizeof(long)*(n+1));
    long max=0;
    int i, j;
    for(i=0; i<queries_rows; i++)
    {
        for(j=queries[i][0]; j<=queries[i][1]; j++)
        {
            p[j] += queries[i][2];
            if(p[j] > max)
                max = p[j];
        }
    }

    return max;
}

int main()
{
    int i,j;
    int row = 3;
    int col = 3;
    int** q = (int**) malloc(sizeof(int*) * row);
    for(i=0; i<row; i++)
    {
        q[i] = (int*) malloc(sizeof(int) * col);
        for(j=0; j<col; j++)
        {
            q[i][j]=0;
        }
    }

    q[0][0]=1; q[0][1]=2; q[0][2]=100;
    q[1][0]=2; q[1][1]=5; q[1][2]=100;
    q[2][0]=3; q[2][1]=4; q[2][2]=100;

    long m = arrayManipulation(5, row, col, q);
    printf("%ld\n", m);
    return 0;
}

