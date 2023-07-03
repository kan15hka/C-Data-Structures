#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node*prev;
    int data;
    struct node*next;
}*tail=NULL;
int length()
{
    int l=0;
    if(tail==NULL)
    {
        return 0;
    }
    struct node*ptr=tail->next;
    do
    {
        l++;
        ptr=ptr->next;
    }while(ptr!=tail->next);
    return l;
}
void insert(int data, int pos)
{
    int l=length();
    struct node *temp=malloc(sizeof(struct node));
    temp->prev=temp;
    temp->data=data;
    temp->next=temp;
    if(tail==NULL)
    {
        tail=temp;
    }
    else if(pos==1)
    {
        struct node*ptr=tail->next;
        temp->next=ptr;
        temp->prev=tail;
        tail->next=temp;
        ptr->prev=temp;       
    }
    else if(pos>=l)
    {
        struct node*ptr=tail->next;
        temp->prev=tail;
        temp->next=ptr;
        tail->next=temp;
        ptr->prev=temp;
        tail=temp;
    }
    else
    {
        pos--;
        struct  node*ptr=tail->next;
        while(pos!=1)
        {
            pos--;
            ptr=ptr->next;
        }
        temp->prev=ptr;
        temp->next=ptr->next;
        ptr->next=temp;
        temp->next->prev=temp;
    }
}
int delete(int pos)
{
    int l=length();
    if(tail==NULL)
    {
        printf("List is Empty");
        return 0;
    }
    else if(pos==1)
    {
        struct node*temp;
        temp=tail->next;
        tail->next=temp->next;
        temp->next->prev=tail;
        free(temp);
        temp=NULL;
    }
    else if(pos>=l)
    {
        struct node*temp;
        temp=tail->prev;
        temp->next=tail->next;
        tail->next->prev=temp;
        free(tail);
        tail=NULL;
    }
    else
    {
        pos--;
        struct node*ptr=tail->next,*temp;
        while(pos!=1)
        {
            pos--;
            tail=tail->next;
        }
        temp->next=ptr->next;
        ptr->next=temp->next;
        temp->next->prev=ptr;
        free(temp);
        temp=NULL;
    }
}
int search(int ele)
{
    struct node*ptr=tail->next;
    do
    {
        if(ptr->data==ele)
        {
            return 1;
        }
        ptr=ptr->next;
    }while(ptr!=tail->next);
    return 0;
}
void print()
{
    struct node*ptr=tail->next;
    do
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    } while (ptr!=tail->next);

}
int main()
{                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
    while(1)
    {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
        int ch,data,pos;
        printf("\n---------------------------");
        printf("\nCIRCULAR DOUBLE LINKED LIST");
        printf("\n1.Insert");
        printf("\n2.Delete");
        printf("\n3.Search");
        printf("\n4.Print");
        printf("\n5.Count");
        printf("\n6.Exit");
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
                int ele;
                printf("Enter element: " );
                scanf("%d",&ele);
                int r=search(ele);
                if(r==1)
                {
                    printf("Element Found");
                }
                else
                {
                    printf("Element not found");
                }
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
                printf("\nLength of List: %d",length());
                break;
            }
            case 6:
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
