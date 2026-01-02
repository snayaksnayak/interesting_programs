#include<stdio.h> //printf, sprintf
#include<stdlib.h> //malloc, free
#include<string.h> //memset, strcpy
#include<limits.h> //INT_MAX
#include<math.h> //pow

int cmp(const void* pa, const void* pb)
{
    int a = *(int*)pa;
    int b = *(int*)pb;

    if(a > b) return 1;
    else if(a < b) return -1;
    else return 0;
}

//time O(NlogN), space O(1)
int mode(int* a, int l)
{
    qsort(a, l, sizeof(int), cmp);

    int md = a[0];
    int mdcnt = 1;

    int curr = a[0];
    int cnt = 1;
    int i;
    for(i=1; i<l; i++)
    {
        if(a[i]==curr)
        {
            cnt++;
        }
        else
        {
            if(cnt>mdcnt)
            {
                md = curr;
                mdcnt = cnt;
            }
            curr = a[i];
            cnt = 1;
        }
    }
    if(cnt>mdcnt)
    {
        md = curr;
        mdcnt = cnt;
    }

    return md;
}

int main()
{
    printf("hello\n");

    int a[10] = {0, 1, 2, 3, 3, 3, 4, 5, 5, 5};
    printf("mode = %d", mode(&a[0], 10));

    return 0;
}
