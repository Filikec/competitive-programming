#include <bits/stdc++.h>

using namespace std;

long long MOD = 1e9+7;
long long D1[1000001];
long long D2[1000001];

void work(){
    int n;
    cin >> n;
    cout << D2[n]+D1[n] << '\n';
}


int main(){

    D1[0] = 1;
    D2[0] = 1;
    long long sum1 = 1;
    for (int i=1;i<=1000000;i++){
        D1[i] += sum1;
        D1[i] %= MOD;

        cout << i << ":\n";
        for (int j=2;j<=i;j++){
            D2[i] += D1[i-j]*D1[i]*2-1%MOD + D1[j]*D2[i-j] % MOD;
            D2[i] %= MOD;   
        }

        D2[i] += D2[i-1]*2;
        D2[i] %= MOD;
        sum1 += D1[i];
        sum1 %= MOD;
        cout << i  << " " << D1[i] << " " << D2[i] << '\n'; 
    }



    int t;
    cin >> t;
    while (t--) work();

    return 0;
}