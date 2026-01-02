#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

#define REM 0
#define CNT 1
#define GNG 2

int compare(const void* a, const void* b)
{
    int*aa=(int*)a;
    int*bb=(int*)b;

    int res=0;
    if(*(aa+CNT)>*(bb+CNT))
        res=1;
    return 1-res; //1-res because we want descending order
}

int nonDivisibleSubset(int k, int s_count, int* s) {

    int book[100][3]={0};
    int i,j;

    for(i=0;i<s_count;i++)
    {
        int rem=s[i]%k;
        book[rem][REM]=rem;
        book[rem][CNT]++;
    }

    qsort(book, 100, sizeof(int)*3, compare);

    //check for all going
    for(i=0;i<100;i++)
    {
        if((book[i][REM]*2)%k!=0) //check if this remainder added with itself breaks the rule
        {
            book[i][GNG]=999; //assume all going

            //check if this added with someone breaks the rule
            for(j=0;j<100;j++)
            {
                if(i==j || book[j][GNG]==0) //don't compare with self, don't compare with others who are not going
                    continue;

                if((book[i][REM]+book[j][REM])%k==0)
                {
                    book[i][GNG]=0; //zero going
                    break; //decided!
                }
            }
            //may be all going or zero going
        }
    }

    //check for one going
    for(i=0;i<100;i++)
    {
        if(book[i][GNG]==0) //for those not going
        {
            book[i][GNG]=1; //assume one going

            //check if this added with someone breaks the rule
            for(j=0;j<100;j++)
            {
                if(i==j || book[j][GNG]==0) //don't compare with self, don't compare with others who are not going
                    continue;

                if((book[i][REM]+book[j][REM])%k==0)
                {
                    book[i][GNG]=0; //zero going
                    break; //decided!
                }
            }
            //may be one going or zero going
        }
    }

    int total = 0;

    //add member counts
    for(i=0;i<100;i++)
    {
        if(book[i][GNG]==999)
            book[i][GNG]=book[i][CNT];
        if(book[i][GNG]==1)
            book[i][GNG]=book[i][CNT]>0? 1: 0;

        printf("%d %d %d\n", book[i][REM], book[i][CNT], book[i][GNG]);
        total+=book[i][GNG];
    }

    return total;
}

int main()
{
    int arr[15]={278, 576, 496, 727, 410, 124, 338, 149, 209, 702, 282, 718, 771, 575, 436};
    int n = nonDivisibleSubset(7, 15, arr);
    printf("%d\n", n);
    return 0;
}

