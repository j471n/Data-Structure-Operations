/*
 *  Objective  : This Program is to insert the element at the given Position in Circular Singly Linked List.
 *  Programmer : Jatin Sharma
 */

#include <stdio.h>
#include <stdlib.h>

int I = 1; // To Print the List using For loop as well as while loop [Global Variable]
int COUNT = 0;
void createLinkedList(int n);
void insert();
void printList();

typedef struct node
{
    int data;
    struct node *next;
} node;

node *start = NULL; // Setting Up teh Node to NULL

int main()
{

    int n;
    printf("Enter the Number of Total Node you want to insert : ");
    scanf("%d", &n);

    createLinkedList(n);
    return 0;
}

void createLinkedList(int n)
{
    node *ptr, *temp;

    for (int i = 0; i < n; i++)
    {

        ptr = (node *)malloc(sizeof(node));
        if (ptr == NULL)
        {
            printf("Cannot Allocate Memory for Overflow Reason. Please Stop some task and try Again.\n");
            return;
        }

        printf("Enter the Data for node [%d] : ", i + 1);
        scanf("%d", &ptr->data);

        if (start == NULL)
        {
            start = ptr;
        }
        else
        {
            temp = start;

            while (temp->next != start)
            {
                temp = temp->next;
            }
            temp->next = ptr;
        }
        ptr->next = start;
        COUNT++;
    }

    printf("\n");
    printf("************************************************************************\n");
    printf("********************* NODES Inserted Successfully. *********************\n");
    printf("************************************************************************\n\n");
    insert();
}

void insert()
{

    node *temp, *ptr;
    int position;
    printf("Enter the position to insert Data : ");
    scanf("%d", &position);
    if (position > COUNT || position <= 0)
    {
        printf("Position is Out of range. Data Can't Inserted. Linked List only have [%d] Node !!!\n", COUNT);
        free(temp);
        free(ptr);
        exit(1);
    }

    ptr = (node *)malloc(sizeof(node));
    if (ptr == NULL)
    {
        printf("Cannot Allocate Memory for Overflow Reason. Please Stop some task and try Again\n");
        exit(1);
    }
    int data;
    printf("Enter data to insert at [%d] position : ", position);
    scanf("%d", &data);
    ptr->data = data;
    
    temp = start;
    if (position == 1)
    {
        while (temp->next != start)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->next = start;
        start = ptr;
    }
    else
    {

        for(int i = 2; i < position; i++)
        {
            temp = temp->next;
        }
        ptr->next = temp->next;
        temp->next = ptr;
    }
    COUNT++;

    printf("\n************************************************************************\n");
    printf("******************** %d Data Inserted Successfully. ********************\n", data);
    printf("************************************************************************\n\n");
    printList();
}

void printList()
{

    node *temp = start;
    if (temp == NULL)
    {
        printf("List is Empty.\n");
        return;
    }

    /*
    // You can Use this loop as well
    for (node *temp ; temp->next != start; temp = temp->next)
    {
        printf("Data of node [%d] ==> %d\n", I, temp->data);
        I++;
    }
    printf("Data of node [%d] ==> %d\n", I, temp->data);
    */

    while (temp->next != start)
    {
        printf("Data of node [%d] ==> %d\n", I, temp->data);
        I++;
        temp = temp->next;
    }
    printf("Data of node [%d] ==> %d\n", I, temp->data);
}