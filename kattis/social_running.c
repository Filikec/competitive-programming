#include <stdio.h>

int Ppl[10000];


int main(){
    int cases,distance,min;

    scanf("%d",&cases);
    
    for (int i=0;i<cases;i++){
        scanf("%d",&Ppl[i]);
    }

    min = 20000;

    for (int i=0;i<cases;i++){
        distance = Ppl[i] + Ppl[(i-2+cases)%cases];
        if (min > distance){
            min = distance;
        }
    }

    printf("%d\n",min);

    return 0;
}
