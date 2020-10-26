int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++) // ввод первого массива
    {
        scanf("%d",&a[i]);
    }
    int m;
    scanf("%d",&m);
    int b[m];
    for (int i=0;i<m;i++) // ввод второго массива
    {
        scanf("%d",&b[i]);
    }
    int v=n+m;
    int c[v];
    for (int i=0;i<n;i++)
        c[i]=a[i];
    for (int i=n;i<v;i++)
        c[i]=b[i-n];
    for (int i=0;i<v;i++)
        printf("%d ",c[i]);
}
