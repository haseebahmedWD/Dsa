#include<stdio.h>
#include<stdlib.h>

//Node structure
struct Node {
    int data;
    struct Node* next;
};

int isFull(struct Node *top)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
struct Node *createNode(struct Node *top, int data)
{   
    if (isEmpty(top))
    {
        top = (struct Node *)malloc(sizeof(struct Node));
        top->data = data;
        top->next = NULL;
        //printf("Node successfully created! \n");
        return top;
    }
    
}
void traversalList(struct Node *top)
{
    // if (top == NULL)
    // {
    //     printf("Stack is empty! \n");
    // }
    //loop traverse till last
    printf("\n");  
    while (top != NULL)
    {
        printf(" [ %d ] -> ",top->data);
        top = top->next;
    }
    printf("\n");  
}

//push the node into stack
struct Node *push(struct Node *top, int data)
{
    if (!isFull(top))
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = data;
        n->next = top;
        top = n;
        return top;
    }
    else
    {
       printf("Stack overflow! \n");
    }
}   

//deleting / pop the node from stack
struct Node *pop(struct Node *top)
{
    int val;
    struct Node *temp;
    if (!isEmpty(top))
    {
        temp = top;
        top = top->next;
        val = temp->data;
        free(temp);
        temp = NULL;
        printf("\n [ %d ] -> \n",val);
        return top;
    }
    else
    {
        printf("Stack is empty! \n");
    }
    
}   
int peak(struct Node *top, int index)
{
    struct Node *temp = top;
    int i = 0;
    while (i < index -1  && temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    if (temp != NULL)
    {
        return temp->data;
    }
    else 
    {
        return 0;
    }
    
}
//this function release memory of all nodes one by one
struct Node *freeMemory(struct Node *top)
{
    //we declare a temporary pointer which points to head
    struct Node *temp = top;
    //this loop traverse the link list till last node + next 
    while (temp != NULL)
    {
        temp = temp->next;  //move to next node
        free(top);          //release previous node
        top= temp;         // assign next node address to ptr
    }

    return top;
}
int main(int argc, char const *argv[])
{
    int data, index, val = 0;
    char choice;
    struct Node *top = createNode(top,7);

    //push into linkList stack
  while (1)
  {
    traversalList(top);
    printf("Enter value to insert in link list (-1 for exit): ");
    scanf("%d",&data);
    if (data < 0)
    {
        break;
    }
    top = push(top,data);
  }
  getchar();
  //peak element in linkList stack
  while (1)
  {
    //traversalList(top);
    printf("Search value from list by giving index: ");
    scanf("%d",&index);
    val = peak(top,index);
    if (val)
    {
        printf("[  %d  ] \n",val);
    }
    else
    {
        printf("Value not found! \n");
        break;
    }
  }
    getchar();
    //pop the node in link list
    while (1)
    {
        traversalList(top);
        printf("Press p to pop value from list | Press e for exit:  ");
        scanf("%c",&choice);
        if (choice == 'e' || isEmpty(top))
        {
            break;
        }
        top = pop(top);
        getchar();
        if (isEmpty(top))
        {
            printf("Stack is empty! \n");
        }
        
    }
    //display linkList
    //traversalList(head);

    //free the heap memory
    top = freeMemory(top);
    //second = NULL;
    //third = NULL;

   
    return 0;
   
    }

   

