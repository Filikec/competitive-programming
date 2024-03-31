#include <stdio.h>

int knights[20001];
int heads[20001];

void doom(void);
void get_result(int,int);

int main(int argc, char **argv){
    int h, k, i;

    scanf("%d %d",&h,&k);

    while (h != 0 && k != 0){

        get_result(h,k);

        for (i=0;i<20001;i++){
            knights[i] = 0;
            heads[i] = 0;
        }

        scanf("%d %d",&h,&k);
    }

    return 0;
}


void doom(){
    printf("Loowater is doomed!\n");
}

void get_result(int h,int k){
    int i, cent, max_h, max_k, j, knights_n;
    long money = 0; 

    max_h = 0;
    max_k = 0;


    for (i=0;i<h;i++){
        scanf("%d",&cent);
        if (cent > max_h){
            max_h = cent;
        }
        heads[cent] += 1;
    }

    for (i=0;i<k;i++){
        scanf("%d",&cent);
        if (cent > max_k){
            max_k = cent;
        }
        knights[cent] += 1;
    }

    if (k<h){
        doom();
        return;
    }

    if (max_h>max_k){
        doom();
        return;
    }
    
    
    for (i=0;i<=max_h;i++){
        if (heads[i]==0){
            continue;
        }
        for (j=i;j<=max_k;j++){
            knights_n = 0;
            if (knights[j] != 0){
                knights_n += knights[j]>heads[i]?heads[i]:knights[j];
                heads[i] -= knights_n;
                knights[j] -= knights_n;
                money += knights_n*j;
                if (!heads[i]){
                    break;
                }
            }
        }
        if (heads[i]){
            doom();
            return;
        }

    }
    printf("%ld\n",money);

}