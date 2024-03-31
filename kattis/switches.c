#include <stdio.h>
#include <stdlib.h>

int Switches[1000][1001]; // 0: possible, 1: impossible, [1000]: impossibles
int Lights_on[1000];
int Lights_off[1000];
int Switches_state[1000];
int Used[1000];
int On, Off;

int cmp(const void *a, const void *b){
    int *n1, *n2, result;

    n1 = (int *) a;
    n2 = (int *) b;
    
    result = n2[1000] - n1[1000];

    return result;
}

int main(){
    int n, photos, i, j, cases, count;
    char c;
    long long int result = 1;   

    scanf("%d %d",&n,&photos);

    for (cases=0;cases<photos;cases++){

        On = 0;
        Off = 0;

        for (i=0;i<n;i++){
            while ( (c = getchar()-'0') != 0 && c != 1){
                ;
            }
            Switches_state[i] = c;
        }
        
        for (i=0;i<n;i++){

            while ( (c = getchar()-'0') != 0 && c != 1){
                ;
            }
            
            if (c){
                Lights_on[On++] = i;
            }else{
                Lights_off[Off++] = i;
            }
        }

        for (i=0;i<n;i++){
            if (Switches_state[i]){
                for (j=0;j<Off;j++){
                    if (!Switches[i][Lights_off[j]]){
                        Switches[i][Lights_off[j]] = 1;
                        Switches[i][1000]++;
                    }
                }
            }else{
                for (j=0;j<On;j++){
                    if (!Switches[i][Lights_on[j]]){
                        Switches[i][Lights_on[j]] = 1;
                        Switches[i][1000]++;
                    }
                }
            }
        }
    }

    qsort(Switches,n,sizeof(int[1001]),cmp);
    
    for (i=0;i<n;i++){
        count = 0;
        for (j=0;j<n;j++){
            if (!Switches[i][j]){
                if (count && !Used[j]){
                    count++;
                }else if (!Used[j]){
                    count = 1;
                    Used[j] = 1;
                }
                
            }
        }

        if (!count){
            printf("0\n");
            return 0;
        }

        result = ((result % 1000003) * (count % 1000003)) % 1000003;
    }

    printf("%lld\n",result);

    return 0;
}