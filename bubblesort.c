//bubble sort

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
void bubblesort(int*a, int l)
{
    int i, j;
    for(i=0; i<l; i++) //i tells us, sort elements from ith to array end, left to ith element, it is already sorted.
    {
        for(j=l-1; j>i; j--) //bubble up smaller element towards left of array
        {
            if(a[j]<a[j-1])
                swap(a, j, j-1);
        }
        //at this point, for i=0, the smallest element must have come to 0th position
        //for i=1, the next smaller element must have come to 1st position
        //for i=2, the next small element must have come to 2nd position
        //and so on.
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

    bubblesort(a, 10);
    printarr(a, 10);

    printf("hello\n");
    return 0;
}
