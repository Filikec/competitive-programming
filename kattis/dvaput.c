#include <stdio.h>

char String[200001];
char Matches[24][200000];
long long int Len;


long long int get_max(long long int index1, long long int index2){
    long long int length;

    length = 0;

    while(index2<Len&&String[index1]==String[index2]&&String[index1]&&String[index2]){
        index1++;
        index2++;
        length++;
    }

    return length;
}

int main(){
    long long int i,j,max,maybe;

    scanf("%lld\n",&Len);
    scanf("%s",String);
    
    max = 0;
    
    for (i=0;i<Len;i++){

    }

    printf("%lld\n",max);

    return 0;
}