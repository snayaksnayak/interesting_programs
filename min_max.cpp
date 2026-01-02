#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

int compare(const void* a, const void* b)
{
    int res=0;
    if( *(int*)a >= *(int*)b )
        res=1;
    return res;
}
void miniMaxSum(int arr_count, int* arr) {
    int i;
    //for(i=0;i<arr_count;i++)
        //printf("%d ", *(arr+i));
    //printf("\n");
    qsort((void *)arr, arr_count, sizeof(int), compare);
    //for(i=0;i<arr_count;i++)
        //printf("%d ", *(arr+i));
    long long sum = 0;
    for(i=1;i<arr_count-1;i++)
    {
        sum += *(arr+i);
    }
    printf("%lld %lld\n", *(arr+0)+sum, *(arr+4)+sum);
}

int main()
{
    int arr_count = 5;
    int arr[5] = {2, 7, 69, 221, 8974};
    miniMaxSum(arr_count, arr);
    return 0;
}

