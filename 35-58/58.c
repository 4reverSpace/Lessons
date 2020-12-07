#include "stdio.h"
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++)
        a[i]=i+1;
    for (int i=1;i<n;i++)
    {
        if (a[i])
        {
            for(int h=i+1;h<n;h++){
                if (a[h]%a[i]==0 )
                    a[h]=0;
            }
            printf("%d ",a[i]);
        }
    }
    return(0);
}
