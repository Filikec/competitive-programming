#include <iostream>
#include <cmath>

using namespace std;

double Digits[1000001];

int main(){
    long int n;

    Digits[0] = 1;

    for (int i=1;i<1000001;i++){
        Digits[i] = log10(i)+Digits[i-1];
    }

    while (scanf("%ld",&n)==1){
        printf("%d\n",(int)Digits[n]);
    }

    return 0;
}