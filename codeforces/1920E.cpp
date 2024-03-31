#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 998244353;

ll D[10000][10000];

void work(){
    int n,k;
    cin >> n >> k;

    D[1][0] = 1;
    D[0][1] = 1;
    for (int i=2;i<=n;i++){
        D[i][0]=0;
        for (int j=0;j<k&&i-j-1>=0;j++) D[i][0] += D[i-1-j][j];
        D[i][0] %= MOD; 
        for (int j=1;j<k;j++) D[i][j] = D[i-1][j-1];
    }

    for (int i=0;i<=n;i++){
        for (int j=0;j<k;j++){
            cout << i << ' ' << j << ' ' << D[i][j] << '\n';
        }
    }

    ll sum = 0;
    for (int i=0;i<k;i++){
        sum += D[n][i];
        sum %= MOD;
    }
    cout << sum << '\n';
}


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) work();


    return 0;
}