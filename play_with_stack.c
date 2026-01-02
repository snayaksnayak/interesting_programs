/* Program to work on a stack */
/* Date: 26 Jan 2003 */
/* Author: Srinivas Nayak */
/* Compile using Turbo C++ */

/* This code is distributed under the GPL License. */
/* For more info check: */
/* http://www.gnu.org/copyleft/gpl.html */



#include<stdio.h>
#define MAX 100
typedef struct{
	int top;
	int content[MAX];
	}STACK;
void stackEmptyTest(STACK test);
void stackFullTest(STACK test);
void display(STACK test);

void main() {
STACK testStack;
char choice;
int t;
     clrscr();
     do {
	 printf("\n1. Initialise\n2. Push\n3. Pop\n4. Display\n5. Stack Empty\n6. Stack Full");
	 printf("\n\nEnter u r choice: ");
	 fflush(stdin);
	 scanf("%c",&choice);
	 switch (choice) {
		case '1':
			testStack.top = -1;
			break;
		case '2':
			printf("\nEnter the Element u want to push into the stack: ");
			scanf("%d",&t);
			push(&testStack,t);
			break;
		case '3':
			t = pop(&testStack);
			if (t!=-9999) printf("\nThe poped element form the stack is: %d",t);
			   else printf("\nStack Under flow");
			break;
		case '4':
			display(testStack);
			break;
		case '5':
			stackEmptyTest(testStack);
			break;
		case '6':
			stackFullTest(testStack);
			break;
		default: exit(0);
	 }
     } while(1);
}
int stackfull(STACK test) {
    return test.top == MAX;
}
int stackempty(STACK test) {
    return test.top == -1;
}
void stackFullTest(STACK test) {
     if (stackfull(test)) printf("\nStack is full:");
	else printf("\nThe stack contains %d Entiries",test.top+1);
}
void stackEmptyTest(STACK test) {
     if (stackempty(test)) printf("\nStack is empty");
	else printf("The stack contains %d Entiries",test.top+1);
}
int  push(STACK *test,int ele) {
    if (!stackfull(*test)) {
	(*test).top++;
	(*test).content[(*test).top] = ele;
    }
}
int pop(STACK *test) {
    if (!stackempty(*test)) return (*test).content[(*test).top--];
       else return -9999;
}
void display(STACK test) {
     int i;
     if (!stackempty(test)) {
	printf("\nThe stack contains the following entries:\n");
	for (i = 0; i<=test.top; i++) printf(" %d ",test.content[i]);
     }
}