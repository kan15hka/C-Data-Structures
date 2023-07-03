#include <stdio.h>
#include <stdlib.h>
#define l 5
int queue[l];
int front=-1,rear=-1;
 
int isFull()
{
    if(rear==l-1)
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
    if(front ==-1 || front==rear+1)
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
        printf("Queue Overflow!!");
        return;
    }
    if(front==-1)
    {
        front=0;
    }
    rear=rear+1;
    queue[rear]=data;
}
int dequeue()
{
    int value;
    if(isEmpty())
    {
        printf("Queue Underflow!!");
        exit(1);
    }
    value=queue[front];
    front=front+1;
    return value;
}
int peek()
{
    if(isEmpty())
    {
        printf("Queue Underflow!!");
        exit(1);
    }
    return queue[front];
}
void print()
{
    int i;
    if(isEmpty())
    {
        printf("Queue Underflow!!");
        return;
    }
    for(i=front;i<=rear;i++)
    {
        printf("%d  ",queue[i]);
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

