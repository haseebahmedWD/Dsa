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

void Merge(int *ptr, int low, int mid, int high)
{
  
    int temp = 0;
    int i = low;        //i moves from 0 to mid
    int j = mid + 1;    // j moves from mid+1 to high
    int k = low;        //k control iteration of second array, it start from 0
    int B[high + 1];
  
    while (i <= mid && j<= high)    
    {
        if (ptr[i] < ptr[j])
        {
            B[k] = ptr[i];
            i++;
            k++;
        }
        else
        {
            B[k] = ptr[j];
            j++;
            k++;
        }
    }
    while (i<=mid)  //copy remining elements of array which are <= mid
    {
        B[k] = ptr[i];
        i++;
        k++;
    }
    while (j<=high) //copy remaining elements of array which are >= high
    {
        B[k] = ptr[j];
        j++;
        k++;
    }
    for (int i = low; i <=high; i++)
    {
        ptr[i] = B[i];  //copying second array data into original array
    }
    
}
void MergeSort(int *ptr, int low, int high)
{
    int mid = 0;
    if (low < high)
    {
        mid = (low + high) / 2;
        MergeSort(ptr, low, mid);
        MergeSort(ptr, mid+1, high);
        Merge(ptr, low, mid, high);
    }
}
void inputArray(int *ptr, int size)
{
    printf("****** MERGE SORT ****** \n");
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
    int low = 0;
    int high = size - 1;
    int *arr = (int *)malloc(size * sizeof(int));
    //input array elements
    inputArray(arr,size);
    displayArray(arr,size);
    MergeSort(arr, low, high);
    printf("Sorted Array: ");
    displayArray(arr,size);
    
    printf("\n \n");
    freeMemory(arr);
    return 0;
}
