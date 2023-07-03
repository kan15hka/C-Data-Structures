#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
}*head=NULL;
int length()
{
    int l=0;
    struct node*ptr=head;
    while(ptr!=NULL)
    {
        l++;
        ptr=ptr->next;
    }
    return l;
}
void insert(int data,int pos)
{
    struct node*temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    int l=length();
    if(head==NULL)
    {
        head=temp;
    }
    else if(pos==1)
    {
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
    else if(pos>l)
    {
        pos=l;
        struct node*ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
        temp->prev=ptr;

    }
    else
    {
        pos--;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
        struct node *p=head,*n=NULL;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
        while(pos!=1)
        {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
            p=p->next;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
            pos--;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
        }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
        n=p->next;
        temp->prev=p;
        temp->next=n;
        p->next=temp;
        n->prev=temp;
    }
}
int delete(int pos)
{
    struct node*temp;
    int l=length(),data;
    if(head==NULL)
    {
        printf("List Empty!!!");
        return 0;
    }
    else if(pos==1)
    {
        data=head->data;
        temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
        temp=NULL;
    }
    else if(pos>l)
    {
        pos=l;
        struct node*ptr=head;
        while(ptr->next->next!=NULL)
        {
            ptr=ptr->next;
        }
        temp=ptr->next;
        ptr->next=NULL;
        free(temp);
        temp=NULL;
    }
    else
    {
        pos--;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
        struct node *p=head,*n=NULL;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
        while(pos!=1)
        {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
            p=p->next;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
            pos--;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
        }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
        n=p->next->next;
        temp=p->next;
        p->next=n;
        n->prev=p;
        free(temp);
        temp=NULL;
    }
}
void reverse()
{
    if(head==NULL)
    {
        printf("Linked List is Empty");
    }
    struct node *ptr1=head,*ptr2=ptr1->next;
    ptr1->next=NULL;
    ptr1->prev=ptr2;
    while(ptr2!=NULL)
    {
        ptr2->prev=ptr2->next;
        ptr2->next=ptr1;
        ptr1=ptr2;
        ptr2=ptr2->prev;
    }
    head=ptr1;
}         
void print()
{                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
    struct node*ptr=head;
    if(head==NULL)
    {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
        printf("Linked List Empty");
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
    else
    {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
        while(ptr!=NULL)
        {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
            printf("%d ",ptr->data);
            ptr=ptr->next;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
        }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
        printf("\n");
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
}               
int main()
{
    while(1)
    {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
        int ch,data,pos;
        printf("\n---------------------------");
        printf("\n1.Insert");
        printf("\n2.Delete");
        printf("\n3.Reverse");
        printf("\n4.Print");
        printf("\n5.Exit");
        printf("\n----------------------------");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
            case 1:
            {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
                printf("Enter data: ");
                scanf("%d",&data);
                printf("Enter position: ");
                scanf("%d",&pos);
                insert(data,pos);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                print();                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
                break;
            }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
            case 2:
            {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
                printf("Enter position: " );
                scanf("%d",&pos);
                data=delete(pos);
                printf("Deleted element: %d\n",data);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
                print();                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
                break;
            }
            case 3:
            {
                reverse();
                printf("\nReversed list\n");
                print();
                break;
            }     
            case 4:
            {
                printf("\nList: ");
                print();
                break;
            }
            case 5:
            {
                exit(1);
            }
            default:
            {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
                printf("Invalid choice!!!");
                break;
            }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
        }
    }
    return 0;                    
}