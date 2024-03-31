#include <stdio.h>

int dec_to_bin(int);
int bin[32];

int main(int argc, char **argv){
    int dec,n,i,len;
    scanf("%d %d",&dec,&n);

    len = dec_to_bin(dec);
    
    if (n){
        for (i=0;i<n-len;i++){
            printf("0");
        }
    }
    
    for (--len;len>=0;len--){
        printf("%c",bin[len]);
    }
    printf("\n");

    return 0;
}

int dec_to_bin(int n){
    int dec,i;

    dec = n;
    i = 0;

    while (dec){
        bin[i++] = dec%2==1?'1':'0';
        dec /= 2;
    }

    return i;
}