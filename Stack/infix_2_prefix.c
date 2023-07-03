#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define l 100
char stack[l];
char infix[l];
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
void print(char *s)
{
    int i=0;
    printf("Equivalent Expression\n");
    while(s[i])
    {
        printf("%c",s[i++]);
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
char *intopost(char *s)
{
    int i,j=0;
    char symbol,next;
    char *postfix;
    int len=strlen(infix);
    postfix = (char *)malloc((len+1)*sizeof(char));
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
    return postfix;
}
char *reverse(char *str)
{
        char temp;
        int len=strlen(str);
        for(int i=0;i<len/2;i++)
        {
            temp=str[len-i-1];
            str[len-i-1]=str[i];
            str[i]=temp;                                                                                                                         
        
        }
        for(int i=0;i<len;i++)
        {
            if(str[i]=='(')
            {
                str[i]=')';
            }
            else if(str[i]==')')
            {
                str[i]='(';
            }      
        }
        return str;       
}
char *intopre(char *infix)
{
    char *prefix;
    int len=strlen(infix);
    prefix = (char *)malloc((len+1)*sizeof(char));
    prefix=reverse(infix);
    print(prefix);
    prefix=intopost(prefix);
    print(prefix);
    prefix=reverse(prefix);
    return prefix;
}
int main()
{
    int a;
    char *post,*pre;
    printf("Enter the algebric expression: ");
    gets(infix);

    post=intopost(infix);
    print(post);
    pre=intopre(infix);
    print(pre);

    return 0;
}