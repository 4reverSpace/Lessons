#include <stdio.h>
int main()
{
    double a,b,c;
    scanf("%lf %lf %lf",&a,&b,&c);
    if (a+b>c && a+c>b && b+c>a)
    {
        if (a==b && b==c)
            printf("Equilateral triangle");
        else
        {
            if (a==b || a==c || b==c)
                printf("Isosceles ");
            if (a*a+b*b>c*c && a*a+c*c>b*b && b*b+c*c>a*a)
                printf("Acute triangle(<90 deg)");
            else if (a*a+b*b<c*c && a*a+c*c<b*b && b*b+c*c<a*a)
                printf("Obtuse triangle(>90 deg)");
            else
                printf("Right triangle(=90 deg)");
        }
    }
    else
        printf("Does not exist");
        return(0);
}
