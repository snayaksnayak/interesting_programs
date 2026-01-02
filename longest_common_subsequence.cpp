#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

//given two strings, find longest common subsequnce

int max(int a, int b)
{
    int max;
    if(a>b)
        max=a;
    else
        max=b;
    return max;
}

#define MAX_LEN 5001
int LCS[MAX_LEN][MAX_LEN]={0}; //1 for empty string ""

int longest_common_subsequence(char* x, int m, char* y, int n)
{
    int i, j;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(x[i-1]==y[j-1]) //1st row i=0 and 1st column j=0 is for empty string ""
            {
                LCS[i][j] = 1 + LCS[i-1][j-1];
            }
            else
            {
                LCS[i][j] = max(LCS[i][j-1], LCS[i-1][j]);
            }
        }
    }

/*
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            printf("%d ", LCS[i][j]);
        }
        printf("\n");
    }
*/

    return LCS[m][n];
}

int main()
{
    char x[MAX_LEN]="harry";
    char y[MAX_LEN]="sally";
    printf("%d\n", longest_common_subsequence(x, strlen(x), y, strlen(y)));
    return 0;
}

