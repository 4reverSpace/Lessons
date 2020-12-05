int main()
{
    int n=0;
    scanf("%d",&n); 
    if (n<0)
    {
        printf("Error");
        return(0);
    }
    int a[n];
    for (int i=0;i<n;i++) 
        scanf("%d",&a[i]);
    int min=a[0];
    int max=a[0];
    for (int i=1;i<n;i++)
    {
        if (a[i]>max)
            max=a[i];
        else if (a[i]<min)
            min=a[i];
    }
    printf("min=%d max=%d",min, max);
    return(0);
}
