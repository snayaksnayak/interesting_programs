#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

#define max 31 //1 for null
char a[max], b[max]; //two operands
char c; //carry or borrow
char t; //temporary result of two digit's operation

#define lim 61 //1 for null
char m[lim]; //for multiplication middle result
char r[lim]; //final result

void strrev(char* src, char* dst) //give sufficient space in dst
{
    int len = strlen(src);
    int k=0;
    for(int i=len-1; i>=0; i--,k++)
    {
        dst[k]=src[i];
    }
    dst[k]=0; //add null to end
}

void add(char* p, char* q, char* ans)
{
    int i;

    //prepare a
    memset(a, 0, max);
    int len1 = strlen(p); if(len1>=max) return;
    strrev(p, a);
    for(i=0; i<len1; i++)
    {
        a[i] -= 48;
    }

    //prepare b
    memset(b, 0, max);
    int len2 = strlen(q); if(len2>=max) return;
    strrev(q, b);
    for(i=0; i<len2; i++)
    {
        b[i] -= 48;
    }

    int bigger_len = len1>len2? len1: len2;
    c=0; //start c with 0
    for(i=0; i<bigger_len; i++)
    {
        t = a[i]+b[i]+c;
        if(t>=10)
        {
            c=1;
            t=t%10;
            r[i]=t;
        }
        else
        {
            c=0;
            r[i]=t;
        }
    }
    if(c==1)
    {
        r[i]=c; //put carry at end
        i++;

        r[i]=0; //put null char
    }
    else
    {
        r[i]=0; //put null char
    }

    i--; //don't convert null char

    //remove 0's from left side
    for(; i>=1; i--) //if all are 0, leave one 0
    {
        if(r[i] != 0) //if you see a digit
        {
            break; //stop
        }
    }

    //convert digits to ascii
    for(; i>=0; i--)
    {
        r[i] += 48;
    }
    strrev(r, ans);
}

//max take 30 digit numbers
int main()
{
    char p[]="50";
    char q[]="50";
    char ans[32]={0};
    add(p, q, ans);
    printf("%s\n\n", ans);

    int i;
    char pp[31];
    char qq[31];
    char answer[32]={0};
    srand(0);
    for(i=0; i<10; i++)
    {
        int n1,n2;
        n1 = rand() % 10000;
        sprintf(pp,"%d",n1);
        printf("%s\n",pp);

        n2 = rand() % 10000;
        sprintf(qq,"%d",n2);
        printf("%s\n",qq);

        printf("%d\n", n1+n2);
        add(pp, qq, answer);
        printf("%s\n\n", answer);
    }

    return 0;
}

