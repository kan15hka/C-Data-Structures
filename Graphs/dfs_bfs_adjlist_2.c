#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void main()
{
    int v1,v2,stack[100],queue[100],i,j,front,rear,n,c;
    printf("ENTER NUMBER OF VERTEX: ");
    scanf("%d",&n);
    struct node *inp[n],*trav,*ptr;
    int visited[n];
    for(i=0;i<n;i++){
        inp[i]=(struct node*)malloc(sizeof(struct node));
        inp[i]->data=i;
        inp[i]->link=NULL;
    }
    while(1){
        printf("\nENTER 1 TO ADD EDGES\nENTER 2 TO DFS\nENTER 3 TO BFS: ");
        scanf("%d",&c);
        switch(c){
            case(1):
                printf("\nENTER THE EDGE: ");
                scanf("%d,%d",&v1,&v2);
                trav=inp[v1];
                while(trav->link!=NULL){
                    trav=trav->link;
                }
                ptr=(struct node*)malloc(sizeof(struct node));
                ptr->data=v2;
                ptr->link=NULL;
                trav->link=ptr;
                trav=inp[v2];
                while(trav->link!=NULL){
                    trav=trav->link;
                }
                ptr=(struct node*)malloc(sizeof(struct node));
                ptr->data=v1;
                ptr->link=NULL;
                trav->link=ptr;
                break;
            case(2):
                    for(i=0;i<n;i++){
                        visited[i]=0;
                    }
                    j=-1;
                    trav=inp[0];
                    do{
                    if(visited[trav->data]==0){
                        printf("%d  ",trav->data);
                        visited[trav->data]=1;
                        j++;
                        stack[j]=trav->data;
                        trav=inp[trav->data]->link;
                    }
                    else if(trav->link!=NULL){
                        trav=trav->link;
                    }
                    else{
                        j--;
                        if(j!=-1){
                        trav=inp[stack[j]]->link;
                        }}
                    }while(j!=-1);
                    break;
            case(3):
                for(i=0;i<n;i++){
                        visited[i]=0;
                    }
                    front=0;
                    rear=-1;
                    trav=inp[0];
                    do{
                    while(trav!=NULL){
                        if(visited[trav->data]==0){
                            printf("%d  ",trav->data);
                            visited[trav->data]=1;
                            rear++;
                            queue[rear]=trav->data;
                        }
                        trav=trav->link;
                    }
                    trav=inp[queue[front]]->link;
                    front++;
                    }
                    while(front!=rear);
                    break;
        }
}
}