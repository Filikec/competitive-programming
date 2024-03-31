#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    unsigned long int n, i, diff, count, s;

    while (scanf("%lud",&n) == 1){
        count = 0;
        s = (unsigned long int) sqrt(n);
        
        for (i=2;i<=s;i++){
            if (!(n%i)){
                count += i;
                
                if (i != n/i){
                    count += n/i;
                    
                }
            }
        }
        
        diff = abs(count+1 - n);
        
        if (!diff){
            printf("%lu perfect\n",n);
        }else if (diff <= 2){
            printf("%lu almost perfect\n",n);
        }else{
            printf("%lu not perfect\n",n);
        }
    }

    return 0;
}
