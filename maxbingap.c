#include<stdio.h> //printf, sprintf
#include<stdlib.h> //malloc, free
#include<string.h> //memset, strcpy
#include<limits.h> //INT_MAX
#include<math.h> //pow

int solution(int N)
{
    int max = 0;
    int count = 0;
    int p = 0;
    int q = 0;

    int i;
    for(i=31; i>=0;)
    {
        while(p==0)
        {
            p=N&1; N=N>>1; i--;
        }

        count = 0;
        q = 0;
        while(q==0 && i>=0)
        {
            q=N&1; N=N>>1; i--;
            if(q==0)
                count++;
        }

        if(q==1)
        {
            if(count>max)
                max = count;
        }

        p = q;
    }
    return max;
}

int main()
{
    printf("hello\n");

    int k = solution(1041); //9-2, 529-4, 20-1, 15-0, 32-0, 1041-5
    printf("%d\n", k);

    return 0;
}
