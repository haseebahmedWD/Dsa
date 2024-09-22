#include<stdio.h>
#include<stdlib.h>

//Node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* previous;
};

struct Node *createNode(struct Node *head, int data)
{   
    if (head == NULL)
    {
        head = (struct Node *)malloc(sizeof(struct Node));
        head->data = data;
        head->next = NULL;
        head->previous = NULL;
        //printf("Node successfully created! \n");
        return head;
    }
    else 
    {   
        //this loop traverse to last node of list
        struct Node* fwd_ptr;   //a temporary forward pointer
        fwd_ptr = head;
        while (fwd_ptr->next != NULL)
        {
            fwd_ptr = fwd_ptr->next;    //traverse till last node
        }
        //creating new node 
        struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
        ptr->data = data;
        ptr->next = NULL;
        ptr->previous = fwd_ptr; //linking new node previous pointer to the last node
        fwd_ptr->next = ptr;    //linking last node next to new node
        return head;
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
// traverse the list in reverse
void traversalListReverse(struct Node *ptr)
{
    if (ptr == NULL)
    {
        printf("No list exist! \n");
    }
    else
    {
        //loop traverse till last node + 1
    while (ptr->next != NULL)
    { 
        ptr = ptr->next;
    }
    while (ptr != NULL) // loop till head node + 1 
    {
        printf(" %d -> ",ptr->data);
        ptr = ptr->previous;        
    }

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
    ptr->previous = NULL;
        
    switch (choice)
    {
    case 1: //inserting at Start
        ptr->next = head;
        head->previous = ptr;
        ptr->previous = NULL;
        head = ptr;
        return head;
    
    case 2: //inserting at specific position/ index (index start from 1)
        temp = head;
        while (temp != NULL)    
        {
            temp = temp->next;
            count++;
        }
        if (count <= 1 )
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
        struct Node *temp_fwd, *temp_pre;   //two pointers for next and previous nodes
        temp_fwd = head;
        for (int i = 1; i < index ; i++)
        {   temp_pre = temp_fwd;        //traverse till index -1
            temp_fwd = temp_fwd->next;  //traverse till index
        }
        //inserting node at specific index
        ptr->next = temp_fwd;       //new nodes points to next node
        temp_fwd->previous = ptr;   // next node previous points to new node
        temp_pre->next = ptr;       //previous node next points to new node
        ptr->previous = temp_pre;   //new node previous points to previous node
        return head;

    case 3: //inserting at End
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->previous = temp;
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
    struct Node *forward_ptr;
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
    //if there is only one Node
        if (head->next == NULL)
        {
            free(head);
            head = NULL;
            return head;
        }
        forward_ptr = head;
        head = head->next;
        head->previous = NULL;
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
        if (count <= 2)
        {
            printf("Less than or equal to two nodes exist! \n");
            return head;
        }
        printf("Enter index > [1] & < [%d] to delete the node: ",count);
        scanf("%d",&index);
        //this loops check as if input index is between the range of link list nodes
        while (index <= 1 || index >= count) 
        {
            printf("Enter index > [1] & < [%d] to delete the node: ",count);
            scanf("%d",&index);
        }
        struct Node *temp_fwd, *temp_pre, *temp_current;   //two pointers for next and previous nodes and one for current node
        temp_fwd = head->next;
        temp_current = head;
        for (int i = 1; i < index ; i++)
        {   
            temp_pre = temp_current;        //traverse till index - 1
            temp_current = temp_fwd;        //traverse till index 
            temp_fwd = temp_fwd->next;  //traverse till index + 1
        }
        //deleting node at specific index
       temp_pre->next = temp_fwd;       //previous node links to next node
       temp_fwd->previous = temp_pre;   //next node links to previous node
        free(temp_current);     //delete current node
        temp_current = NULL;
        return head;
        
    case 3: //delete at end  
        temp_fwd = head;
        //check if there is only one node
        if (temp_fwd->next == NULL)
        {
            free(temp_fwd);
            temp_fwd = NULL;
            head = NULL;
            return head;
        }
        else
        {
            //traverse till last node
            while (temp_fwd->next != NULL)
            {
            temp_pre = temp_fwd;
            temp_fwd = temp_fwd->next;
            }
            temp_pre->next = temp_fwd->next;
            free(temp_fwd);
            forward_ptr = NULL;
            return head;
        }
    case 4: //delete the specific node
        forward_ptr = head;
        //if there is one node
        if (head->next == NULL && head->data == data)
        {
            free(head);
            head = NULL;
            return head;
        }
        //if node found at first
        if (forward_ptr->data == data)
        {
            head = head->next;
            head->previous = NULL;
            free(forward_ptr);
            forward_ptr = NULL;
            return head;
        }
        else
        {
            //traverse till the specific node found
            temp_fwd = head;
            while (temp_fwd->next != NULL)  // traverse till last node
            {
                if (temp_fwd->data == data) //check if data found before last node
                {
                temp_current = temp_fwd;    //current node will be required node
                temp_fwd = temp_fwd->next;  //fwd pointer points to next node to required node
                temp_pre->next = temp_fwd;  // previous node's next pointer links to next node to required node
                temp_fwd->previous = temp_pre;  //next node to require node's previous pointer points to previous node
                free(temp_current);
                temp_current = NULL;
                return head;
                }
                temp_pre = temp_fwd;
                temp_fwd = temp_fwd->next;
            }
            //if data matches at last node
            if (temp_fwd->data == data)
            {
                free(temp_fwd);
                temp_fwd = NULL;
                temp_pre->next = NULL;
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
    // struct Node *second = createNode(head,8);
    // struct Node *third = createNode(head,9);

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
   // traversalList(head);

    //display linkList in reverse
    traversalListReverse(head);

    //free the heap memory
    head = freeMemory(head);
    //second = NULL;
    //third = NULL;

   
    return 0;
}
