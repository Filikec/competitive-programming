#include <stdio.h>



int main(){
    char s1[4],s2[4];
    int n1=0,n2=0;

    scanf("%s %s",s1,s2);

    for (int i=0;i<3;i++){
        n1 = n1*10+(s1[2-i]-'0');
        n2 = n2*10+(s2[2-i]-'0');
    }

    printf("%d\n",n1>n2?n1:n2);

    return 0;
}