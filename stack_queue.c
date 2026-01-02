//stack and queue using linked list

#include<stdio.h>
#include<stdlib.h>
//#include<string.h>
//#include<math.h>

typedef struct node
{
    int val;
    struct node* next;
    struct node* prev;
} node;

node* maken(int val)
{
    node* n = (node*) malloc(sizeof(node));
    if( ! n)
        return 0;
    n->val = val;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

int nfree(node* n)
{
    free(n);
    return 1;
}

typedef struct list
{
    node* head;
    node* tail;
} list;

list* makel()
{
    list* l = (list*) malloc(sizeof(list));
    if( ! l)
        return 0;
    node* h = maken(0);
    if( ! h)
    {
        free(l); return 0;
    }
    node* t = maken(0);
    if( ! t)
    {
        free(l); free(h); return 0;
    }

    h->prev = NULL;
    h->next = t;

    t->next = NULL;
    t->prev = h;

    l->head = h;
    l->tail = t;
    return l;
}

node* linsert(list* l, node* n)
{
    node* h = l->head;

    node* o = h->next;

    h->next = n;
    n->prev = h;

    n->next = o;
    o->prev = n;

    return n;
}

int lempty(list* l)
{
    node* h = l->head;
    node* t = l->tail;

    if(h->next == t)
        return 1;
    else
        return 0;
}

node* lremlifo(list* l)
{
    if(lempty(l))
        return 0;
    node* h = l->head;
    node* n = h->next;
    node* o = n->next;
    h->next = o;
    o->prev = h;
    return n;
}

node* lremfifo(list* l)
{
    if(lempty(l))
        return 0;
    node* t = l->tail;
    node* n = t->prev;
    node* o = n->prev;
    o->next = t;
    t->prev = o;
    return n;
}

int lfree(list* l)
{
    if( ! lempty(l))
        return 0;
    free(l->head);
    free(l->tail);
    free(l);
}

int main()
{
    printf("hello\n");

    list* l = makel();
    if( ! l)
        return -1;
    int i;
    while(scanf("%d", &i) == 1)
    {
        node* n = maken(i);
        if( ! n)
            return -1;
        linsert(l, n);
    }
    while( ! lempty(l))
    {
        //node* n = lremfifo(l);
        node* n = lremlifo(l);
        printf("%d\n", n->val);
        nfree(n);
    }
    if( ! lfree(l))
        return -1;

    return 0;
}
