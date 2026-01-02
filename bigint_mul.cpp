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
char rt[lim]; //to store result temporarily
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

//this function will only be used to
//add partial results of multiplication.
//p and q are not ascii, they are ascii-48
void add_for_mul(char* p, char* q)
{
    int i;

    c=0; //start c with 0
    for(i=0; i<lim-1; i++)
    {
        t = p[i]+q[i]+c;
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
    //at this stage it is guarenteed that
    //there will not be any carry over left
    //it is because multiplication of two 30 digit numbers
    //will result in a maximum of 60 digit number.
    //here we add two 60 digit partial results
    //hence final answer will also be a 60 digit number only.
    if(c==1)
    {
        printf("something went seriously wrong!\n");
        printf("we reached a imposible state!\n");
    }

    r[i]=0; //put null char
}

//p and q are not ascii, they are ascii-48
void mul_1_digit(char* p, int plen, char q, char* mp)
{
    int i;

    c=0;
    for(i=0; i<plen; i++)
    {
        t=p[i]*q+c;
        if(t>=10)
        {
            c=t/10;
            t=t%10;
            mp[i]=t;
        }
        else
        {
            c=0;
            mp[i]=t;
        }
    }
    if(c>0)
    {
        mp[i]=c;
        i++;
        c=0;
    }
}

void mul(char* p, char* q, char* ans)
{
    int i;

    int plen = strlen(p); if(plen>=max) return;
    int qlen = strlen(q); if(qlen>=max) return;

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

    memset(r, 0, lim); //start r=0
    for(i=0; i<qlen; i++)
    {
        memset(m, 0, lim);//make m=0;
        mul_1_digit(a, plen, b[i], &m[i]); //get one partial multiplication result in m
        memcpy(rt, r, lim); //copy result (so far) from r to rt
        add_for_mul(m, rt); //add m with rt to produce r
    }

    //put null char at the very end
    r[lim-1]=0;

    //remove 0's from left side
    for(i=lim-1; i>=1; i--) //if all are 0, leave one 0
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
    //for 30 digit numbers,
    //addition results in 31 digits,
    //subtraction results in 30 digits,
    //multiplication results in 60 digits.
    char answer[61]={0};
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

        printf("%d\n", n1*n2);
        mul(pp, qq, answer);
        if(s)
            printf("-");
        printf("%s\n\n", answer);
    }

    return 0;
}

