#include <stdio.h>

void swap_array(int* a, int n1,n2)
{
  if (n1<0 || n2<0)
  exit(1); 
  else
  a[n1]^=a[n2]^=a[n1]^=a[n2];

}

int swap_numbers(int* a,int* b )
{
  *a^=*b^=*a^=*b;
}

int main() {
int a=2;
int b=10;
printf("a=%d b=%d\t",a,b);
swap_numbers(&a,&b);
printf("a=%d b=%d\n",a,b);
int c[3]={1,2,3};
printf("%d,%d,%d\t",c[0],c[1],c[2]);
swap_array(c, 1, 2);
printf("%d,%d,%d",c[0],c[1],c[2]);
return 0;
}
