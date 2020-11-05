/*
 *  Objective  : This Program is to perform all the operation of Queue using Linked List.
 *  Programmer : Jatin Sharma
 *  Warning    : In this I'm using Singly Linked List, You are free to use whichever you want.
 */

#include <stdio.h>
#include <stdlib.h>

/* Global Variables */
int SIZE = 0;

/* Linked List Structure */
typedef struct node
{
    int data;
    struct node *next;
} node;

node *start = NULL;
node *last = NULL;

/* Functions Declaration */
void enqueue();
void dequeue();
void peek();
void printQueue();
void isQueueEmpty();
void size();

/* main() Function */
int main()
{

    int choice;

    do
    {
        printf("\nChoose Option to perform operation in Queue Using Linked List :\n");
        printf("PRESS 1 FOR [EN-QUEUE]\nPRESS 2 FOR [DE-QUEUE]\nPRESS 3 FOR [PEEK]\nPRESS 4 FOR [PRINT-QUEUE]\nPRESS 5 FOR [SIZE OF QUEUE]\nPRESS 6 FOR [EXIT]\n\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);

        /* Switch Case */
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            printQueue();
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
    } while (choice != 6);

    return 0;
}

/* Functions Definition */
void isQueueEmpty()
{
    /* Checking IS Queue Empty */
    if (start == NULL)
    {
        printf("Queue is Empty. Can't Perform Operation.\n");
        exit(1);
    }
}
void enqueue()
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
    ptr->next = NULL;

    if (start == NULL)
    {
        start = ptr;
        last = ptr;
    }
    else
    {
        node *temp = last;
        last->next = ptr;
        last = ptr;
        
    }

    printf("[%d] Inserted Successfully in Queue.\n", ptr->data);
    SIZE++;
}
void dequeue()
{
    isQueueEmpty();
    int data;

    node *temp = start;
    data = start->data;
    start = start->next;
    free(temp);

    printf("[%d] Deleted Successfully in Queue.\n", data);
    SIZE--;
}
void peek()
{
    isQueueEmpty();
    printf("[%d] is the Top Element of Queue.\n", start->data);
}
void printQueue()
{
    isQueueEmpty();
    node *temp = start;
    while (temp != NULL)
    {
        printf("%d <== ", temp->data);
        temp = temp->next;
    }
}

void size()
{
    printf("Queue size = [%d].\n", SIZE);
}
