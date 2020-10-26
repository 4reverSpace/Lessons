
#include <stdio.h>
#include <math.h>
int simple(int a)
{
    int flag=1;
    for (int i=2;i<=sqrt(a);i++)
    {
        if (a%i==0)
        {
            flag=0;
            break;
        }
    }
    if (a==3 || a==2)
        flag=1;
    return (flag);
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        if (n%i==0&&simple(i))
            printf("%d ",i);
    }
    return(0);
}
