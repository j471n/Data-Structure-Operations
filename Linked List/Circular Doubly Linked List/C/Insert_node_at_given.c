/*
    TODO: This Program is to Insert a node at given position in Circular Doubly Linked List.
 *  Programmer : Jatin Sharma
*/

#include <stdio.h>
#include <stdlib.h>

int I = 1;
void createLinkedList(int n);
void insert(int element, int position);
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
    
    int element, position;
    printf("Enter Position to Insert Data : ");
    scanf("%d", &position);

    if (position > n || position <= 0)
    {
        printf("\nInserting Attempt FAILED. List only had %d nodes and you are searching for %d. Are You Mad??\n", n, position);
        return 1;
    }
    else
    {

        printf("Enter the Data to Insert at [%d] Position : ", position);
        scanf("%d", &element);
        insert(element, position);
    }

    printLinkedList();   // Printing Circular Doubly Linked List.
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
            ptr->next = start;
            ptr->prev = temp;
            last->next = ptr;
            last = ptr;
            start->prev = last;
        }
    }

    printf("\n************************************************************************\n");
    printf("********************* NODES Created Successfully. *********************\n");
    printf("************************************************************************\n\n");
}

void insert(int element, int position)
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
        temp = start;
        if (position == 1)
        {
            ptr->next = start;
            ptr->prev = last;
            start->prev = ptr;
            last->next = ptr;
            start = ptr;
        }
        else
        {

            for (int i = 2; i < position; i++)
            {
                temp = temp->next;
            }

            ptr->next = temp->next;
            ptr->prev = temp;
            temp->next = ptr;
            temp->next->prev = ptr;
        }
    }

    printf("\n************************************************************************\n");
    printf("******************** Data %d Inserted at %d - Successfully. ********************\n", element, position);
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
    while (temp->next != start)
    {
        printf("Data of node [%d] ==> %d\n", I, temp->data);
        I++;
        temp = temp->next;
    }
    printf("Data of node [%d] ==> %d\n", I, temp->data);
}