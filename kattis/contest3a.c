#include <stdio.h>

char string[100];


int main(){
    int n,sum,l,c;
    sum  = 0;
    l = 0;

    while (scanf("%s",string) == 1){
        sum += n;
        l++;
    }

    for (int i=0;i<l;i++){
        if (sum-nums[i] == nums[i]){
            printf("%lld\n",nums[i]);
        }
    }
    

    return 0;
}