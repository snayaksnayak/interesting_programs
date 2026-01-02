//find sum of ascii values of characters in a string
//for vowels take inverse of ascii value, i.e. their negatives.

#include<stdio.h>
#include<stdlib.h>

int main()
{
    char a[] = "Dealing with failure is easy: Work hard to improve. Success is also easy to handle: You’ve solved the wrong problem. Work hard to improve.";
    int sum = 0;
    char* p = a;
    while(*p != '\0')
    {
        if((*p >= 'A' && *p <= 'Z')
        || (*p >= 'a' && *p <= 'z'))
        {
            if(*p == 'A' || *p == 'a'
            || *p == 'E' || *p == 'e'
            || *p == 'I' || *p == 'i'
            || *p == 'O' || *p == 'o'
            || *p == 'U' || *p == 'u')
            {
                sum = sum + (0 - *p);
            }
            else
            {
                sum = sum + *p;
            }
        }

        p++;
    }

    printf("%d\n", sum);
    return 0;
}
