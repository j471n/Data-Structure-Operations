/**
 *  Objective  : This Program is to create One Dimenstional Array.
 *  Programmer : Jatin Sharma
**/

/* Header File */
#include <stdio.h>

/* Declaring the inputArray() Function to take the input for an Array */
void inputArray(int arr[], int size);
/* Declaring the printArray() Function to print an Array */
void printArray(int arr[], int size);


/* Main Function */
int main()
{
    int size;       // Declaring the size of an array

    /* Taking the Value for int size; */
    printf("Enter the Total Number of Elements You want to Insert : ");
    scanf("%d", &size);

    /* Declaring an Array of size = size; */
    int arr[size];

    /* Calling Input Function to take Inputs */
    inputArray(arr, size);
    /* Printing an Array the User just Inputed */
    printArray(arr, size);     
    return 0;
}

/* Definition of inputArray() Function */
void inputArray(int arr[], int size){

    /* Loop Through All elements of an Array */
    for (int i = 0; i < size; i++)
    {
        printf("Enter the Element for index [%d] : ", i+1);
        scanf("%d", &arr[i]);
    }
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