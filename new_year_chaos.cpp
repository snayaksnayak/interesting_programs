#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

void minimumBribes(int q_count, int* q)
{
    int i;
    int b=0;
    int p1;
    int p2;
    int t;
    for(i=q_count-1; i>=0; i--)
    {
        int num=i+1;
        if(q[i] != num)
        {
            if(i>=2)
            {
                p1 = i-1;
                p2 = i-2;
                if(q[p1] == num)
                {
                    t=q[p1];
                    q[p1]=q[i];
                    q[i]=t;

                    b++;
                }
                else if(q[p2] == num)
                {
                    t=q[p2];
                    q[p2]=q[p1];
                    q[p1]=t;

                    b++;

                    t=q[p1];
                    q[p1]=q[i];
                    q[i]=t;

                    b++;
                }
                else
                {
                    printf("Too chaotic\n");
                    return;
                }
            }
            else if(i==1)
            {
                p1 = 0;
                if(q[p1] == num)
                {
                    t=q[p1];
                    q[p1]=q[i];
                    q[i]=t;

                    b++;
                }
                else
                {
                    printf("impossible 1\n");
                    return;
                }
            }
            else
            {
                printf("impossible 0\n");
                return;
            }
        }
        else
        {
            continue;
        }
    }
    printf("%d\n", b);
}

int main()
{
    int a[5]={2, 1, 5, 3, 4};
    minimumBribes(5, &a[0]);
    return 0;
}

