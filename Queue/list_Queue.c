#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
} *front=NULL,*rear=NULL;

int isEmpty()
{
    if(front==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(int data)
{
    struct node *temp=malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Stack Overflow");
        exit(1);
    }
    temp->data=data;
    temp->link=NULL;
    if(rear==NULL)
    {
        front=rear=temp;
    }
    else{
        rear->link=temp;
        rear=temp;
    }
}
int dequeue()
{
    struct node*temp;
    int value;
    if(isEmpty())
    {
        printf("Stack Underflow!!");
        exit(1);
    }
    temp=front;
    value=temp->data;
    front=front->link;
    free(temp);
    temp=NULL;
    return value;
}
int peek()
{
    if(isEmpty())
    {
        printf("Stack Underflow!!");
        exit(1);
    }
    return front->data;
}
void print()
{
    struct node *temp;
    if(isEmpty())
    {
        printf("Stack Underflow!!");
        return;
    }
    temp=front;
    while(temp!=NULL)
    {
        printf("%d  ",temp->data);
        temp=temp->link;
    }
    printf("\n");
}
 
int main()
{
    int ch,data;
    while(1)
    {
        printf("\n------------------------");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. First");
        printf("\n4. Print");
        printf("\n5. Quit");
        printf("\n------------------------");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
 
        switch(ch)
        {
            case 1:
            {
                printf("Enter element: ");
                scanf("%d",&data);
                enqueue(data);
                break;
            }
            case 2:
            {
                data=dequeue();
                printf("Element popped: %d",data);
                break;
            }
            case 3:
            {
                printf("First element: %d",peek());
                break;
            }
            case 4:
            {
                print();
                break;
            }
            case 5:
            {
                exit(1);
            }
            default:
            {
                printf("Invalid choice!!");
            }
        }
    }
    return 0;
}

