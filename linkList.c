#include<stdio.h>
#include<stdlib.h>

//Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node *createNode(struct Node *head, int data)
{   
    if (head == NULL)
    {
        head = (struct Node *)malloc(sizeof(struct Node));
        head->data = data;
        head->next = NULL;
        //printf("Node successfully created! \n");
        return head;
    }
    else 
    {   
        //this loop traverse to last node of list
        while (head->next != NULL)
        {
            head = head->next;
        }
        //creating new node and link it after last node
        struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
        ptr->data = data;
        ptr->next = NULL;
        head->next = ptr;
        return ptr;
    }
}
void traversalList(struct Node *ptr)
{
    if (ptr == NULL)
    {
        printf("No list exist! \n");
    }
    //loop traverse till last
    while (ptr != NULL)
    {
        printf(" %d -> ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");  
}

//inserting Node at at specific positions (start, end, in-between)
struct Node *insertNode(struct Node *head, int data, int choice)
{
    int index, count = 0;
    struct Node *temp;
    //creating new node
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL; 
        
    switch (choice)
    {
    case 1: //inserting at Start
        ptr->next = head;
        head = ptr;
        return head;

    case 3: //inserting at End
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        return head;
        
    case 2: //inserting at specific position/ index (index start from 1)
        temp = head;
        while (temp != NULL)    
        {
            temp = temp->next;
            count++;
        }
        if (count <= 1)
        {
            printf("Insert at least 2 nodes! \n");
            return head;
        }
        printf("Enter index > [1] & <= [%d] to insert the node: ",count);
        scanf("%d",&index);
        //this loops check as if input index is between the range of link list nodes
        while (index <= 1 || index > count) 
        {
            printf("Enter index > [1] & <= [%d] to insert the node: ",count);
            scanf("%d",&index);
        }
        temp = head;
        for (int i = 1; i < index-1; i++)
        {
            temp = temp->next;
        }
        //inserting node at specific index
        ptr->next = temp->next;
        temp->next = ptr;
        return head;
        
    default:
        printf("wrong choice! \n");
        break;
    }
    
}   

//deleting Node at at specific positions (start, in-between, end, specific)
struct Node *deleteNode(struct Node *head, int data, int choice)
{
    int index, count = 0;
    struct Node *forward_ptr, *prev_ptr;
    if (head == NULL)
    {
        printf("List is empty! \n");
        return head;
    }
    else
    {
        switch (choice)
    {
    case 1: //delete from start
        forward_ptr = head;
        head = head->next;
        free(forward_ptr);
        forward_ptr = NULL;
        return head;

    case 2: //delete in between two nodes (index start from 1)
        forward_ptr = head;
        while (forward_ptr != NULL)    
        {
            forward_ptr = forward_ptr->next;
            count++;
        }
        if (count <= 1)
        {
            printf("Only one node exist! \n");
            return head;
        }
        printf("Enter index > [1] & <= [%d] to delete the node: ",count);
        scanf("%d",&index);
        //this loops check as if input index is between the range of link list nodes
        while (index <= 1 || index > count) 
        {
            printf("Enter index > [1] & <= [%d] to delete the node: ",count);
            scanf("%d",&index);
        }
        forward_ptr = head;
        for (int i = 1; i < index; i++)
        {
            prev_ptr = forward_ptr; //prev_ptr points to the previous node of the desired node which we want to delete
            forward_ptr = forward_ptr->next;
        }
        //deleting node at specific index
        prev_ptr->next = forward_ptr->next; //forward_ptr points to the exact node which we want to delete
        free(forward_ptr);
        forward_ptr = NULL;
        return head;
        
    case 3: //delete at end  
        forward_ptr = head;
        //check if there is only one node
        if (forward_ptr->next == NULL)
        {
            free(forward_ptr);
            forward_ptr = NULL;
            head = NULL;
            return head;
        }
        else
        {
            //traverse till last node
            while (forward_ptr->next != NULL)
            {
            prev_ptr = forward_ptr;
            forward_ptr = forward_ptr->next;
            }
            prev_ptr->next = forward_ptr->next;
            free(forward_ptr);
            forward_ptr = NULL;
            return head;
        }
    case 4: //delete the specific node
        forward_ptr = head;
        //if node found at first 
        if (forward_ptr->data == data)
        {
            head = head->next;
            free(forward_ptr);
            forward_ptr = NULL;
            return head;
        }
        else
        {
            //traverse till the specific node found
            while (forward_ptr->next != NULL)
            {
                prev_ptr = forward_ptr;
                forward_ptr = forward_ptr->next;
                if (forward_ptr->data == data)
                {
                prev_ptr->next = forward_ptr->next;
                free(forward_ptr);
                forward_ptr = NULL;
                return head;
                }
            }
                printf("Node not found! \n");
                return head;
        }     

    default:
        printf("wrong choice! \n");
        break;
    }
    }    
}   

//this function release memory of all nodes one by one
struct Node *freeMemory(struct Node *ptr)
{
    //we declare a temporary pointer which points to head
    struct Node *temp = ptr;
    //this loop traverse the link list till last node + next 
    while (temp != NULL)
    {
        temp = temp->next;  //move to next node
        free(ptr);          //release previous node
        ptr = temp;         // assign next node address to ptr
    }

    return ptr;
}
int main(int argc, char const *argv[])
{
    int data, choice = 0;
    struct Node *head = createNode(head,7);
    //struct Node *second = createNode(head,8);
    //struct Node *third = createNode(head,9);

    //inserting Node in link list 
    while (1)
    {
    traversalList(head);
    printf("Select position to insert Node \n Press 1 to Insert at first \n Press 2 to insert between two nodes \n Press 3 to insert at end \n Press 0 to exit! \n ");
    scanf("%d",&choice);
    if (!(choice >=1 && choice <= 3))
    {
        break;
    }
    printf("Enter value to insert in link list: ");
    scanf("%d",&data);
    head = insertNode(head,data,choice);
    }

    //deleting the node in link list
    while (1)
    {    
    traversalList(head);
    printf("Select position to delete Node \n Press 1 to delete at first \n Press 2 to delete between two nodes \n Press 3 to delete at end \n Press 4 to delete specific node \n Press 0 to exit \n ");
    scanf("%d",&choice);
    if (!(choice >=1 && choice <= 4) || head == NULL)
    {
        break;
    }
    if (choice == 4)
    {
        printf("Enter node value to delete: ");
        scanf("%d",&data);
        head = deleteNode(head,data,choice);
    }
    else
    {
        head = deleteNode(head,0,choice);   //called if choice >=1 && choice<=3
    }
    }
    //display linkList
    traversalList(head);

    //free the heap memory
    head = freeMemory(head);
    //second = NULL;
    //third = NULL;

   
    return 0;
}
