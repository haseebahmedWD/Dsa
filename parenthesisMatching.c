#include<stdio.h>
#include<stdlib.h>
//this program is about parenthesis matching
//it take input of a character array expression 
//it give output if the expression is balanced or not
//two conditions for a balanced parenthesis
// (1) at the end of expression stack must be empty or underflowed
// (2) during the pop operations the stack must not be empty or underflowed
struct stackArr
{
    int size;   //total size of stack
    int top;    //top index of stack
    char *ptr;     //pointer for stack memory on heap
};

void *createStack(struct stackArr *arr, int size)
{
    arr->size = size;
    arr->top = -1;
    arr->ptr = (char *)malloc(size * sizeof(char)); //creating memory according to size on heap
   // printf("\n**Stack of size %d is created successfully!** \n",size);
   
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
void push(struct stackArr *arr, char val)
{
    
    //char c = '\0';
    //printf("Enter integer value to push into stack: ");
    //scanf("%d",&val);
    arr->top++;
    arr->ptr[arr->top] = val;
    //getchar();  
}
char pop(struct stackArr *arr)
{
    char val = arr->ptr[arr->top];
    arr->ptr[arr->top] = 0;
    arr->top--;
    return val;
}

//this function return value on stack according to index
// int peak(struct stackArr *arr)
// {
//     int i = 0;
//     printf("Enter index to search value on stack (1-%d): ",arr->top+1);
//     scanf("%d",&i);
//     //top - i + 1 is formula to get index (index start from 1)
//     if (i <= 0 || i > arr->top+1)
//     {
//         printf("Wrong index! \n");
//         return -1;
//     }
//     else
//     {
//         return arr->ptr[arr->top - i + 1];
//     }
// }
void freeStack(struct stackArr *arr)
{
    free(arr->ptr);
    free(arr);
    arr->ptr = NULL;
    arr = NULL;
    printf("\n**** Heap memory free! **** \n");
}
int arrayElements(char *p)
{
    int i = 0;
    for (i = 0; p[i] != '\0'; i++);
    return i;
}
//this function works for both single type of brackets and multiple type of brackets
void parenthesisMatchingFunc(struct stackArr *arr, char *p, int size)
{
    int i, flag = 0;
    for (i = 0; i < size; i++)
    {
        if (p[i] == '(' || p[i] == '[' || p[i] == '{')
        {
            push(arr,p[i]);
        }
        else if (p[i] == ')' || p[i] == ']' || p[i] == '}')
        {
            if (!isEmpty(arr))
            {
                //check if array closing bracket matches with stack opening bracket type
                if (p[i] == ')' && arr->ptr[arr->top] == '(' || p[i] == ']' && arr->ptr[arr->top] == '[' || p[i] == '}' && arr->ptr[arr->top] == '{')
                {
                    pop(arr);
                }
                else
                {
                    break;
                }
            }
            else
            {
                printf("Stack is empty \n");
                break;
            }   
        }
    }
    if ((i < size && isEmpty(arr)) || (i < size && !isEmpty(arr)) || (i == size && !isEmpty(arr)))
    {
        printf("Expression parenthesis not balanced! \n");
    }
    else 
    {
        printf("Expression parenthesis is balanced! \n");
    }
     
}
int main(int argc, char const *argv[])
{
    char choice;
    int sizeOfArray = 0;
    
    char array[50];
    printf("Enter expression: ");   //input expression: example-> ((8+2)+(3+9))
    scanf("%s",array);              //output expression
    printf("%s \n",array);
    sizeOfArray = arrayElements(array); //count total elements in array;
    //printf("%d",sizeOfArray);
    struct stackArr *obj1Stack = (struct stackArr *)malloc(sizeof(struct stackArr));    //creating stack on heap memory
    createStack(obj1Stack,sizeOfArray);   //stack created according to count of array elements
    //parenthesis matching function
    parenthesisMatchingFunc(obj1Stack,array,sizeOfArray);
    
    freeStack(obj1Stack);
    return 0;
}
