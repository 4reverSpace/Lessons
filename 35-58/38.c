#include <stdio.h>
long long int fact(long long int n)
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
int main (void)
{
    long long int n;
    scanf("%lld",&n);
    printf("%lld",fact(n));
}
