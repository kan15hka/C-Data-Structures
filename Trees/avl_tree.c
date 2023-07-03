#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *left;
    int data;
    int bf;
    struct node *right;
}*Root=NULL;
int height(struct node*root)
{
    int hl=0,hr=0;
    if(!root)
    {
        return 0;
    }
    hl=height(root->left);
    hr=height(root->right);
    return hl>hr?hl+1:hr+1;
}
struct node *LLrotation(struct node *root)
{
    struct node *rootl=root->left;
    int lbf,rbf;
    rootl->bf=0;
    root->left=rootl->right;
    rootl->right=root;
    lbf=height(root->left)+1;
    rbf=height(root->right)+1;
    root->bf=lbf-rbf;
    if(root==Root)
    {
        Root=rootl;
    }
    return rootl;
}
struct node *LRrotation(struct node *root)
{
    struct node *rootl=root->left;
    struct node *rootlr=rootl->right;
    int lbf,rbf;
    rootlr->bf=0;
    root->left=rootlr->right;
    rootl->right=rootlr->left;
    rootlr->left=rootl;
    rootlr->right=root;
    lbf=height(root->left)+1;
    rbf=height(root->right)+1;
    root->bf=lbf-rbf;
    
    lbf=height(rootl->left)+1;
    rbf=height(rootl->right)+1;
    rootl->bf=lbf-rbf;
    if(root==Root)
    {
        Root=rootlr;
    }
    return rootlr;
    
}
struct node *RRrotation(struct node *root)
{
    struct node *rootr=root->right;
    int lbf,rbf;
    rootr->bf=0;
    root->right=rootr->left;
    rootr->left=root;
    lbf=height(root->left)+1;
    rbf=height(root->right)+1;
    root->bf=lbf-rbf;
    if(root==Root)
    {
        Root=rootr;
    }
    return rootr;
}
struct node *RLrotation(struct node *root)
{
    struct node *rootr=root->right;
    struct node *rootrl=rootr->left;
    int lbf,rbf;
    rootrl->bf=0;
    root->right=rootrl->left;
    rootr->left=rootrl->right;
    rootrl->left=root;
    rootrl->right=rootr;
    lbf=height(root->left)+1;
    rbf=height(root->right)+1;
    root->bf=lbf-rbf;
    
    lbf=height(rootr->left)+1;
    rbf=height(rootr->right)+1;
    rootr->bf=lbf-rbf;
    if(root==Root)
    {
        Root=rootrl;
    }
    return rootrl;
}

struct node *insert(struct node*root,int data)
{
    int lbf,rbf;
    struct node *temp;
    if(root==NULL)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=data;
        temp->bf=0;
        temp->left=temp->right=NULL;
        return temp;
    }
    if(data<root->data)
    {
        root->left=insert(root->left,data);
    }
    else if(data>root->data)
    {
        root->right=insert(root->right,data);
    }
    lbf=height(root->left)+1;
    rbf=height(root->right)+1;
    root->bf=lbf-rbf;
    if(root->bf==2 && root->left->bf==1)
    {
        return LLrotation(root);
    }
    if(root->bf==2 && root->left->bf==-1)
    {
        return LRrotation(root);
    }
    if(root->bf==-2 && root->right->bf==-1)
    {
        return RRrotation(root);
    }
    if(root->bf==-2 && root->right->bf==1)
    {
        return RLrotation(root);
    }
    return root;
}
int search(struct node *root,int data){
    struct node *temp=root;
    if(root==0)
    {
        printf("Tree is dead");                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
    else
    {
        while(temp!=0)
        {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
            if(data==temp->data)
            {
                return 1;
            }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
            else if(data>temp->data)
            {
                temp=temp->right;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
            }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
            else
            {
                temp=temp->left;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
            }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
        }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
     temp=root;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
}
void preorder(struct node*root)
{
    if(root==NULL)
    {
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct node*root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void postorder(struct node*root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
struct node *inorder_successor(struct node *node){
    struct node *current=node;
    while(current && current->left!=NULL){
            current=current->left;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
    return current;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
struct node *delete(struct node *root,int data){
    if(root==NULL)
    {
        return root;
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
    if(data < root->data)
    {
        root->left=delete(root->left,data);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
    else if(data >root->data)
    {
        root->right=delete(root->right,data);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
    else
    {
        if(root->left==NULL)
        {
            struct node *temp=root->right;
            free(root);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
            return temp;
        }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
        else if(root->right==NULL)
        {
            struct node *temp=root->left;
            free(root);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
            return temp;
        }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
        struct node *temp=inorder_successor(root->right);
        root->data=temp->data;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
        root->right=delete(root->right,temp->data);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
    }            
    int lbf=0,rbf=0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
    lbf=height(root->left)+1;
    rbf=height(root->right)+1;
    root->bf=lbf-rbf;
    if(root->bf==2 && root->left->bf==1)
    {
        return LLrotation(root);
    }
    if(root->bf==2 && root->left->bf==0)
    {
        return LLrotation(root);
    }
    if(root->bf==2 && root->left->bf==-1)
    {
        return LRrotation(root);
    }
    if(root->bf==-2 && root->right->bf==-1)
    {
        return RRrotation(root);
    }
    if(root->bf==-2 && root->left->bf==0)
    {
        return RRrotation(root);
    }
    if(root->bf==-2 && root->right->bf==1)
    {
        return RLrotation(root);
    }
    return root;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
             
int main()
{
    int ch,data;
    while(1)
    {
        printf("-----------------\n");
        printf("AVL TREE\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Search\n");
        printf("4.Preorder Traversal\n");
        printf("5.Inorder Traversal\n");
        printf("6.Postorder Traversal\n");
        printf("7.Exit\n");
        printf("-----------------\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                printf("Enter data: ");
                scanf("%d",&data);
                Root=insert(Root,data);
                break;
            }
            case 2:
            {
                printf("Enter element to delete: ");
                scanf("%d",&data);
                Root=delete(Root,data);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
                break;
            }
            case 3:
            {
                printf("Enter the element to search: ");
                scanf("%d",&data);
                int x=search(Root,data);
                (x==1)?printf("Element is found in the tree\n"):printf("Element is not found in the tree\n");
                break;
            }
            case 4:
            {
                printf("\nPreorder Traversal\n");
                preorder(Root);
                printf("\n");
                break;
            }
            case 5:
            {
                printf("\nInorder Traversal\n");
                inorder(Root);
                printf("\n");
                break;
            }
            case 6:
            {
                printf("\nPostorder Traversal\n");
                postorder(Root);
                printf("\n");
                break;
            }
            case 7:
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