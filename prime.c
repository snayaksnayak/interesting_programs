#include<stdio.h> //printf, sprintf
#include<stdlib.h> //malloc, free
#include<string.h> //memset, strcpy
#include<limits.h> //INT_MAX
#include<math.h> //pow
int main()
{
    printf("hello\n");

    int a[100]={0};
    int filled_index = -1;
    int number = 2;

    while(filled_index < 100-1)
    {
        int div_count = 0;
        int index=0;
        int i;
        for(i = 1; i <= number/i;  ) // = needed for non-memoization solution
        {
printf("%d`", i);
            if((number % i) == 0)
                div_count++;

            //get next prime number
            if( index <= filled_index )
            {
                i=a[index]; index++;
printf("%d ", i);
            }
            else //only needed for first time, when a[] is not filled at all
                i++;
        }
printf("for %d\n", number);

        if(div_count == 1)
        {
            filled_index++;
            a[filled_index] = number;
printf("prime: %d\n", number);
        }

        number++;
    }

    int j;
    for(j=0; j<100; j++)
        printf("%d ", a[j]);
    printf("\n");

    return 0;
}
