#include<stdio.h>
#include<stdlib.h>

//This is insertion sort
//This is stable
//This is adaptive
void InsertionSort(int *ptr, int size)
{
    int temp, j = 0;
    for (int i = 0; i < size - 1; i++)  //outer loop control iteration
    {
        j = i+1;
        while (ptr[j] < ptr[j - 1]) // check if previous element is greater or not. If greater than swap
        {
                //swapping
            temp = ptr[j];
            ptr[j] = ptr[j - 1];
            ptr[j - 1] = temp;
            j--;
        } 
    }
}
void displayArray(int *ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf(" | %d | ",ptr[i]);
    }
    printf("\n \n");
}
void inputArray(int *ptr, int size)
{
    printf("****** INSERTION SORT ****** \n");
    printf("Enter array elements! \n");
    for (int i = 0; i < size; i++)
    {
        printf("a[%d]: ",i);
        scanf("%d",&ptr[i]);
    } 
}
void freeMemory(int *ptr)
{
    free(ptr);
    ptr = NULL;
}
int main(int argc, char const *argv[])
{
    int size = 5;
    int *arr = (int *)malloc(size * sizeof(int));
    //input array elements
    inputArray(arr,size);
    displayArray(arr,size);
    //Insertion sort
    InsertionSort(arr,size);
    printf("Sorted Array: ");
    displayArray(arr,size);
    freeMemory(arr);
    return 0;
}
