int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++) 
    {
        scanf("%d",&a[i]);
    }
    int ch; //сдвиг
    scanf("%d",&ch);
    for (int j=0;j<ch;j++)
    {
        int b=a[n-1];
        for (int i=n-2;i>-1;i--)
        {
            a[i+1]=a[i];
        }
        a[0]=b;
    }
    for (int i=0;i<n;i++)
        printf("%d ",a[i]);
}
