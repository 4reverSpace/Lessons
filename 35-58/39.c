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
int main(void)
{
    int a,n;
    scanf("%d %d",&a,&n);
    printf("%d",pow(a,n));
}
