#include <stdio.h>
#include "malloc.h"
#define inf -2147483648
int min_n(int a , int b)
{
    if (a < b)
        return a;
    else
        return b;
}
int max_n(int a , int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int min(int* array, int start, int size)
{
    if (start >= size)
        return inf;
    int minimum = start;
    for (int i = start+1 ; i < size ; i++)
    {
        if (array[i] < array[minimum]) {
            minimum = i;
        }
    }
    int ans = array[minimum];
    array[minimum]^=array[start]^=array[minimum]^=array[start];
    return ans;
}
int main() {
    int len_a , len_b;
    scanf("%d", &len_a);
    scanf("%d", &len_b);
    int litle = min_n(len_a, len_b);
    int big = max_n(len_a, len_b);

    int* less = malloc(sizeof (int)*len_a);
    for (int i = 0 ; i < len_a; i++)
        scanf("%d", &less[i]);
    int* bigger = malloc(sizeof (int)* len_b);
    for (int i = 0 ; i < len_b; i++)
        scanf("%d", &bigger[i]);
    if ( len_a > len_b) {
        int* a =less;
        less = bigger;
        bigger = a;
    }
    int* answer = malloc(sizeof (int)*(litle+big));
    for (int i = 0 ; i < litle ; i++)
    {
        int a = min(less, i, litle );
        int b = min(bigger, i, big );
        answer[2*i]=min_n(a,b);
        answer[2*i+1]=max_n(a,b);
    }
    for ( int i = litle ; i < big ; i++)
    {
        answer[litle + i] = min(bigger,i,big);
    }
    for ( int i= 0 ; i < litle + big ; i++)
    {
        printf("%d ", answer[i]);
    }
    free(less);
    free(bigger);
    free(answer);
    return 0;
}
