// This program is about double Ended Queue implementation using array
//it uses Circular queue principle
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
    if ((arr->front == arr->rear))
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
    if (arr->rear == arr->front-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Queue *EnqueueFront(struct Queue *arr)
{
    int val = 0;
    if (!isFull(arr))
    {
    printf("Enter value to insert in queue: ");
    scanf("%d",&val);
    if (arr->front == -1)
    {
        arr->front = arr->size - 1;
        arr->ptr[arr->front] = val;
        return arr;
    }
    arr->front = (arr->front - 1) % arr->size;
    arr->ptr[arr->front] = val;
    return arr;
    }
    else
    {
        printf("Queue is full! \n");
        return arr;
    }   
}
struct Queue *EnqueueRear(struct Queue *arr)
{
    int val = 0;
    if (!isFull(arr))
    {
    printf("Enter value to insert in queue: ");
    scanf("%d",&val);
    arr->rear = (arr->rear + 1) % arr->size;
    arr->ptr[arr->rear] = val;
    return arr;
    }
    else
    {
        printf("Queue is full! \n");
        return arr;
    } 
}
struct Queue *DequeueFront(struct Queue *arr)
{
    int val;

    if (arr->front == arr->rear)    //if there is last element left in queue
    {
        printf(" arr[%d]: %d \n",arr->front,arr->ptr[arr->front]);
        arr->ptr[arr->front] = 0;
        printf("Queue is Empty! \n");
        return arr;
    }
    else
    {
        printf(" arr[%d]: %d \n",arr->front,arr->ptr[arr->front]);
        arr->ptr[arr->front] = 0;
        arr->front = (arr->front + 1) % arr->size; //formula to get 0 index after size - 1 index
        return arr;
    }
}
struct Queue *DequeueRear(struct Queue *arr)
{
    int val;

    if (arr->front == arr->rear)    //if there is last element left in queue
    {
        printf(" arr[%d]: %d \n",arr->rear,arr->ptr[arr->rear]);
        arr->ptr[arr->rear] = 0;
        printf("Queue is Empty! \n");
        return arr;
    }
    else
    {
        if (arr->rear == -1)    
        {
            arr->rear = arr->size - 1;
        }
        printf(" arr[%d]: %d \n",arr->rear,arr->ptr[arr->rear]);
        arr->ptr[arr->rear] = 0;
        arr->rear--; 
        return arr;
    }
}
void display(struct Queue *arr)
{
    for (int i = 0; i < arr->size; i++)
    {
        printf(" | %d | ",arr->ptr[i]);
    }
    printf("\n");
}
void freeMemory(struct Queue *arr)
{
    free(arr->ptr);
    arr->ptr = NULL;
    arr = NULL;
}
int main(int argc, char const *argv[])
{
    int choice;
    struct Queue *que_obj = createQueue(que_obj,6);
    while (1)
    {
        printf(" 1. Insert from front \n 2. Insert from rear \n 3. Dequeue from front \n 4. Dequeue from rear \n 5. Display Queue \n 6. Exit \n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            que_obj = EnqueueFront(que_obj);
            break;
        case 2:
            que_obj = EnqueueRear(que_obj);
            break;
        case 3:
            que_obj = DequeueFront(que_obj);
            break;
        case 4:
            que_obj = DequeueRear(que_obj);
            break;
        case 5:
            display(que_obj);
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Wrong choice! \n");
            break;
        }
    }
    
    freeMemory(que_obj);
    return 0;
}
