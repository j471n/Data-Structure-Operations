/*
 *  Objective  : This Program is to delete a node at the first Position in Doubly Linked List.
 *  Programmer : Jatin Sharma
 */

#include <stdio.h>
#include <stdlib.h>

int I = 1; // To Print the List using For loop as well as while loop [Global Variable]

void createLinkedList(int n);
void delete ();
void printList();

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;

} node;

node *start = NULL; // Setting Up tekh Node to NULL

int main()
{

    int n;
    printf("Enter the Number of Total Node you want to insert : ");
    scanf("%d", &n);

    createLinkedList(n);

    char choice[3];

    printf("Do you want to delete the First node of the list (y/n): ");
    scanf("%s", choice);

    if (choice[0] == 'n')
    {
        printf("You choosed not to delete the First node of the list.\n");
        exit(1);
    }

    else if (choice[0] == 'y')
    {
        delete ();
    }
    else
    {
        printf("You Entered Invalid Choice. Please Try Again.\n");
        exit(1);
    }

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
        ptr->next = NULL;

        if (start == NULL)
        {
            ptr->prev = NULL;
            start = ptr;
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
        }
    }

    printf("\n************************************************************************\n");
    printf("********************* NODES Created Successfully. *********************\n");
    printf("************************************************************************\n\n");
}

void delete ()
{
    int data;
    if (start == NULL)
    {
        printf("List is empty.\n");
        exit(1);
    }
    else if (start->next == NULL)
    {
        data = start->data;
        free(start);
        printf("\nNode Only had one Element %d Deleted Successfully.\n", data);
        exit(0);
    } else {

    node *temp = start;
    data = temp->data;
    start = temp->next;
    start->prev = NULL;
    free(temp);
    }

    printf("\n************************************************************************\n");
    printf("*********************** %d Deleted Successfully. ***********************\n", data);
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