//Author - Abhishek

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

//-----------------INSERTION----------------------------
void insertAtStart(struct node** head, int data)
{
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    
    tmp->data = data;
    tmp->prev = NULL;
    tmp->next = (*head);
    
    //important case, when we are pushing the node at the front.
    //we must point the current front node i.e. previous node to the
    //current suggested front node i.e. tmp.
    if (*head != NULL) {
        (*head)->prev = tmp;
    }
    
    //At the end head should point to current front node.
    (*head) = tmp;
}

void insertAtEnd(struct node* head, int data)
{
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    
    tmp->data = data;
    tmp->next = NULL;
    
    //we keep iterating untill we reach last node.
    while(head->next != NULL)
    {
        head = head->next;
    }
    
    //upon reaching the last node we update, suggested last node'
    //previous pointer to current last nodes previous node.
    tmp->prev = head;
    
    //also we now point the current last node's next to suggested 
    //last node.
    head->next = tmp;
    
}


void insertAfterNode(struct node* head, int data, int afterData)
{
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    
    tmp->data = data;
    
    
    //we keep iterating untill we reach last node.
    while(head->data != afterData)
    {
        head = head->next;
    }
    
    //upon reaching the last node we update, suggested last node'
    //previous pointer to current last nodes previous node.
    tmp->prev = head;
    tmp->next = head->next;
    
    //also we now point the current last node's next to suggested 
    //last node.
    head->next = tmp;
    
}

//---------------------REVERSAL-----------------------------

void reverseLL(struct node** head)
{
    struct node* curr = *head;
    struct node* prv = NULL;
    struct node* nxt = NULL;
    
    //lets consider ll [4->3->2->1->5]
    //so curr initially points to 4.
    //we store 3 in the nxt variable
    //we make the next pointer variable point to prv, in first 
    //iteration to NULL, we point prev pointer to next element
    //then we make prv variable as curr.
    //and then curr variable will move to next member i.e. 3. again we repeat every thing.
    while(curr != NULL)
    {
        nxt         = curr->next;
        curr->next  = prv;
        curr->prev  = nxt;
        prv         = curr;
        curr        = nxt;
    }
    
    *head = prv;
}


//---------------------DELETION-----------------------------
void deleteNode(struct node** head, int position)
{
    struct node* prv = NULL;
    struct node* tmp = NULL;
    
    prv = *head;
    tmp = *head;
    
    for(int i = 0 ; i < position ; ++i)
    {
        //we want to delete first position
        if((i == 0) && (position == 1))
        {
            //try to visualize, very simple, we simply move the 
            //head from first node to second node, so we change the 
            //pointer to the next node.
            //in this case we also want to change the next pointer's
            //previous member to NULL, since now 2nd node is first node.
            (*head) = (*head)->next;
            (*head)->next->prev = NULL;
            
            //either free tmp or prv, basically both are pointing to same memory.
            free(prv);
            return;
        }
        //first look at the else condition, we have reached the position that we want to remove
        if(i == position - 1)
        {
            //now here also try to visualize, lets say this is the ll [4->3->2->1->5->10]
            //we want to remove the position no. 5 which is node 5.
            //now currently prv is pointing to 1 & tmp is pointing to 5.
            //so first we want to make sure that prv's next is updated to tmp->next, cuz
            //node 5 will be removed.
            //Also we want to make sure that node 10's previous is pointing to the prv node.
            prv->next = tmp->next;
            
            //this condition is necessary if we want to remove the last node our ll is [4->3->2->1->5->10]
            //now we want to remove 10 from the ll.
            //prv is pointing to 5, and tmp is pointing to 10
            //above we have made sure that prv's next is pointing to temp's next which will be NULL sice it's 
            //last node.
            //But we don't have to update the temp's next node's prev pointer since there is no node.
            if(tmp->next != NULL)
                tmp->next->prev = prv;
            
            //free the memory so it can be reused!!!
            free(tmp);
        }
        else        //here we keep assigning the prv pointer to current nodes previous node and keep moving tmp to next node.
        {
            prv = tmp;
            
            //the position was greater than the size of ll
            if(prv == NULL)
                return;
                
            tmp = tmp->next;
        }
    }
    
}


//---------------------PRINTING-----------------------------
void printList(struct node* head)
{
    while(head->next != NULL)
    {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("%d", head->data);
}

int main()
{
    struct node* head= NULL;
    
    insertAtStart(&head, 1);
    insertAtStart(&head, 2);
    insertAtStart(&head, 3);
    insertAtStart(&head, 4);
    printList(head);
    printf("\n");
    
    insertAtEnd(head, 5);
    printList(head);
    printf("\n");
    
    insertAfterNode(head, 10, 5);
    printList(head);
    printf("\n");
    
    deleteNode(&head, 6);
    printList(head);
    printf("\n");
    
    reverseLL(&head);
    printList(head);
    printf("\n"); 
    
    return 0;
}
