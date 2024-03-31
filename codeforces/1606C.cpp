#include <bits/stdc++.h>

using namespace std;


typedef long long ll;

void work(){
    int n;
    cin >> n;
    vector<ll> v(2*n);
    for (auto &c : v) cin >> c;
    sort(v.begin(),v.end());
    ll s=0;
    for (int i=0;i<2*n;i+=2) s += v[2*n-1-i-1];
    cout << s << '\n';
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) work();

    return 0;
}