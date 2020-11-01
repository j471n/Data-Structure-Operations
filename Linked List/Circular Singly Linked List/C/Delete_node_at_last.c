/*
 *  Objective  : This Program is to delete the node at the last Position in Circular Singly Linked List.
 *  Programmer : Jatin Sharma
 */

#include <stdio.h>
#include <stdlib.h>

int I = 1; // To Print the List using For loop as well as while loop [Global Variable]

void createLinkedList(int n);
void pop();
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
    pop();
    printList();

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
            ptr->next = start;
        }
        else
        {
            temp = start;

            while (temp->next != start)
            {
                temp = temp->next;
            }

            ptr->next = start;
            temp->next = ptr;
        }
    }

    printf("\n");
    printf("************************************************************************\n");
    printf("********************* NODES Inserted Successfully. *********************\n");
    printf("************************************************************************\n\n");
}

void pop()
{
    int data;

    if (start == NULL)
    {
        printf("List is Empty.\n");
        exit(1);
    }
    else if (start->next == start)
    {
        data = start->data;
        start = NULL;
        free(start);
        printf("Only node in List deleted Succussfully, Data was - %d\n", data);
        exit(0);
    }
    else
    {
        node *toDelete = start, *temp;
        while (toDelete->next != start)
        {
            temp = toDelete;
            toDelete = toDelete->next;
        }
        temp->next = toDelete->next;
        data = toDelete->data;
        free(toDelete);
    }

    printf("\n************************************************************************\n");
    printf("******************** %d Data Deleted Successfully. ********************\n", data);
    printf("************************************************************************\n\n");
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