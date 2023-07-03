#include <stdio.h> 
#include <stdlib.h> 

struct node {
    float coeff; 
    int expo; 
    struct node* link;
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

struct node* create(struct node* head)
{ 
    int n, i; 
    float coeff; 
    int expo; 

    printf("Enter the number of terms: "); 
    scanf("%d", &n); 

    for(i=0; i<n; i++) 
    {
        printf("Enter the coefficient for term %d: ", i+1);
        scanf("%f", &coeff); 

        printf("Enter the exponent for term %d: ", i+1); 
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
        struct node* temp = head; 
        while(temp != NULL)
        {
            printf("(%.1fx^%d)", temp->coeff, temp->expo); 
            temp = temp->link; 
            if(temp!=NULL) 
                printf(" + "); 
            else printf("\n");
        }
    }
}

int main() 
{
    struct node* head = NULL; 
    printf("Enter the polynomial\n "); 
    head = create(head);
    print(head); 
    return 0; 
} 