/*
 *  Objective  : This Program is to insert the element at the last Position in Circular Singly Linked List.
 *  Programmer : Jatin Sharma
 */

#include <stdio.h>
#include <stdlib.h>

int I = 1; // To Print the List using For loop as well as while loop [Global Variable]

void createLinkedList(int n);
void append();
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
    }

    printf("\n");
    printf("************************************************************************\n");
    printf("********************* NODES Inserted Successfully. *********************\n");
    printf("************************************************************************\n\n");
    append();
}

void append()
{

    node *temp, *ptr;
    int data;
    ptr = (node *)malloc(sizeof(node));
    if (ptr == NULL)
    {
        printf("Cannot Allocate Memory for Overflow Reason. Please Stop some task and try Again\n");
        return;
    }

    printf("Enter data to insert at position Last : ");
    scanf("%d", &data);
    ptr->data = data;

    if (start == NULL)
    {
        start = ptr;
        free(temp);
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