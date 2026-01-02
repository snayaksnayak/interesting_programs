#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

int jumpingOnClouds(int c_count, int* c)
{
    int zs=0, ze;
    int i, d, jumps=0;
    for(i=0;i<c_count;i++)
    {
        if(c[i]==1)
        {
            ze=i-1;

            d=ze-zs;
            jumps += d==0?0:(d+1)/2;

            jumps++;

            zs=i+1;
        }
    }

    ze=i-1;

    d=ze-zs;
    jumps += d==0?0:(d+1)/2;

    return jumps;
}


int main()
{
    int c[]={0,1,0,0,1,0};
    printf("%d\n", jumpingOnClouds(6,c));
    return 0;
}

