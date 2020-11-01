/*
 *  Objective  : This Program is to delete the node at the Given Position in Circular Singly Linked List.
 *  Programmer : Jatin Sharma
 */

#include <stdio.h>
#include <stdlib.h>

int I = 1; // To Print the List using For loop as well as while loop [Global Variable]
int COUNT = 0;
void createLinkedList(int n);
void delete();
void printList();

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

    createLinkedList(n);
    delete();
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

        if (start == NULL)
        {
            start = ptr;
            ptr->next = start;
        }
        else
        {
            temp = start;

            while (temp->next != start)
            {
                temp = temp->next;
            }

            ptr->next = start;
            temp->next = ptr;
        }
        COUNT++;
    }

    printf("\n");
    printf("************************************************************************\n");
    printf("********************* NODES Inserted Successfully. *********************\n");
    printf("************************************************************************\n\n");
}

void delete()
{
    int data;
    node *toDelete, *temp;
    if (start == NULL)
    {
        printf("List is Empty.\n");
        free(toDelete);
        free(temp);
        exit(1);
    }
    else if (start->next == start)
    {

        char choice[3];
        printf("List Has only one node. You want to delete it ? (yes/no) : ");
        scanf("%s", choice);

        if (choice[0] == 'n')
        {
            printf("You choosed not to delete the last Node from the list.\n");
        }

        else if (choice[0] == 'y')
        {

            data = start->data;
            start = NULL;
            free(start);
            printf("Only node in List deleted Succussfully, Data was - %d\n", data);
        }
        else
        {
            printf("You Entered Invalid Choice. Please Try Again.\n");
        }
        exit(1);
    }
    else
    {

        //Taking Position to Delete the Node
        int position;
        node *temp;

        printf("\nEnter the position of the node you want to perform deletion : ");
        scanf("%d", &position);

        // Checking Inseted Position by user is Valid or not.
        if (position > COUNT || position <= 0)
        {
            printf("Postion is Out of range. Data Can't Deleted !!!\n");
            exit(1);
        }
        else if (position == 1)
        {
            temp = start;
            while (temp->next != start)
            {
                temp = temp->next;
            }
            temp->next = start->next;
            data = start->data;
            free(start);
            start = temp->next;
        }
        else
        {
            node *toDelete = start;
            for (int i = 1; i < position; i++)
            {
                temp = toDelete;
                toDelete = toDelete->next;
            }
            temp->next = toDelete->next;
            data = toDelete->data;
            free(toDelete);

            
        }
        COUNT--;
    }

    printf("\n************************************************************************\n");
    printf("******************** %d Data Deleted Successfully. ********************\n", data);
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