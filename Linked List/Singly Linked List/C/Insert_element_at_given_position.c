/*
 *  Objective  : This Program is to insert the element at the Given/Specific Position in Singly Linked List.
 *  Programmer : Jatin Sharma
 */

#include <stdio.h>
#include <stdlib.h>

int I = 1; // To Print the List using For loop as well as while loop [Global Variable]
int count = 0;

void create_linked_list(int n);
void insert_element_at_given();
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

    start = (node *)malloc(sizeof(node));
    if (start == NULL)
    {
        printf("Cannot Allocate Memory for Overflow Reason. Please Stop some task and try Again>\n");
        return;
    }

    temp = start;

    for (int i = 0; i < n; i++)
    {

        array = (node *)malloc(sizeof(node));
        if (array == NULL)
        {
            printf("Cannot Allocate Memory for Overflow Reason. Please Stop some task and try Again>\n");
            return;
        }

        printf("Enter the Data for node [%d] : ", i + 1);
        scanf("%d", &array->data);
        array->next = NULL;
        temp->next = array;
        temp = temp->next;
        count++;
    }

    printf("\n");
    printf("************************************************************************\n");
    printf("********************* NODES Inserted Successfully. *********************\n");
    printf("************************************************************************\n\n");
    insert_element_at_given();

}

void insert_element_at_given()
{

    node *temp, *array;
    int data , position;
    printf("Enter the position to insert Data : ");
    scanf("%d", &position);
    if (position > count)
    {
        printf("Postion is Out of range. Data Can't Inserted !!!\n");
        return ;
    }
    
    array = (node *)malloc(sizeof(node));
    if (array == NULL)
    {
        printf("Cannot Allocate Memory for Overflow Reason. Please Stop some task and try Again\n");
        exit;
    }
    printf("Enter data to insert at %d postion : ", position);
    scanf("%d", &array->data);

    temp = start;
    for (int i = 1; i < position; i++)
    {
        temp = temp->next;

    }

    array->next = temp->next;
    temp->next = array;
    count++;
    // printf("Node Inserted at %d position.\n", position);

 
    printf("\n************************************************************************\n");
    printf("******************* Node Inserted at given Position. *******************\n");
    printf("************************************************************************\n\n");
    print_list();
}

void print_list()
{

    if (start == NULL)
    {
        printf("List is Empty.\n");
        return;
    }

    /*
    // You can Use this loop as well
    node *temp = start;
    for (node *temp ; temp != NULL; temp = temp->next)
    {

        printf("Data of node %d = %d\n", I, temp->next->data);
        I++;
    }*/
    
    while (start != NULL)
    {
        printf("Data of node %d = %d\n", I, start->next->data);
        I++;
        start = start->next;
    }

}