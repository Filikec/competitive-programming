#include <bits/stdc++.h>

using namespace std;    

long long MOD = 1000000007;
long long D[200001][202];   

int main(){
    long long n,x;
    cin >> n >> x;
    vector<long long> a(n);
    for (int i=0;i<n;i++) cin >> a[i];

    if (!a[0]) for (int i=1;i<=x;i++) D[0][i]++;
    else D[0][a[0]]++;

    for (int i=1;i<n;i++){
        if (a[i]){
            D[i][a[i]] += D[i-1][a[i]-1] + D[i-1][a[i]+1] + D[i-1][a[i]];
            D[i][a[i]] %= MOD;
            continue;
        }
        for (int j=1;j<=x;j++){
            D[i][j] += D[i-1][j-1]+D[i-1][j+1]+D[i-1][j];
            D[i][j] %= MOD;
        }
    }

    long long most = 0;
    for (int i=1;i<=x;i++) most += D[n-1][i], most %= MOD;
    cout << most << '\n';

    return 0;
}