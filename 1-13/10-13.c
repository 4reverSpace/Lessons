#include <stdio.h>
#include <math.h>

int Knight(int a, int b, int c, int d){
    if((abs(a-c)==1 && abs(b-d)==2)||(abs(a-c)==2 && abs(b-d)==1) )
        return 1;
    else
        return 0;
}

int Bishop(int a, int b, int c, int d){
    if(abs(a - c) == abs(b - d)){
        return 1;
    }
    else{
        return 0;
    }
}

int Rook(int a, int b, int c, int d){
    if(abs(b - d) == 0 || abs(a - c) == 0){
        return 1;
    }
    else{
        return 0;
    }
}

int main()
{
    int b, d, v, t;
    char a, c, space, fig;
    scanf("%c%d%c%c%d%c%c", &a, &b, &space, &c, &d, &space, &fig);
    a = a - 'a' + 1;
    c = c - 'a' + 1;
    if(fig == 'K')
    {
        if(Knight(a, b, c, d)){
            printf("Yes");
        }
        else{
            printf("No");
        }
    }
    else if(fig == 'B'){
        if(Bishop(a, b, c, d)){
            printf("Yes");
        }
        else{
            printf("No");
        }
    }
    else if(fig == 'R'){
        if(Rook(a, b, c, d)){
            printf("Yes");
        }
        else{
            printf("No");
        }
    }
    else{
        if(Bishop(a, b, c, d) || Rook(a, b, c, d)){
            printf("Yes");
        }
        else{
            printf("No");
        }
    }
    return(0);
}

