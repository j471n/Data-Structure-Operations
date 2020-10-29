/*
 *  Objective  : This Program is to Delete a node at last position in Doubly Linked List.
 *  Programmer : Jatin Sharma
 */

#include <stdio.h>
#include <stdlib.h>

int I = 1;
void createLinkedList(int n);
void pop();
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

    // Creating List
    createLinkedList(n);

    // Checking List is empty or not to delete the element
    if (start == NULL)
    {
        printf("List is Empty. First Insert the nodes.\n");
        exit(1);
    }
    char choice[3];

    printf("Do you want to delete the Last node of the list (y/n): ");
    scanf("%s", choice);

    if (choice[0] == 'n')
    {
        printf("You choosed not to delete the Last node of the list.\n\n");
        exit(0);
    }
    else if (choice[0] == 'y')
    {
        pop();
    }
    else
    {
        printf("Invalid Choice. Check your Input and Try Again.\n");
        exit(1);
    }

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
            printf("Cannot Allocate Memory because of Overflow Reason. Please \"Stop\" some task and try Again.\n");
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

void pop()
{

    int data;
    node *temp = last;

    data = last->data;
    last = temp->prev;
    last->next = NULL;
    free(temp);

    printf("\n************************************************************************\n");
    printf("***********************  %d Deleted Successfully. **********************\n", data);
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