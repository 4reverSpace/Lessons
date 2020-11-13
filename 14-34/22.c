#include <stdio.h> // пожалуйста, не проверяйте пока, написано с помощью костылей
#include <malloc.h>
int pow(int a)
{
	return(a * a);
}
int* Massive(int* b,int a)
{
	int* f = (int*)malloc(sizeof(int) * a);
	for (int i = 0; i < a ; i++)
	{
		int d = 0;
		for (int j = 0; j < 10; j++)
		{
			if (i-9+j >= 0 && i-9+j<=a-10)
				d += *(b + i-9+j);
		}
		*(f+i)=d;
	}
	return(f);
}
int main()
{
	int n,num=10;
	int* l;
	scanf_s("%d", &n);
	int sum = 0;
	int* b = (int*)malloc(sizeof(int) * 10);
	for (int i = 0; i < 10; i++)
	{
		*(b + i) = 1;	

	}
	for (int i = 0; i < (n / 2 - 1); i++)
	{
		num += 9;
		l=Massive(b,num);
		b = (int*)realloc(b, sizeof(int) * num);
		for (int i = 0; i < num; i++)
			*(b + i) = *(l + i); 
	}
	for (int i = 0; i < num; i++)
	{
		sum+=(*(b+i))*(*(b+i));
	}
	printf("%d ", sum);
	free(b);
}
