/*
 *  Objective  : This Program is to Search an element in Singly Linked List.
 *  Programmer : Jatin Sharma
 */

#include <stdio.h>
#include <stdlib.h>

int I = 1;  // To Print the List using For loop as well as while loop [Global Variable]

void create_linked_list(int n);
void search();
void wanna_print();
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
    printf("********************* NODES Inserted Successfully. *********************\n");
    printf("************************************************************************\n\n");
    search();
    
}

// It is a linear Search 
void search(){
    node *temp = start;
    int element;
    printf("Enter the Element to Search : ");
    scanf("%d", &element);

    while (temp!=NULL)
    {
        if (temp->data == element)
        {
            printf("Element found at [%d] index.\n", I);  
            wanna_print();
            return;
        }

        temp=temp->next;
        I++;
    }
    printf("Element Not Found.\n");
    wanna_print();          // Calling Wanna_Print() Funtion
    
}



void wanna_print(){
    
    char choice[3];
    do
    {
        printf("Do you want to print Nodes? (yes/no) : ");
        scanf("%s", choice);

        if (choice[0] == 'n')
        {
            printf("Thanks For Using.\n");
            break;
        }

        else if (choice[0] == 'y')
        {
            printf("Here is Your Linked List -->.\n");
            print_list();
            break;
        }
        else
        {
            printf("You Entered Invalid Choice. Please Try Again.\n");
        }

    } while (1);
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