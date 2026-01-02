#include<stdio.h> //printf, sprintf
#include<stdlib.h> //malloc, free
#include<string.h> //memset, strcpy
#include<limits.h> //INT_MAX
#include<math.h> //pow
int cmp(const void* pa, const void* pb)
{
    int a = *(int*)pa;
    int b = *(int*)pb;

    if(a > b) return 1;
    else if(a < b) return -1;
    else return 0;
}

int solution(int A[], int N)
{
    qsort(A, N, sizeof(int), cmp);

    int i;
    //for(i=0; i<N; i++) printf("%d ", A[i]);
    //printf("\n");

    for(i=0; i<N-1; i++)
    {
        if(A[i]==A[i+1])
            i++;
        else
            return A[i];
    }

    if(i==N-1)
        return A[i];

    return 0;
}

int main()
{
    printf("hello\n");
    //int A[] = {2, 2, 5, 3, 3};
    //int A[] = {2, 2, 3, 5, 5};
    //int A[] = {2, 5, 5, 3, 3};
    int A[] = {5, 5, 3, 3};
    int k = solution(A, 4);
    printf("%d\n", k);

    return 0;
}
