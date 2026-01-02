//selection sort

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
void selecsort(int*a, int l)
{
    int i;
    for(i=0; i<l; i++) //i defines where to put the selected smallest
    {
        int j = i; //start from i

        int minpos = j;
        while(j<l) //till array end find the smallest element
        {
            if(a[j] < a[minpos])
                minpos = j;
            j++;
        }

        swap(a, i, minpos); //put the smallest element at i
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

    selecsort(a, 10);
    printarr(a, 10);

    printf("hello\n");
    return 0;
}
