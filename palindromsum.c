//find sum of all palindromic numbers less than 10000

#include<stdio.h>
#include<stdlib.h>

int chkpal(int i)
{
    int a[4]={-1,-1,-1,-1};
    int j=3;
    int q, r;

    r = i%10; q = i/10;
    while(!(r==0 && q==0))
    {
        a[j] = r;
        j--;
        r = q%10; q = q/10;
    }

    int m=j+1;
    int n=3;
    while(m<=n)
    {
        if(a[m] != a[n])
            return 0;
        m++;
        n--;
    }
    return 1;
}

int main()
{
    int i=0;
    int max = 10000;
    int sum=0;

    for(i=1; i<max; i++)
    {
        if(chkpal(i))
        {
            sum = sum + i;
        }
    }

    printf("%d\n", sum);
    return 0;
}
