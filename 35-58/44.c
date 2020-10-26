int main()
{
    int a[100];
    for (int i=1;i<=100;i++)
        a[i-1]=2*i;
    for (int i=0;i<100;i++) //вывод массива
        printf("%d\n" ,a[i]);
}
