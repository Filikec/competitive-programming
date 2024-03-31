#include <stdio.h>


long long int factorial(int c){
    if (!c)
        return 1;
    return factorial(c-1)*c;
}

long long int combination(int up, int down){
    long long int upper = 1, i;

    if (up <= 0 || down <=0)
        return 0;

    for (i=up;i>up-down;i--){
        upper *= i;
    }
    
    return upper/factorial(down);
}

long long int impossible(int n, int m, int cannons){
    long long int columns, rows, diagonals, dia_n;

    columns =  n*combination(m,3)*combination(m*n-3,cannons-3);
    rows = m*combination(n,3)*combination(m*n-3,cannons-3);
    diagonals = dia_n*combination()
}

int main(){
    int n,m;

    scanf("%d %d",&n,&m);

    printf("%d %d %lld\n",n,m,combination(2,2));
    

    return 0;
}