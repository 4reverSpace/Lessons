#include "malloc.h"
#include "stdio.h"

/*int find(int **graph,int size)
{
    int spring = -1, sum = 0;
    for (int i = 0 ; i < size ; i++)
    {
        for(int j = 0 ; j <size ; j++)
            sum+= graph[j][i];

        if(sum == 0) {
            spring = i;
            break;
        }
        sum =0;
    }

    return spring;
}

void top_sort(int** graph,int size , int* array , int last)
{
    int vertex = find(graph, size);
    if (vertex == -1 && last != size)
    {
        printf("Cycle");
        return;
    }
    else
    {
        for (int i = 0; i < size ; i++) {
            graph[vertex][i] = 0;
            graph[i][vertex] = -1;
        }
        array[last]=vertex+1;
        last ++;
        if(last == size)
        {
            printf("Done \n");
            for(int i =0 ; i < size ; i++)
                printf("%d ",array[i]);
            return;
        }
        top_sort(graph , size ,array, last );
        return;
    }
}

int main (){
    int i ;
    scanf("%d",&i);
    int j = i;
    int ** graph = (int**)malloc(sizeof(int*) * i );
    for (int a = 0 ; a < i ;  a++ )
    {
        graph[a] =(int * )malloc(sizeof (int) * j);
        for(int b = 0 ; b < j ; b ++)
        {
            scanf("%d",&graph[a][b]);
        }
    }
    int* array = (int*)malloc(sizeof (int)*i);
    int last = 0 ;
    top_sort(graph, i , array, last);
    free(array);
    for (int a = 0 ; a <i; a++)
        free(graph[a]);
    free(graph);
    return 0;
}
/*из строки в столбец
     1 2 3
    1 0 1 1 -> из 1 в 2 , 3
    2 1 0 1
    3 1 1 0

    можно забить на память и сделать список посщенных вершин, рассматриваемых

 4
 0 1 0 0
 0 0 0 0
 1 0 0 0
 0 1 0 0
 */

/*
void dfs(int** graph , int vertex , int size, int* seen) {
    seen[vertex]--;
    printf("%d ",vertex+1);
    for (int i = 0; i < size; i++) {
        if (graph[vertex][i] && seen[i]) {
            bfs(graph, i, size, seen);
        }
    }
}
int main () {
    int i;
    scanf("%d", &i);
    int **graph = (int **) malloc(sizeof(int *) * i);
    for (int a = 0; a < i; a++) {
        graph[a] = (int *) malloc(sizeof(int) * i);
        for (int b = 0; b < i; b++) {
            scanf("%d", &graph[a][b]);
        }
    }
    int *seen = (int *) malloc(sizeof(int) * i);
    for (int a = 0; a < i; a++)
        seen[a] = 1;
    for (int a = 0 ; a < i ;a ++)
    {
        if(seen[a])
            dfs(graph,a ,i ,seen);
    }
    free(seen);
    for (int a = 0; a < i; a++)
        free(graph[a]);
    free(graph);
    return 0;
} */

void bfs (int ** graph , int vertex ,int size , int * seen, int * stack )
{
    int first_in_stack = 0 ;
    int last_in_stack = 1 ;
    while(last_in_stack!=first_in_stack)
    {
        printf("%d ",stack[first_in_stack]+1);
        first_in_stack++;
        for(int i = 0 ; i <size ; i ++)
        {
            if (graph[vertex][i] && seen[i]){
                seen[i]--;
                last_in_stack++;
                stack[last_in_stack-1] = i;
            }
        }
    }
}
int main ()
{
    int i;
    scanf("%d", &i);
    int **graph = (int **) malloc(sizeof(int *) * i);
    for (int a = 0; a < i; a++) {
        graph[a] = (int *) malloc(sizeof(int) * i);
        for (int b = 0; b < i; b++) {
            scanf("%d", &graph[a][b]);
        }
    }
    int *seen = (int *) malloc(sizeof(int) * i);
    int * stack = (int * ) malloc(sizeof(int) * i);
    for (int a = 0; a < i; a++)
        seen[a] = 1;
    for (int a = 0 ; a < i ;a ++)
    {
        if(seen[a]) {
            stack [0] = a ;
            bfs(graph, a, i, seen, stack);
        }
    };
    free(seen);
    free(stack);
    for (int a = 0; a < i; a++)
        free(graph[a]);
    free(graph);
    return 0;
}
/*
4
0 0 0 1
0 0 1 1
0 1 0 0
1 1 0 0*/
