/*
 *  Objective  : This Program is to insert the element at the first Position in Singly Linked List.
 *  Programmer : Jatin Sharma
 */

#include <stdio.h>
#include <stdlib.h>

int I = 1; // To Print the List using For loop as well as while loop [Global Variable]

void create_linked_list(int n);
void insert_element_at_first();
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

        //temp = temp->next;
    }

    printf("\n");
    printf("************************************************************************\n");
    printf("********************* NODES Inserted Successfully. *********************\n");
    printf("************************************************************************\n\n");
    insert_element_at_first();
}

void insert_element_at_first()
{

    node *temp;
    int data;
    printf("Enter data to insert at position First : ");
    scanf("%d", &data);

    temp = (node *)malloc(sizeof(node));
    if (temp == NULL)
    {
        printf("Cannot Allocate Memory for Overflow Reason. Please Stop some task and try Again\n");
        return;
    }

    temp->data = data;
    temp->next = start;
    start = temp;

    printf("\n************************************************************************\n");
    printf("******************* Node Inserted at first Position. *******************\n");
    printf("************************************************************************\n\n");
    print_list();
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