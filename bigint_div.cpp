#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

#define lim 31 //1 for null
char a[lim], b[lim]; //two input operands

//used in addition and subtraction
char c; //carry or borrow
char t; //temporary result of two digit's operation
int s; //sign
char ar[lim + 1]; //for addition result, two 30 digit number when added results in a 31 digit number
char sr[lim]; //for subtraction result

//used in division
char dd[lim]; //for temporary dividends of division
char dr[lim]; //for division result, unlike all others, remember, dr is generated in MSB at 0th location.
char dremainder[lim]; //for division remainder
char bmul[lim + 1]; //for keeping b*1, b*2, ..., b*9, when a 30 digit number and a 1 digit number get multiplied, we get a 31 digit number

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
//add divisor with itself in division
//p and q are not ascii, they are ascii-48
//this adds two 30 digit numbers
void add_for_div(char* p, char* q)
{
    int i;

    c=0; //start c with 0
    for(i=0; i<lim-1; i++) //add 30 digits
    {
        t = p[i]+q[i]+c;
        if(t>=10)
        {
            c=1;
            t=t%10;
            ar[i]=t;
        }
        else
        {
            c=0;
            ar[i]=t;
        }
    }
    if(c==1)
    {
        ar[i]=c; //put carry at end, make it a 31 digit number
        i++;

        ar[i]=0; //put null char
    }
    else
    {
        ar[i]=0; //put null char
    }
}

//if p>q, return 1
//else return 0
//it compares one 31 digit number
//with a 30 digit number
//null char at end of 30 digit number
//also compared for both to be of same length
int bigger(char* p, char* q)
{
    int res;
    int i;
    for(i=lim-1; i>=0; i--) //compare null char of 30 digit number with MSB of 31 digit number
    {
        if(p[i]<q[i])
        {
            res=0;
            break;
        }
        else if(p[i]>q[i])
        {
            res=1;
            break;
        }
        else //p[i]==q[i]
        {
            res=0;
            continue;
        }
    }
    return res;
}

//this function will only be used to
//subtract b from bmul in division
//this subtracts a 30 digit number from a 31 digit number
//here it is guarented that b is smaller than bmul
//b<bmul, 31 digit-30 digit, result must be 30 digit, because result<=dd and dd can at max be a 30 digit number

//this function will only be used to
//subtract bmul from dd in division
//this subtracts a 31 digit number from a 30 digit number
//here it is guarented that bmul is smaller than dd
//bmul<dd, so even if it is a 30 digit-31 digit, result must be a 30 digit

//p and q are not ascii, they are ascii-48
void sub_for_div(char* p, char* q)
{
    int i;

    c=0; //start c with 0
    for(i=0; i<lim; i++) //31 digit subtraction
    {
        //adjust previous c (loan?)
        if(c==-1)
        {
            if(p[i]>0)
            {
                p[i]=p[i]+c; //c is -ve, so deduct 1
                c=0; //previous c adjusted
            }
            else //a[i]==0
            {
                p[i]=9;
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
            if(p[i]<q[i])
            {
                //impossible because we assigned a[i]=9 when we couldn't adjust previous c
            }
            else //p[i]>=q[i]
            {
                c=-1; //carry this loan to next iteration
                sr[i]=p[i]-q[i];
            }
        }
        else //if we had already adjusted previous c
        {
            if(p[i]<q[i])
            {
                c=-1; //make new loan
                t=10+p[i];
                sr[i]=t-q[i];
            }
            else //p[i]>=q[i]
            {
                c=0; //no new loan
                sr[i]=p[i]-q[i];
            }
        }
    }

    //put null char
    sr[i]=0; //when we do a 31 digit-30 digit, how can we put a null char in 31st place?
            //is it guarenteed that 31st place will always be a 0?
            //at least in cases of subtractions involved in division?
            //yes, it is guarenteed.
            //for one case, b<bmul, 31 digit-30 digit, result must be 30 digit, because result<=dd and dd can at max be a 30 digit number
            //for another case, bmul<dd, so even if it is a 30 digit-31 digit, result must be a 30 digit
}

void div(char* p, char* q, char* ans, char* rem)
{
    int i,j;

    int plen = strlen(p); if(plen>=lim) return;
    int qlen = strlen(q); if(qlen>=lim) return;

    //put p in a
    memset(a, 0, lim); //null char also getting set
    strrev(p, a);
    for(i=0; i<plen; i++)
    {
        a[i] -= 48;
    }

    //put q in b
    memset(b, 0, lim); //null char also getting set
    strrev(q, b);
    for(i=0; i<qlen; i++)
    {
        b[i] -= 48;
    }

    memset(dd, 0, lim); //temporary dividend, null char also getting set
    memset(dr, 0, lim); //result of division, null char also getting set
    memset(dremainder, 0, lim); //remainder of division, null char also getting set
    for(i=0; i<plen; i++)
    {
        dd[0]=a[plen-1 - i]; //copy 1 digit from MSB side of a to dd[0]

        memset(bmul, 0, lim+1); //31 digit number, null char also getting set
        for(j=1;j<=9;j++)
        {
            memset(ar, 0, lim+1); //31 digit number, null char also getting set

            add_for_div(bmul, b); //ar=b*j
            memcpy(bmul, ar, lim); //bmul=ar, null char not getting copied

            if(bigger(bmul, dd)) //bmul is a 31 digit number, dd is a 30 digit number
            {
                dr[i]=j-1; //remember, dr is generated in MSB at 0th location.
                break;
            }
            else
            {
                continue;
            }
        }
        //bmul is more than dd
        sub_for_div(bmul, b); //make bmul less by b, b<bmul, 31 digit-30 digit, result must be 30 digit, because result<=dd
        memcpy(bmul, sr, lim); //bmul=sr, 30 digit+null copied to 31 digit
        //now bmul is less than dd
        sub_for_div(dd, bmul); //subtract bmul from temporary dividend, bmul<dd, so even if it is a 30 digit-31 digit, result must be a 30 digit
        memcpy(&dd[1], sr, lim-1 - 1); //keep LSB of dd free, this assignment will go wrong only in the last iteration
                                        //because, till we have 30 digits in dd, there is no chance that sr can be of 30 digits.
                                        //once we have 30 digits in dd, it is the last iteration!
                                        //there, sr may have a 30 digit remainder, but since we are not going to use dd any more,
                                        //we can here copy only 29 digits from sr to dd
    }
    memcpy(dremainder, sr, lim-1); //last subtraction result is remainder, null char not getting copied

    //put null char at the very end, just to be safe
    dr[lim-1]=0;

    //remember, dr is generated in MSB at 0th location.

    //ignore 0's from left side of the answer of division
    //for n digit dividend, answer must be of n digit only
    for(i=0; i<plen - 1; i++) //if all are 0, leave one 0
    {
        if(dr[i] != 0) //if you see a digit
        {
            break; //stop
        }
    }
    int ans_start=i; //here from actual answer start, excluding left 0's, note this position

    //convert digits to ascii
    for(; i<plen; i++) //for n digit dividend, answer must be of n digit only
    {
        dr[i] += 48;
    }
    dr[i]=0; //for n digit dividend, answer must be of n digit only, so put null soon after it

    //dr is generated in MSB at 0th location. so no need of reverse
    //strrev(dr, ans);
    //but we need to copy dr to ans excluding 0's those are present on left
    memcpy(ans, &dr[ans_start], plen-ans_start);
    ans[plen-ans_start]=0; //put null char soon after answer ends

    //for remainder
    //put null char at the very end
    dremainder[lim-1]=0;

    //ignore 0's from left side
    for(i=lim-1; i>=1; i--) //if all are 0, leave one 0
    {
        if(dremainder[i] != 0) //if you see a digit
        {
            break; //stop
        }
    }

    //convert digits to ascii
    for(; i>=0; i--)
    {
        dremainder[i] += 48;
    }
    strrev(dremainder, rem);
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
    char pp[lim];
    char qq[lim];
    //for 30 digit numbers,
    //addition results in 31 digits,
    //subtraction results in 30 digits,
    //multiplication results in 60 digits.
    //division results in 30 digit answer and 30 digit remainder.
    char answer[lim]={0};
    char remainder[lim]={0};
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

        printf("%d %d\n", n1/n2, n1%n2);
        div(pp, qq, answer, remainder);
        if(s)
            printf("-");
        printf("%s %s\n\n", answer, remainder);
    }

    return 0;
}

