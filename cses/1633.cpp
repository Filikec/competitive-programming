#include <bits/stdc++.h>

using namespace std;

long long MOD = 1e9+7;


int D[1000001];


int main(){

    int n;
    cin >> n;

    D[0] = 1;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=6;j++) if (i-j >= 0) D[i] += D[i-j], D[i] %= MOD;
    }
    cout << D[n] << '\n';

    return 0;
}