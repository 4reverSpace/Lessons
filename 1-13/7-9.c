#include <stdio.h>
int main()

    int a,b;
    scanf("%d %d",&a,&b);
    if (a>b)
        printf("%d",a);
    else
        printf("%d",b);
    return(0);
}

    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if (a<b)
        a=b;
    if (a>c)
        printf("%d",a);
    else
        printf("%d",c);
    return(0);
}

{
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    if (a<b)
        a=b;
    if (a<c)
        a=c;
    if (a>d)
        printf("%d",a);
    else
        printf("%d",d);
    return(0);
}
