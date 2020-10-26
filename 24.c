#include <math.h>

int main(void)
{
    int a=1;
    for (int i=3;a<=100;i+=2)
    {
        printf("%d  ",a);
        a+=i;
    }

}
