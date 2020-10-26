#include <math.h>

int main(void)
{
    int s ;
    int a;
    scanf("%d %d",&a,&s);
    for (int i=1;i<=a;i++)
    {
        for (int j=0;j<=s;j++)
        {
            printf("%d ",s-s*(i%2)+(-1+2*(i%2))*j);
        }
        printf("\n");
    }
}
