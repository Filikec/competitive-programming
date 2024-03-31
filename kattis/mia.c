#include <stdio.h>

char Read[4];
int Throws[4];
int Asters;
int Possibilities;

void possible(){
    for (i=0;i<4;i++){
        if (Throws[i] == -6){
            Asters++;
        }
    }
}


int main(){

    scanf("%c %c %c %c",&Read[0],&Read[1],&Read[2],&Read[3]);//-6

    for (int i=0;i<4;i++){
        Throws[i] = Read[i]-'0';
    } 



    return 0;
}