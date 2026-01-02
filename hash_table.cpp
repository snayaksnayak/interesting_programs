#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

#define HT_SIZE 101

typedef struct node node;
struct node
{
    char* key;
    int val;

    node* prev;
    node* next;
};

node ht[HT_SIZE]={0};

int hash(char* s)
{
    int res;
    int len=strlen(s);
    unsigned long p = 0;
    int i;
    for(i=0; i<len; i++)
    {
        p = p*31 + s[i];
    }
    res = p % HT_SIZE;
    return res;
}

node* ht_find(char* key)
{
    node* head;
    int i = hash(key);
    head = &ht[i];

    node* found=0;

    if(head->next == 0) //bucket empty
    {
        found = 0;
    }
    else
    {
        //search key
        node* n=head->next;
        while(n != 0)
        {
            if(strcmp(n->key, key)==0)
            {
                found = n;
                break;
            }
            n = n->next;
        }
        //if found or not
            //return found
    }

    return found;
}

void ht_insert(char* key, int val)
{
    node* head;
    int i = hash(key);
    head = &ht[i];

    if(head->next == 0) //bucket empty
    {
        node* n = (node*)malloc(sizeof(node));

        int l = strlen(key);
        n->key = (char*)malloc(sizeof(char)*(l+1));
        strcpy(n->key, key);
        n->val = val;

        //update new node
        n->prev = head;
        n->next = 0;

        //update head
        head->next = n;
    }
    else //something exist here, head->next != 0
    {
        node* found = 0;

        //search key
        node* n=head->next;
        while(n != 0)
        {
            if(strcmp(n->key, key)==0)
            {
                found = n;
                break;
            }
            n = n->next;
        }

        if(found == 0) //key not found
        {
            node* n = (node*)malloc(sizeof(node));

            int l = strlen(key);
            n->key = (char*)malloc(sizeof(char)*(l+1));
            strcpy(n->key, key);
            n->val = val;

            //update new node
            n->prev = head;
            n->next = head->next;

            //update old node
            head->next->prev = n;

            //update head
            head->next = n;
        }
        else //key found
        {
            //so update val
            found->val = val;
        }
    }
}

void checkMagazine(int magazine_count, char** magazine, int note_count, char** note)
{
    node* n;
    int i;

    for(i=0; i<magazine_count; i++)
    {
        n = ht_find(magazine[i]);
        if(n==0)
        {
            ht_insert(magazine[i], 1);
        }
        else //found
        {
            ht_insert(magazine[i], n->val+1);
        }
    }

    for(i=0; i<note_count; i++)
    {
        n = ht_find(note[i]);
        if(n==0)
        {
            printf("No\n");
            return;
        }
        else //found
        {
            if(n->val == 0)
            {
                printf("No\n");
                return;
            }
            else
            {
                n->val = n->val - 1;
            }
        }
    }
    printf("Yes\n");
    return;
}

int main()
{
    char* m[10]={0};
    char* n[10]={0};

    m[0]="two"; //two times three is not four
    m[1]="times";
    m[2]="three";
    m[3]="is";
    m[4]="not";
    m[5]="four";

    n[0]="two"; //two times two is four
    n[1]="times";
    n[2]="two";
    n[3]="is";
    n[4]="four";

    checkMagazine(6, m, 5, n);

    //printf("%ld\n", 0);
    return 0;
}

/*
int compare(const void* a, const void* b)
{
    int res=0;

    char* p=*(char**)a; //compare always gets "a pointer to the content" of array passed to qsort
    char* q=*(char**)b;
    //printf("%s %s\n", p, q);

    if(p && q)
    {
        int r = strcmp(p, q);
        if(r>0)
            res=1;
    }

    return res;
}

int compare_string(const void* key, const void* item)
{
    int res;

    char* k=*(char**)key; //compare always gets "a pointer to the content" of array passed to qsort
    char* i=*(char**)item;
    //printf("%s %s\n", k, i);

    if(i) //don't check k for the time being, assume always good k!=0
    {
        res = strcmp(k, i);
    }
    else //if i == 0
    {
        res = 1;
    }

    return res;
}

qsort(magazine, magazine_count, sizeof(char*), compare);
void* v = bsearch(&note[i], magazine, magazine_count, sizeof(char*), compare_string);
char** c = (char**) v;

*/
