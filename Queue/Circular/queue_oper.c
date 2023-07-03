#include <stdio.h>
#include <stdlib.h>
#define l 5
int queue[l];
int front=-1,rear=-1;
int isEmpty()
{
    if(front==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull()
{
    if((front==0 && rear==l-1) || (front==rear+1))
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
    if(isFull())
    {
        printf("Queue Overflow");
        exit(1);
    }
    if(front==-1)
    {
        front=0;
    }
    if(rear==l-1)
    {
        rear=0;
    }
    else
    {
        rear=rear+1;
    }
    queue[rear]=data;
}
int dequeue()
{
    int data;
    if(isEmpty())
    {
        printf("Queue Underflow");
        exit(1);
    }
    data=queue[front];
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else if(front==l-1)
    {
        front=0;
    }
    else
    {
        front+=1;
    }
    return data;
}
void print()
{
    int i;
    if(isEmpty())
    {
        printf("Queue Underflow");
        exit(1);
    }
    for(i=front;i<=rear;i++)
    {
        printf("%d ",queue[i]);
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
        printf("\n3. Print");
        printf("\n4. Quit");
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
                print();
                break;
            }
            case 4:
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

