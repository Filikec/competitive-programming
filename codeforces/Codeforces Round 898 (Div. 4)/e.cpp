#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;


void work(){
    ll n,m;
    cin >> n >> m;

    ll lo,hi;
    lo = 1,hi=1e9*2;

    vector<ll> v(n);
    for (auto &c : v) cin >> c;

    while (lo < hi){
        ll mid = (lo+hi)/2+(lo+hi)%2;

        ll sum=0;
        for (auto c : v) sum += max(mid-c,0LL);
        
        if (sum > m){
            hi = mid-1;
        }else{
            lo = mid;
        }
    }
    cout << lo << '\n';

}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) work();

    return 0;   
}