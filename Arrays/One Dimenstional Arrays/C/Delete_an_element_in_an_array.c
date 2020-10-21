/**
 *  Objective  : This Program is to Delete an Element at given position in One Dimenstional Array.
 *  Programmer : Jatin Sharma
**/

/* Header File */
#include <stdio.h>
#include <stdlib.h>

/* Declaring the inputArray() Function : to take the input for an Array */
void inputArray(int arr[], int size);
/* Declaring the delete() Function : to insert an element at given position */
int delete(int arr[], int size);
/* Declaring the printArray() Function : to print an Array */
void printArray(int arr[], int size);

/* Main Function */
int main()
{
    int size; // Declaring the size of an array

    /* Taking the Value for int size; */
    printf("Enter the Total Number of Elements You want to Insert : ");
    scanf("%d", &size);

    /* Declaring an Array of size = size; */
    int arr[size];

    /* Calling Input Function to take Inputs */
    inputArray(arr, size);
    /* Deleting an element an Array  */
    size = delete(arr, size);
    /* Printing an Array after Perform Deletion */
    printArray(arr, size);

    return 0;
}

/* Definition of inputArray() Function */
void inputArray(int arr[], int size)
{

    /* Loop Through All elements of an Array */
    for (int i = 0; i < size; i++)
    {
        printf("Enter the Element for index [%d] : ", i + 1);
        scanf("%d", &arr[i]);
    }
}


/**
 *  WARNING    : In this Program element actually not got deleted, it's just got replaced with the next one and after deleting an elment the size (variable) will have the garbage value. 
**/

/* Definition of delete() Function */
int delete(int arr[], int size)
{
    /* Printing an Array Before Deleting an Element */
    printf("Before Deleting ");
    printArray(arr, size);

    /* Declaring position and value variable */
    int position;

    do
    {
        /* Taking the value of position */
        printf("\nEnter the \"position\" to Delete an Element : ");
        scanf("%d", &position);

        /* Checking the position isValid ;*/
        if (position > size || position < 1)
        {
            printf("Invalid Position.\n");
        }
        else
        {
            /* Checking Array have one element or not? */
            if (size == 1)
            {
                printf("Array (only) element deleted.\n");
                /* exiting with status code 0*/
                exit(0);
            }

            /* Loop thorogh position to size of an arrary */ 
            for (int i = position-1; i < size; i++)
            {
                arr[i] = arr[i + 1];
            }

            /* Decreasing the size of an array*/
            size--;
            break;
        }
        
    } while (1);

    /* Returning size to main() so printArray() can print that */
    return size;
}

/* Definition of printArray() Function */
void printArray(int arr[], int size)
{
    printf("Here's the Array ==>\n");
    /* Loop Through All elements of an Array */
    for (int i = 0; i < size; i++)
    {
        printf("%d | ", arr[i]);
    }
    
}