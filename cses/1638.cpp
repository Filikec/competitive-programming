#include <bits/stdc++.h>

using namespace std;

int MOD = 1e9+7;
char G[1000][1000];
int D[1001][1001];

int main(){
    int n;
    cin >> n;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            cin >> G[i][j];
    
    D[0][0] = 1;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            if (G[i][j] != '*') D[i][j] %= MOD, D[i+1][j] += D[i][j], D[i][j+1] += D[i][j];
            else D[i][j] = 0;
    

    cout << D[n-1][n-1] << '\n';

    return 0;
}