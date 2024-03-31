#include <stdio.h>


/// scores from 1 to 20
// double, triple

void print_score(int n, int j){
    if (j == 1){
        printf("single %d\n",n);
    }else if (j==2){
        printf("double %d\n",n);
    }else{
        printf("triple %d\n",n);
    }
}

int main(){
    int score, i,i1, j, j1, k, k1, n, c = 0;

    scanf("%d",&score);

    if (score == 1){
        printf("single 1\n");
        return 0;
    }else if(score == 2){
        printf("single 2\n");
        return 0;
    }
    
    for (i=1;i<21;i++){
        for (i1=1;i1<4;i1++){
            for (j=1;j<21;j++){
                for (j1=1;j1<4;j1++){
                    for (k=1;k<21;k++){
                        for (k1=1;k1<4;k1++){
                            if (i*i1 + j*j1 + k*k1 == score){
                                print_score(i,i1);
                                print_score(j,j1);
                                print_score(k,k1);
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }

    printf("impossible\n");

    return 0;

}