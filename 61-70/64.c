#include <stdio.h>

int main() {
    int n,k;
    FILE *file;
    scanf("%d %d",&n,&k);
    int a[n+1][n+1];
    for (int i=0;i<=n;i++)
    {
        a[i][0]=1;
    }
    for (int i=0;i<=n;i++)
    {
        a[0][i]=1;
    }
    for(int i=1;i<=n;i++)
    {
      for (int j=1;j<=k;j++)
      {
            a[i][j]=a[i-1][j]+a[i][j-1];
      }
    }
    file=fopen("answer.txt","w");
    fprintf(file,"%d",a[n-k][k]);
return 0;
}
