#include <stdio.h>
#include <stdlib.h>

struct node {
    int data; 
    struct node* link; 
};

struct node* addToEmpty(int data) 
{
    struct node* temp = malloc(sizeof(struct node)); 
    temp->data = data; 
    temp->link = NULL; 
    return temp;
}

struct node* addAtEnd(struct node* head, int data)
{ 
    struct node* temp = malloc(sizeof(struct node)); 
    temp->data = data; 
    temp->link = NULL;

    struct node* ptr = head; 
    while(ptr->link != NULL) 
        ptr = ptr->link; 
    ptr->link = temp; 
    return head; 
}

struct node* insert(struct node* head, int data) 
{ 
    struct node *ptr;
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;

    int key=data;
    if(head==NULL || key<head->data)
    {
        temp->link=head;
        head=temp;
    }
    else
    {
        ptr=head;
        while(key>ptr->link->data && ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        temp->link=ptr->link;
        ptr->link=temp;
    }
    return head;
}

void print (struct node* head) 
{
    struct node* temp = head; 
    while(temp != NULL)
    { 
        printf("%d ", temp->data); 
        temp = temp->link;
    } 
    printf("\n"); 
}

int main() 
{ 
    struct node* head = NULL; 
    head = addToEmpty(24); 
    addAtEnd(head, 45); 
    addAtEnd(head, 56); 
    addAtEnd(head, 100); 
    head = insert(head, 75); 
    print(head); 
    return 0;
}