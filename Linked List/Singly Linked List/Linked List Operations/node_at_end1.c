#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *endnode(struct node*ptr,int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;
    ptr->link=temp;
    return temp;
}

int main()
{
    int data1;
    struct node *head=(struct node*)malloc(sizeof(struct node));
    head->data=1000;
    head->link=NULL;

    struct node *ptr=head;
    ptr=endnode(ptr,2000);
    ptr=endnode(ptr,3000);
    ptr=endnode(ptr,4000);

    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    free(ptr);
    return 0;
}
