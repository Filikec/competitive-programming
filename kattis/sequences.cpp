#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int main(){

    char c;
    long long count = 0, left = 0, prev_pow = 0, power = 1, times = 0;
    while ((c = getchar())!='\n'){
        if (c == '1'){
            left++;
        }else{
            if (c == '?'){
                count *= 2;
                count %= MOD;
                count += ((prev_pow*times)%MOD+(left*power)%MOD)%MOD;
                count %= MOD;
                prev_pow = power;
                power *= 2;
                power %= MOD;
                times++;
            }else{
                count += ((prev_pow*times)%MOD+(left*power)%MOD)%MOD;
                count %= MOD;
            }
        }
    }

    cout << count << '\n';



    return 0;
}