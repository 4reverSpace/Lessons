long long int fact(int n)
{
    if (n<0)
    {
        return(-1);
    }
    if (n==0 || n==1)
    {
        return (1);
    }
    return (n*fact(n-1));
}
double pow(double a,int n)
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
double sin(double a)
{
    double s=a;
    for (int i=1;i<=10;i++)
    {
        s+=(1-2*(i%2))*pow(a,2*i+1)/fact(2*i+1);
    }
    return(s);
}
double cos(double a)
{
    double s=1;
    for (int i=1;i<=10;i++)
    {
        s+=(1-2*(i%2))*pow(a,2*i)/fact(2*i);
    }
    return(s);
}
int main()
{
    double n;
    scanf("%lf",&n);
    printf("%.15f  %.15f ",sin(n), cos(n));
}
