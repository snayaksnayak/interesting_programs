#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

#define HT_SIZE 101 //better to be a prime

typedef struct node node;

struct node
{
    char* key;
    int val;

    node* next; //singly linked list
};

node* ht[HT_SIZE]={0}; //since singly linked list, let it be node*
                        //for doubly linked list, better it to be node, not node*

int hash(char* key)
{
    int len = strlen(key);
    unsigned long h = 0; //unsigned makes h = h % 64, i.e. forget higher bits
    int i=0;
    while(i<len)
    {
        h = h*31 + key[i]; //multiplier 31 better to be a prime, note that implicitly we do h = h % 64
        i++;
    }

    return h % HT_SIZE;
}

node* ht_find(char* key)
{
    node* found=0;
    int h = hash(key);
    node* p = ht[h];

    while(p!=0)
    {
        if(strcmp(p->key, key)==0)
        {
            found = p;
            break;
        }
        p=p->next;
    }

    return found;
}

void ht_insert(char* key, int val)
{
    node* found=0;
    int h = hash(key);
    node* p = ht[h];

    if(p==0)
    {
        node* n = (node*) malloc(sizeof(node));
        int len = strlen(key);
        n->key = (char*) malloc(len+1);
        strcpy(n->key, key);
        n->val = val;
        n->next = 0;

        ht[h]=n;
    }
    else
    {
        while(p!=0)
        {
            if(strcmp(p->key, key)==0)
            {
                found = p;
                break;
            }
            p=p->next;
        }

        if(found == 0)
        {
            node* n = (node*) malloc(sizeof(node));
            int len = strlen(key);
            n->key = (char*) malloc(len+1);
            strcpy(n->key, key);
            n->val = val;
            n->next = ht[h];

            ht[h]=n;
        }
        else
        {
            found->val = val;
        }
    }
}

int compare(const void* a, const void* b)
{
    int res=0;
    char p = *(char*)a;
    char q = *(char*)b;
    if(p>q)
        res=1;
    return res;
}

node* sublist=0;

int sherlockAndAnagrams(char* s)
{
    int count=0;
    int len = strlen(s);

    int i,j;
    for(i=0;i<len;i++)
    {
        for(j=i;j<len;j++)
        {
            int l = j-i+1;

            node* sub = (node*)malloc(sizeof(node));
            sub->key = (char*)malloc(l+1);
            strncpy(sub->key, s+i, l);
            sub->key[l]=0;
            sub->val=0;
            sub->next=0;

            //two strings are anagram if one is permute of another
            //that means if they are equal after sorted
            qsort(sub->key, l, 1, compare); //so sort substrings and keep count

            node* ht_n = ht_find(sub->key);
            if(ht_n==0)
            {
                ht_insert(sub->key, 1);

                //add sorted substring to a separate list
                //to search for its count in hash table later
                if(sublist==0)
                {
                    sublist = sub;
                }
                else
                {
                    sub->next = sublist;
                    sublist = sub;
                }
            }
            else
            {
                ht_insert(sub->key, ht_n->val+1); //increase count
            }
        }
    }

    node* l_n = sublist;
    while(l_n!=0)
    {
        char* sub = l_n->key;

        node* ht_n = ht_find(sub);

        //we want to count how many substring pairs are anagram of each other
        //say, we got a count k of a sorted substring
        //that means C(k,2) number of anagram pairs exist
        //C(k,2) = k!/2!(k-2)! = k*(k-1)/2
        count += (ht_n->val) * (ht_n->val - 1) / 2;

        l_n=l_n->next;
    }

    //freeup sublist
    l_n = sublist;
    while(l_n!=0)
    {
        node* p = l_n;
        char* sub = l_n->key;
        free(sub);

        l_n=l_n->next;
        free(p);
    }
    sublist = 0;

    //freeup hash table
    for(i=0; i<HT_SIZE; i++)
    {
        node* ht_n = ht[i];
        while(ht_n!=0)
        {
            node* p = ht_n;
            char* sub = ht_n->key;
            free(sub);

            ht_n=ht_n->next;
            free(p);
        }
        ht[i] = 0;
    }

    return count;
}

int main()
{
    char m[]="abcd";
    int res = sherlockAndAnagrams(m);
    printf("%d\n", res);
    return 0;
}

