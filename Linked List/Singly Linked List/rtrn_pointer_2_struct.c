#include <stdio.h>
#include <stdlib.h>
struct point
{
    int x;
    int y;
};
struct point *coordinates(int a,int b)
{
    struct point *ptr = (struct point*)malloc(sizeof(struct point));
    ptr->x=a+5;
    ptr->y=b+10;
    return ptr;
}
void print(struct point *ptr)
{
    printf("%d  %d\n",ptr->x,ptr->y);
}
int main()
{
    struct point *ptr1,*ptr2;
    ptr1=coordinates(5,10);
    ptr2=coordinates(15,20);
    print(ptr1);
    print(ptr2);
    free(ptr1);
    free(ptr2);
    return 0;
}