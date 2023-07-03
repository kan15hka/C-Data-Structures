#include <stdio.h>
#include <stdlib.h>
void addedge(int v, int matrix[][v], int i, int j) {
    matrix[i][j] = 1;
    matrix[j][i] = 1;
}

void print(int v, int matrix[][v]) {
    int i, j;
    for (i = 0; i < v; i++) 
    {
        printf("%d: ", i);
        for (j = 0; j < v; j++) 
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int v,ch,v1,v2;
    printf("Enter the number of vertex: ");
    scanf("%d",&v);
    int matrix[v][v];
    for (int i = 0;i<v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            matrix[i][j] = 0;
        }
    }
    while(1)
    {
        printf("GRAPH ADJACENT MATRIX\n");
        printf("--------------------\n");
        printf("1.Add Edge\n");
        printf("2.Print\n");
        printf("3.Exit\n");
        printf("--------------------\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                printf("Enter the vertex 1: ");
                scanf("%d",&v1);
                printf("Enter the vertex 2: ");
                scanf("%d",&v2);
                addedge(v,matrix,v1,v2);
                break;
            }
            case 2:
            {
                printf("\nAdjacency Matrix of vertex\n");
                print(v,matrix);
                break;
            }
            case 3:
            {
                exit(1);
            }
            case 4:
            {
                printf("Invalid choice!!");
            }
        }
    }   
}