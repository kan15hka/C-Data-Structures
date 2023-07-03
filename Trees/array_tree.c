#include <stdio.h>
#include <stdlib.h>
char tree[100]="";
int length()
{
    int l;
    for(int i=0;tree[i]!=NULL;i++)
    {
        l++;
    }
    return l;
}
void insert(char data)
{
    printf("%c",tree[0]);
    if (tree[0]=='0')
    {
        tree[0]=data;
    }
    else
    {
        for(int i=i;i<length();i++)
        {
            if(tree[i]=='0')
            {

            } 
            else if(data<)  
        }
    }
    
}
int main()
{
    int ch;
    char data;
    printf("\nBINARY ARRAY TREE\n");
    printf("-------------------\n");
    printf("1.Insert\n");
    printf("2.Inorder\n");
    printf("3.exit\n");
    printf("-------------------\n");
    printf("Enter your choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        {
            printf("Enter data: ");
            scanf(" %c",&data);
            insert(data);
            break;
        }
        case 2:
        {
            printf("");
            break;
        }
        case 3:
        {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
            exit(1);
        }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
        default:
        {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
            printf("Invalid choice!!");
        }      
    }
}