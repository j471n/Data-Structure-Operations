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
void size();

/* main() Function */
int main(){

    int choice;

    do
    {
        printf("\nChoose Option to perform operation in Stack Using an Array :\n");
        printf("PRESS 1 FOR [PUSH]\nPRESS 2 FOR [POP]\nPRESS 3 FOR [PEEK]\nPRESS 4 FOR [PRINT-STACK]\nPRESS 5 FOR [SIZE OF STACK]\nPRESS 6 FOR [EXIT]\n\n");
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
            size();
            break;
        case 6:
            printf("Thanks For Using...(*_*)\n");
            break;
        default:
            printf("Invalid Choice. Try Again.\n");
            break;
        }
    } while (choice !=6);

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
    if (TOP == SIZE-1){
        printf("Can't Insert Element, Stack is Full.\n");
        exit(1);
    }

    /* Taking Value and Adding to an Araay */
    printf("Enter the value : ");
    scanf("%d", &STACK[++TOP]);
    printf("[%d] Inserted Successfully in Stack.\n", STACK[TOP]);
    
}
void pop(){

    isStackEmpty();
    printf("[%d] Deleted Successfully from Stack.\n", STACK[TOP--]);
}
void peek(){

    isStackEmpty();
    printf("[%d] is the Top Element of the Stack.\n", STACK[TOP]);
}
void printStack(){

    isStackEmpty();
    printf("Stack Elements are -\n");
    for (int i = TOP; i >= 0; i--)
    {
        printf("==> %d ", STACK[i]);
    }
    
}

void size(){
    printf("Stack size = [%d].\n", TOP);
}
