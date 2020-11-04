/*
 *  Objective  : This Program is to perform all the operation of Stack using an Array.
 *  Programmer : Jatin Sharma
 */

#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

/* Global Variables */
int STACK[SIZE], TOP = -1;

/* Function Declaration*/
void push();
void pop();
void peek();
void printStack();
void isStackEmpty();

/* main() Function */
int main(){

    int choice;

    do
    {
        printf("\nChoose Option to perform operation in Stack Using an Array :\n");
        printf("PRESS 1 FOR [PUSH]\tPRESS 2 FOR [POP]\tPRESS 3 FOR [PEEK]\tPRESS 4 FOR [PRINT-STACK]\tPRESS 5 FOR [EXIT]\n\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);

        /* Switch Case */
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            printStack();
            break;
        case 5:
            printf("Thanks For Using...(*_*)\n");
            break;
        default:
            printf("Invalid Choice. Try Again.\n");
            break;
        }
    } while (choice !=5);

    return 0;
}

/* Function Definitions */
void isStackEmpty()
{
    /* Checking IS Stack Empty */
    if (TOP == -1)
    {
        printf("Stack is Empty. Can't Print Stack.\n");
        exit(1);
    }
}
void push(){

    /* Checking Does Stack have Space to Enter the Element */
    if (TOP >= SIZE){
        printf("\n Overflow");
        exit(1);
    }

    /* Taking Value and Adding to an Araay */
    printf("Enter the value : ");
    scanf("%d", &STACK[++TOP]);
    printf("[%d] added Successfully.\n", STACK[TOP]);
    
}
void pop(){

    isStackEmpty();
    printf("[%d] Deleted Successfully.\n", STACK[TOP--]);
}
void peek(){

    isStackEmpty();
    printf("[%d] is the Top Element of the Stack.\n", STACK[TOP]);
}
void printStack(){

    isStackEmpty();
    printf("Here Is the Stack -\n");
    for (int i = TOP; i >= 0; i--)
    {
        printf("Stack Element = [%d]\n", STACK[i]);
    }
    
}

