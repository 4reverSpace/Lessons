int main(void)
{
     int a,b,n ;// n- до какого числа выводить
     scanf("%d %d %d",&a,&b,&n);
     if (n<=0)          // проверка счетчика
        printf("Error");
     else if (n==1)
        printf("%d",a);
     else if (n==2)
        printf("%d",b);
     else
     {
        printf("%d %d ",a,b);
        for (int i=2;i<=n;i++)
        {
            b+=a;
            a=b-a;
            printf("%d ",b);
        }
     }
}

