int pow(int a,int n)
{
    int p=1;
    if (n>0)
    {
        for (int i=0;i<n;i++)
        {
            p*=a;
        }
    }
    else if (n==0)
    {

        p=1;
    }
    else
    {
        p=-1;
    }
    return (p);
}
long long int fact(long long int n)
{
    if (n<0)
    {
        printf("Error");
    }
    if (n==0 || n==1)
    {
        return (1);
    }
    return (n*fact(n-1));
}
double exp(int x, int n)
{
    if (n<=0)
    {
        return (-1);
    }
    double e=0;
    for (int i=0;i<=n;i++)
    {
        e+=(pow(x,i)*1.0)/fact(i);
    }
    return e;
}
int main(void)
{
    int x,n;
    scanf("%d %d",&x,&n);
    printf("%lf",exp(x,n));
}
