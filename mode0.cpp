#include<stdio.h> //printf, sprintf
#include<stdlib.h> //malloc, free
#include<string.h> //memset, strcpy
#include<limits.h> //INT_MAX
#include<math.h> //pow

//time O(N^2), space O(1)
int mode(int* a, int l)
{
    int i, j;

    int maxval = -1;
    int maxcnt = 0;

    for(i=0; i<l; i++)
    {
        int cnt = 0;
        for(j=0; j<l; j++)
        {
            if (*(a+j) == *(a+i))
            {
                cnt++;
            }
        }

        if(cnt > maxcnt) //when there are two modes, ">" gives first mode
        //if(cnt >= maxcnt) //">=" gives second mode
        {
           maxcnt = cnt;
           maxval = a[i];
        }
    }

    return maxval;
}

int main()
{
    printf("hello\n");

    int a[10] = {0, 1, 2, 3, 3, 3, 4, 5, 5, 5};
    printf("mode = %d", mode(&a[0], 10));

    return 0;
}
