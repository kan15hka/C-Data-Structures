#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void begnnode(struct node **p,int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->link=*p;
    *p=temp;
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
    
    int data=1000;
    begnnode(&head,data);
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    return 0;
}
