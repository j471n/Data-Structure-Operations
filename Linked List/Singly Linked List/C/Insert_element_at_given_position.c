/*
 *  Objective  : This Program is to insert the node at the Given/Specific Position in Singly Linked List.
 *  Programmer : Jatin Sharma
 */

#include <stdio.h>
#include <stdlib.h>

int I = 1; // To Print the List using For loop as well as while loop [Global Variable]
int count = 0;

void create_linked_list(int n);
void insert_node_at_given();
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
        count++;
    }

    printf("\n");
    printf("************************************************************************\n");
    printf("********************* NODES Inserted Successfully. *********************\n");
    printf("************************************************************************\n\n");
    insert_node_at_given();
}

void insert_node_at_given()
{

    node *temp, *array;
    int position;

    printf("Enter the position to insert Data : ");
    scanf("%d", &position);
    if (position > count || position <= 0)
    {
        printf("Position is Out of range. Data Can't Inserted. Linked List only have [%d] Node !!!\n", count);
        return;
    }

    array = (node *)malloc(sizeof(node));
    if (array == NULL)
    {
        printf("Cannot Allocate Memory for Overflow Reason. Please Stop some task and try Again.\n");
        return;
    }
    printf("Enter data to insert at [%d] position : ", position);
    scanf("%d", &array->data);
    temp = start;

    //Case for Inserting node If the position is 1
    if (position == 1)
    {
        array->next = start;
        start = array;
        count++;
    }
    else
    {

        for (int i = 2; i < position; i++)
        {
            temp = temp->next;
        }

        array->next = temp->next;
        temp->next = array;
        count++;
    }

    printf("\n************************************************************************\n");
    printf("******************* Node Inserted at given Position. *******************\n");
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
    }*/

    while (temp != NULL)
    {
        printf("Data of node [%d] ==> %d\n", I, temp->data);
        I++;
        temp = temp->next;
    }
}