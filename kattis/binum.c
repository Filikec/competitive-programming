#include <stdio.h>
#include <math.h>

typedef struct bignum{
    int num[100];
    int length;
} BigNum;

BigNum Num;

void print_bignum(BigNum *n){
    for (int i =0; i<n->length;i++){
        printf("%d",n->num[i]);
    }
}
void read_bignum(BigNum *num){
    char c;
    c=getchar()-'0';
    while (c>=0 && c<10){
        num->num[num->length++] = c;
        c=getchar()-'0';
    }
}

int divide_bignum(BigNum *n, long long int div){
    long long int dividing = 0, i = 0, ni = 0, last = 0,divided = 0;
    int new_num[100];
    
    while (divided == 0 && i<n->length){
        dividing = dividing*10 + n->num[i++];
        divided = dividing/div;
    }
    
    new_num[ni] = divided;
    dividing -= new_num[ni]*div;
    ni++;

    while (i<n->length){
        dividing = dividing*10 + n->num[i++];
        divided = dividing/div;
        new_num[ni] = divided;
        dividing -= new_num[ni]*div;
        ni++;
    }
    if (dividing){
        return 0;
    }

    for (i=0;i<ni;i++){
        n->num[i] = new_num[i];
    }
    n->length = ni;

    return 1;
}

int is_prime(long long int n){
    long long int i, sqr;

    sqr = (long long int) sqrt((double)n)+1;

    for (i=2;i<sqr;i++){
        if (n%i == 0){
            return 0;
        }
    }

    return 1;

}

int main(){
    long long int i,count, flag = 0;

    Num.length = 0;

    read_bignum(&Num);


    printf("Prvociselny rozklad cisla ");
    print_bignum(&Num);
    printf(" je:\n");
    for (i=2;i<=1000000;i++){
        if (is_prime(i)){
            count = 0;
            while (divide_bignum(&Num,i)){
                count++;
            }
            if (count){
                if (flag){
                    printf("* ");
                }
                if (count>1){
                    printf("%lld^%lld ",i,count);
                }else{
                    printf("%lld ",i);
                }
                
                flag = 1;
            }
        }
    }

    printf("\n");
   

    return 0;
}