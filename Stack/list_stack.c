#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
} *top;

int isEmpty()
{
    if(top==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(int data)
{
    struct node *temp=malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Stack Overflow");
        exit(1);
    }
    temp->data=data;
    temp->link=NULL;
    temp->link=top;
    top=temp;
}
int pop()
{
    struct node*temp;
    int value;
    if(isEmpty())
    {
        printf("Stack Underflow!!");
        exit(1);
    }
    temp=top;
    value=temp->data;
    top=top->link;
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
    return top->data;
}
void print()
{
    struct node *temp;
    if(isEmpty())
    {
        printf("Stack Underflow!!");
        return;
    }
    temp=top;
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
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Top");
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
                push(data);
                break;
            }
            case 2:
            {
                data=pop();
                printf("Element popped: %d",data);
                break;
            }
            case 3:
            {
                printf("Topmost element: %d",peek());
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

