int sum(int a, int b)
{
    return (a+b);
}
int con (int a, int b)
{
    return (a | b);
}

int dis (int a, int b)
{
    return (a & b);
}

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d  %d  %d",sum(a,b),con(a,b),dis(a,b));
}
