/*
 *  Objective  : This Program is to delete the node at the first Position in Singly Linked List.
 *  Programmer : Jatin Sharma
 */

#include <stdio.h>
#include <stdlib.h>

int I = 1; // To Print the List using For loop as well as while loop [Global Variable]

void create_linked_list(int n);
void delete_node_at_first();
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
    printf("********************* NODES Created Successfully. *********************\n");
    printf("************************************************************************\n\n");
    delete_node_at_first();
}

void delete_node_at_first()
{

    node *temp;

    if (start == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    char choice;

    printf("Do you want to delete the First node of the list (y/n): ");
    // choice = getchar();
    scanf("%s", &choice);

    if (choice == 'n')
    {
        printf("You choosed not to delete the First node of the list.\n\n");
        print_list();
        return;
    }

    else if (choice == 'y')
    {
        temp = start;
        start = temp->next;
        free(temp);

        printf("\n************************************************************************\n");
        printf("******************* Node Deleted at First Position. ********************\n");
        printf("************************************************************************\n\n");
        print_list();
        return;
    }
    else {
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