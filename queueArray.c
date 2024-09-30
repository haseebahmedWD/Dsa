// This program is about Queue implementation using array
#include<stdio.h>
#include<stdlib.h>
struct Queue
{
    int size;
    int front;  //front pointer
    int rear;   //rear pointer
    int *ptr;   //point the memory allocated on heap
};
struct Queue *createQueue(struct Queue *arr, int qSize)
{
    arr = (struct Queue *)malloc(sizeof(struct Queue)); //creating queue
    arr->size = qSize;
    arr->front = -1;
    arr->rear = -1;
    arr->ptr = (int *)malloc(qSize * sizeof(int));  //creating memory on heap
    printf("*****Queue of size %d is created successfully***** \n",qSize);
    return arr;
}
int isEmpty(struct Queue *arr)
{
    if ((arr->front == arr->rear + 1))
    {
        printf("Queue is Empty! \n");
        return 1;
    }
    else
    {
        return 0;
    }
    
}
int isFull(struct Queue *arr)
{
    if (arr->rear == arr->size-1)
    {
        printf("Queue is full! \n");
        return 1;
    }
    else
    {
        return 0;
    }
}
void firstValue(struct Queue *arr)
{
    printf(" %d ",arr->ptr[arr->front]);
}
void lastValue(struct Queue *arr)
{
    printf(" %d ",arr->ptr[arr->rear]);
}
struct Queue *Enqueue(struct Queue *arr)
{
    int val = 0;
    printf("Enter value to insert in queue: ");
    scanf("%d",&val);
    arr->rear++;
    arr->ptr[arr->rear] = val;
    return arr;
   
}
 int Dequeue(struct Queue *arr)
{
    int val;
    if (arr->front == -1)
    {
       arr->front++;
    }
    
    val = arr->ptr[arr->front];
    printf(" arr[%d]: %d \n",arr->front,val);
    arr->ptr[arr->front] = 0;
    arr->front++;
    return val;
   
}
int peak(struct Queue *arr)
{
    int i = 0;
    printf("Enter index to search value(0-%d): ",arr->size-1);
    scanf("%d",&i);
    if (i<0 || i>arr->size-1)
    {
        printf("incorrect index! \n");
        return 1;
    }
    else
    {
        printf(" arr[%d]: %d \n",i,arr->ptr[i]);
        return 0;
    }
    
     
}
void freeMemory(struct Queue *arr)
{
    free(arr->ptr);
    arr->ptr = NULL;
    arr = NULL;
}
int main(int argc, char const *argv[])
{
    char c;
    struct Queue *que_obj = createQueue(que_obj,6);
    printf("*** Enqueue ***\n");
    while (!isFull(que_obj))
    {
        que_obj = Enqueue(que_obj);
    }
    printf("*** Peak ***\n");
    while (!peak(que_obj))
    {
        peak(que_obj);
    }
    printf("*** Dequeue ***\n ");
    while (1)
    {
        Dequeue(que_obj);
        getchar();
        printf("press 'q' to quit or 'c' to continue: ");
        scanf("%c",&c);
        if (c == 'q' || isEmpty(que_obj))
        {
            break;
        }
    }
    freeMemory(que_obj);
    return 0;
}
