#include <bits/stdc++.h>

using namespace std;

int D[100001];

int main(){
    int n,x;
    cin >> n >> x;
    vector<int> a(n),b(n);
    for (auto &c : a) cin >> c;
    for (auto &c : b) cin >> c;
    
    D[x]=0;
    int most = 0;
    for (int i=0;i<n;i++){
        for (int j=0;j+a[i]<=x;j++){
            D[j] = max(D[j],D[j+a[i]]+b[i]);
            most = max(most,D[j]);
        }
    }

    cout << most << '\n';

    return 0;
}