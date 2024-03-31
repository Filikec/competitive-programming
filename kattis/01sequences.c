#include <stdio.h>
#include <math.h>

#define MOD 1000000007

long long int Twopow = 1; // 2^Possible_n
long long int Twopow_minus = 0; // Two^(Possible_n-1)
long long int Possible_n = 0; // How many ?'s
long long int Ones = 0; // How many ones in the string so far
long long int Sum = 0;

long long int possible(){
    long long int x;
    x = (int) ((((Twopow_minus*Possible_n)%MOD) + ((Twopow*Ones)%MOD) )%MOD);
    return x;
}

int main(){
    char c;
    int flag = 0;

    while ((c = getchar())){
        if (c == '?'){
            Sum = (2*Sum + possible())%MOD;
            Possible_n++;
            Twopow = (Twopow*2)%MOD;
            if (!flag){
                Twopow_minus = 1;
                flag = 1;
            }else{
                Twopow_minus = (Twopow_minus*2)%MOD;
            }
        }else if (c == '1'){
            Ones++;
        }else if (c == '0'){
            Sum = (Sum + possible())%MOD;
        }else{
            printf("%lld\n",Sum);
            return 0;
        }
    }

    return 0;
}