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