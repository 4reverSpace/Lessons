int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++) 
    {
        scanf("%d",&a[i]);
    }
    int j=0;
    for(int i=1;i<n;i++)
    {
        j=i;
        while(j>0 && a[j]<a[j-1])
        {
            a[j]^=a[j-1]^=a[j]^=a[j-1];
            j-=1;
        }
    }
    for (int i=0;i<n;i++)
        printf("%d ",a[i]);
}
