/*
 *  Objective  : This Program is to insert the element at the Given/Specific Position in Singly Linked List.
 *  Programmer : Jatin Sharma
 */

#include <stdio.h>
#include <stdlib.h>

int I = 1; // To Print the List using For loop as well as while loop [Global Variable]
int count = 0;

void create_linked_list(int n);
void delete_element_at_given();
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

    //It is creating nodes for the data.
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
    delete_element_at_given();
}

void delete_element_at_given()
{


    node *toDelete, *temp;
    int position;

    printf("\nEnter the position of the node you want to perform deletion : ");
    scanf("%d", &position);

    // Checking Inseted Position by user is Valid or not.
    if (position > count || position <= 0)
    {
        printf("Postion is Out of range. Data Can't Deleted !!!\n");
        return;
    }

    if (start == NULL)      // Checking isListEmpty
    {
        printf("List is Empty.\n");
        return;
    }
    else if (start->next == NULL)       // when list only have one element.
    {
        start = NULL;
        free(start);
        printf("Node (had one element) Deleted Successfully.\n");
        return ;
    }

    toDelete = start;

    // Loop to the position 
    for (int i = 0; i < position; i++)
    {
        temp = toDelete;
        toDelete = toDelete->next;
    }
    temp->next = toDelete->next;
    free(toDelete);
    count--;

    printf("\n************************************************************************\n");
    printf("******************** Node Deleted from %d Position. ********************\n", position);
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
    node *temp =start;
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