#include<stdio.h>
#include<stdlib.h>


void displayArray(int *ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf(" | %d | ",ptr[i]);
    }
    printf("\n \n");
}

int partition(int *ptr, int low, int high)
{
    int temp = 0;
    int pivot = ptr[low];
    int i = low + 1;
    int j = high;
    do
    {
        while (ptr[i] <= pivot) //move low to right till greater element than pivot found
    {
        i++;
    }
    while (ptr[j] > pivot ) // move higher to left till smaller element than pivot found
    {
        j--;
    }
    if (i < j)  //if low < high swap the ptr[i] and ptr[j]
    {
        temp = ptr[i];
        ptr[i] = ptr[j];
        ptr[j] = temp;
    }
    } while (i < j);  
    //if i > j then swap ptr[j] with pivot
    temp = ptr[low];
    ptr[low] = ptr[j];
    ptr[j] = temp;
    return j;
    
}
void QuickSortHarry(int *ptr, int low, int high)
{
    int partitionIndex;
    if (low < high)
    {
        partitionIndex = partition(ptr, low, high);
        QuickSortHarry(ptr, low, partitionIndex - 1);
        QuickSortHarry(ptr, partitionIndex+1, high);
    }
}
void inputArray(int *ptr, int size)
{
    printf("****** QUICK SORT ****** \n");
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
    int size = 10;
    int low = 0;
    int high = size - 1;
    int *arr = (int *)malloc(size * sizeof(int));
    //input array elements
    inputArray(arr,size);
    displayArray(arr,size);
    QuickSortHarry(arr, low, high);
    printf("Sorted Array: ");
    displayArray(arr,size);
    freeMemory(arr);
    return 0;
}
