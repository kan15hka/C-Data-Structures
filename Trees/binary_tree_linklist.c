#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node*left;
    int data;
    struct node*right;
}*root=NULL;

//Queue
#define l 100
struct node *queue[l];
int front=-1,rear=-1;
 
int isfull()
{
    if(rear==l-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty()
{
    if(front ==-1 || front==rear+1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(struct node*data)
{
    if(isfull())
    {
        printf("Queue Overflow!!");
        return;
    }
    if(front==-1)
    {
        front=0;
    }
    rear=rear+1;
    queue[rear]=data;
}
struct node* dequeue()
{
    struct node *value;
    if(isEmpty())
    {
        printf("Queue Underflow!!");
        exit(1);
    }
    value=queue[front];
    front=front+1;
    return value;
}


struct node *insert()
{
    int c,data;
    printf("-------------\n1.Enter data\n0.Return\n-------------\n");
    printf("Enter your choice: ");
    scanf("%d",&c);
    if(!c)
    {
        return NULL;
    }
    else
    {
        struct node *temp= malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&data);
        printf("-------------\n");
        temp->data=data;
        printf("Left child of %d\n",temp->data);
        temp->left=insert();
        printf("Right child of %d\n",temp->data);
        temp->right=insert();
        return temp;
    }
    
}
int count(struct node*root)
{
    if(root==NULL)
    {
        return 0;
    }
    if((root->left==NULL) && (root->right==NULL))
    {
        return 1;
    }
    int left=count(root->left);
    int right=count(root->right);
    return (left + right +1);
}
int isFull(struct node*root)
{
    int left,right;
    if(root==NULL)
    {
        return 1;
    }
    if((root->left==NULL) && (root->right==NULL))
    {
        return 1;
    }
    if(root->left && root->right)
    {
        left=isFull(root->left);
        right=isFull(root->right);
        return (left && right);
    }
    return 0;
}
int isComplete(struct node*root,int n,int i)
{
    if(root==NULL)
    {
        return 1;
    }
    if(i>=n)
    {
        return 0;
    }
    int left=isComplete(root->left,n,2*i+1);
    int right=isComplete(root->right,n,2*i+2);
    return (left && right);
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
void levelorder(struct node*root)
{
    struct node* ptr=root;
    if(ptr==NULL)
    {
        printf("The Binary Tree is empty\n");
        return;
    }
    enqueue(ptr);
    while(!isEmpty())
    {
        ptr=dequeue();
        printf("%d ",ptr->data);
        if(ptr->left!=NULL)
        {
            enqueue(ptr->left);
        }
        if(ptr->right!=NULL)
        {
            enqueue(ptr->right);
        }
    }
}
int main()
{
    int ch;
    while(1)
    {
        printf("-----------------\n");
        printf("BINARY TREE\n");
        printf("1.Insert\n");
        printf("2.Count Nodes\n");
        printf("3.Check Full Binary Tree\n");
        printf("4.Check Complete Binary Tree\n");
        printf("5.Preorder Traversal\n");
        printf("6.Inorder Traversal\n");
        printf("7.Postorder Traversal\n");
        printf("8.Levelorder\n");
        printf("9.Exit\n");
        printf("-----------------\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                root=insert();
                break;
            }
            case 2:
            {
                int n=count(root);
                printf("Total number of nodes: %d \n",n);
                break;
            }
            case 3:
            {
                if(isFull(root))
                {
                    printf("\nFull Binary Tree\n");
                }
                else
                {
                    printf("\nNot a Full Binary Tree\n");
                }
                break;
            }
            case 4:
            {
                int n=count(root);
                int i=0;
                if(isComplete(root,n,i))
                {
                    printf("\nComplete Binary Tree\n");
                }
                else
                {
                    printf("\nNot a Complete Binary Tree\n");
                }
                break;
            }
            case 5:
            {
                printf("\nPreorder Traversal\n");
                preorder(root);
                printf("\n");
                break;
            }
            case 6:
            {
                printf("\nInorder Traversal\n");
                inorder(root);
                printf("\n");
                break;
            }
            case 7:
            {
                printf("\nPostorder Traversal\n");
                postorder(root);
                printf("\n");
                break;
            }
            case 8:
            {
                printf("\nLevelorder Traversal\n");
                levelorder(root);
                printf("\n");
                break;
            }
            case 9:
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