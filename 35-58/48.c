#include <math.h>
int main()
{

    int n=0,s=0,p=1;
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for (int i=0;i<n;i++)
    {
        s+=a[i];
        p*=a[i];
    }
    printf("%lf - arifm %lf - geom",s*1.0/n,pow(p*1.0,1.0/n));
}
