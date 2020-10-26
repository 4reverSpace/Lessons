#include <stdio.h>
int main()

{
    int n=0;
    for(int a = 0 ; a < 1000000 ; a++)
        if (a/100000 + (a/10000)%10 + (a/1000)%10 == (a/1000)/100 + (a%100)/10 + a%10)
            n+=1;
    printf("%d",n);
    return (0);
}
