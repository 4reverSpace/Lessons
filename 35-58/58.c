int notin(long long int *a,long long int b)
{
    for ( int i=0;i<sizeof(a)/sizeof(long long int);i++)
        if (b%a[i]==0)
        return(0);
    return(1);

}

int main()
{
    int n,i=0;
    scanf("%d",&n);
    long long int a[n],j=2;
    while(i<n)
    {
        if (notin(a,j))
        {
           a[i]=j;
           i++;
        }
        j++;
    }
    for (int i=0;i<n;i++)
        printf("%lld ",a[i]);
    return(0);
}
