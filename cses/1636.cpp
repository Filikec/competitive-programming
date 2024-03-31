#include <bits/stdc++.h>

using namespace std;

int MOD = 1e9+7;
int D[1000001];


int main(){

    int n,x;
    cin >> n >> x;
    vector<int> v(n);
    for (auto &c:v) cin >> c;
    D[0]=1;
    sort(v.begin(),v.end());

    for (auto c : v){
        for (int i=c;i<=x;i++){
            D[i] += D[i-c];
            D[i] %= MOD;
        }
    }

    cout << D[x] << '\n';

    return 0;
}