#include<stdio.h>
#include<stdlib.h>

//this program is about bubble sort
//bubble sort is stable algo
//it is not adaptive (but we can make it)
void BubbleSort(int *ptr, int size)
{
    int temp = 0;
    int swapCount = 0;
    for (int i = size - 1; i > 0; i--)  //outer loop control iteration
    {
        for (int j = 0; j < i; j++) //inner loop control swaps
        {
            if (ptr[j] > ptr[j + 1])
            {
                //swapping
                temp = ptr[j];
                ptr[j] = ptr[j+1];
                ptr[j+1] = temp;
                swapCount++;
            } 
        }
        //this function will save time if array is already sorted (it makes this Bubble sort function Adaptive!)
        if (swapCount == 0)
        {
            printf("Array is already sorted! \n");
            break;
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
    printf("****** BUBBLE SORT ****** \n");
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
    int size = 6;
    int *arr = (int *)malloc(size * sizeof(int));
    //input array elements
    inputArray(arr,size);
    displayArray(arr,size);
    //bubble sort 
    BubbleSort(arr,size);
    printf("Sorted Array: ");
    displayArray(arr,size);
    freeMemory(arr);
    return 0;
}
