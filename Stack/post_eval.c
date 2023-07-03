#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define l 100
int stack[l];
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
void push(int c)
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
    int value;
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
int power(int a,int b)
{
    int i,pow=1;
    for(i=0;i<b;i++)
    {
        pow*=a;
    }
    return pow;
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
int intopost()
{
    int i,j=0;
    char symbol,next;
    for(i=0;i<strlen(infix);i++)
    {
        symbol=infix[i];
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
int posteval()
{
    int i,a,b;
    for(i=0;i<strlen(postfix);i++)
    {
        if(!space(postfix[i]))
        {
            if(postfix[i]>='0' && postfix[i]<='9')
            {
                push(postfix[i]-'0');
            }
            else
            {
                a=pop();
                b=pop();
                switch(postfix[i])
                {
                    case '+':
                    {
                        push(b+a);
                        break;
                    }
                    case '-':
                    {
                        push(b-a);
                        break;
                    }
                    case '*':
                    {
                        push(b*a);
                        break;
                    }
                    case '/':
                    {
                        push(b/a);
                        break;
                    }
                    case '^':
                    {
                        push(power(b,a));
                        break;
                    }
                }
            }
        }
    }
    return pop();
}  
int main()
{
    int a,result;
    printf("Enter the algebric expression: ");
    gets(infix);

    intopost();
    result=posteval();
    print();
    printf("Postfix Expression result\n");
    printf("%d",result);
    return 0;
}