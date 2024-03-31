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
    for (int i=0;i<=x;i++){
        for (auto c : v){
            if (i+c <= x) D[i+c] += D[i]>0, D[i+c] %= MOD;
        }
    }

    cout << D[x] << '\n';

    return 0;
}