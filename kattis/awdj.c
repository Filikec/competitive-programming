#include <stdio.h>



void change_to_ten(int *p){
    p = 10;
}


int main(){
    int n, n1;

    n = 5;

    change_to_ten(n);

    printf("%d\n",n);

    return 0;
}