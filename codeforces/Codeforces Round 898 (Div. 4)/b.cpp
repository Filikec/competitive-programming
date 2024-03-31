#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;


void work(){
    ll n;
    cin >> n;
    vector<ll>v(n);
    for (auto &c : v) cin >> c;
    ll best = 0;
    for (int i=0;i<n;i++){
        ll p=1;
        for (int j=0;j<n;j++) if (i!=j) p *= v[j];
        best = max(best,p*(v[i]+1));
    }
    cout << best << '\n';

}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) work();

    return 0;   
}