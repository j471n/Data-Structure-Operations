/**
 *  Objective  : This Program is to Insert an Element at given position in One Dimenstional Array.
 *  Programmer : Jatin Sharma
**/

/* Header File */
#include <stdio.h>
#include <stdlib.h>

/* Declaring the inputArray() Function : to take the input for an Array */
void inputArray(int arr[], int size);
/* Declaring the insert() Function : to insert an element at given position */
int insert(int arr[], int size);
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
    /* Inserting an element an Array  */
    size = insert(arr, size);
    /* Printing an Array  */
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

/* Definition of insert() Function */
int insert(int arr[], int size)
{

    /* Declaring position and value variable */
    int position, value;

    do
    {
        /* Taking the value of position */
        printf("Enter the \"position\" to Insert at : ");
        scanf("%d", &position);

        /* Checking the position isValid ;*/
        if (position > size || position < 1)
        {
            printf("Invalid Position.\n");
        }
        else
        {
            printf("Enter the \"value\" to Insert : ");
            scanf("%d", &value);

            for (int i = size; i >= position - 1; i--)
            {
                arr[i + 1] = arr[i];
            }

            arr[position - 1] = value;
            size++;
            break;
        }
    } while (1);

    /* Returning size to main() so printArray can print that*/ 
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