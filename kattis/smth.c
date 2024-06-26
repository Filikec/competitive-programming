#include <stdio.h>
#include <math.h>

int is_prime(int n){
    int sqr;

    sqr = sqrt(n) + 1;

    for (int i=2;i<sqr;i++){
        if (n%i==0){
            return 0;
        }
    }

    return 1;
}


int main(){
    int n;

    scanf("%d",&n);

    if (is_prime(n)){
        printf("%d is a prime\n",n);
    }else{
        printf("%d is not a prime\n",n);
    }

    return 0;
}