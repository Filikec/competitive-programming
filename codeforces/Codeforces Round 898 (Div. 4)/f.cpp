#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

void work(){
    ll n,m;
    cin >> n >> m;
    vector<ll> h(n),f(n);
    for (auto &c : f) cin >> c;
    for (auto &c : h) cin >> c;

    vector<ll> v(n);
    for (int i=0;i<n-1;i++) v[i] = h[i]%h[i+1]==0;
    v[n-1] = 0;

    ll sum = 0;
    ll best = 0;
    ll cur = 0;
    for (int i=0;i<n;i++){
        sum += f[i];

        if (!v[i]){
            if (!cur){
                sum = 0;
            }else{
                if (sum <= m) best = max(best,cur+1);
                sum = 0;
                cur = 0;
            }
        }else{
            cur++;
            while (sum > m){
                sum -= f[i-cur+1];
                cur--;
            }
            best = max(best,cur);
        }   
    }

    for (auto c : f) if (c<=m) best=max(best,1LL);

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