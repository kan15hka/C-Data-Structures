#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node*link;
};
struct List
{
    struct Node*head;
};
struct Graph
{
    int v;
    struct List *array;
};
struct Graph *creategraph(int v)
{
    struct Graph *graph=(struct Graph*)malloc(sizeof(struct Graph));
    graph->v=v;
    graph->array=(struct List*)malloc(v * sizeof(struct List));
    int i;
    for (i = 0; i < v; ++i)
                graph->array[i].head = NULL;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
        return graph;
}
struct Node* createnode(int data)
{
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->link=NULL;
    return temp;
}
void addedge(struct Graph *graph,int v1,int v2)
{
    struct Node*ptr=NULL;

    struct Node*temp=createnode(v2);
    if(graph->array[v1].head==NULL)
    {
        temp->link=graph->array[v1].head;
        graph->array[v1].head=temp;
    }
    else
    {
        ptr=graph->array[v1].head;
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr->link=NULL;
    }

    temp=createnode(v1);
    if(graph->array[v2].head==NULL)
    {
        temp->link=graph->array[v2].head;
        graph->array[v2].head=temp;
    }
    else
    {
        ptr=graph->array[v2].head;
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr->link=NULL;
    }

}
void print(struct Graph *graph,int v)
{
    for(int i=0;i<v;i++)
    {
        struct Node*ptr=graph->array[i].head;
        printf("[%d]    ",v);
        while(ptr)
        {
            printf("-> %d ",ptr->data);
            ptr=ptr->link;
        }
        printf("\n");
    }
}
int main()
{
    int ch,v,v1,v2;
    printf("Enter the number of vertices: ");
    scanf("%d",&v);
    struct Graph *graph = creategraph(v);
    while(1)
    {
        printf("GRAPH ADJACENT LIST\n");
        printf("--------------------\n");
        printf("1.Add Edge\n");
        printf("2.Print\n");
        printf("3.Exit\n");
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
                addedge(graph,v1,v2);
                break;
            }
            case 2:
            {
                printf("\nAdjacency List of vertex\n");
                print(graph,v);
                break;
            }
            case 3:
            {
                exit(1);
            }
            case 4:
            {
                printf("Invalid choice!!");
            }
        }
    }
    return 0;
}