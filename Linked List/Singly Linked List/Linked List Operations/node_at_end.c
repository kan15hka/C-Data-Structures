#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
int endnode(struct node*head,int data)
{
    struct node*ptr,*temp;
    ptr=head;
    temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;
    while(ptr!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=temp;
}
int printdata(struct node*head)
{
    if(head==NULL){
        printf("Linked List is Empty");
    }
    struct node*ptr=NULL;
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
}
int main()
{
    int data1;
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
    printf("Enter element:");
    scanf("%d",&data1);
    endnode(head,4000);
    printdata(head);
    return 0;
}
