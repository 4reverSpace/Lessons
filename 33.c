#include <math.h>

int main(void)
{
    int s ;
    scanf("%d",&s);
    for (int i=0;i<=s;i++)
    {
        for (int j=0;j<=s+i;j++)
        {
            printf("%d ",j);
        }
        printf("\n");
    }
}
