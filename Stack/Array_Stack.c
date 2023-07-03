#include <stdio.h>
#include <stdlib.h>
#define l 5
int stack[l];
int top=-1;
 
int isFull()
{
    if(top==l-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty()
{
    if(top==-1)
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
    if(isFull())
    {
        printf("Stack Overflow!!");
        return;
    }
    top=top+1;
    stack[top]=data;
}
int pop()
{
    int value;
    if(isEmpty())
    {
        printf("Stack Underflow!!");
        exit(1);
    }
    value=stack[top];
    top=top-1;
    return value;
}
int peek()
{
    if(isEmpty())
    {
        printf("Stack Underflow!!");
        exit(1);
    }
    return stack[top];
}
void print()
{
    int i;
    if(isEmpty())
    {
        printf("Stack Underflow!!");
        return;
    }
    for(i=top;i>=0;i--)
    {
        printf("%d  ",stack[i]);
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

