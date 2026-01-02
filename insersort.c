//insertion sort

#include<stdio.h> //printf, sprintf
#include<stdlib.h> //malloc, free
#include<string.h> //memset, strcpy
#include<limits.h> //INT_MAX
#include<math.h> //pow
void swap(int* a, int p, int q)
{
    int k;
    k = a[p];
    a[p] = a[q];
    a[q] = k;
}
void inssort(int*a, int l)
{
    int i;
    for(i=1; i<l; i++)
    {
        int j = i; //take ith element,
        //insert it between 0th and (i-1)th element
        //where it should actually stay.
        //for this, compare ith to (i-1)th element,
        //if lesser, swap and continue the same
        //untill it is no more lesser.
        //once it is not lesser, stop.
        //because, after iteration i=1,
        //0th to 1st elements are sorted.
        //similarly, after iteration i=5,
        //0th to 5th elements are sorted, and so on.
        while(j>0 && a[j]<a[j-1])
        {
            swap(a, j, j-1);
            j--;
        }
    }
}
void printarr(int* a, int l)
{
    int i;
    for(i=0; i<l; i++)
        printf("%d ", a[i]);
    printf("\n");
}
int main()
{
    int a[10] = {0};

    printf("enter 10 numbers\n");
    int i = 0;
    while(i<10 && scanf("%d", &a[i])==1)
        i++;
    printarr(a, 10);

    inssort(a, 10);
    printarr(a, 10);

    printf("hello\n");
    return 0;
}
