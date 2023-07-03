#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *left;
    int data;
    struct node *right;
}*root=NULL;

struct node *insert(struct node *node,int data)
{
    if(node==NULL)
    {
        struct node *temp=malloc(sizeof(struct node));
        temp->data=data;
        temp->left=temp->right=NULL;
        return temp;
    }
    else if(node->data > data)
    {
        node->left=insert(node->left,data);
    }
    else
    {
        node->right=insert(node->right,data);
    }
    return node;
}
struct node *inorder_predecesor(struct node *root)
{
    struct node *ptr=root;
    while(ptr && ptr->left!=NULL)
    {
        ptr=ptr->left;
    }
    return ptr;
}
struct node *delete(struct node *root,int data)
{
    if(root==NULL)
    {
        return root;
    }
    else if(root->data > data)
    {
        root->left=delete(root->left,data);
    }
    else if(root->data < data)
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
        struct node *temp=inorder_predecesor(root->right);
        root->data=temp->data;
        root->right=delete(root->right,temp->data);
    }
    return root;
}
int search(struct node *root,int data)
{
    struct node*ptr=root;
    if(ptr==NULL)
    {
        return 0;
    }
    else
    {
        while(ptr!=NULL)
        {
            if(ptr->data==data)
            {
                return 1;
            }
            else if(ptr->data > data)
            {
                ptr=ptr->left;
            }
            else
            {
                ptr=ptr->right;
            }
        }
    }
    ptr=root;
}
void preorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void postorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
int main()
{
    int ch,data;
    while(1)
    {
        printf("-----------------\n");
        printf("BINARY TREE\n");
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
                root=insert(root,data);
                break;
            }
            case 2:
            {
                printf("Enter element to delete: ");
                scanf("%d",&data);
                root=delete(root,data);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
                break;
            }
            case 3:
            {
                printf("Enter the element to search: ");
                scanf("%d",&data);
                int x=search(root,data);
                (x==1)?printf("Element is found in the tree"):printf("Element is not found in the tree");
                break;
            }
            
            case 4:
            {
                printf("\nPreorder Traversal\n");
                preorder(root);
                printf("\n");
                break;
            }
            case 5:
            {
                printf("\nInorder Traversal\n");
                inorder(root);
                printf("\n");
                break;
            }
            case 6:
            {
                printf("\nPostorder Traversal\n");
                postorder(root);
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