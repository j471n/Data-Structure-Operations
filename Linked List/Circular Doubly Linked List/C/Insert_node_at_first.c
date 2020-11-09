/*
    TODO: This Program is to Insert a node at first position in Circular Doubly Linked List.
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

node *start = NULL;     // Setting start to NUll
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

    insert(element);   // Calling insert Function with element argument
    printLinkedList(); // Printing Doubly Linked List.
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
            ptr->prev = start;
            last = ptr;
        }
        else
        {
            temp = start;
            ptr->next = start;
            ptr->prev = last;
            last->next = ptr;
            last = ptr;
            start->prev = last;
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
        start = ptr;
        ptr->next = start;
        ptr->prev = start;
        last = ptr;
    }
    else
    {
        last->next = ptr;
        ptr->prev = last;
        start->prev = ptr;
        ptr->next = start;
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
    for (node *temp ; temp->next != start; temp = temp->next)
    {
        printf("Data of node [%d] ==> %d\n", I, temp->data);
        I++;
    }
    printf("Data of node [%d] ==> %d\n", I, temp->data);

    */
    while (temp->next!= start)
    {
        printf("Data of node [%d] ==> %d\n", I, temp->data);
        I++;
        temp = temp->next;
    }
    printf("Data of node [%d] ==> %d\n", I, temp->data);
}