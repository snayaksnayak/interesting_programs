//quick sort

#include<stdio.h> //printf, sprintf
#include<stdlib.h> //malloc, free
#include<string.h> //memset, strcpy
#include<limits.h> //INT_MAX
#include<math.h> //pow
void swap(int* a, int l, int u)
{
    int k = a[l];
    a[l] = a[u];
    a[u] = k;
}
int partition(int* a, int lb, int ub)
{
    int l = lb;
    int u = ub;

    int m = a[lb]; //m=pivot element; value
    while(l<u)
    {
        while(a[l]<=m && l<ub)
            l++;
        while(a[u]>=m && u>lb)
            u--;
        if(l<u)
            swap(a, l, u);
    }
    swap(a, lb, u); //lb=pivot position
    return u;
}
void quicksort(int* a, int lb, int ub)
{
    int p;
    if(!(lb<ub)) //minimum 2 elements
        return;
    p = partition(a, lb, ub);
    quicksort(a, lb, p-1);
    quicksort(a, p+1, ub);
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
    int a[10]={0};
    int i = 0;

    printf("enter 10 numbers\n");
    while(i<10 && scanf("%d", &a[i]) == 1)
        i++;
    printarr(a, 10);

    quicksort(a, 0, 9);
    printarr(a, 10);

    return 0;
}
