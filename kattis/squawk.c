#include <stdio.h>

long long Relations[101][101]; //starts from one
long long Squawks1[101]; //start
long long Squawks2[101]; //after
long long users;
long long Sent;

void send_squawks(long long n){
    for (long long i=0;i<users;i++){
        if (Relations[n][i]){
            Squawks2[i]+=Squawks1[n];
            Sent+=Squawks1[n];
        }
    }
}

void next_step(){
    Sent = 0;
    for (long long i=0;i<users;i++){
        if (Squawks1[i]){
            send_squawks(i);
        }
    }

    for (long long i=0;i<users;i++){
        Squawks1[i] = Squawks2[i];
        Squawks2[i] = 0;
    }
}

long long main(){
    long long links,initial,minutes,n1,n2;

    scanf("%lld %lld %lld %lld",&users,&links,&initial,&minutes);

    for (long long i=0;i<links;i++){
        scanf("%lld %lld",&n1,&n2);
        Relations[n1][n2] = 1;
        Relations[n2][n1] = 1;
    }

    Squawks1[initial] = 1;

    for (long long i=0;i<minutes;i++){
        next_step();
    }


    printf("%lld\n",Sent);



    return 0;
}