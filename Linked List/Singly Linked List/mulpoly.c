#include <stdio.h> 
#include <stdlib.h>
struct node
{
    float coeff;
    int expo;
    struct node *link;
};
struct node*insert(struct node *head,int co,int ex)
{
    struct node *temp=malloc(sizeof(struct node));
    struct node*ptr=head;
    temp->coeff=co;
    temp->expo=ex;
    temp->link=NULL;
    if(head==NULL || ex>head->expo)
    {
        temp->link=head;
        head=temp;
    }
    else
    {
        while(ptr->link!=NULL && ptr->link->expo >= ex)
        {
            ptr=ptr->link;
        }
        temp->link=ptr->link;
        ptr->link=temp;
    }
    return head;
}
struct node*create(struct node*head)
{
    int n, i; 
    float coeff; 
    int expo; 

    printf("Enter the number of terms: "); 
    scanf("%d", &n); 

    for(i=0; i<n; i++) 
    {
        printf("Enter the coefficient %d: ", i+1);
        scanf("%f", &coeff); 

        printf("Enter the exponent %d: ", i+1); 
        scanf("%d", &expo); 

        head = insert(head, coeff, expo); 
    }
    return head; 
}
void print(struct node* head)
{ 
    if(head == NULL) 
        printf("No Polynomial."); 
    else {
        struct node* ptr = head; 
        while(ptr != NULL)
        {
            printf("(%.1fx^%d)", ptr->coeff, ptr->expo); 
            ptr = ptr->link; 
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
void mulpoly(struct node*head1,struct node*head2)
{
    struct node* ptr1 = head1; 
    struct node* ptr2 = head2; 
    struct node* head3 = NULL; 

    //Check if first or second polynomial is NULL
    if(head1 == NULL || head2 == NULL) 
    {
        printf("Zero polynomial\n"); 
        return;
    } 
    
    //Multiplication of two polynomials
    while(ptr1 != NULL)
    {
        while(ptr2 != NULL)
        {
            head3 = insert(head3, ptr1->coeff * ptr2->coeff, ptr1->expo + ptr2->expo); 
            ptr2 = ptr2->link; 
        }
        ptr1 = ptr1->link; 
        ptr2 = head2; 
    } 
    struct node* ptr3 = head3; 
    struct node* temp = NULL;

    while(ptr3->link != NULL) {
        if(ptr3->expo == ptr3->link->expo)
        { 
            ptr3->coeff = ptr3->coeff + ptr3->link->coeff; 
            temp = ptr3->link; 
            ptr3->link = ptr3->link->link; 
            free(temp); 
        }
        else { 
            ptr3 = ptr3->link;  
        }
    } 
    printf("\n Resultant Polynomial\n"); 
    print(head3); 

}
int main()
{
    struct node *head1=NULL,*head2=NULL;
    printf("\nFirst Polynomial");
    printf("\n-----------------------\n");
    head1=create(head1);
    printf("\nSecond Polynomial");
    printf("\n-----------------------\n");
    head2=create(head2);

    mulpoly(head1,head2);
    return 0;
}