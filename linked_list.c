/* Program to use a linked list */
/* Date: 17 Jul 2003 */
/* Author: Srinivas Nayak */
/* Compile using Turbo C++ */

/* This code is distributed under the GPL License. */
/* For more info check: */
/* http://www.gnu.org/copyleft/gpl.html */


#include<stdio.h>
#include<conio.h>
#include<alloc.h>
struct node
{
    int no;
    char name[10];
    struct node *next;
};
struct node *ptr;
int i;
void fill();
void main()
{
       struct node *head;
       clrscr();
       head =(struct node *)malloc(sizeof (struct node));
       ptr=head;
       for(i=0;i<5;i++)
       {
	fill();
       }
       printf("\n\n");
       while(head!=NULL)
       {    printf("\n");
	    printf("%d",head->no);
	    printf("    %s",head->name);
	    head=head->next;

       }
       getch();
}
void fill()
{
	printf("no: ");
	scanf("%d",&ptr->no);
	printf("name: ");
	scanf("%s",&ptr->name);
	if(i<4)
	{
	ptr->next=(struct node *)malloc(sizeof (struct node));
	ptr=ptr->next;
	}
	else
	ptr->next=NULL;
}





