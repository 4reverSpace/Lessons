#include <stdio.h>
#include <math.h>

int main(void) {
    int n,ind=-1;
    scanf("%d",&n);
    int c=ceil(log2(n));
    int a[c];
    for (int i=1;i<=sqrt(n);i++){
        if (n%i==0)
        {
            ind ++;
            a[ind]=i;
            printf("%d ",i);
        }
    }
    if(sqrt(n)==a[ind])
        ind--;
    for (int j=ind;j>=0;j--)
        printf("%d ",n/a[j]);
    return 0;
}
