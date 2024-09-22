#include<stdio.h>
#include<stdlib.h>

//struct of ADT myArray
struct myArray
{
    int total_size; //total size of array
    int used_size;  //used size of array
    int *baseAdd;   //it is pointer that store base address of array
};
void creatArray(struct myArray *arr, int tSize, int Usize)
{
    arr->total_size = tSize;
    arr->used_size = Usize;
    arr->baseAdd = (int *)malloc(tSize * sizeof(int));
}
void setVal(struct myArray *arr)
{
    for (int i = 0; i < arr->used_size; i++)
    {
        printf("a[%d]: ",i);
        scanf("%d",&arr->baseAdd[i]);
    }
    
}
void getVal(struct myArray *arr)
{
     for (int i = 0; i < arr->used_size; i++)
    {
        printf(" %d ",arr->baseAdd[i]);
        
    }
    printf("\n");
}
void updateArraySorted(struct myArray *arr)
{
   
    int i, index, element = 0;
    char c = '\0';
    do
    {
    if (arr->used_size >= arr->total_size)
    {
        printf("Insufficient memory in array! \n");
        break;
    }
    else
    {
        printf("Insert element index wise in array \n");
        printf("Enter index: ");
        scanf("%d",&index);
        //checking if index is less than or equal to used size of array
        while (index > arr->used_size)
        {
        printf("Please enter index less than or equal to [%d] \n",arr->used_size);
        printf("Enter index: ");
        scanf("%d",&index);
        }
        printf("Enter Element: ");
        scanf("%d",&element);
        //shifting elements one step to right from last element
        for (i = arr->used_size-1; i >= index; i--)
        {
            arr->baseAdd[i+1] = arr->baseAdd[i];
        } 
        //placing element at index provided
        arr->baseAdd[i+1] = element;
        //updating array size
        arr->used_size++;
        getchar();  //getting empty character
        printf("Do you want to insert more elements? (Press y for yes or Press n for no): ");
        scanf("%c",&c);
    }
    }while (c != 'n');   
}
void updateArrayUnsorted(struct myArray *arr)
{
int i, index, element = 0;
    char c = '\0';
    do
    {
    if (arr->used_size >= arr->total_size)
    {
        printf("Insufficient memory in array! \n");
        break;
    }
    else
    {
        printf("Insert element index wise in array \n");
        printf("Enter index: ");
        scanf("%d",&index);
        //checking if index is less than or equal to used size of array
        while (index > arr->used_size)
        {
        printf("Please enter index less than or equal to [%d] \n",arr->used_size);
        printf("Enter index: ");
        scanf("%d",&index);
        }
        printf("Enter Element: ");
        scanf("%d",&element);
        //if element is at last index place it at last
        if (index == arr->used_size)
        {
            arr->baseAdd[index] = element;
            arr->used_size++;   //increasing array used size by 1
        }
        else
        {
        //place index element after last element and put upcoming element at its place 
        arr->baseAdd[arr->used_size] = arr->baseAdd[index];
        arr->baseAdd[index] = element; 
        arr->used_size++;   //increasing array used size by 1
        }
        getchar();
        printf("Do you want to insert more elements? (Press y for yes or Press n for no): ");
        scanf("%c",&c);
    }
    }while (c != 'n');
}

void deleteVal(struct myArray *arr)
{
    int index, i = 0;
    char c = '\0';
    do
    {
        if (arr->used_size == 0)
        {
            printf("Array is empty! \n");
            break;
        }
        else
        {
        printf("Enter index to delete value: ");
        scanf("%d",&index);
        //checking if index is < 0 or >= array size
        while (index < 0 || index >= arr->used_size)
        {
        printf("Please enter index >= 0 and < [%d] \n",arr->used_size);
        printf("Enter index: ");
        scanf("%d",&index);
        }
        //now start shifting elements from index (left to right) till last element
        for (int i = index; i < arr->used_size-1; i++)
        {
            arr->baseAdd[i] = arr->baseAdd[i+1];
        }
        arr->used_size--;
        getchar();
        printf("Do you want to delete more elements? (Press y for yes or Press n for no): ");
        scanf("%c",&c);
        }
    } while (c != 'n');
      
}
void freeMemory(struct myArray *arr)
{
    free(arr->baseAdd);
}
int main(int argc, char const *argv[])
{
    struct myArray arr;
    int tSize = 10;
    int uSize = 5;
    int val = 0;
    //creating array
    creatArray(&arr,tSize,uSize);

    //taking input in array
    printf("Enter integer array elements! \n");
    setVal(&arr);

    //display array elements
    getVal(&arr);

    //update sorted array
    updateArraySorted(&arr);

   //update unsorted array
    //updateArrayUnsorted(&arr);

    //display array elements
    getVal(&arr);

    //delete value from array elements
    deleteVal(&arr);

    //display array elements
    getVal(&arr);

    //free memory of heap
    freeMemory(&arr);
    return 0;
}
