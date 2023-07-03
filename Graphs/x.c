#include <stdio.h>
#include <stdlib.h>
#define l 100
int queue[l];
int rear=-1,front=-1;
int isFull()
{
    if(rear==l-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty()
{
    if(front==-1 || front==rear+1)
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
    if(front=-1)
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
void addedge(int v,int m[v][v],int v1,int v2)
{
    m[v1][v2]=1;
    m[v2][v1]=1;
}
void print(int v, int matrix[][v]) {
    int i, j;
    for (i = 0; i < v; i++) 
    {
        printf("%d: ", i);
        for (j = 0; j < v; j++) 
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
void bfs(int v,int m[v][v],int src,int visited[v])
{
    int i,x;
    visited[src]=1;
    printf("%d ",src);
    enqueue(src);
    while(!isEmpty())
    {
        x=dequeue();
        for(i=0;i<v;i++)
        {
            if(m[x][i]=!0 && visited[i]!=1)
            {
                printf("%d ",i);
                visited[i]=1;
                enqueue(i);
            }
        }
    }
}
void dfs(int v,int m[v][v],int src,int visited[v])
{
    visited[src]=1;
    printf("%d ",src);
    for(int i=0;i<v;i++)
    {
        if(m[src][i]!=0 && visited[i]!=1)
        {
            dfs(v,m,i,visited);
        }
    }
}
int main()
{
    
    int v,v1,v2,ch,src;
    
    printf("Enter the number of vertices: ");
    scanf("%d",&v);
    int m[v][v];
    int visited[v];
    for(int i=0;i<v;i++)
    {
        visited[i]=0;
    }
    for (int i = 0;i<v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            m[i][j] = 0;
        }
    }
    while(1)
    {
        printf("GRAPH ADJACENT MATRIX\n");
        printf("--------------------\n");
        printf("1.Add Edge\n");
        printf("2.Print\n");
        printf("3.BFS\n");
        printf("4.DFS\n");
        printf("5.Exit\n");
        printf("--------------------\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                printf("Enter the vertex 1: ");
                scanf("%d",&v1);
                printf("Enter the vertex 2: ");
                scanf("%d",&v2);
                addedge(v,m,v1,v2);
                break;
            }
            case 2:
            {
                printf("\nAdjacency Matrix of vertex\n");
                print(v,m);
                break;
            }
            case 3:
            {
                printf("\nBreadth First Search\n");
                printf("Enter the source: ");
                scanf("%d",&src);
                bfs(v,m,src,visited);
                for(int i=0;i<v;i++)
                {
                    visited[i]=0;
                }
                printf("\n");
                break;
            }
            case 4:
            {
                printf("\nDepth First Search\n");
                printf("Enter the source: ");
                scanf("%d",&src);
                dfs(v,m,src,visited);
                for(int i=0;i<v;i++)
                {
                    visited[i]=0;
                }
                printf("\n");
                break;
            }
            case 5:
            {
                exit(1);
            }
            case 6:
            {
                printf("Invalid choice!!");
            }
        }
    }   
}
