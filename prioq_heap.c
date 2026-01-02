//priority queue implemented using an array
//priority queue is heap
//heap is balanced binary tree

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#define MAXNODE 31
typedef struct prioq
{
    int* a;
    int n;
    int max;
} prioq;

prioq* makepq(int maxsize)
{
    prioq* pq = (prioq*)malloc(sizeof(prioq));
    if(!pq)
        return 0;
    pq->a = (int*)malloc(sizeof(int)*(maxsize+1));
    if(!pq->a)
        {free(pq); return 0;}
    pq->n = 0;
    pq->max = maxsize;
    return pq;
}

void upheap(prioq* pq, int k)
{
    pq->a[0] = INT_MAX;

    int v;
    v = pq->a[k];
    while(v > pq->a[k/2])
    {
        pq->a[k] = pq->a[k/2];
        k = k/2;
    }
    pq->a[k] = v;
}

int inspq(prioq* pq, int v)
{
    if(pq->n >= pq->max)
        return 0;
    pq->n++;
    pq->a[pq->n] = v;
    upheap(pq, pq->n);

    return 1;
}

void downheap(prioq* pq, int k)
{
    int v;
    v = pq->a[k];
    while(k <= pq->n/2)
    {
        int j;
        j = 2*k;
        if( j < pq->n && (pq->a[j] < pq->a[j+1]) ) j++;
        if(v >= pq->a[j]) break;
        pq->a[k] = pq->a[j];
        k = j;
    }
    pq->a[k] = v;
}

int rempq(prioq* pq, int* ret)
{
    if(pq->n <= 0)
        return 0;
    int v = pq->a[1];
    pq->a[1] = pq->a[pq->n];
    pq->n--;
    downheap(pq, 1);
    *ret = v;

    return 1;
}

#define MAXX 80
#define MAXY 6
void printnode(prioq* pq, int k, int lvl, char* buf, int x, int y)
{
    if(k > pq->n)
        return;

    int c = sprintf(buf+y*MAXX+x, "%02d", pq->a[k]); *(buf+y*MAXX+x+c)=' ';
    y++;
    x-=pow(2, lvl-1);
    printnode(pq, 2*k, lvl-1, buf, x, y);
    x+=2*pow(2, lvl-1);
    printnode(pq, 2*k+1, lvl-1, buf, x, y);
}

void printpq(prioq* pq, int k)
{
    if(k > pq->n)
        return;

    char buf[MAXX*MAXY];
    memset(buf, ' ', MAXX*MAXY);

    int lvl = 0; int ck = k; for( ; ck<=pq->n; ck=ck*2) lvl++;
    printnode(pq, k, lvl, buf, MAXX/2, 0);

    int y;
    int x;
    for(y=0; y<MAXY; y++)
    {
        for(x=0; x<MAXX; x++)
        {
            printf("%c", buf[y*MAXX+x]);
        }
        printf("\n");
    }
}

int main()
{
    printf("hello\n");
    prioq* pq = makepq(MAXNODE);
    if(!pq)
        {printf("err: no mem\n"); return 0;}

    int v=0;
    while(v < MAXNODE)
    {
        v++;
        inspq(pq, v);
        printf("ins: %d\n", v);
        printpq(pq, 1);
    }

    while(rempq(pq, &v)==1)
    {
        printf("rem: %d\n", v);
        printpq(pq, 1);
    }
    return 0;
}

/*
    char buf[10];
    memset(buf, 'o', 9); buf[9] = '\0';
    int c;

    int p = 9;
    c = sprintf(&buf[3], "%02d", p); buf[3+c]='o';
    printf("%s\n", buf);

    p = 98;
    c = sprintf(&buf[5], "%02d", p); buf[5+c]='o';
    printf("%s\n", buf);
*/
