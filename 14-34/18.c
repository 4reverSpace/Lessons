#include <stdio.h>
#include <math.h>
int main()
{
    double a, b, c = 0.0;
    scanf("%lf %lf %lf",&a, &b, &c);
    double D = b*b - 4*a*c;
    if (a == 0.0)
        printf("Error");
    else
    {
        if (D < 0)
            printf("No x");
        else if (D == 0)
            printf("%lf",-b/(2*a) );
        else
            printf("%lf %lf", (sqrt(D)-b)/(2*a), (-sqrt(D)-b)/(2*a) );
    }
    return (0);
}
