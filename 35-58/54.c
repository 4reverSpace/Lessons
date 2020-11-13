int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++) 
    {
        scanf("%d",&a[i]);
    }
    int flags=1;
    while(flags)
    {
        flags=1;
        for(int i=0;i<n-1;i++)
        {
            if (a[i]>a[i+1])
            {
                a[i]^=a[i+1]^=a[i]^=a[i+1];
                flags++;
            }
        }
        flags--;
        }
    for (int i=0;i<n;i++)
        printf("%d ",a[i]);

    }
