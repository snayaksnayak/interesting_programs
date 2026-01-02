#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

void countApplesAndOranges(int s, int t, int a, int b,
    int apples_count, int* apples, int oranges_count, int* oranges)
{
    //s = house start
    //t = house end
    //a = apple tree
    //b = orange tree
    int i;
    int num_apples=0;
    for(i=0; i<apples_count; i++)
    {
        if(a+apples[i]>=s && a+apples[i]<=t)
        {
            num_apples++;
        }
    }

    int j;
    int num_oranges=0;
    for(j=0; j<oranges_count; j++)
    {
        if(b+oranges[j]>=s && b+oranges[j]<=t)
        {
            num_oranges++;
        }
    }
    printf("%d\n", num_apples);
    printf("%d\n", num_oranges);
}

int main()
{
    int apples[]={-2, 2, 1};
    int oranges[]={5, -6};
    countApplesAndOranges(7, 11, 5, 15,
    3, apples, 2, oranges);

    return 0;
}

