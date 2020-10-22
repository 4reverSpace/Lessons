#include <stdio.h>

int main(void)
{
    long int a,b;
        char sp;
    scanf("%ld%c%ld%c",&a,&sp,&b,&sp);
    int c[a],max,s;
    for (long int i=0;i<a;i++)
    {
        scanf("%d%c",&max,&sp);
        c[i]=max;
    }
    max=0;
    s=0;
    for (long int i=0;i<(a-b+1);i++)
    {
        for (long int j=i;j<(i+b-1);i++)
            s+=c[j];
        if (s>max)
            max=s;
    }
    printf("%ld",max);
}
