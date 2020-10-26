#include <math.h>

int main(void)
{
    int a=1;
    for (int i=1;a<=100;i+=1)
    {
        printf("%d  ",a);
        a+=a-(a-1)*(i%2);
    }

}
