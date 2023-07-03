int printdata(struct node*head)
{
    if(head==NULL){
        printf("Linked List is Empty");
    }
    struct node*ptr=NULL;
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
}