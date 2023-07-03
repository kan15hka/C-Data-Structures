#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
int main()
{
    struct node *head=(struct node*)malloc(sizeof(struct node));
    head->data=1000;
    head->link=NULL;

    struct node *current=(struct node*)malloc(sizeof(struct node));
    current->data=2000;
    current->link=NULL;
    head->link=current;
    
    current=malloc(sizeof(struct node));
    current->data=3000;
    current->link=NULL;
    head->link->link=current;
    return 0;
}
