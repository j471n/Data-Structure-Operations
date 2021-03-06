/*
    TODO  : This Program is to Delete the node at the Given/Specific Position in Circular Doubly Linked List.
 *  Programmer : Jatin Sharma
 */

#include <stdio.h>
#include <stdlib.h>

int I = 1;     // To Print the List using For loop as well as while loop [Global Variable]
int COUNT = 0; // Counting how much element list have?

void createLinkedList(int n);
void delete();
void printList();

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

node *start = NULL; // Setting Up teh Node to NULL
node *last = NULL;

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
            ptr->prev = start;
            last = ptr;
        }
        else
        {
            temp = start;
            ptr->next = start;
            ptr->prev = last;
            last->next = ptr;
            last = ptr;
            start->prev = last;
        }
        COUNT++;
    }

    printf("\n************************************************************************\n");
    printf("********************* NODES Created Successfully. *********************\n");
    printf("************************************************************************\n\n");
}


void delete ()
{

    node *toDelete, *temp;
    int data;

    if (start == NULL) // Checking isListEmpty
    {
        printf("List is Empty.\n");
        return;
    }
    else if (start->next == start) // when list only have one node.
    {
        char choice[3];
        printf("List Has only one node. You want to delete it ? (yes/no) : ");
        scanf("%s", choice);

        if (choice[0] == 'n')
        {
            printf("You choosed not to delete the last Node from the list.\n");
            printList();
        }

        else if (choice[0] == 'y')
        {
            data = start->data;
            free(start);
            printf("Only Node (element %d) Deleted Successfully, Now List is Empty.\n", data);
        }
        else
        {
            printf("You Entered Invalid Choice. Please Try Again.\n");
        }
        exit(0);
    }

    //Taking Position to Delete the Node
    int position;

    printf("\nEnter the position of the node you want to perform deletion : ");
    scanf("%d", &position);

    // Checking Inseted Position by user is Valid or not.
    if (position > COUNT || position <= 0)
    {
        printf("Postion is Out of range. Data Can't Deleted !!!\n");
        exit(1);
    }

    if (position == 1)
    {
        temp = start;
        data = start->data;
        start = start->next;
        start->prev = temp->prev;
        last->next = temp->next;
        free(temp);
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
        data = toDelete->data;
        temp->next = toDelete->next;
        toDelete->next->prev = toDelete->prev;
        free(toDelete);
    }
    COUNT--;

    printf("\n************************************************************************\n");
    printf("***************** Element %d Deleted from %d Position. *****************\n", data, position);
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

