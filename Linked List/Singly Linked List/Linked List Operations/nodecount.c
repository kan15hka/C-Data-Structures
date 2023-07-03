#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
int nodecount(struct node*head)
{
    int count=0;
    if(head==NULL){
        printf("Linked List is Empty");
    }
    struct node*ptr=NULL;
    ptr=head;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->link;
    }
    return count;
}
int main()
{
    int n;
    struct node *head=(struct node*)malloc(sizeof(struct node));
    head->data=1000;
    head->link=NULL;

    struct node *current=(struct node*)malloc(sizeof(struct node));
    current->data=2000;
    current->link=NULL;
    head->link=current;
    
    current=malloc(sizeof(struct node));
    current->data=3000;
    current->link=NULL;
    head->link->link=current;
    n=nodecount(head);
    printf("%d elements present",n);
    return 0;
}
