#include <stdio.h>
#include <malloc.h>

int main() {
  int*a=(int*)malloc(sizeof(int));
  char*c=(char*)malloc(sizeof(char)*4);
  c=(char*)a;
int a0;
scanf("%d",&a0);
int a1,a2,a3;
a1=a0/16777216;
a0-=a1*16777216;
a2=a0/65536;
a0-=a2*65536;
a3=a0/256;
a0-=a3*256;
printf("%d  %d  %d  %d ",a1,a2,a3,a0);
*c=a0;
*(c+1)=a3;
*(c+2)=a2;
*(c+3)=a1;
printf("%d",*a);
return 0;
}
// 0-1 ;1- 256  ; 2- 65536 ; 3-  16777216
