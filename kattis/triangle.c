#include <stdio.h>
#include <math.h>

int get_digits(long long );

int main(int argc, char **argv){
    int n, i;
    i = 1;

    while(scanf("%d",&n)!=EOF){
        printf("Case %d:",i++);
        printf(" %d\n",(int) (ceil(log10(3)+n*log10(1.5))));
    }
    return 0;
}
