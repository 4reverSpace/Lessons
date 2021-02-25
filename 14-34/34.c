#include <stdio.h>
#include "malloc.h"
int contur(int** array, int iteration, int first, int sizes )
{
    int j = first;
    int i = iteration;
    int k = iteration;
    for (; i < sizes - iteration  ; i++) {
        array[k][i] = j;
        j++;
    }
    i--;
    j--;
    for (; k < sizes - iteration  ; k++) {
        array[k][i]=j;
        j++;
    }
    k--;
    j--;
    for (; i >iteration - 1  ; i--) {
        array[k][i]=j;
        j++;
    }
    i++;
    j--;
    for (; k >iteration  ; k--) {
        array[k][i] = j;
        j++;
    }
    k++;
        return (j);
}

int main() {
    int n;
    scanf("%d", &n);
    int **a = malloc(sizeof(int *) * n);
    for(int i = 0; i < n; i++){
        a[i] = malloc(sizeof(int) * n);
    }
    int i =0 , first = 0 ;
    while ( first < n*n)
    {
     first = contur(a, i, first, n);
     i++;
    }
    for( int i = 0 ; i < n ; i++ )
    {
        for( int j = 0 ; j < n ; j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
