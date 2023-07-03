#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define l 100
char stack[l];
char infix[l],postfix[l];
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
int space(char symbol)
{
    if(symbol==' ' || symbol=='\t')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void print()
{
    int i=0;
    printf("Equivalent Expression\n");
    while(postfix[i])
    {
        printf("%c",postfix[i++]);
    }
    printf("\n");

}
int precedence(char symbol)
{
    switch(symbol)
    {
        case '+':
        case '-':
        {
            return 1;
        }
        case '*':
        case '/':
        {
            return 2;
        }
        case '^':
        {
            return 3;
        }
        default:
        {
            return 0;
        }
    }
}
int intopost(char *s)
{
    int i,j=0;
    char symbol,next;
    for(i=0;i<strlen(s);i++)
    {
        symbol=s[i];
        if(!space(symbol))
        {
            switch(symbol)
            {
                case '(':
                {
                    push(symbol);
                    break;
                }
                case ')':
                {
                    while((next=pop())!='(')
                    {
                        postfix[j++]=next;
                    }
                    break;
                }
                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                {
                    while(!isEmpty() && precedence(stack[top])>=precedence(symbol))
                    {
                        postfix[j++]=symbol;
                    }
                    push(symbol);
                    break;
                }
                default:
                {
                    postfix[j++]=symbol;
                    
                }
            }
        }
    }
    while(!isEmpty())
    {
        postfix[j++]=pop();
    }
    postfix[j]='\0';
}

int main()
{
    int a;
    printf("Enter the algebric expression: ");
    scanf("%s",infix);
    intopost(infix);
    print();
    return 0;
}