#include <stdio.h>
#include <stdlib.h>

// This is count sort
// This is linear but expensive due to extra space

void CountSort(int *ptr, int size)
{
    int element, max = 0;
    int j = 0;
    max = ptr[0];
    // check the max element in array
    for (int i = 1; i < size; i++)
    {
        if (max < ptr[i])
        {
            max = ptr[i];
        }
    }
    // printf("Array max element: %d\n",max);
    // initialize array to 0
    int B[max + 1];
    for (int i = 0; i < max + 1; i++)
    {
        B[i] = 0;
    }
    // creating count array
    for (int i = 0; i < size; i++)
    {
        B[ptr[i]]++;
    }
    // decrypting data into first array
    for (int i = 0; i < max + 1; i++)
    {
        element = B[i];
        if (B[i] > 0) // check non zero elements
        {
            if (B[i] > 1) // mean there are duplicate elements
            {
                while (element > 0)
                {
                    ptr[j] = i;
                    j++;
                    element--;
                }
            }
            else // if there are only one time occurrence of element
            {
                ptr[j] = i;
                j++;
            }
        }
    }
}

void displayArray(int *ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf(" | %d | ", ptr[i]);
    }
    printf("\n \n");
}
void inputArray(int *ptr, int size)
{
    printf("****** COUNT SORT ****** \n");
    printf("Enter array elements! \n");
    for (int i = 0; i < size; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &ptr[i]);
    }
}
void freeMemory(int *ptr)
{
    free(ptr);
    ptr = NULL;
}
int main(int argc, char const *argv[])
{
    int size = 7;
    int *arr = (int *)malloc(size * sizeof(int));
    // input array elements
    inputArray(arr, size);
    displayArray(arr, size);
    // Count sort
    CountSort(arr, size);
    printf("Sorted Array: ");
    displayArray(arr, size);
    freeMemory(arr);
    return 0;
}
