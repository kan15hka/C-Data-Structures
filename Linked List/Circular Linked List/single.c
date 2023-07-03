#include <stdio.h>
#include <stdlib.h>
struct node
{
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
void insert(int data,int pos)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=temp;
    int l=length();
    if(tail==NULL)
    {
        tail=temp;
    }
    else if(pos==1)
    {
        temp->next=tail->next;
        tail->next=temp;
    }
    else if(pos>l || pos==l)
    {
        temp->next=tail->next;
        tail->next=temp;
        tail=tail->next;
    }
    else
    {
        pos--;
        struct node*ptr=tail->next;
        while(pos!=1)
        {
            pos--;
            tail=tail->next;
        }
        temp->next=ptr->next;
        ptr->next=temp;
    }
}
int delete(int pos)
{
    struct node*temp=NULL;
    int l=length(),data;
    if(tail==NULL)
    {
        printf("List is Empty");
        return 0;
    }
    else if(pos==1)
    {
        temp=tail->next;
        tail->next=temp->next;
        data=temp->data;
        free(temp);
        temp=NULL;
        return data;
    }
    else if(pos>=l)
    {
        printf("kk");
        struct node*ptr=tail->next;
        while(ptr->next!=tail)
        {
            ptr=ptr->next;
        }
        ptr->next=tail->next;
        data=tail->data;
        free(tail);
        tail=NULL;
        tail=ptr;
        return data;
    }
    else
    {
        struct node*ptr=tail->next,*temp=NULL;
        pos--;
        while(pos!=1)
        {
            pos--;
            ptr=ptr->next;
        }
        temp=ptr->next;
        ptr->next=temp->next;
        data=temp->data;
        free(temp);
        temp=NULL;
        return data;
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
    }while(ptr!=tail->next);
}
int main()
{                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
    while(1)
    {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
        int ch,data,pos;
        printf("\n---------------------------");
        printf("\nCIRCULAR LINKED LIST");
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
