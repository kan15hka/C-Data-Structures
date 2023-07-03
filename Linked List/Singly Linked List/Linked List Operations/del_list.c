#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *del_list(struct node *head)
{
    struct node*temp=head;
    while(temp!=NULL)
    {
        temp=temp->link;
        free(head);
        head=temp;
    }
    return head;
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
    head=del_list(head);
    if(head==NULL)
    {
        printf("List Deleted");
    }
    return 0;
}
