#include <stdio.h>
#include <stdlib.h>
struct node
{
        int data;
        struct node *link;
}*first=NULL;
void Display(struct node *p)
{
        while(p!=NULL)
        {
                printf("%d ",p->data);
                p=p->link;
        }
}
void create(int A[],int n)
{
        int i;
        struct node *temp,*last;
        first=(struct node *)malloc(sizeof(struct node));
        first->data=A[0];
        first->link=NULL;
        last=first;

        for(i=1;i<n;i++)
        {
                temp=(struct node*)malloc(sizeof(struct node));
                temp->data=A[i];
                temp->link=NULL;
                last->link=temp;
                last=temp;
        }
}
int isLoop(struct node *first)
{
        struct node *p,*q;
        p=q=first;

        do
        {
                p=p->link;
                q=q->link;
                q=q?q->link:q;
        }while(p && q && p!=q);

        if(p==q)
                return 1;
        else
                return 0;
}
int main()
{
        struct node *t1,*t2;

        int A[]={10,20,30,40,50};
        create(A,5);

        t1=first->link->link;
        t2=first->link->link->link->link;
        t2->link=t1;
        printf("%d\n",isLoop(first));
        return 0;
}