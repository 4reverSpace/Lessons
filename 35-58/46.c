int main()
{
    long long int a[63]={1};
    for (int i=1;i<63;i++)
        a[i]=a[i-1]*2;
    for (int i=0;i<63;i++) //вывод массива
        printf("%lld\n" ,a[i]);
}
