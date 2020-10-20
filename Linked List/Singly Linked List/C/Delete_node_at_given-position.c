/*
 *  Objective  : This Program is to insert the node at the Given/Specific Position in Singly Linked List.
 *  Programmer : Jatin Sharma
 */

#include <stdio.h>
#include <stdlib.h>

int I = 1; // To Print the List using For loop as well as while loop [Global Variable]
int count = 0;

void create_linked_list(int n);
void delete_node_at_given();
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
    delete_node_at_given();
}

void delete_node_at_given()
{

    node *toDelete, *temp;

    if (start == NULL) // Checking isListEmpty
    {
        printf("List is Empty.\n");
        return;
    }
    else if (start->next == NULL) // when list only have one node.
    {
        char choice[3];
        printf("List Has only one node. You want to delete it ? (yes/no) : ");
        scanf("%s", choice);

        if (choice[0] == 'n')
        {
            printf("You choosed not to delete the last Node from the list.\n");
            print_list();
        }

        else if (choice[0] == 'y')
        {

            start = NULL;
            free(start);
            printf("Only Node Deleted Successfully, Now List is Empty.\n");
        }
        else
        {
            printf("You Entered Invalid Choice. Please Try Again.\n");
        }
        return;
    }

    //Taking Position to Delete the Node
    int position;

    printf("\nEnter the position of the node you want to perform deletion : ");
    scanf("%d", &position);

    // Checking Inseted Position by user is Valid or not.
    if (position > count || position <= 0)
    {
        printf("Postion is Out of range. Data Can't Deleted !!!\n");
        return;
    }

    if (position == 1)
    {
        temp = start;
        start = temp->next;
        free(temp);
        count--;
    }
    else
    {

        toDelete = start;

        // Loop to the position
        for (int i = 1; i < position; i++)
        {
            temp = toDelete;
            toDelete = toDelete->next;
        }
        temp->next = toDelete->next;
        free(toDelete);
        count--;
    }

    printf("\n************************************************************************\n");
    printf("******************** Node Deleted from %d Position. ********************\n", position);
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