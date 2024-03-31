#include <bits/stdc++.h>

using namespace std;

int MOD = 1e9+7;
int D[1000001];


int main(){

    int n;
    cin >> n;


    for (int i=1;i<=n;i++){
        D[i] = 1e9;
        string ds = to_string(i);
        for (auto c : ds){
            int d = c-'0';
            D[i] = min(D[i],D[i-d]+1);
        }
    }
    cout << D[n] << '\n';

    return 0;
}