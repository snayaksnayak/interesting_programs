#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

#define max 31 //1 for null
char a[max], b[max]; //two operands
char c; //carry or borrow
char t; //temporary result of two digit's operation
int s; //sign

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

void sub(char* p, char* q, char* ans)
{
    int i;

    int plen = strlen(p); if(plen>=max) return;
    int qlen = strlen(q); if(qlen>=max) return;
    int bigger_len = plen>qlen? plen: qlen;

    //put p in a
    memset(a, 0, max);
    strrev(p, a);
    for(i=0; i<plen; i++)
    {
        a[i] -= 48;
    }

    //put q in b
    memset(b, 0, max);
    strrev(q, b);
    for(i=0; i<qlen; i++)
    {
        b[i] -= 48;
    }

    //decide sign
    s=0; //sign positive
    for(i=bigger_len-1; i>=0; i--)
    {
        if(a[i]<b[i])
        {
            s=1; //sign negative

            //put q in a
            memset(a, 0, max);
            strrev(q, a);
            for(i=0; i<qlen; i++)
            {
                a[i] -= 48;
            }

            //pur p in b
            memset(b, 0, max);
            strrev(p, b);
            for(i=0; i<plen; i++)
            {
                b[i] -= 48;
            }

            break;
        }
        else if(a[i]>b[i])
        {
            s=0; //sign positive
            break;
        }
        else //a[i]==b[i]
        {
            continue;
        }
    }

    c=0; //start c with 0
    for(i=0; i<bigger_len; i++)
    {
        //adjust previous c (loan?)
        if(c==-1)
        {
            if(a[i]>0)
            {
                a[i]=a[i]+c; //c is -ve, so deduct 1
                c=0; //previous c adjusted
            }
            else //a[i]==0
            {
                a[i]=9;
                c=-1; //previous c couldn't be adjusted
            }
        }
        else //c==0
        {
            //no change to a[i]
            c=0; //previous c adjusted
        }

        //now subtract digits
        if(c==-1) //if we couldn't adjust previous c because of a[i]==0
        {
            if(a[i]<b[i])
            {
                //impossible because we assigned a[i]=9 when we couldn't adjust previous c
            }
            else //a[i]>=b[i]
            {
                c=-1; //carry this loan to next iteration
                r[i]=a[i]-b[i];
            }
        }
        else //if we had already adjusted previous c
        {
            if(a[i]<b[i])
            {
                c=-1; //make new loan
                t=10+a[i];
                r[i]=t-b[i];
            }
            else //a[i]>=b[i]
            {
                c=0; //no new loan
                r[i]=a[i]-b[i];
            }
        }
    }

    //put null char
    r[i]=0;

    //don't convert null char
    i--;

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
/*
    char p[]="50";
    char q[]="50";
    char ans[32]={0};
    sub(p, q, ans);
    printf("%s\n\n", ans);
*/
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

        printf("%d\n", n1-n2);
        sub(pp, qq, answer);
        if(s)
            printf("-");
        printf("%s\n\n", answer);
    }

    return 0;
}

