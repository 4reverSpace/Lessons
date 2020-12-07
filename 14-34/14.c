#include <stdio.h>
void swap(double a,double b)
{
    double *i=&a,*j=&b;
    *i=*i + *j;
    *j=*i-*j;
    *i=*i - *j;
}
int main()
{
    double a,b,c;
    scanf("%lf %lf %lf",&a,&b,&c);
     if (b>a && b>c)
        swap(a,b);
    else if(c>a && c>b)
        swap(a,c);
    if (a<b+c)
    {
        if (a==b && b==c)
            printf("Equilateral triangle");
        else
        {
            if ( b==c)
                printf("Isosceles ");
            if (b*b+c*c>a*a)
                printf("Acute triangle(<90 deg)");
            else if (b*b+c*c<a*a)
                printf("Obtuse triangle(>90 deg)");
            else
                printf("Right triangle(=90 deg)");
        }
    }
    else
        printf("Does not exist");
    return(0);
}
