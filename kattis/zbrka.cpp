#include <iostream>

using namespace std;

#define MOD 1000000007


long long D[1001][10001],S[1001][10001];

int main(){
    int n,c;

    cin >> n >> c;

    for (int i=1;i<=n;i++) D[i][0] = S[i][0] = 1;
    for (int i=0;i<=c;i++) S[1][i] = 1;

    for (int i=2;i<=n;i++){
        for (int j=1;j<=c;j++){
            if (j-i>=0) D[i][j] = (S[i-1][j]-S[i-1][j-i]+MOD)%MOD;
            else D[i][j] = S[i-1][j];
            S[i][j] = (S[i][j-1]+D[i][j])%MOD;
        }
    }
    cout << D[n][c] << '\n';
}