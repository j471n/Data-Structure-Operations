/*
 *  Objective  : This Program is to Insert a node at First position in Doubly Linked List.
 *  Programmer : Jatin Sharma
 */

#include <stdio.h>
#include <stdlib.h>

int I = 1;
void createLinkedList(int n);
void insert(int element);
void printLinkedList();

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

node *start = NULL; // Setting start to NUll
node *last = NULL;
int main()
{

    int n;
    printf("Enter the Number of Total Node you want to insert : ");
    scanf("%d", &n);

    createLinkedList(n);
    int element;
    printf("Enter the Data to Insert at First Position : ");
    scanf("%d", &element);

    insert(element);        // Calling insert Function with element argument
    printLinkedList();      // Printing Doubly Linked List.
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
        ptr->next = NULL;

        if (start == NULL)
        {
            ptr->prev = NULL;
            start = ptr;
            last = ptr;
        
        }
        else
        {
            temp = start;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = ptr;
            ptr->next = NULL;
            ptr->prev = temp;
            last = ptr;
        }
    }

    printf("\n************************************************************************\n");
    printf("********************* NODES Created Successfully. *********************\n");
    printf("************************************************************************\n\n");
}

void insert(int element)
{
    node *ptr, *temp;
    ptr = (node *)malloc(sizeof(node));

    if (ptr == NULL)
    {
        printf("Cannot Allocate Memory for Overflow Reason. Please Stop some task and try Again.\n");
        return;
    }

    ptr->data = element;

    if (start == NULL)
    {
        ptr->prev = NULL;
        ptr->next = NULL;
        start = ptr;
        last = ptr;
    }
    else
    {
        ptr->prev = start;
        ptr->next = start;
        start->prev = ptr;
        start = ptr;
        
    }

    printf("\n************************************************************************\n");
    printf("******************** Data %d Inserted Successfully. ********************\n", element);
    printf("************************************************************************\n\n");
}

void printLinkedList()
{

    node *temp = start;
    if (temp == NULL)
    {
        printf("List is Empty.\n");
        return;
    }

    /*
    // You can Use this loop as well
    for (node *temp ; temp != NULL; temp = temp->next)
    {

        printf("Data of node [%d] ==> %d\n", I, temp->data);
        I++;
    }
    */
    while (temp != NULL)
    {
        printf("Data of node [%d] ==> %d\n", I, temp->data);
        I++;
        temp = temp->next;
    }
}