#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll get(ll c, ll n ,ll l, ll t){
    ll all = ceil(n/7.0);
    return l*c+min(all,c*2)*t;
}

void work(){
    ll n,p,t,l;
    cin >> n >> p >> l >> t;
    ll lo=0,hi=n;

    while (lo<hi){
        ll mid = (lo+hi)/2;
        ll v = get(mid,n,l,t); 
        if (v > p) hi = mid;
        else if (v < p) lo = mid+1;
        else lo = hi = mid;
    }

    cout << n-lo << '\n';
}


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);


    int t;
    cin >> t;
    while (t--) work();

    return 0;
}
