/*
 *  Objective  : This Program is to perform all the operation of Queue using an Array.
 *  Programmer : Jatin Sharma
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

/* Global Variables */
int QUEUE[MAX_SIZE];
int front = -1;
int TOP = -1 ;
int SIZE = 0;

/* Function Declaration*/
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
        printf("\nChoose Option to perform operation in Queue Using an Array :\n");
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

/* Function Definitions */
void isQueueEmpty()
{
    /* Checking IS Queue Empty */
    if (TOP == -1 || front == -1 || front > TOP)
    {
        printf("QUEUE is Empty. Can't Perform Operation.\n");
        exit(1);
    }
}
void enqueue()
{
    /* Checking Does Queue have Space to Enter the Element */
    if (TOP == MAX_SIZE - 1)
    {
        printf("Can't Insert Element, Queue is Full.\n");
        exit(1);
    }
    if (front == -1)
    {
        front = 0;
    }
    /* Taking Value and Adding to an Araay */
    printf("Enter the value : ");
    scanf("%d", &QUEUE[++TOP]);
    printf("[%d] Inserted Successfully in Queue.\n", QUEUE[TOP]);
    SIZE++;
}
void dequeue()
{

    isQueueEmpty();
    
    printf("[%d] Deleted Successfully from Queue.\n", QUEUE[front++]);
    SIZE--;
}
void peek()
{
    isQueueEmpty();
    printf("[%d] is the Top Element of the Queue.\n", QUEUE[front]);
}
void printQueue()
{
    isQueueEmpty();
    printf("Queue Elements are -\n");
    for (int i = front; i <= TOP; i++)
    {
        printf("==> %d ", QUEUE[i]);
    }
}
void size()
{
    printf("Queue size = [%d].\n", SIZE);
}
