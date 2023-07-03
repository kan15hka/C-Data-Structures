#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define l 100
char stack[l];
int top=-1;

int isFull()
{
    if(top==l-1)
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
    if(top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(char c)
{
    if(isFull())
    {
        printf("Stack Overflow!!");
        return;
    }
    top=top+1;
    stack[top]=c;
}
int pop()
{
    char value;
    if(isEmpty())
    {
        printf("Stack Underflow!!");
        exit(1);
    }
    value=stack[top];
    top=top-1;
    return value;
}
int match_char(char a,char b)
{
    if(a=='[' && b==']'){return 1;}
    if(a=='(' && b==')'){return 1;}
    if(a=='{' && b=='}'){return 1;}
    return 0;
}
int validate(char *s)
{
    int i;
    char temp;
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='[' || s[i]=='(' || s[i]=='{')
        {
            push(s[i]);
        }
        if(s[i]==']' || s[i]==')' || s[i]=='}')
        {
            if(isEmpty())
            {
                printf("Right brackets > Left brackets\n");
                return 0;
            }
            else
            {
                temp=pop();
                if(!match_char(temp,s[i]))
                {
                    printf("Mismatched Brackets!!\n");
                    return 0;
                }
            }
        }
    }
    if(isEmpty())
    {
        printf("Brackets are balanced\n");
        return 1;
    }
    else
    {
        printf("Left brackets > Right brackets\n");
        return 0;
    }
}

int main()
{
    char expr[l];
    int a;
    printf("Enter the algebric expression: ");
    gets(expr);
    a=validate(expr);
    if(a==1)
    {
        printf("Expression is valid");
    }
    else
    {
        printf("Expression is not valid");
    }
    return 0;
}