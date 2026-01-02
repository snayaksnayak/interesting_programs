//find sum of all odd numbers in fibonacci numbers less than 10000

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i= 0;
    int j= 1;
    int k;

    int sum = 0;
    while(j < 10000)
    {
        if(j%2 == 1)
            sum = sum + j;
        k = i + j;
        i = j;
        j = k;
    }

    printf("%d\n", sum);
    return 0;
}
