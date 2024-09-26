#include<stdio.h>
#include<stdlib.h>

struct Node *front = NULL; 
struct Node *rear = NULL;
//This program is about implementation of Queue using Linklist

struct Node 
{
    int data;
    struct Node *next;
};
struct Node *createNode(struct Node *head)
{
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 0;
    head->next = NULL;
}
int isFull()
{
    struct Node *n = (struct Node * )malloc(sizeof(struct Node));
    if (n == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }  
} 
int isEmpty(struct Node *front, struct Node *rear)
{
    if (front == NULL && rear == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    } 
}
void queueTraversal(struct Node *head)
{
    while (head != NULL)
    {
        printf(" %d-->",head->data);
        head = head->next;

    }  

}
struct Node *Enqueue(struct Node *head)
{
    int val;
    struct Node *n = (struct Node * )malloc(sizeof(struct Node));
    if (!isFull())
    {
        printf("Enter value of node: ");
        scanf("%d",&val);
        if (isEmpty(front, rear))
        {
            n->data = val;
            front = n;
            rear = n;
            head = n;
        }
        else
        {
            n->data = val;
            rear->next = n; //assign new node next to rear
            rear = n;    //point rear to new node
        } 
          return head;
    }
    else
    {
        printf("Queue is full! \n");
    }
    
    
}
struct Node *Dequeue(struct Node *head)
{
    if (!isEmpty(front,rear))
    {
        struct Node *temp = head;
        printf(" %d--> \n",head->data);
        head = head->next;
        front = front->next;
        if (front == NULL && head == NULL)  //after deletion of last Node assign rear pointer to NULL
        {
            rear = NULL;
        }
        
        free(temp);
        temp = NULL;
        return head;
    }
    else
    {
        printf("Queue is Empty! \n");
        return head;
    }
    
}
int main(int argc, char const *argv[])
{
   
    struct Node *head = createNode(head);
    int counter = 0;
    printf("*** Enqueue *** \n");
    while (counter < 5)
    {
        head = Enqueue(head);
        counter++;
    }
    queueTraversal(head);

    printf("\n *** Dequeue *** \n");
    while (!isEmpty(front,rear))
    {
        head = Dequeue(head);
    }
    
    return 0;
}
