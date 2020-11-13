int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++) // ввод массива
    {
        scanf("%d",&a[i]);
    }
    int j=0,min=0;
    for(int i=0;i<n;i++)
    {
        int c=a[i];
        min=i;
        for (int j=i+1;j<n;j++)
        {
            if (a[j]<a[min])
                min=j;
        }
        c^=a[min]^=c^=a[min];
        a[i]=c;
    }
    for (int i=0;i<n;i++)
        printf("%d ",a[i]);
}
