#include <stdio.h>
int main()
{
    for (int i =1; i <= 100;i++)
    {
        if (i%3!=0 && i%5!=0)
            printf("%d",i);
        else
        {
            if (i%3==0)
                printf("FIZZ");
            if (i%5==0)
                printf("BUZZ");
        }
        printf("\n");
    }
    return (0);
}
