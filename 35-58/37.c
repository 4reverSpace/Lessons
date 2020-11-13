int fib(int a, int b,int n)
{
     if (n<=0)          // 
        printf("Error");
     else if (n==1)
        printf("%d",a);
     else if (n==2)
        printf("%d",b);
     else
     {
        for (int i=2;i<=n;i++)
        {
            b+=a;
            a=b-a;
        }
        printf("%d ",b);
     }
}

int main(void)
{
    int n;
    scanf("%d",&n);
    fib(1,1,n);
}

