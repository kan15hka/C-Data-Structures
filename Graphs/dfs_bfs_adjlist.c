#include <stdio.h>
#include <stdlib.h>
#define l 100
 struct node
 {
    int data;
    struct node *link;
 }*graph[l];
int x=0;

void insert()
{
    int vertex;
    if(x>=l)
    {
        printf("Data Breach!!");
    }
    else
    {
        printf("Enter the vertex: ");
        scanf("%d",&vertex);
        struct node *temp=(struct node*)malloc(sizeof(struct node));
        temp->data=vertex;
        temp->link=NULL;
        graph[x]=temp;
        x++;
        printf("Vertex created successfully.\n");
    }
}
void addEdges()
{
    int v1,v2,i;
    printf("Enter the adjacent vertices: \n");
    printf("Enter vertex 1: ");
    scanf("%d",&v1);
    printf("Enter vertex 2: ");
    scanf("%d",&v2);
    for(i=0;i<x;i++)
    {
        if(v1==graph[i]->data)
        {
            struct node *ptr=graph[i];
            while(ptr->link!=NULL)
            {
                ptr=ptr->link;
            }
            struct node*temp=malloc(sizeof(struct node));
            temp->data=v2;
            temp->link=NULL;
            ptr->link=temp;
        }
        if(v2==graph[i]->data)
        {
            struct node *ptr=graph[i];
            while(ptr->link!=NULL)
            {
                ptr=ptr->link;
            }
            struct node*temp=malloc(sizeof(struct node));
            temp->data=v1;
            temp->link=NULL;
            ptr->link=temp;
        }
    }
}
void bfs()
{
    int queue[l],i,j;
    int front=0,rear=0,temp,flag=0;
    queue[rear]=graph[0]->data;
    struct node *ptr;
    while(front<=rear)
    {
        for(i=0; i<x; i++)
        {
            if(queue[front]==graph[i]->data)
            {
                ptr=graph[i];                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
                ptr=ptr->link;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
                while(ptr)
                {
                    flag=0;
                    temp=0;
                    while(temp<=rear)
                    {
                        if(ptr->data==queue[temp])
                        {
                            flag=1;
                            break;                           
                        }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
                        else
                            temp++;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
                    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                    if(flag==0)
                        queue[++rear]=ptr->data;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
                        ptr=ptr->link;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
                }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
            }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
        }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
        front++;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
    for(j=0 ;j<front; j++)
        printf("%d  ",queue[j]);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
    printf("\n\n");
}
void dfs()
{
    int output[l],stack[l],top=0,flag=0,temp=0,i,j;
    output[temp++]=graph[0]->data;
    stack[top++]=graph[0]->data;
    struct node *ptr=graph[0]->link;
    while(ptr)
    {
        flag=0;
        for(i=0;i<temp;i++)
        {
            if(output[i]==ptr->data)
            {
                flag=1;
                break;
            }   
        }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
        if(flag==0)
        {
            output[temp++]=ptr->data;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
            stack[top++]=ptr->data;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
        }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
        else
        {
            top--;   
        }
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
        for(i=0;i<x;i++)
        {
            if(graph[i]->data==stack[top-1])
            {
                ptr=graph[i]->link;                                                                                                                                                                                                                                                                                                                                                                                                                            
                    for(j=0;j<temp;j++)
                    {
                        if((ptr->link!=NULL)&&(ptr->data==output[j]))
                        {
                            ptr=ptr->link;                                                                                                                                                                                                                                                                                                                                                                                                                           
                            j=-1;
                        }                                                                                                                                                                                                                                                                                                                                                                                                                                        
                    }                                                                                                                                                                                                                                                                                                                                                                                                                                            
                }                                                                                                                                                                                                                                                                                                                                                                                                                                                
            }                                                                                                                                                                                                                                                                                                                                                                                                                                                    
            if(temp==x)
                break;
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
    for(j=0;j<temp;j++)
        printf("%d  ",output[j]);
                                                                                                                                                                                                                                                                                                                                                                                                                                                         
    printf("\n\n");
}                 
int main()
{
    int ch,data;
    while(1)
    {
        printf("-----------------\n");
        printf("GRAPH SEARCH\n");
        printf("1.Insert vertex\n");
        printf("2.Add Edges\n");
        printf("3.Depth First Search(DFS)\n");
        printf("4.Breadth First Search(DFS)\n");
        printf("5.Exit\n");
        printf("-----------------\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                insert();
                break;
            }
            case 2:
            {
                addEdges();                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
                break;
            }
            case 3:
            {
                bfs();
                break;
            }
            case 4:
            {
                dfs();
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