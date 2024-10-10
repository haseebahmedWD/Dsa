#include<stdio.h>
#include<stdlib.h>

//This is Selection sort
//This is neither stable nor adaptive
void SelectionSort(int *ptr, int size)
{
    int temp,index,min = 0;
    for (int i = 0; i < size - 1; i++)  //outer loop control iteration
    {
        min = ptr[i];
        for (int j = i + 1; j < size; j++)  
        {
            if (ptr[j] < min)   //check if there is smaller element then minimum
            {
                min = ptr[j];
                index = j;      //save the index of smaller element
            }
        }
                //swapping of previous minimum element to new minimum element
            temp = ptr[i];
            ptr[i] = ptr[index];
            ptr[index] = temp;
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
    printf("****** SELECTION SORT ****** \n");
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
    SelectionSort(arr,size);
    printf("Sorted Array: ");
    displayArray(arr,size);
    freeMemory(arr);
    return 0;
}
