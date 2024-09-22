#include<stdio.h>
#include<stdlib.h>
//this program is about implementing stack using array
struct stackArr
{
    int size;   //total size of stack
    int top;    //top index of stack
    int *ptr;     //pointer for stack memory on heap
};

struct stackArr *createStack(struct stackArr *arr, int size)
{
    arr = (struct stackArr *)malloc(sizeof(struct stackArr));    //creating stack on heap memory
    arr->size = size;
    arr->top = -1;
    arr->ptr = (int *)malloc(size * sizeof(int)); //creating memory according to size on heap
    printf("\n**Stack of size %d is created successfully!** \n",size);
   return arr;
}
//check if stack is empty
int isEmpty(struct stackArr *arr)
{
    if (arr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
//check if stack is full
int isFull(struct stackArr *arr)
{
    if (arr->top == arr->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//push() function in stack
void push(struct stackArr *arr)
{
    int val = 0;
    char c = '\0';
    printf("Enter integer value to push into stack: ");
    scanf("%d",&val);
    arr->top++;
    arr->ptr[arr->top] = val;
    getchar();  
}
int pop(struct stackArr *arr)
{
    int val = arr->ptr[arr->top];
    arr->ptr[arr->top] = 0;
    arr->top--;
    return val;
}
//this function return value on stack according to index
int peak(struct stackArr *arr)
{
    int i = 0;
    printf("Enter index to search value on stack (1-%d): ",arr->top+1);
    scanf("%d",&i);
    //top - i + 1 is formula to get index (index start from 1)
    if (i <= 0 || i > arr->top+1)
    {
        printf("Wrong index! \n");
        return -1;
    }
    else
    {
        return arr->ptr[arr->top - i + 1];
    }
}
void freeStack(struct stackArr *arr)
{
    free(arr->ptr);
    free(arr);
    arr->ptr = NULL;
    arr = NULL;
    printf("\n**** Heap memory free! **** \n");
}

int main(int argc, char const *argv[])
{
    char choice;
    struct stackArr *obj1Stack = createStack(obj1Stack,5);   //assign values to newly created stack
    //push elements in stack
    do
    {
        push(obj1Stack);
        //printf("Do you want to push more elements Press 'y' for Yes Press 'n' for No: ");
        //scanf("%c",&choice);
    } while (!isFull(obj1Stack) /*&& choice == 'y'*/); 
    if (isFull(obj1Stack))
    {
       printf("\n**** Stack is Full! **** \n");
    }
    //a loop to print stack elements
    
    for (int i = obj1Stack->top; i >= 0; i--)
    {
        printf("top->[%d]: [  %d  ] \n", i , obj1Stack->ptr[i]);
    }
    
    //peak elements
    printf("\n**** Peak Function! **** \n");
    do
    {
        printf(" %d \n",peak(obj1Stack));
        getchar();
        printf("Do you want to peak more elements? Press 'y' for Yes Press 'n' for No: ");
        scanf("%c",&choice);
    } while (choice == 'y');
     getchar();
    //pop elements from stack
    printf("\n**** Pop Function !**** \n");
    do
    {
        printf(" %d \n",pop(obj1Stack));
        printf("Do you want to pop more elements? Press 'y' for Yes Press 'n' for No: ");
        scanf("%c",&choice);
        getchar();
    } while (!isEmpty(obj1Stack) && choice == 'y');
    if (isEmpty(obj1Stack))
    {
       printf("\n**** Stack is Empty! **** \n");
    }
    freeStack(obj1Stack);
    return 0;
}
