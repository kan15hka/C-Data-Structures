#include <stdio.h>
#include <stdlib.h>
struct node
{
    float coeff;
    int expo;
    struct node*link;
};
struct node* insert(struct node* head, float co, int ex) 
{
    struct node* ptr; 
    struct node* temp = malloc(sizeof(struct node)); 
    temp->coeff = co; 
    temp->expo = ex; 
    temp->link = NULL;

    if(head == NULL || ex > head->expo) 
    {
        temp->link = head; 
        head = temp; 
    }
    else 
    { 
        ptr = head; 
        while(ptr->link != NULL && ptr->link->expo >= ex) 
            ptr = ptr->link; 
        temp->link = ptr->link; 
        ptr->link = temp; 
    }
    return head; 
}
struct node* create(struct node*head)
{
    int i,n,expo;
    float coeff;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the coefficient for term %d: ", i+1);
        scanf("%f", &coeff); 
        printf("Enter the exponent for term %d: ", i+1); 
        scanf("%d", &expo); 
        head = insert(head, coeff, expo);
    }    
    return head;
}

void print(struct node*head)
{
    if(head==NULL)
    {
        printf("No Polynomial");
    }
    else
    {
        struct node*ptr=head;
        while(ptr!=NULL)
        {
            printf("(%.2f)x^%d",ptr->coeff,ptr->expo);
            ptr=ptr->link;
            if(ptr!=NULL)
            {
                printf(" + ");
            }
            else
            {
                printf("\n");
            }
        }
    }  
}
void addpoly(struct node*head1,struct node*head2)
{
    struct node *ptr1=head1,*ptr2=head2,*ptr3=NULL;
    while(ptr1!=NULL &&ptr2!=NULL)
    {
        if(ptr1->expo==ptr2->expo)
        {
            ptr3=insert(ptr3,ptr1->coeff+ptr2->coeff,ptr1->expo);
            ptr1=ptr1->link;
            ptr2=ptr2->link;
        }
        else if(ptr1->expo>ptr2->expo)
        {
            ptr3=insert(ptr3,ptr1->coeff,ptr1->expo);
            ptr1=ptr1->link;
        }
        else if(ptr1->expo<ptr2->expo)
        {
            ptr3=insert(ptr3,ptr2->coeff,ptr1->expo);
            ptr2=ptr2->link;
        }
        
    }
    while(ptr1!=NULL)
    {  
        ptr3 = insert(ptr3, ptr1->coeff, ptr1->expo); 
        ptr1 = ptr1->link; 
    }
    while(ptr2!=NULL) 
    {
        ptr3 = insert(ptr3, ptr2->coeff, ptr2->expo); 
        ptr2 = ptr2->link;
    }
    printf("Added polynomial is: "); 
    print(ptr3);

}
int main()
{
    struct node *head1=NULL,*head2=NULL;
    printf("Enter first polynomial:\n");
    head1=create(head1);
    printf("Enter second polynomial:\n");
    head2=create(head2);

    addpoly(head1,head2);

    return 0;
}