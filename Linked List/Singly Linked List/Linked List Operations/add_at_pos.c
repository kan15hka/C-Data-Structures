#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void add_at_pos(struct node *head,int data,int pos)
{
    struct node*ptr=head;
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;
    pos--;
    while(pos!=1)
    {
        ptr=ptr->link;
        pos--;
    }
    temp->link=ptr->link;
    ptr->link=temp;
    
}
int main()
{
    struct node *head=(struct node*)malloc(sizeof(struct node));
    head->data=2000;
    head->link=NULL;

    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=3000;
    ptr->link=NULL;

    head->link=ptr;
    
    int data=1000,pos=2;
    add_at_pos(head,data,pos);
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    return 0;
}
