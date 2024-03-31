#include <stdio.h>
#include <string.h>

typedef struct person{
    long long int restarted;
    long long int money;
} Person;

Person People[1000001]; //0 root

void restart(long long int money){
    Person *root;

    root = &People[0];

    root->money = money;
    root->restarted++;
}

void print(long long int n){
    Person *peep, *root;

    peep = &People[n];
    root = &People[0];

    if (peep->restarted <= root->restarted){ // wasnt set
        printf("%lld\n",root->money);
    }else{
        printf("%lld\n",peep->money);
    }
    
}

void set(long long int n, long long int money){
    Person *peep, *root;

    peep = &People[n];
    root = &People[0];
    peep->money = money;

    if (peep->restarted <= root->restarted){ //wasnt set
        peep->restarted = root->restarted+1;
    }
}

int main(){
    long long int n, q, i,a1,a2;
    char string[500];

    scanf("%lld %lld",&n,&q);

    for (i=0;i<q;i++){
        scanf("%s",string);
        if (!strcmp("PRINT",string)){
            scanf("%lld",&a1);
            print(a1);
        }else if (!strcmp("SET",string)){
            scanf("%lld %lld",&a1,&a2);
            set(a1,a2);
        }else{
            scanf("%lld",&a1);
            restart(a1);
        }
    }

    return 0;
}