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
    if (arr->front == -1 && arr->rear == -1)
    {
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
    if (isEmpty(arr))
    {
        arr->front++;
        arr->rear++;
        arr->ptr[arr->front] = val;
        return arr;
    }
    else
    {
        arr->rear++;
        arr->ptr[arr->rear] = val;
        return arr;
    }
   
}
struct Queue *Dequeue(struct Queue *arr)
{
    int val;
    int temp = 0;
    if (isEmpty(arr))
    {
        printf("***Queue is Empty!*** \n");
        return arr;
    }
    else if (arr->front == arr->rear)   
    {
        val = arr->ptr[arr->front];
        printf(" %d \n",val);
        arr->front--;
        arr->rear--;
        return arr;
    }
    else
    {
        val = arr->ptr[arr->front];
        temp = arr->front;
        while (temp != arr->rear)
        {
            arr->ptr[temp] = arr->ptr[temp+1];  //shift values to left
            temp++;
        }
        arr->rear--;
        printf(" %d ",val);
        return arr;
    }
}
int peak(struct Queue *arr)
{
    int i = 0;
    printf("Enter index to search value(0-%d): ",arr->rear);
    scanf("%d",&i);
    if (i >= 0 && i<=arr->rear)
    {
        printf(" %d \n",arr->ptr[i]);
       return 1;
    }
    else
    {
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
    struct Queue *que_obj = createQueue(que_obj,5);
    printf("*** Enqueue ***\n");
    while (!isFull(que_obj))
    {
        que_obj = Enqueue(que_obj);
    }
    printf("*** Peak ***\n");
    while (peak(que_obj))
    {
        /* code */
    }
    printf("*** Dequeue ***\n ");
    while (!isEmpty(que_obj))
    {
        que_obj = Dequeue(que_obj);
    }
    
    freeMemory(que_obj);
    return 0;
}
