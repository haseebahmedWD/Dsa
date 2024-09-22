#include<stdio.h>
#include<stdlib.h>
//this program is about expression conversion
//this program convert infix expression to Postfix using stack
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
//this function used to check precedence of operators
int precedence(char c)
{
    if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}
//this function check if character is operator or not
int isOperator(char c)
{
    if (c == '*' || c =='/' || c =='+' || c == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//this function convert infix to postfix
void infixToPostfix(struct stackArr *arr, char *p, int size)
{
    int i, flag = 0;
    char pop_value = '\0';
    for (i = 0; i < size; i++)
    {
       if (isOperator(p[i]))    //check if it is operator
       {
        if (isEmpty(arr))       //check if stack is empty
        {
            push(arr,p[i]);
        }
        else
        {   //check if current array operator's precedence is higher than stack top operator
            if (precedence(p[i]) > precedence(arr->ptr[arr->top]))  
            {
               push(arr,p[i]);
            }
            else
            {
                 //pop operators from stack until higher precedence operator than current array operator found on stack
                while (precedence(p[i]) <= precedence(arr->ptr[arr->top]))
                {
                    pop_value = pop(arr);
                    printf(" %c ",pop_value);
                }
                //push current array operator onto stack
                push(arr,p[i]);
            } 
        }
       }
       else 
       {
        printf(" %c ",p[i]);
       } 
    } 
    //if stack is not empty pop all operators
    while (!isEmpty(arr))
    {
        pop_value = pop(arr);
        printf(" %c ",pop_value);
    }
}
int main(int argc, char const *argv[])
{
    char choice;
    int sizeOfArray = 0;
    
    char array[50];
    printf("Enter expression: ");   //input infix: example-> x+y*z
    scanf("%s",array);              
    printf("%s \n",array);          //output expression
    sizeOfArray = arrayElements(array); //count total elements in array;
    //printf("%d",sizeOfArray);
    struct stackArr *obj1Stack = (struct stackArr *)malloc(sizeof(struct stackArr));    //creating stack on heap memory
    createStack(obj1Stack,sizeOfArray);   //stack created according to count of array elements
    //infix to postfix conversion function
    infixToPostfix(obj1Stack,array,sizeOfArray);
    
    freeStack(obj1Stack);
    return 0;
}
