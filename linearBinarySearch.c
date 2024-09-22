#include<stdio.h>

//linear search function
int linearSearch(int *ptr, int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (ptr[i] == element)
        {
            return i;
        }
        
    }
    return -1;
}
//Binary Search Function
int binarySearch(int *ptr, int size, int element)
{
    int low, high, mid = 0;
    high = size - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (ptr[mid] == element)
        {
            return mid;
        }
        if (ptr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        } 
    }
    return -1;    
}
void displayArray(int *p, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", p[i]);
    }
    printf("\n");
}
int main(int argc, char const *argv[])
{
    int arr1[] = {50,66,3,10,19,100};
    int arr2[] = {1,2,3,4,5,6,7,8,9,10};
    int element = 0;
    displayArray(arr1,6);

    //linear search
    element = 10;
    int linearResult = linearSearch(arr1,6,element);
    if (linearResult >= 0)
    {
     printf("Element found at [%d] index! \n",linearResult);   
    }
    else
    {
        printf("Element not found! \n");
    }
    
    //binary search
    displayArray(arr2,10);
    element = 10;
    int binaryResult = binarySearch(arr2, 10, element);
    if (binaryResult >= 0)
    {
     printf("Element found at [%d] index! \n",binaryResult);   
    }
    else
    {
        printf("Element not found! \n");
    }

    return 0;
}
