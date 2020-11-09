/*
    TODO: This Program is to delete a node at first position in Circular Doubly Linked List.
 *  Programmer : Jatin Sharma
*/

#include <stdio.h>
#include <stdlib.h>

int I = 1;
void createLinkedList(int n);
void delete ();
void printLinkedList();

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

node *start = NULL; // Setting start to NUll
node *last = NULL;

int main()
{

    int n;
    printf("Enter the Number of Total Node you want to insert : ");
    scanf("%d", &n);

    createLinkedList(n);

    char choice[3];

    printf("Do you want to delete the first node of the list (y/n): ");
    scanf("%s", choice);

    if (choice[0] == 'n')
    {
        printf("You choosed not to delete the first node of the list.\n\n");
        exit(0);
    }
    else if (choice[0] == 'y')
    {
        delete ();
    }
    else
    {
        printf("Invalid Choice. Check your Input and Try Again.\n");
        exit(1);
    }

    printLinkedList(); // Printing Doubly Linked List.
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
            last = ptr;
            ptr->prev = last;
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
    }

    printf("\n************************************************************************\n");
    printf("********************* NODES Created Successfully. *********************\n");
    printf("************************************************************************\n\n");
}

void delete ()
{

    int data;
    // Checking List is empty or not to delete the element
    if (start == NULL)
    {
        printf("List is Empty. First Insert the nodes.\n");
        exit(1);
    }
    else if (start->next == start)
    {
        data = start->data;
        free(start);
        printf("\nNode Only had one Element %d Deleted Successfully.\n", data);
        exit(0);
    }
    else
    {
        node *temp = start;
        data = start->data;
        start = start->next;
        start->prev = temp->prev;
        last->next = temp->next;
        free(temp);
    }

    printf("\n************************************************************************\n");
    printf("******************** Data %d Deleted Successfully. ********************\n", data);
    printf("************************************************************************\n\n");
}

void printLinkedList()
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