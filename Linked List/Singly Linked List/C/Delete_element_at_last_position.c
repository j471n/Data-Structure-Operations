/*
 *  Objective  : This Program is to Delete the node at the Last Position in Singly Linked List.
 *  Programmer : Jatin Sharma
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int I = 1; // To Print the List using For loop as well as while loop [Global Variable]

void create_linked_list(int n);
void delete_node_at_last();
void print_list();

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

    create_linked_list(n);
    return 0;
}

void create_linked_list(int n)
{
    node *array, *temp;

    for (int i = 0; i < n; i++)
    {

        array = (node *)malloc(sizeof(node));
        if (array == NULL)
        {
            printf("Cannot Allocate Memory for Overflow Reason. Please Stop some task and try Again.\n");
            return;
        }

        printf("Enter the Data for node [%d] : ", i + 1);
        scanf("%d", &array->data);
        array->next = NULL;

        if (start == NULL)
        {
            start = array;
        }
        else
        {
            temp = start;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = array;
        }
    }

    printf("\n");
    printf("************************************************************************\n");
    printf("********************** NODE Created Successfully. **********************\n");
    printf("************************************************************************\n\n");
    delete_node_at_last();
}

void delete_node_at_last()
{

    node *toDelete, *temp;

    if (start == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    else if (start->next == NULL)
    {
        start = NULL;
        free(start);
        printf("Node (had one node) Deleted Successfully at Last.\n");
        return;
    }

    char choice[3];

    printf("Do you want to delete the last node of the list (yes/no): ");
    scanf("%s", choice);
    
    if (choice[0] == 'n')
    {
        printf("You choosed not to delete the last Node from the list.\n");
        print_list();
        return;
    }

    else if (choice[0] == 'y')
    {
        toDelete = start;

        while (toDelete->next != NULL)
        {
            temp = toDelete;
            toDelete = toDelete->next;
        }

        temp->next = NULL;
        free(toDelete);

        printf("\n************************************************************************\n");
        printf("******************* Node Deleted at last Position. ********************\n");
        printf("************************************************************************\n\n");
        print_list();
        return;
    }
    else
    {
        printf("You Entered Invalid Choice. Please Try Again.\n");
        return;
    }
}

void print_list()
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

        printf("Data of node %d = %d\n", I, temp->data);
        I++;
    }
    */
    while (temp != NULL)
    {
        printf("Data of node %d = %d\n", I, temp->data);
        I++;
        temp = temp->next;
    }
}