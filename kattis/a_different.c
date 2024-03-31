#include <stdio.h>
#include <math.h>

long Count;
long long N;
long long primes[60];
int quantity[3660];
int I;
int J=-1;
int Ii;


void get_primes(long long);
int get_amount(int, long int *);


int main(int argc, char **argv){
    long i;
    long long n_current, n_last;

    scanf("%lld",&N);

    get_primes(N);

    n_last = -1;
    
    for (i=0;i<I;i++){
        n_current = primes[i];
        printf("%lld ",primes[i]);

        if (n_current!=n_last){
            J++;
        }

        quantity[J] += 1;
    
        n_last = n_current;
    }
    printf("\n");


    Count = get_primes_count(++J);


    printf("%ld\n",Count==0?1:Count);

    return 0;
}

int get_amount(int n, long int *edge){
    int i = 0;
    int an = 1;
    int ani = 0;
    while (n >= an){
        i++;
        ani = an + i + 1;
        an = ani;

    }
    *edge = ani - i - 1;
    return i;
}

void get_primes(long long n){
    int i;

    for (i=2; i<=sqrt(n); i++){
        if (n%i == 0){
            get_primes(i);

            get_primes(n/i);
                

            return;
        }
    }
    if (n!=N){
        primes[I++] = n;
    }   
}


int get_primes_count(int size){
    long edge, target_edge, count;
    int i, j, no_others, new_size, nomo;
    int new_quantity[3660];

    count = 0;
    new_size = 0;

    for (i=0;i<size;i++){
        new_quantity[i] = 0;
        
    }

    for (i=0;i<size;i++){
        count += get_amount(quantity[i],&edge);
        printf("%d %d<\n",get_amount(quantity[i],&edge),quantity[i]);
    }
    for (i=0;i<size;i++){   
        if (!quantity[i])
            continue;
            
        while (1){
            nomo = 0;
            no_others = 1;

            get_amount(quantity[i],&edge);
            

            for (j=i+1;j<size;j++){
                if (quantity[i] - edge < 1){
                    nomo = 1;
                    break;
                }
                get_amount(quantity[j],&target_edge);
                if (quantity[j] - target_edge > 0){
                    no_others = 0;
                    quantity[j]--;
                    quantity[i]--;
                    new_quantity[((i)*(size-1)+j)] += 1;
                    if (((i)*(size-1)+j)>new_size){
                        new_size = ((i)*(size-1)+j);
                    }
                }
            }

            if (no_others || nomo){
                break;
            }
        }
    }
    ++new_size;

    for (i=0;i<new_size;i++){
        quantity[i] = new_quantity[i];
        printf("%d ",quantity[i]);
    }
    printf("\n");
    
    count += new_size>1?get_primes_count(new_size):0;

    return count; 
}