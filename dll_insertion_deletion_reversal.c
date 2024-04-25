/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

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
    tmp->prev = head->prev;
    
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
    tmp->prev = head->prev;
    tmp->next = head->next;
    
    //also we now point the current last node's next to suggested 
    //last node.
    head->next = tmp;
    
}


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
    
    return 0;
}
