//Author - Abhishek

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

int findNthNode(struct node **head, int pos)
{
    struct node *n1 = *head;
    for(int i = 1; i<pos; i++)
    {
        //the position was greater than the size of ll
        if(n1 == NULL)
            return;
            
        n1 = n1->next;
    }
    
    return n1->data;
}

void deletingNode(struct node **head, int pos)
{
    struct node* prv = NULL;
    struct node* tmp = NULL;
    
    prv = *head;
    tmp = *head;
    
    for(int i = 0; i < pos; i++)
    {
        //we want to delete first position
        if((i == 0) && (pos == 1))
        {
            (*head) = (*head)->next;
            //either free tmp or prv, basically both are pointing to same memory.
            free(prv);                  
        }
        else
        {
            if(i == pos - 1)
            {
                //what it will do is, it will point to the next to the next element 
                //and free the memory occupied by that node.
                prv->next = tmp->next;
                free(tmp);
            }
            else
            {
                prv = tmp;
                
                //the position was greater than the size of ll
                if(prv == NULL)
                    return;
                    
                tmp = tmp->next;
            }
        }
        
        
    }
}

//in this algo we keep on getting the next node of LL in nxt variable and then we point the next to prv variable which will
//be initially NULL and then it will be current node, and then we move the iterator to the next node which is stored in the nxt 
//variable.
//At the end we point the *head to prv because it is the current node which is the last node of original linkedlist.
void reverseLinkedList(struct node **head)
{
    struct node* prv = NULL;
    struct node* curr = *head;
    struct node* nxt = NULL;
    
    while(curr != NULL)
    {
        nxt = curr->next;
        curr->next = prv;
        
        prv = curr;
        curr = nxt;
    }
    
    *head = prv;
}

void pushAfterNode(struct node *head, int data, int after)
{
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    
    temp->data = data;
    
    while(head != NULL)
    {
        if(head->data == after)
        {
            if(head->next != NULL)
            {
                temp->next = head->next;
                head->next = temp;
                break;
            }
        }
        
        head = head->next;
    }
}

void pushAtEnd(struct node *head, int data)
{
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    
    temp->data = data;
    temp->next = NULL;
    while(head->next != NULL)
    {
        head = head->next;
    }
    
    head->next  = temp;
}

void pushNode(struct node **head, int data)
{
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->data = data;
    temp->next = (*head);
    (*head)    = temp;
}

void printList(struct node* head)
{
    struct node *temp = head;
    
    while(temp != NULL)
    {
        printf("%d\n", temp->data);
        temp  = temp->next;
    }
}

int main()
{
    struct node *head = NULL;
    
    pushNode(&head,1);
    pushNode(&head,2);
    pushNode(&head,3);
    pushNode(&head,4);
    printList(head);
    printf("\n");
    
    pushAfterNode(head, 5, 2);
    printList(head);
    printf("\n");
     
    pushAtEnd(head, 10);
    printList(head);
    printf("\n");
     
    reverseLinkedList(&head);
    printList(head);
    printf("\n");
     
    deletingNode(&head, 6);
    printList(head);
    printf("\n");
    
    int x = findNthNode(&head, 5);
    printf("Nth node is : %d", x);
    printf("\n");
    
}