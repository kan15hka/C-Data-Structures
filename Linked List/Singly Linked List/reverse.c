#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *link;
};

struct node*reverse(struct node*head)
{
    struct node *prev=NULL,*next=NULL;
    while(head!=NULL)
    {
        next=head->link;
        head->link=prev;
        prev=head;
        head=next;
    }
    head=prev;
    return head;
}
int main()
{
    struct node *head=malloc(sizeof(struct node));
    head->data=10;
    head->link=NULL;

    struct node *current=malloc(sizeof(struct node));
    current->data=20;
    current->link=NULL;
    head->link=current;

    current=malloc(sizeof(struct node));
    current->data=30;
    current->link=NULL;
    head->link->link=current;

    current=malloc(sizeof(struct node));
    current->data=40;
    current->link=NULL;
    head->link->link->link=current;
    current=head;
    printf("\nLinked List\n");
    while(current!=NULL)
    {
        printf("%d ",current->data);
        current=current->link;
    }
    printf("\nReversed Linked List\n");
    head=reverse(head);

    current=head;
    while(current!=NULL)
    {
        printf("%d ",current->data);
        current=current->link;
    }
    return 0;
}