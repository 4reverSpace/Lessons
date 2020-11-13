int main()
{
    int d,m,y,d1,m1,y1,s=0;
    printf("Date one dd.mm.yyyy\nDate two dd.mm.yyyy\n");
    scanf("%d.%d.%d",&d,&m,&y);
    scanf("%d.%d.%d",&d1,&m1,&y1);
    int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int a1[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if ((y%100!=0 && y%4==0)||y%400==0)
        a[1]++;
    if ((y1%100!=0 && y1%4==0)||y1%400==0)
        a1[1]++;
    for (int i=y;i<y1;i++)
    {
        if ((i%100!=0 && i%4==0)||i%400==0){
            s+=366;}
        else{
            s+=365;}
    }
    for (int i=0;i<m-1;i++)
        s-=a[i];
    for(int i=0;i<m1-1;i++)
        s+=a1[i];
    s+=-d+d1;
    printf("%d",s);
}
