#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

int migratoryBirds(int arr_count, int* arr) {
    int carr[6]={0};
    int carr_count=6;
    for(int i=0; i<arr_count; i++)
    {
        carr[arr[i]]++;
    }

    for(int i=0; i<carr_count;i++)
    {
        printf("%d ", carr[i]);
    }

    int max_count=0;
    for(int i=1; i<carr_count;i++)
    {
        if(carr[i]>max_count)
            max_count = carr[i];
    }
    int min_val=0;
    for(int i=1; i<carr_count;i++)
    {
        if(carr[i]==max_count)
        {
            min_val = i;
            break;
        }
    }
    return min_val;
}

int main()
{
    int arr_count = 11;
    int arr[11] = {1, 2, 3, 4, 5, 4, 3, 2, 1, 3, 4};
    int val = migratoryBirds(arr_count, arr);
    printf("\n\n%d\n", val);
    return 0;
}

