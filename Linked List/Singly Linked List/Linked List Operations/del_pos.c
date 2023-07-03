#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void del_pos(struct node **head,int pos)
{
    struct node *previous=*head,*current=*head;
    if(*head==NULL)
    {
        printf("List Empty");
    }
    else if(pos==1)
    {
        *head=current->link;
        free(current);
        current=NULL;
    }
    else
    {
        while(pos!=1)
        {
            previous=current;
            current=current->link;
            pos--;
        }
        previous->link=current->link;
        free(current);
        current=NULL;
    }
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
    
    ptr=malloc(sizeof(struct node));
    ptr->data=4000;
    ptr->link=NULL;

    head->link->link=ptr;

    int pos=2;
    del_pos(&head,pos);
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    return 0;
}
