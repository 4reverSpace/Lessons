#include <math.h>

int main(void)
{
    int s =1;
    int a;
    scanf("%d",&a);
    for (int i=1;i<=a;i++)
    {
        for (int j=1;j<=a;j++)
        {
            printf("%d  ",s);
            s+=1;
        }
        printf("\n");
    }
}
