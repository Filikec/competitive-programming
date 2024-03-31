#include <bits/stdc++.h>

using namespace std;

long long MOD = 1e9+7;


int D[1000001];


int main(){

    int n,x;
    cin >> n >> x;

    for (int i=1;i<=x;i++) D[i] = 1e9;
    D[0] = 0;

    for (int i=0;i<n;i++){
        int c;
        cin >> c;
        for (int i=c;i<=x;i++) D[i] = min(D[i],D[i-c]+1);
    }
    if (D[x] == 1e9) cout << "-1\n";
    else cout << D[x] << '\n';

    return 0;
}