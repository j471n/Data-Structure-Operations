/*
 *  Objective  : This Program is to perform all the operation of Stack using Linked List.
 *  Programmer : Jatin Sharma
 *  Warning    : In this I'm using Singly Linked List, You are free to use whichever you want.
 */

#include <stdio.h>
#include <stdlib.h>

int SIZE = 0;
/* Linked List Structure */
typedef struct node
{
    int data;
    struct node *next;
} node;

node *start = NULL;

/* Functions Declaration */
void push();
void pop();
void peek();
void printStack();
void isStackEmpty();
void size();

/* main() Function */
int main()
{

    int choice;

    do
    {
        printf("\nChoose Option to perform operation in Stack Using Linked List :\n");
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
    } while (choice != 5);

    return 0;
}

/* Functions Definition */
void isStackEmpty()
{
    /* Checking IS Stack Empty */
    if (start == NULL)
    {
        printf("Stack is Empty. Can't Perform Task.\n");
        exit(1);
    }
}
void push()
{

    node *ptr = (node *)malloc(sizeof(node));
    if (ptr == NULL)
    {
        printf("Can't Allocate Memory Overflow.\n");
        exit(1);
    }

    int data;
    printf("Enter Data : ");
    scanf("%d", &ptr->data);

    if (start == NULL)
    {
        ptr->next = NULL;
        start = ptr;
    }
    else
    {
        ptr->next = start;
        start = ptr;
    }

    printf("[%d] Inserted Successfully in Stack.\n", ptr->data);
    SIZE++;
}
void pop()
{
    isStackEmpty();
    int data;
    
    node *temp = start;
    data = start->data;
    start=start->next;
    free(temp);

    printf("[%d] Deleted Successfully in Stack.\n", data);
    SIZE--;
}
void peek()
{
    isStackEmpty();
    printf("[%d] is the Top Element of Stack.\n", start->data);
}
void printStack()
{
    isStackEmpty();
    node *temp = start;
    while (temp != NULL)
    {
        printf("==> %d ", temp->data);
        temp = temp->next;
    }
}

void size()
{
    printf("Stack size = [%d].\n", SIZE);
}
