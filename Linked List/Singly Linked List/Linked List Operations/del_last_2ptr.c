#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node* del_last(struct node *head)
{
    if(head==NULL)
    {
        printf("List Empty");
    }
    else if(head->link=NULL){
        free(head);
        head=NULL;
    }
    else{
        struct node*temp=head;
        struct node*temp2=head;
        while(temp->link=NULL);
        {
            temp2=temp;
            temp=temp->link;
        }
        temp2->link=NULL;
        free(temp);
        temp=NULL;
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
    head=del_last(head);
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    return 0;
}
